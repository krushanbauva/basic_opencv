#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
	Mat img = imread(argv[1],0);
	int len = 2*sqrt(img.rows*img.rows + img.cols*img.cols);
	Mat img1(len,181,CV_8UC1,Scalar(255));
	double theta;
	int count;
	int r;
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			if(img.at<uchar>(i,j)>250) {
				count++;
				for(int th=0 ; th<181 ; th++) {
					theta = 3.14*th/180.0;
					r = i*cos(theta) + j*sin(theta);
					img1.at<uchar>(len/2-r,th)-=2;
				}
			}
		}
	}
	namedWindow("Hough Transform",WINDOW_NORMAL);
	imshow("Hough Transform",img1);
	cout<<count<<endl;
	waitKey(0);
	return 0;
}
