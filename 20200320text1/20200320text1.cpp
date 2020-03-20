#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main() {
	cv::Mat srcMat = imread("E:\\Git\\coin.png", 0);
	//��ȡͼƬ
	if (srcMat.empty()) {
		return -1;
	}//��ȡʧ��
	cv::Mat binaryMat;
	threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);
	cv::imshow("��ֵ��", binaryMat);//��ʾ��ֵ��ͼ��
	//��ֵ��
	Mat erode_result;
	Mat dilate_result;
	Mat open_result;
	Mat close_result;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//�����ṹԪ�ش�СΪ3*3
	morphologyEx(binaryMat, erode_result, MORPH_ERODE, kernel);//��ʴ����
	morphologyEx(binaryMat, dilate_result, MORPH_DILATE, kernel);//���Ͳ���
	morphologyEx(binaryMat, open_result, MORPH_OPEN, kernel);//������
	morphologyEx(binaryMat, close_result, MORPH_CLOSE, kernel);//�ղ���

	imshow("��ʴ", erode_result);
	imshow("����", dilate_result);
	imshow("������", open_result);
	imshow("������", close_result);
	waitKey(0);
}