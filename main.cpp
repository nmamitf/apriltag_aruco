#include<iostream>
#include "markdetector.h"
#include"opencv2/opencv.hpp"
using namespace std;
using namespace cv;

void test_mark() {
        Mat img = imread("102809.png", 0);
		MarkerDetector detectorM;
        detectorM.setMarkType(TAG25h9);

		std::vector<Marker> marks;
		detectorM.detect(img, marks);

        Mat rgbImg;
        cv::cvtColor(img, rgbImg, CV_GRAY2BGR);
		for (int i = 0; i < marks.size(); ++i)
		{
			for (int j = 0; j < marks[i].pt.size(); ++j)
                circle(rgbImg, marks[i].pt[j], 5, Scalar(0, 0, 255));
		}
        imwrite("out.png",rgbImg);
}

int main() {

	test_mark();
	return 0;
}
