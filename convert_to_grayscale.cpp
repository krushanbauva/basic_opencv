#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <algorithm>

using namespace std;
using namespace cv;

void display(String message,Mat &image) {
	namedWindow(message,WINDOW_NORMAL);
	imshow(message,image);
	waitKey(0);
}

void simple_avg(char *src) {
	int sum;
	Mat img = imread(src,1);
	Mat g_img(img.rows , img.cols , CV_8UC1);
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			sum = 0;
			for(int k=0 ; k<3 ; k++) {
				sum = sum + img.at<Vec3b>(i,j)[k];
			}
			g_img.at<uchar>(i,j) = (int)(sum/3);
		}
	}
	display("Greyscale image",g_img);
}

void weighted_avg(char *src) {
	double sum;
	double A[] = {0.07,0.72,0.21};
	Mat img = imread(src,1);
	Mat g_img(img.rows , img.cols , CV_8UC1);
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			sum = 0.0;
			for(int k=0 ; k<3 ; k++) {
				sum = sum + (A[k] * img.at<Vec3b>(i,j)[k]);
			}
			g_img.at<uchar>(i,j) = (int)sum;
		}
	}
	display("Greyscale image",g_img);
}

void max_min(char *src) {
	int b,g,r;
	Mat img = imread(src,1);
	Mat g_img(img.rows , img.cols , CV_8UC1);
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			b = img.at<Vec3b>(i,j)[0];
			g = img.at<Vec3b>(i,j)[1];
			r = img.at<Vec3b>(i,j)[2];
			g_img.at<uchar>(i,j) = (int)((max(b,max(g,r))+min(b,min(g,r)))/2);
		}
	}
	display("Greyscale image",g_img);
}

int main(int argc, char **argv) {
	int option;
	cout<<"Choose any one out of the three methods to convert an image to a greyscale image\n";
	cout<<"1.Simple Average\n";
	cout<<"2.Average of max and min\n";
	cout<<"3.Weighted Average\n";
	cin>>option;
	if(option == 1) {
		simple_avg(argv[1]);
	}
	else if(option == 2) {
		max_min(argv[1]);
	}
	else if(option == 3) {
		weighted_avg(argv[1]);
	}
	else {
		cout<<"Wrong input\n";
	}
	
	return 0;
}
