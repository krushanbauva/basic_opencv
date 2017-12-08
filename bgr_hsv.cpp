#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
	Mat img = imread(argv[1],1);
	Mat hsv_img(img.rows,img.cols,CV_8UC3);
	cvtColor(img,hsv_img,CV_BGR2HSV);
	namedWindow("BGR",WINDOW_NORMAL);
	imshow("BGR",img);
	namedWindow("HSV",WINDOW_NORMAL);
	imshow("HSV",hsv_img);
	waitKey(0);
	return 0;
}
