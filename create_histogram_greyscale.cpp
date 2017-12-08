#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

long long no_pixels[256];
long long max_no;

void scale_down(){
	double factor = 300.0/max_no;
	for(int i=0 ; i<256 ; i++) {
		no_pixels[i]=(int)(factor*no_pixels[i]);
	}
}

void create_hist() {
	Mat hist(320,256,CV_8UC1,Scalar(255));
	for(int i=0 ; i<256 ; i++) {
		for(int j=0 ; j<no_pixels[i] ; j++) {
			hist.at<uchar>(319-j,i) = 0;
		}
	}
	namedWindow("Histogram",WINDOW_NORMAL);
	imshow("Histogram",hist);
	waitKey(0);
}

int main(int argc, char **argv) {
	Mat img = imread(argv[1],0);
	long long temp;
	max_no = 0;
	for(int i=0 ; i<256 ; i++) {
		no_pixels[i] = 0;
	}
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			temp = ++no_pixels[img.at<uchar>(i,j)];
			if(temp>max_no) {
				max_no = temp;
			}
		}
	}
	
	scale_down();
	
	create_hist();
	
	return 0;
}
