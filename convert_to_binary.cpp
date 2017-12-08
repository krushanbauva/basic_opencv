#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat image;

void update_img(int t, void *a) {
	Mat b_image(image.rows,image.cols,CV_8UC1);
	for(int i=0 ; i<image.rows ; i++) {
		for(int j=0 ; j<image	.cols ; j++) {
			b_image.at<uchar>(i,j) = (image.at<uchar>(i,j) > t) ? 0 : 255;
		}
	}
	imshow("Binary Image",b_image);
}

int main(int argc, char **argv) {
	
	image = imread(argv[1],0);
	
	namedWindow("Binary Image",WINDOW_NORMAL);
	
	int th = 127;
	
	update_img(th,NULL);
	
	createTrackbar("Threshold value","Binary Image",&th,255,update_img);
	
	waitKey(0);
	
	return 0;
}
