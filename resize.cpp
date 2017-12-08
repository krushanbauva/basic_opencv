#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img1,img2,img3;

Mat upscale(int factor) {
	int xtemp,ytemp;
	Mat img4(img1.rows*factor,img1.cols*factor,CV_8UC3);
	for(int i=0 ; i<img1.rows ; i++) {
		for(int j=0 ; j<img1.cols ; j++) {
			xtemp = factor*i;
			ytemp = factor*j;
			for(int q=0 ; q<factor ; q++) {
				for(int w=0 ; w<factor ; w++) {
					img4.at<Vec3b>(xtemp+q,ytemp+w) = img1.at<Vec3b>(i,j);
				}
			}
		}
	}
	return img4;
}

Mat downscale(int factor) {
	int xtemp,ytemp,bsum,gsum,rsum;
	Mat img5(img2.rows/factor,img2.cols/factor,CV_8UC3);
	for(int i=0 ; i<img5.rows ; i++) {
		for(int j=0 ; j<img5.cols ; j++) {
			xtemp = factor*i;
			ytemp = factor*j;
			bsum=gsum=rsum=0;
			for(int q=0 ; q<factor ; q++) {
				for(int w=0 ; w<factor ; w++) {
					bsum = bsum+img2.at<Vec3b>(xtemp+q,ytemp+w)[0];
					gsum = gsum+img2.at<Vec3b>(xtemp+q,ytemp+w)[1];
					rsum = rsum+img2.at<Vec3b>(xtemp+q,ytemp+w)[2];
				}
			}
			img5.at<Vec3b>(i,j)[0] = bsum/(factor*factor);
			img5.at<Vec3b>(i,j)[1] = gsum/(factor*factor);
			img5.at<Vec3b>(i,j)[2] = rsum/(factor*factor);
		}
	}
	return img5;
}

int main(int argc, char **argv) {
	img1 = imread(argv[1],1);
	img2 = upscale(argv[2]);
	img3 = downscale(argv[3]);
	namedWindow("Original Image",WINDOW_AUTOSIZE);
	namedWindow("Final Image",WINDOW_AUTOSIZE);
	imshow("Original Image",img1);
	imshow("Final Image",img3);
	waitKey(0);
	
	return 0;
}
