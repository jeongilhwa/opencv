#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	//�̹����ҷ�����
	Mat img = imread("wifi.jpg");
	//�̹����� ����ְų� ������ faill���� ���
	if (img.empty())
	{
		cerr << "img load faill!!" << endl;
		return -1;
	}

	namedWindow("img");
	imshow("img", img);
	//while������ �׻���
	while (true)
	{
		int keycode = waitKey();

		//�빮�� �ҹ��� i �� �Է��ϸ� ȭ�����
		if (keycode == 'i' || keycode == 'I')
		{
			img = ~img;
			imshow("img", img);
		}
		//�ƽ�Ű�� 27==esc, q,Q�� ������ ���α׷� ����
		else if (keycode == 27 || keycode == 'q' || keycode == 'Q')
		{
			break;
		}


	}
	return 0;
}