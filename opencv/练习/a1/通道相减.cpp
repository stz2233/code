#include <opencv2/opencv.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main(int argc, char* argv[]){
	VideoCapture video;
        //用VideoCapture来读取摄像头
	Mat picture,image;
    //namedWindow("imput");
    video.open(4);            // 括号的0表示使用电脑自带的摄像头
    vector<Mat> channels;
    if (!video.isOpened())    //判断摄像头是否读取成功
	{
		return -1;   //返回一个代数值，表示函数失败（若为return 1，则表示ture）
	}
	while(1)   //（读取成功，使用循环语句将视频一帧一帧地展示出来）
    {
		video >> picture;   //词条将video中的数据流向picture
        image = picture;
        imshow("original", image);
        split(image, channels);
        imshow("B", channels[0]); //蓝色通道
        imshow("G", channels[1]); //绿色通道
        imshow("R", channels[2]); //红色通道
        //imshow("B-G", channels[0] - channels[1]); //蓝减绿
        //imshow("B-R", channels[0] - channels[2]); //蓝减红
        //imshow("G-R", channels[1] - channels[2]); //绿减红
        imshow("B-G-R", channels[0] - channels[1] - channels[2]); //蓝减绿减红


        waitKey(30);   
	}
	
 
	
	
 
	waitKey(0);
 
	return 0;
}