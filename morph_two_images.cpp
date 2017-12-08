#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img1,img2;

void update_img(int alpha , void *b) {
	double a;
	a = alpha/100.0;
	Mat morphed_img(img1.rows,img1.cols,CV_8UC3);
	for(int i=0 ; i<img1.rows ; i++) {
		for(int j=0 ; j<img1.cols ; j++) {
			morphed_img.at<Vec3b>(i,j)[0] = (int)((a*img1.at<Vec3b>(i,j)[0])+((1-a)*img2.at<Vec3b>(i,j)[0]));
			morphed_img.at<Vec3b>(i,j)[1] = (int)((a*img1.at<Vec3b>(i,j)[1])+((1-a)*img2.at<Vec3b>(i,j)[1]));
			morphed_img.at<Vec3b>(i,j)[2] = (int)((a*img1.at<Vec3b>(i,j)[2])+((1-a)*img2.at<Vec3b>(i,j)[2]));
		}
	}
	imshow("Morphed Image",morphed_img);
}

int main(int argc, char **argv) {
	img1 = imread(argv[1],1);
	img2 = imread(argv[2],1);
	namedWindow("Morphed Image",WINDOW_NORMAL);
	int alpha = 50;
	update_img(alpha,NULL);
	createTrackbar("Morphing","Morphed Image",&alpha,100,update_img);
	waitKey(0);
	return 0;
}
