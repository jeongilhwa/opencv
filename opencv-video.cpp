//맷객체를 쓰기위한 모듈
#include<opencv2/core.hpp>
//비디오 디바이스에 접근하여 영상을 가져오기에 필요한 비디오io모듈
#include<opencv2/videoio.hpp>
//인터페이스를 위한 하이구이모듈
#include<opencv2/highgui.hpp>
//이미지 프로세싱 모듈
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
		cerr << "카메라를 열 수 없습니다." << endl;
		return -1;
	}
	
	int fps = cap.get(CAP_PROP_FPS);
	
	//동영상 찍기
	
	//int width = cap.get(CAP_PROP_FRAME_WIDTH);
	//int height = cap.get(CAP_PROP_FRAME_HEIGHT);
	//int Fourcc = VideoWriter::fourcc('X', 'V', 'I', 'D');

	//VideoWriter outputVideo;
	//outputVideo.open("output.avi", -1, fps, Size(width, height), true);
	//if(!outputVideo.isOpened())
	//{
	//	cerr << "동영상 저장을 위한 초기화중 에러" << endl;
	//	return -1;

	//}
	while (1)
	{
		cap.read(frame);
		if (frame.empty())
		{
			cerr << "캡처 실패" << endl;
			break;
		}
		//void cv::cvtColor(inputArray src,OutputArray dst,int code,int dstCn=0)
		//						입력		출력			변환코드	
		
		//						흑백
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		
		imshow("Live", frame);

		//outputVideo.write(frame);

		int wait = int(1.0 / fps * 1000);
		if (waitKey(wait) >= 0)
			break;
	}
	return 0;
}
