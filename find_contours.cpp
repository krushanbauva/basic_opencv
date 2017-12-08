#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
	Mat img  = imread(argv[1],0);
	Mat img1(img.rows,img.cols,CV_8UC1);
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(255));
	vector<vector<Point> > contours;
	vector<Vec4i> heirarchy;
	threshold(img,img1,250,255,THRESH_BINARY_INV);
	dilate(img1,img1,Mat());
	dilate(img1,img1,Mat());
	dilate(img1,img1,Mat());
	dilate(img1,img1,Mat());
	erode(img1,img1,Mat());
	erode(img1,img1,Mat());
	erode(img1,img1,Mat());
	erode(img1,img1,Mat());
	findContours(img1,contours,heirarchy,RETR_TREE,CHAIN_APPROX_NONE);
	for(int i=0 ; i<contours.size() ; i++) {
		for(int j=0 ; j<contours[i].size() ; j++) {
			img2.at<uchar>(contours[i][j].y,contours[i][j].x) = 0;
		}
	}
	namedWindow("Output",WINDOW_NORMAL);
	namedWindow("After Contour",WINDOW_NORMAL);
	imshow("Output",img1);
	imshow("After Contour",img2);
	waitKey(0);
}
