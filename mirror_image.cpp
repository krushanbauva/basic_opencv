#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;

int main() {
	
	Mat img = imread("image.jpg",1);
	namedWindow("Original Image",WINDOW_NORMAL);
	imshow("Original Image",img);
	waitKey(0);
	
	Mat mirror_img(img.rows,img.cols,CV_8UC3);
	
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			mirror_img.at<Vec3b>(i,img.cols-j-1) = img.at<Vec3b>(i,j);
		}
	}
	
	namedWindow("Mirror Image",WINDOW_NORMAL);
	imshow("Mirror Image",mirror_img);
	waitKey(0);
	
	return 0;
}
