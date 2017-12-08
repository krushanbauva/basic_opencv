#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;

int main() {
	
	Mat img(8,8,CV_8UC1,Scalar(0));
	
	for(int i=0 ; i<8 ; i++) {
		for(int j=0 ; j<8 ; j++) {
			if((i+j)%2 == 0) {
				img.at<uchar>(i,j) = 255;
			}
		}
	}
	
	namedWindow("Chessboard",WINDOW_NORMAL);
	imshow("Chessboard",img);
	waitKey(0);
	
	return 0;
}
