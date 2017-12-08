#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img(640,480,CV_8UC1,Scalar(255));

int isValid(int x , int y) {
	if((x>=0)&&(y>=0)&&(x<img.rows)&&(y<img.cols)) {
		return 1;
	}
	return 0;
}

void onMouse(int event, int y , int x , int flag , void *a) {
	if(flag == EVENT_FLAG_LBUTTON) {
		img.at<uchar>(x,y) = 0;
	}
	imshow("Colour",img);
}

int main() {
	namedWindow("Colour",WINDOW_NORMAL);
	imshow("Colour",img);
	setMouseCallback("Colour",onMouse,NULL);
	waitKey(0);
	return 0;
}
