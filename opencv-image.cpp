#include<opencv2/core.hpp>
//이미지저장시 사용된는 멧크레스비롯 오픈cv에서 사용되는 기본적인 자료구조와함수
#include<opencv2/imgcodecs.hpp>
//이미지 파일을 읽어오는함수와 이미지파일로 저장하는함수
#include<opencv2/highgui.hpp>
//인터페이스를 구현한 모듈 사용자의 입력을 받기위해 대기하는함수와
//화면의 이미지를 보여주기 위한 함수

//#include<opencv2/opencv.hpp> 통합

#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	//이미지를 저장할 Mat 객체를 생성
	Mat image;

	image = imread("wifi.jpg", IMREAD_COLOR);
	//imread()함수를 사용하여 이미지를 읽어 리턴되는 mat객체를 변수에 대입
	if (image.empty())
	{
		cout << "could not open or find the image" << endl;
		return -1;
	}
	namedWindow("Original", WINDOW_AUTOSIZE);
	imshow("original", image);

	waitKey(0);

	return 0;
}