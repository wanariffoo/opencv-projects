// tutorial by Satya Mallick, https://www.learnopencv.com/blob-detection-using-opencv-python-c/

#include <iostream>
#include <stdlib.h>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
    // read image
    Mat im = imread("blob.jpeg", 0 );

    // set up the detector with default parameters
    SimpleBlobDetector::Params params;

    // set up the threshold
	params.minThreshold = 10;
	params.maxThreshold = 200;

	// filter by area
	params.filterByArea = true;
	params.minArea = 1500;

	// filter by circularity
	params.filterByCircularity = true;
	params.minCircularity = 0.1;

	// filter by convexity
	params.filterByConvexity = true;
	params.minConvexity = 0.87;

	// filter by inertia
	params.filterByInertia = true;
	params.minInertiaRatio = 0.01;


	// storing the blobs
	vector<KeyPoint> keypoints;

    // the detected blobs are drawn as red circles
	// note: DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures the size of the circle corresponds to the size of blob

	Mat im_with_keypoints;
	drawKeypoints( im, keypoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );

	// output blobs
	imshow("keypoints", im_with_keypoints );
	waitKey(0);


    return 0;
}