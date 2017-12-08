#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;

int main(int argc, char **argv) {
	
	Mat img = imread(argv[1],1);
	namedWindow("Original Image",WINDOW_NORMAL);
	imshow("Original Image",img);
	waitKey(0);
	
	Mat water_img(img.rows , img.cols , CV_8UC3);
	
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			water_img.at<Vec3b>(img.rows-i-1,j) = img.at<Vec3b>(i,j);
		}
	}
	
	namedWindow("Water Image",WINDOW_NORMAL);
	imshow("Water Image",water_img);
	waitKey(0);
	
	return 0;
}
