#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	//이미지불러오기
	Mat img = imread("wifi.jpg");
	//이미지가 비어있거나 없으면 faill문자 출력
	if (img.empty())
	{
		cerr << "img load faill!!" << endl;
		return -1;
	}

	namedWindow("img");
	imshow("img", img);
	//while문으로 항상대기
	while (true)
	{
		int keycode = waitKey();

		//대문자 소문자 i 를 입력하면 화면반전
		if (keycode == 'i' || keycode == 'I')
		{
			img = ~img;
			imshow("img", img);
		}
		//아스키값 27==esc, q,Q를 누르면 프로그램 종료
		else if (keycode == 27 || keycode == 'q' || keycode == 'Q')
		{
			break;
		}


	}
	return 0;
}