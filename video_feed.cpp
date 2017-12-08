#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture vid(0);
	Mat frame;
	while(1) {
		vid>>frame;
		//vid.read(frame);
		imshow("Video Feed",frame);
		waitKey(50);
	}
	return 0;
}
