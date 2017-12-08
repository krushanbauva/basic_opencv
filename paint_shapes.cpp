#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img;
int X[] = {-1,0,0,1};
int Y[] = {0,1,-1,0};

int isValid(int x , int y) {
	if((x>=0)&&(y>=0)&&(x<img.rows)&&(y<img.cols)) {
		return 1;
	}
	return 0;
}

void dfs(int x , int y) {
	if(isValid(x,y)) {
		if(img.at<uchar>(x,y)>200) {
			img.at<uchar>(x,y)=0;
			for(int k=0 ; k<9 ; k++) {
				dfs(x+X[k],y+Y[k]);
			}
		}
	}
}

void onMouse(int event , int y , int x , int flag , void *a) {
	if(event == EVENT_LBUTTONDOWN) {
		dfs(x,y);
	}
	imshow("Colour",img);
}

int main(int argc, char **argv) {
	img = imread(argv[1],0);
	namedWindow("Colour",WINDOW_NORMAL);
	imshow("Colour",img);
	setMouseCallback("Colour",onMouse,NULL);
	waitKey(0);
	return 0;
}
