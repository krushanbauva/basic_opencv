#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture vid(0);
	Mat frame;
	while(1) {
		vid>>frame;
		for(int i=0 ; i<frame.rows ; i++) {
			for(int j=0 ; j<frame.cols/2 ; j++) {
				frame.at<Vec3b>(i,(frame.cols/2)+j) = frame.at<Vec3b>(i,(frame.cols)/2-j-1);
			}
		}
		imshow("Video Output",frame);
		waitKey(50);
	}
}
