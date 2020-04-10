#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
	Mat dst;
	Mat src = imread("E:\\Git\\lena.jpg", 1);
	Point2f center(src.cols / 2.0, src.rows / 2.0);
	Mat rot = getRotationMatrix2D(center, -10, 1);
	//��ȡ����ı���
	Rect bbox = RotatedRect(center, src.size(), -10).boundingRect();
	//��������������
	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;
	//����任
	cv::warpAffine(src, dst, rot, bbox.size());

	imshow("dst", dst);
	waitKey(0);
}