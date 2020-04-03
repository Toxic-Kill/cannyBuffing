#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);//调用摄像头
	while (1)
	{
		cv::Mat frame;
		cv::Mat dstMat1;
		cv::Mat dstMat2;
		cv::Mat gryMat;
		cv::Mat dxMat;
		cv::Mat dyMat;
		cv::Mat abs_dxMat;
		cv::Mat abs_dyMat;
		cap >> frame;//获取当前帧
		cv::cvtColor(frame, gryMat, CV_BGR2GRAY);//将当前帧转为灰度图
		cv::Sobel(frame, dxMat, CV_16SC1, 1, 0, 3);//用Sobel对x方向微分
		cv::Sobel(frame, dyMat, CV_16SC1, 0, 1, 3);//用Sobel对y方向微分
		cv::Canny(dxMat, dyMat, dstMat1, 30, 90);//用Canny进行边缘检测
		cv::Canny(gryMat, dstMat2, 30, 90, 3);//用Canny进行边缘检测
		cv::imshow("frame", frame);//输出当前帧
		cv::imshow("dst1", dstMat1);//输出边缘检测后的结果
		cv::imshow("dst2", dstMat2);//输出边缘检测后的结构
		waitKey(30);
	}
}