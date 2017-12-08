#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int rows,cols;

int isValid(int x , int y) {
	if((x>=0)&&(y>=0)&&(x<rows)&&(y<cols)) {
		return 1;
	}
	return 0;
}

int main(int argc, char **argv) {
	int flag;
	Mat img = imread(argv[1],0);
	rows = img.rows , cols = img.cols;
	Mat n_img(img.rows,img.cols,CV_8UC1,Scalar(255));
	int X[] = {-1,-1,-1,0,0,0,1,1,1};
	int Y[] = {-1,0,1,-1,0,1,-1,0,1};
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			flag = 0;
			for(int k=0 ; k<9 ; k++) {
				if(isValid(i+X[k],j+Y[k])) {
					if(img.at<uchar>(i+X[k],j+Y[k])==0) {
						flag = 1;
					}
				}
			}
			if(flag==1) {
				n_img.at<uchar>(i,j)=0;
			}
		}
	}
	namedWindow("Erosion",WINDOW_NORMAL);
	imshow("Erosion",n_img);
	waitKey(0);
	return 0;	
}
