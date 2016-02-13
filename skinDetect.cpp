

#include<iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <cv.h>
#include <highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char**argv)
{
  Mat Original,image;
  Original = imread(argv[1]);
  imshow("Original image", Original);

//copy image
  image=Original.clone();
  blur( image, image, Size(3,3) );

   Mat hsv,img;
//convert RGB to HSV
   img=Original.clone();
   cvtColor(image, hsv, CV_BGR2HSV);
   Mat detect_hsv;
   inRange(hsv, Scalar(0, 10, 60), Scalar(20, 150, 255), detect_hsv);
   imshow("skin_pixels", detect_hsv);

   waitKey(0);
    return 0;
}
