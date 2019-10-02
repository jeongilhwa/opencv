#include<opencv2/core.hpp>
//�̹�������� ���ȴ� ��ũ������� ����cv���� ���Ǵ� �⺻���� �ڷᱸ�����Լ�
#include<opencv2/imgcodecs.hpp>
//�̹��� ������ �о�����Լ��� �̹������Ϸ� �����ϴ��Լ�
#include<opencv2/highgui.hpp>
//�������̽��� ������ ��� ������� �Է��� �ޱ����� ����ϴ��Լ���
//ȭ���� �̹����� �����ֱ� ���� �Լ�

//#include<opencv2/opencv.hpp> ����

#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	//�̹����� ������ Mat ��ü�� ����
	Mat image;

	image = imread("wifi.jpg", IMREAD_COLOR);
	//imread()�Լ��� ����Ͽ� �̹����� �о� ���ϵǴ� mat��ü�� ������ ����
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