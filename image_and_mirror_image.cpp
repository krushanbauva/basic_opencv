#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;

int main(int argc, char **argv) {
	
	Mat img = imread(agrv[1],1);
	namedWindow("Original Image",WINDOW_NORMAL);
	imshow("Original Image",img);
	waitKey(0);
	
	Mat img_mirror_img(img.rows , 2*img.cols , CV_8UC3);
	
	for(int i=0 ; i<img.rows ; i++) {
		for(int j=0 ; j<img.cols ; j++) {
			img_mirror_img.at<Vec3b>(i,j) = img.at<Vec3b>(i,j);
			img_mirror_img.at<Vec3b>(i,img.cols+j) = img.at<Vec3b>(i,img.cols-j-1);
		}
	}
	
	namedWindow("Image and Mirror Image",WINDOW_NORMAL);
	imshow("Image and Mirror Image",img_mirror_img);
	waitKey(0);
	
	return 0;
}
