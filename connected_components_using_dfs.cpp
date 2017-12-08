#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img;
int X[] = {-1,-1,-1,0,0,1,1,1};
int Y[] = {-1,0,1,-1,1,-1,0,1};

int isValid(int x , int y) {
	if((x>=0)&&(y>=0)&&(x<img.rows)&&(y<img.cols)) {
		return 1;
	}
	return 0;
}

void dfs(int x , int y) {
	img.at<uchar>(x,y) = 0;
	for(int k=0 ; k<9 ; k++) {
		if(isValid(x+X[k],y+Y[k])) {
			if(img.at<uchar>(x+X[k],y+Y[k])>250) {
				dfs(x+X[k],y+Y[k]);
			}
		}
	}
}

int main(int argc, char **argv) {
	img = imread(argv[1],0);
	int count = 0;
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			if((img.at<uchar>(i,j)>250)) {
				count++;
				dfs(i,j);
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
