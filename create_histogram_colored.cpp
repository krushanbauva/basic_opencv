#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

struct bgr {
	long long b;
	long long g;
	long long r;
};

bgr no_pixels[256];
long long max_no;

void scale_down(){
	double factor = 300.0/max_no;
	for(int i=0 ; i<256 ; i++) {
		no_pixels[i].b = (int)(factor*no_pixels[i].b);
		no_pixels[i].g = (int)(factor*no_pixels[i].g);
		no_pixels[i].r = (int)(factor*no_pixels[i].r);
	}
}

void create_hist() {
	Mat hist_b(320,256,CV_8UC3,Scalar(255,255,255));
	Mat hist_g(320,256,CV_8UC3,Scalar(255,255,255));
	Mat hist_r(320,256,CV_8UC3,Scalar(255,255,255));
	
	for(int i=0 ; i<256 ; i++) {
		for(int j=0 ; j<no_pixels[i].b ; j++) {
			hist_b.at<Vec3b>(319-j,i)[1] = 0;
			hist_b.at<Vec3b>(319-j,i)[2] = 0;
		}
		for(int j=0 ; j<no_pixels[i].g ; j++) {
			hist_g.at<Vec3b>(319-j,i)[0] = 0;
			hist_g.at<Vec3b>(319-j,i)[2] = 0;
		}
		for(int j=0 ; j<no_pixels[i].r ; j++) {
			hist_r.at<Vec3b>(319-j,i)[0] = 0;
			hist_r.at<Vec3b>(319-j,i)[1] = 0;
		}
	}
	
	
	namedWindow("Blue Histogram",WINDOW_NORMAL);
	imshow("Blue Histogram",hist_b);
	namedWindow("Green Histogram",WINDOW_NORMAL);
	imshow("Green Histogram",hist_g);
	namedWindow("Red Histogram",WINDOW_NORMAL);
	imshow("Red Histogram",hist_r);
	waitKey(0);
}

int main(int argc, char **argv){
	long long temp;
	Mat img = imread(argv[1],1);
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			temp = ++(no_pixels[img.at<Vec3b>(i,j)[0]].b);
			max_no = max_no>temp ? max_no : temp ;
			temp = ++(no_pixels[img.at<Vec3b>(i,j)[1]].g);
			max_no = max_no>temp ? max_no : temp ;
			temp = ++(no_pixels[img.at<Vec3b>(i,j)[2]].r);
			max_no = max_no>temp ? max_no : temp ;
		}
	}
	
	scale_down();
	
	create_hist();
	
	return 0;
}
