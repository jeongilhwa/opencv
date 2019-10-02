//�˰�ü�� �������� ���
#include<opencv2/core.hpp>
//���� ����̽��� �����Ͽ� ������ �������⿡ �ʿ��� ����io���
#include<opencv2/videoio.hpp>
//�������̽��� ���� ���̱��̸��
#include<opencv2/highgui.hpp>
//�̹��� ���μ��� ���
#include<opencv2/imgproc.hpp>



#include<iostream>

using namespace cv;
using namespace std;

int main()
{

	Mat frame;

	VideoCapture cap("output.avi");
	if (!cap.isOpened())
	{
		cerr << "ī�޶� �� �� �����ϴ�." << endl;
		return -1;
	}
	
	int fps = cap.get(CAP_PROP_FPS);
	
	//������ ���
	
	//int width = cap.get(CAP_PROP_FRAME_WIDTH);
	//int height = cap.get(CAP_PROP_FRAME_HEIGHT);
	//int Fourcc = VideoWriter::fourcc('X', 'V', 'I', 'D');

	//VideoWriter outputVideo;
	//outputVideo.open("output.avi", -1, fps, Size(width, height), true);
	//if(!outputVideo.isOpened())
	//{
	//	cerr << "������ ������ ���� �ʱ�ȭ�� ����" << endl;
	//	return -1;

	//}
	while (1)
	{
		cap.read(frame);
		if (frame.empty())
		{
			cerr << "ĸó ����" << endl;
			break;
		}
		//void cv::cvtColor(inputArray src,OutputArray dst,int code,int dstCn=0)
		//						�Է�		���			��ȯ�ڵ�	
		
		//						���
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		
		imshow("Live", frame);

		//outputVideo.write(frame);

		int wait = int(1.0 / fps * 1000);
		if (waitKey(wait) >= 0)
			break;
	}
	return 0;
}
