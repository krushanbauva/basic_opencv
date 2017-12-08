#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>

using namespace std;
using namespace cv;

Mat img;
int rows,cols;

int isValid(int x , int y) {
	if((x>=0)&&(y>=0)&&(x<rows)&&(y<cols)) {
		return 1;
	}
	return 0;
}

void rotate(int t,void *a) {
	double theta = (3.14/180.0)*t;
	int side;
	side = sqrt((rows*rows)+(cols*cols));
	Mat r_img(side,side,CV_8UC3,Scalar(0,0,0));
	int xcn = side/2;
	int ycn = side/2;
	int xco = rows/2;
	int yco = cols/2;
	int xtn,ytn,xto,yto;
	int xo,yo;
	for(int i=0 ; i<r_img.rows ; i++) {
		for(int j=0 ; j<r_img.cols ; j++) {
			xtn = i-xcn;
			ytn = j-ycn;
			yto = (int)(cos(theta)*ytn + sin(theta)*xtn);
			xto = (int)(cos(theta)*xtn - sin(theta)*ytn);
			xo = xto + xco;
			yo = yto + yco;
			if(isValid(xo,yo)) {
				r_img.at<Vec3b>(i,j) = img.at<Vec3b>(xo,yo);
			}
		}
	}
	imshow("Rotated Image",r_img);
}

int main(int argc, char **argv) {
	img = imread(argv[1],1);
	namedWindow("Rotated Image",WINDOW_NORMAL);
	int theta = 0;
	rows = img.rows , cols = img.cols;
	rotate(theta,NULL);
	createTrackbar("Degrees","Rotated Image",&theta,360,rotate);
	waitKey(0);
	return 0;
}
