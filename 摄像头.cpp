#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
 Mat Pretreat(Mat img)//预处理
{
    Mat imgHsv,imgBlur,imgRange,imgDil,imgErode;

    int low_H=35, low_S=43, low__V=46;
    //最低值
    vector<Vec3f> circles;
    //收集圆的坐标
    resize(img,imgRange,img.size());
    resize(img,imgHsv,img.size());
    resize(img,imgBlur,img.size());

    int high_H=77, high_S=255, high_V=255;
    //最高值
    cvtColor(img, imgHsv, COLOR_BGR2HSV);
    //BGR转化为HSV
    
    inRange(imgHsv,  Scalar(low_H, low_S, low__V), Scalar(high_H, high_S, high_V),imgRange);

    medianBlur(imgRange,imgBlur,(3,3));
    //中值滤波
    HoughCircles(imgBlur, circles, HOUGH_GRADIENT, 1, 500, 15, 3,20,50);
    //找圆
    
        circle(img, Point(circles[0][0], circles[0][1]), circles[0][2], Scalar(0, 0, 255), 5);
        // 画圆；
    

    return img;
}
int main() 
{
	VideoCapture video;
        //用VideoCapture来读取摄像头
	Mat picture,img;
        
    
    
    //namedWindow("imput");
    video.open(4);            // 括号的0表示使用电脑自带的摄像头
    if (!video.isOpened())    //判断摄像头是否读取成功
	{
		return -1;   //返回一个代数值，表示函数失败（若为return 1，则表示ture）
	}
	while(1)   //（读取成功，使用循环语句将视频一帧一帧地展示出来）
    {
		video >> picture;   //词条将video中的数据流向picture
        //img = Pretreat(picture);
        img = picture;
        imshow("imput", img); // 使用imshow语句将图片显示出来
        waitKey(30);   
	}
	return 0;
}