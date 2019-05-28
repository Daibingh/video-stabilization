#ifndef UTILS_H
#define UTILS_H

#include "opencv2/opencv.hpp"
#include <vector>

using namespace std;
using namespace cv;


inline void crt_data(double* data, int len)
{
    for(int i=0; i<len; i++)
    {
        data[i] = rand() % 100 / 100.0;
    }
}

inline void range(double* data, double start, double step, int max_len)
{
    int len = 0;
    double val = start;
    while(len<max_len)
    {
        data[len] = val;
        val += step;
        len += 1;
    }
}


inline Mat get_transT(const Mat& prev, const Mat& curr, vector<cv::Point2f>& curr_pts)
{
    Mat prev_gray, curr_gray;
    cvtColor(prev, prev_gray, COLOR_BGR2GRAY);
    cvtColor(curr, curr_gray, COLOR_BGR2GRAY);
      vector <Point2f> prev_pts;

      // Detect features in previous frame
      goodFeaturesToTrack(prev_gray, prev_pts, 200, 0.01, 30);

      // Calculate optical flow (i.e. track feature points)
      vector <uchar> status;
      vector <float> err;
      calcOpticalFlowPyrLK(prev_gray, curr_gray, prev_pts, curr_pts, status, err);

      // Filter only valid points
      auto prev_it = prev_pts.begin();
      auto curr_it = curr_pts.begin();
      for(size_t k = 0; k < status.size(); k++)
      {
          if(status[k])
          {
            prev_it++;
            curr_it++;
          }
          else
          {
            prev_it = prev_pts.erase(prev_it);
            curr_it = curr_pts.erase(curr_it);
          }
      }


      // Find transformation matrix
      Mat T = estimateRigidTransform(prev_pts, curr_pts, false);
      return T;
}

inline void smooth(const vector<double>& x, const vector<double>& y, const vector<double>& a,
                   vector<double>& avg_x, vector<double>& avg_y, vector<double>& avg_a, int radius)
{
 for(int i=0; i < x.size(); i++) {
     double sum_x = 0;
     double sum_y = 0;
     double sum_a = 0;
     int count = 0;

     for(int j=-radius; j <= radius; j++) {
         if(i+j >= 0 && i+j < x.size()) {
             sum_x += x[i+j];
             sum_y += y[i+j];
             sum_a += a[i+j];

             count++;
         }
     }

     avg_a.push_back(sum_a / count);
     avg_x.push_back(sum_x / count);
     avg_y.push_back(sum_y / count);
 }

}

inline void smooth_one_point(const vector<double>& x, const vector<double>& y, const vector<double>& a,
                   vector<double>& avg_x, vector<double>& avg_y, vector<double>& avg_a, int radius)
{
     double sum_x = 0;
     double sum_y = 0;
     double sum_a = 0;
     int count = 0;

     int pos = avg_a.size();

     for(int j=-radius; j <= radius; j++) {
         if(pos+j >= 0 && pos+j < x.size()) {
             sum_x += x[pos+j];
             sum_y += y[pos+j];
             sum_a += a[pos+j];

             count++;
         }
     }

     avg_a.push_back(sum_a / count);
     avg_x.push_back(sum_x / count);
     avg_y.push_back(sum_y / count);

}

inline Mat getTransform(double dx, double dy, double da)
{
    Mat T(2,3,CV_64F);
    // Reconstruct transformation matrix accordingly to new values
    T.at<double>(0,0) = cos(da);
    T.at<double>(0,1) = -sin(da);
    T.at<double>(1,0) = sin(da);
    T.at<double>(1,1) = cos(da);

    T.at<double>(0,2) = dx;
    T.at<double>(1,2) = dy;

    return T;
}

inline void fixBorder(Mat &frame_stabilized)
{
 Mat T = getRotationMatrix2D(Point2f(frame_stabilized.cols/2, frame_stabilized.rows/2), 0, 1.04); // make frame a little larger.
 warpAffine(frame_stabilized, frame_stabilized, T, frame_stabilized.size(), INTER_LINEAR, BORDER_REPLICATE);
}

inline void draw_pornts(Mat& mat, const vector<cv::Point2f>& pts)
{
    for(int i=0; i<pts.size(); i++)
    {
        cv::circle(mat, pts[i], 3, Scalar(0,255,0), 2);
    }
}


#endif
