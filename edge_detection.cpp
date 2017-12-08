#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>

using namespace std;
using namespace cv;

Mat img,g_img;
int rows,cols;

void update_img(int th, void *a) {
	Mat img1(rows,cols,CV_8UC1,Scalar(255));
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			if(g_img.at<uchar>(i,j)>=th) {
				img1.at<uchar>(i,j) = 0;
			}
		}
	}
	imshow("Output",img1);
}

int main(int argc, char **argv) {
	img = imread(argv[1],0);
	g_img.create(img.rows,img.cols,CV_8UC1);
	rows = img.rows;
	cols = img.cols;
	int x[] = {-1,-1,-1,0,0,0,1,1,1};
	int y[] = {-1,0,1,-1,0,1,-1,0,1};
	int gx[] = {-1,0,1,-2,0,2,-1,0,1};
	int gy[] = {-1,-2,-1,0,0,0,1,2,1};
	int gxsum,gysum;
	for(int i=1 ; i<img.rows-1 ; i++) {
		for(int j=1 ; j<img.cols-1 ; j++) {
			gxsum=0;
			gysum=0;
			for(int k=0 ; k<9 ; k++) {
				gysum += gy[k]*img.at<uchar>(i+x[k],j+y[k]);
				gxsum += gx[k]*img.at<uchar>(i+x[k],j+y[k]);
			}
			g_img.at<uchar>(i,j) = sqrt((gxsum*gxsum)+(gysum*gysum))/8;
		}
	}
	namedWindow("Output",WINDOW_NORMAL);
	int th = 5;
	update_img(th,NULL);
	createTrackbar("Threshold value","Output",&th,255,update_img);
	waitKey(0);
	return 0;
}
