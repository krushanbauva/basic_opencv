#include <iostream>
#include <opencv2/opencv.hpp>
#include <limits.h>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
	Mat img = imread(argv[1],1);
	Mat tmpl = imread(argv[2],1);
	Mat result(img.rows-tmpl.rows+1 , img.cols-tmpl.cols+1 , CV_32FC1);
	matchTemplate(img,tmpl,result,TM_SQDIFF_NORMED);
	float min = 255.0;
	int x=0 , y=0;
	for(int i=0 ; i<result.rows ; i++) {
		for(int j=0 ; j<result.cols ; j++) {
			if(result.at<float>(i,j)<min) {
				min = result.at<float>(i,j);
				x=i , y=j;
			}
		}
	}
	for(int i=0 ; i<tmpl.rows ; i++) {
		for(int k=0 ; k<3 ; k++) {
			img.at<Vec3b>(i+x,y)[k] = 0;
			img.at<Vec3b>(i+x,y+tmpl.cols-1)[k] = 0;
		}
	}
	for(int j=0 ; j<tmpl.cols ; j++) {
		for(int k=0 ; k<3 ; k++) {
			img.at<Vec3b>(x,y+j)[k] = 0;
			img.at<Vec3b>(x+tmpl.rows-1,y+j)[k] = 0;
		}
	}
	namedWindow("Output",WINDOW_NORMAL);
	imshow("Output",img);
	namedWindow("Template",WINDOW_NORMAL);
	imshow("Template",tmpl);
	waitKey(0);
	return 0;
}
