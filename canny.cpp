#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img;
int L,H;

void update_img(int th , void *a) {
	Mat img1(img.rows,img.cols,CV_8UC1);
	Canny(img,img1,L,H,3,true);
	imshow("Edge Detection",img1);
}

int main(int argc, char **argv) {
	img = imread(argv[1],0);
	namedWindow("Edge Detection",WINDOW_NORMAL);
	L=50 , H=100;
	update_img(0,NULL);
	createTrackbar("L","Edge Detection",&L,200,update_img);
	createTrackbar("H","Edge Detection",&H,600,update_img);
	waitKey(0);
	return 0;
}
