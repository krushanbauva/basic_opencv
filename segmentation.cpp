#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img;
int b_low,b_high,g_low,g_high,r_low,r_high;

int isValid(int x, int y) {
	if((img.at<Vec3b>(x,y)[0]>=b_low)&&(img.at<Vec3b>(x,y)[0]<=b_high)) {
		if((img.at<Vec3b>(x,y)[1]>=g_low)&&(img.at<Vec3b>(x,y)[1]<=g_high)) {
			if((img.at<Vec3b>(x,y)[2]>=r_low)&&(img.at<Vec3b>(x,y)[2]<=r_high)) {
				return 1;
			}
		}
	}
	return 0;
}

void update_img(int t,void *a) {
	Mat n_img(img.rows,img.cols,CV_8UC1,Scalar(255));
	//cout<<t<<endl;
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			if(isValid(i,j)) {
				n_img.at<uchar>(i,j) = 0;
			}
		}
	}
	imshow("Output",n_img);
}

int main(int argc, char **argv) {
	img = imread(argv[1],1);
	namedWindow("Output",WINDOW_NORMAL);
	b_low = g_low = r_low = 0;
	b_high = g_high = r_high = 255;
	update_img(0,NULL);
	createTrackbar("B Low","Output",&b_low,255,update_img);
	createTrackbar("B High","Output",&b_high,255,update_img);
	createTrackbar("G Low","Output",&g_low,255,update_img);
	createTrackbar("G High","Output",&g_high,255,update_img);
	createTrackbar("R Low","Output",&r_low,255,update_img);
	createTrackbar("R High","Output",&r_high,255,update_img);
	waitKey(0);
	return 0;
}
