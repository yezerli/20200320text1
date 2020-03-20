#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main() {
	cv::Mat srcMat = imread("E:\\Git\\coin.png", 0);
	//读取图片
	if (srcMat.empty()) {
		return -1;
	}//读取失败
	cv::Mat binaryMat;
	threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);
	cv::imshow("二值化", binaryMat);//显示二值化图像
	//二值化
	Mat erode_result;
	Mat dilate_result;
	Mat open_result;
	Mat close_result;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//创建结构元素大小为3*3
	morphologyEx(binaryMat, erode_result, MORPH_ERODE, kernel);//腐蚀操作
	morphologyEx(binaryMat, dilate_result, MORPH_DILATE, kernel);//膨胀操作
	morphologyEx(binaryMat, open_result, MORPH_OPEN, kernel);//开操作
	morphologyEx(binaryMat, close_result, MORPH_CLOSE, kernel);//闭操作

	imshow("腐蚀", erode_result);
	imshow("膨胀", dilate_result);
	imshow("开运算", open_result);
	imshow("闭运算", close_result);
	waitKey(0);
}