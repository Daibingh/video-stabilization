#include "mainwindow.h"
#include <QFile>


MainWindow::MainWindow(QWidget* parent): QMainWindow(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);
//    this->resize(800, 600);
    d = new Dialog(this);

    ui->qwtPlot->setAxisAutoScale(0);
    ui->qwtPlot->setAxisAutoScale(1);

    grid = new QwtPlotGrid;
    grid_2 = new QwtPlotGrid;
    grid_3 = new QwtPlotGrid;

    curve_11 = new QwtPlotCurve(QString("x"));
    curve_12 = new QwtPlotCurve(QString("y"));
    curve_21 = new QwtPlotCurve(QString("a"));
    curve_22 = new QwtPlotCurve(QString("a"));
    curve_31 = new QwtPlotCurve(QString("a"));
    curve_32 = new QwtPlotCurve(QString("a"));

    grid->attach(ui->qwtPlot);
    grid_2->attach(ui->qwtPlot_2);
    grid_3->attach(ui->qwtPlot_3);


    curve_11->setPen(Qt::blue, 1);
    curve_11->setStyle(QwtPlotCurve::Lines);
    curve_11->attach(ui->qwtPlot);

    curve_21->setPen(Qt::blue, 1);
    curve_21->setStyle(QwtPlotCurve::Lines);
    curve_21->attach(ui->qwtPlot_2);

    curve_31->setPen(Qt::blue, 1);
    curve_31->setStyle(QwtPlotCurve::Lines);
    curve_31->attach(ui->qwtPlot_3);

    curve_12->setPen(Qt::red, 1);
    curve_12->setStyle(QwtPlotCurve::Lines);
    curve_12->attach(ui->qwtPlot);

    curve_22->setPen(Qt::red, 1);
    curve_22->setStyle(QwtPlotCurve::Lines);
    curve_22->attach(ui->qwtPlot_2);

    curve_32->setPen(Qt::red, 1);
    curve_32->setStyle(QwtPlotCurve::Lines);
    curve_32->attach(ui->qwtPlot_3);

//    curve_2->attach(ui->qwtPlot_2);
//    curve_3->attach(ui->qwtPlot_3);
//    int num = 100;
//    double* x = new double[num];
//    double* y_11 = new double[num];
//    double* y_12 = new double[num];
//    range(x, 0, 1, num);
//    crt_data(y_11, num);
//    crt_data(y_12, num);

//    curve_11->setSamples(x, y_11, num);
//    curve_12->setSamples(x, y_12, num);

    ui->qwtPlot->replot();

    QFile qss(":/qss/dark.qss");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    player = new Videoplayer;
    player->moveToThread(&thread);

    connect(&thread, &QThread::finished, player, &QObject::deleteLater);
    connect(this, &MainWindow::start, player, &Videoplayer::play); // 连接启动耗时操作的槽函数
//    connect(player, &Videoplayer::img_ready, this, &MainWindow::show_img); // 连接耗时操作完成的信号
    connect(player, &Videoplayer::process_ready, this, &MainWindow::handle_process_ready); // 连接耗时操作完成的信号
    connect(player, &Videoplayer::finished, this, &MainWindow::handle_finished);
    thread.start(); // 启动新线程的事件循环

//    qDebug()<<ui->scrollArea->size().width();
//    qDebug()<<ui->scrollArea->size().height();
    this->resize(1200, 700);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(time_ticks) delete time_ticks;
    thread.quit();
    thread.wait();
    cap.release();
}

void MainWindow::on_actionopen_triggered()
{
    video_file = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      ".",
                                                      tr("Videos (*.avi *.mp4)"));
    cap.open(video_file.toStdString());
    if(!cap.isOpened())
    {
        QMessageBox::information(this, tr("Error"), tr("Open video failed!"));
        return;
    }
    open_success = true;
    frame_width = int(cap.get(CAP_PROP_FRAME_WIDTH));
    frame_height = int(cap.get(CAP_PROP_FRAME_HEIGHT));
    n_frames = int(cap.get(CAP_PROP_FRAME_COUNT));
    frame_rate = int(cap.get(CV_CAP_PROP_FPS));
    cap >> frame;
    float scaled_h = play_height / float(frame_height);
    float scaled_w = play_width / float(frame_width);
    play_scale = scaled_h < scaled_w ? scaled_h : scaled_w;
//    qDebug()<<frame_width<<", "<<frame_height;
//    qDebug()<<play_scale;
    cv::resize(frame, scaled_frame, cv::Size(0, 0), play_scale, play_scale);
    ui->label->setPixmap(QPixmap::fromImage(QImage(scaled_frame.data, scaled_frame.cols,
                                                   scaled_frame.rows, scaled_frame.step, QImage::Format_RGB888)));

    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(n_frames);
    ui->horizontalSlider->setValue(0);
    time_ticks = new double[n_frames-1];
    range(time_ticks, 1, 1, n_frames-1);
    clear_plot();
    ui->label_2->clear();
    ui->label_2->setText(tr("-: Video :-"));
    //    qDebug()<<video_file;
}

void MainWindow::on_actionstart_triggered()
{
    player->reset = false;
   if(!open_success)
   {
       QMessageBox::information(this, tr("Error"), tr("Please open a video first!"));
   }
   else if(isbusy)
   {
       QMessageBox::information(this, tr("Error"), tr("The player is busy!"));
   }
   else
   {
       isbusy = true;
       clear_plot();
       player->set_info(cap, play_scale, 20, frame_width, frame_height, frame_rate);
       emit start();
   }
}

//void MainWindow::show_img(const QImage& img, double* x, double* y, double* a, int frame_pos)
//{
//    ui->label->setPixmap(QPixmap::fromImage(img));
//    ui->horizontalSlider->setValue(frame_pos);
//    curve_11->setSamples(time_ticks, x, frame_pos);
//    curve_21->setSamples(time_ticks, y, frame_pos);
//    curve_31->setSamples(time_ticks, a, frame_pos);
////    qDebug()<<frame_pos;
//    ui->qwtPlot->replot();
//    ui->qwtPlot_2->replot();
//    ui->qwtPlot_3->replot();
//}

void MainWindow::handle_process_ready(const QImage& img, const QImage& img_2, double* x, double* y, double* a,
                                      double* avg_x, double* avg_y, double* avg_a, int frame_pos)
{
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label_2->setPixmap(QPixmap::fromImage(img_2));
    ui->horizontalSlider->setValue(frame_pos);
    curve_11->setSamples(time_ticks, x, frame_pos);
    curve_21->setSamples(time_ticks, y, frame_pos);
    curve_31->setSamples(time_ticks, a, frame_pos);
    curve_12->setSamples(time_ticks, avg_x, frame_pos);
    curve_22->setSamples(time_ticks, avg_y, frame_pos);
    curve_32->setSamples(time_ticks, avg_a, frame_pos);
//    qDebug()<<frame_pos;
    ui->qwtPlot->replot();
    ui->qwtPlot_2->replot();
    ui->qwtPlot_3->replot();
}

void MainWindow::handle_finished()
{
    isbusy = false;
}

void MainWindow::on_actionradius_triggered()
{
    d->show();
}

void MainWindow::on_actionstop_triggered()
{
    if(!isbusy) return;
    if(ui->actionstop->text() == tr("stop"))
    {
        ui->actionstop->setText(tr("continue"));
        player->stop = true;
    }
    else
    {
        ui->actionstop->setText(tr("stop"));
        player->stop = false;
    }
}

void MainWindow::on_actionreset_triggered()
{
    player->reset = true;
    clear_plot();
    ui->actionstop->setText(tr("stop"));
    isbusy = false;
    if(cap.isOpened())
    {
        cap.set(CAP_PROP_POS_FRAMES, 0);
        cap>>frame;
        cv::resize(frame, scaled_frame, cv::Size(0, 0), play_scale, play_scale);
        ui->label->setPixmap(QPixmap::fromImage(QImage(scaled_frame.data, scaled_frame.cols,
                                                       scaled_frame.rows, scaled_frame.step, QImage::Format_RGB888)));
        ui->horizontalSlider->setValue(0);
        ui->label_2->clear();
        ui->label_2->setText(tr("-: Video :-"));
    }
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    player->reset = true;
    event->accept();
}

void MainWindow::clear_plot()
{
    curve_11->setSamples(0, 0, 0);
    curve_12->setSamples(0, 0, 0);
    curve_21->setSamples(0, 0, 0);
    curve_22->setSamples(0, 0, 0);
    curve_31->setSamples(0, 0, 0);
    curve_32->setSamples(0, 0, 0);
    ui->qwtPlot->replot();
    ui->qwtPlot_2->replot();
    ui->qwtPlot_3->replot();
}
