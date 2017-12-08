#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int rows,cols;

int isValid(int x , int y) {
	if((x>=0)&&(x<rows)&&(y>=0)&&(y<cols)) {
		return 1;
	}
	return 0;
}

struct bgr {
	double b;
	double g;
	double r;
};

int main(int argc, char **argv) {
	Mat img = imread(argv[1],1);
	rows = img.rows, cols = img.cols;
	Mat b_img(rows,cols,CV_8UC3);
	bgr sum;
	double count;
	int X[] = {-1,0,1,-1,0,1,-1,0,1};
	int Y[] = {-1,-1,-1,0,0,0,1,1,1};
	double V[] = {0.0625 , 0.125 , 0.0625 , 0.125 , 0.25 , 0.125 , 0.0625 , 0.125 , 0.0625};
	for(int i=0 ; i<rows ; i++) {
		for(int j=0 ; j<cols ; j++) {
			count = 0.0;
			sum.b = 0.0;
			sum.g = 0.0;
			sum.r = 0.0;
			for(int k=0 ; k<9 ; k++) {
				if(isValid(i+X[k],j+Y[k])==1) {
					count = count+V[k];
					sum.b += img.at<Vec3b>(i+X[k],j+Y[k])[0]*V[k];
					sum.g += img.at<Vec3b>(i+X[k],j+Y[k])[1]*V[k];
					sum.r += img.at<Vec3b>(i+X[k],j+Y[k])[2]*V[k];
				}
			}
			b_img.at<Vec3b>(i,j)[0] = (int)(sum.b/count);
			b_img.at<Vec3b>(i,j)[1] = (int)(sum.g/count);
			b_img.at<Vec3b>(i,j)[2] = (int)(sum.r/count);
		}
	}
	namedWindow("Gaussian Blur",WINDOW_NORMAL);
	imshow("Gaussian Blur",b_img);
	waitKey(0);
	
	return 0;
}
