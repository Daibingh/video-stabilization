#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_window.h"
#include <QMainWindow>
#include <QtWidgets>
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>
#include <qwt_plot.h>
#include <vector>
#include <cstdlib>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QThread>
#include "utils.hpp"
#include "dialog.h"
#include <QCloseEvent>


const int SMOOTHING_RADIUS = 50; // In frames. The larger the more stable the video, but less reactive to sudden panning

using namespace std;
using namespace cv;

class Dialog;


class Videoplayer: public QObject
{
    Q_OBJECT
public:
    VideoCapture cap;
    Mat frame;
    Mat scaled_frame;
    Mat scaled_frame_2;
    Mat frame_stabilized;
    int ms_delay;
    float play_scale;
    QImage img, img_2;
    vector<double> x;
    vector<double> y;
    vector<double> a;
    vector<double> avg_x;
    vector<double> avg_y;
    vector<double> avg_a;
    int radius = 50;
    bool stop = false;
    bool reset = false;

    void set_info(const VideoCapture& cap, float play_scale, int ms_delay)
    {
        this->cap = cap;
        this->play_scale = play_scale;
        this->ms_delay = ms_delay;
//        qDebug()<<ms_delay;
    }

    ~Videoplayer()
    {
        frame.release();
        scaled_frame.release();
        scaled_frame_2.release();
    }

    void clear_data()
    {
        x.clear();
        y.clear();
        a.clear();
        avg_x.clear();
        avg_y.clear();
        avg_a.clear();
    }

 public slots:
    void play()
    {
        clear_data();

        cap.set(CV_CAP_PROP_POS_FRAMES, 0);
        int n_frames = int(cap.get(CAP_PROP_FRAME_COUNT));

        Mat curr;
        Mat prev;

        // Read first frame
        cap >> prev;

        Mat last_T;

        double xx = 0;
        double yy = 0;
        double aa = 0;

        for(int i=1; i<n_frames-1; i++)
        {
            while(stop)
            {
                if(reset)
                {
                    clear_data();
                    return;
                }
            }
            if(reset)
            {
                clear_data();
                return;
            }
            vector<cv::Point2f> pts;
            double dx, dy, da;
            // Read next frame
            bool success = cap.read(curr);
            if(!success) break;
            Mat T = get_transT(prev, curr, pts);
            if(T.data == NULL) last_T.copyTo(T);
            T.copyTo(last_T);
            dx = T.at<double>(0,2);
            dy = T.at<double>(1,2);
            da = atan2(T.at<double>(1,0), T.at<double>(0,0));
            x.push_back(xx+=dx);
            y.push_back(yy+=dy);
            a.push_back(aa+=da);

            qDebug()<<i<<": "<<x[i-1]<<", "<<y[i-1]<<", "<<a[i-1];

            // Move to next frame
            curr.copyTo(prev);

            draw_pornts(curr, pts);

            cv::resize(curr, scaled_frame, cv::Size(0, 0), play_scale, play_scale);
            img = QImage(scaled_frame.data, scaled_frame.cols, scaled_frame.rows, scaled_frame.step, QImage::Format_RGB888);      

            emit img_ready(img, x.data(), y.data(), a.data(), i);
            QThread::msleep(5);
        }

        smooth(x, y, a, avg_x, avg_y, avg_a, radius);
        cout<<"radius in player: "<<radius<<endl;
        cap.set(CV_CAP_PROP_POS_FRAMES, 0);
        Mat T;

        for( int i = 0; i < x.size()-1; i++)
        {
            while(stop)
            {
                if(reset)
                {
                    clear_data();
                    return;
                }
            }
            if(reset)
            {
                clear_data();
                return;
            }
            bool success = cap.read(frame);
            if(!success) break;

            // Extract transform from translation and rotation angle.
            double dx_smoothed, dy_smoothed, da_smoothed;
            dx_smoothed = avg_x[i] + x[i+1] - 2*x[i];
            dy_smoothed = avg_y[i] + y[i+1] - 2*y[i];
            da_smoothed = avg_a[i] + a[i+1] - 2*a[i];
//            dx_smoothed = avg_x[i+1] - avg_x[i];
//            dy_smoothed = avg_y[i+1] - avg_y[i];
//            da_smoothed = avg_a[i+1] - avg_a[i];
            cout<<i<<": "<<dx_smoothed<<", "<<dy_smoothed<<", "<<da_smoothed<<endl;
            T = getTransform(dx_smoothed, dy_smoothed, da_smoothed);

            // Apply affine wrapping to the given frame
            warpAffine(frame, frame_stabilized, T, frame.size(), INTER_LINEAR, BORDER_REPLICATE);

            // Scale image to remove black border artifact
            fixBorder(frame_stabilized);

            cv::resize(frame, scaled_frame, cv::Size(0, 0), play_scale, play_scale);
            cv::resize(frame_stabilized, scaled_frame_2, cv::Size(0, 0), play_scale, play_scale);
            img = QImage(scaled_frame.data, scaled_frame.cols, scaled_frame.rows, scaled_frame.step, QImage::Format_RGB888);
            img_2 = QImage(scaled_frame_2.data, scaled_frame_2.cols, scaled_frame_2.rows, scaled_frame_2.step, QImage::Format_RGB888);
            emit process_ready(img, img_2, avg_x.data(), avg_y.data(), avg_a.data(), i);
            QThread::msleep(ms_delay);
        }
        emit finished();
    }

signals:
    void img_ready(const QImage& img, double* x, double* y, double* a, int frame_pos);
    void process_ready(const QImage& img, const QImage& img_2, double* x, double* y, double* a, int frame_pos);
    void finished();
};


class MainWindow: public QMainWindow
{
     Q_OBJECT
public:
    explicit MainWindow(QWidget* parent=0);
    ~MainWindow();
    void clear_plot();

    Dialog* d;
    Ui_MainWindow* ui;
    QString video_file;
    VideoCapture cap;
    Mat frame;
    Mat scaled_frame;
    int n_frames;
    int frame_width;
    int frame_height;
    int frame_rate;
    bool open_success = false;
    bool isbusy = false;
    int play_width = 420;
    int play_height = 380;
    float play_scale;

    QwtPlotGrid* grid;
    QwtPlotGrid* grid_2;
    QwtPlotGrid* grid_3;

    QwtPlotCurve* curve_11;
    QwtPlotCurve* curve_12;
    QwtPlotCurve* curve_21;
    QwtPlotCurve* curve_22;
    QwtPlotCurve* curve_31;
    QwtPlotCurve* curve_32;

    QThread thread;
    Videoplayer* player;

    double* time_ticks = NULL;

public slots:
    void on_actionopen_triggered();
    void on_actionstart_triggered();
    void show_img(const QImage& img, double* x, double* y, double* a, int frame_pos);
    void handle_process_ready(const QImage& img, const QImage& img_2, double* x, double* y, double* a, int frame_pos);
    void handle_finished();
    void on_actionradius_triggered();
    void on_actionstop_triggered();
    void on_actionreset_triggered();
signals:
    void start();
protected:
     void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H