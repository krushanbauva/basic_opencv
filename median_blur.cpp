#include <iostream>
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <vector>

using namespace std;
using namespace cv;

int rows,cols;

int isValid(int x , int y) {
	if((x>=0)&&(x<rows)&&(y>=0)&&(y<cols)) {
		return 1;
	}
	return 0;
}

int main(int argc, char **argv) {
	Mat img = imread(argv[1],1);
	rows = img.rows, cols = img.cols;
	Mat b_img(rows,cols,CV_8UC3);
	int count;
	int X[] = {-1,0,1,-1,0,1,-1,0,1};
	int Y[] = {-1,-1,-1,0,0,0,1,1,1};
	for(int i=0 ; i<rows ; i++) {
		for(int j=0 ; j<cols ; j++) {
			count = 0;
			vector<int> b_Neighbours;
			vector<int> g_Neighbours;
			vector<int> r_Neighbours;
			for(int k=0 ; k<9 ; k++) {
				if(isValid(i+X[k],j+Y[k])==1) {
					count++;
					b_Neighbours.push_back(img.at<Vec3b>(i+X[k],j+Y[k])[0]);
					g_Neighbours.push_back(img.at<Vec3b>(i+X[k],j+Y[k])[1]);
					r_Neighbours.push_back(img.at<Vec3b>(i+X[k],j+Y[k])[2]);
				}
			}
			sort(b_Neighbours.begin(),b_Neighbours.end());
			sort(g_Neighbours.begin(),g_Neighbours.end());
			sort(r_Neighbours.begin(),r_Neighbours.end());
			b_img.at<Vec3b>(i,j)[0] = b_Neighbours[count/2];
			b_img.at<Vec3b>(i,j)[1] = g_Neighbours[count/2];
			b_img.at<Vec3b>(i,j)[2] = r_Neighbours[count/2];
		}
	}
	namedWindow("Median Blur",WINDOW_NORMAL);
	imshow("Median Blur",b_img);
	waitKey(0);
	
	return 0;
}
