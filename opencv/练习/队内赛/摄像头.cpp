#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
 Mat Pretreat(Mat img)//预处理
{
    Mat imgHsv,imgBlur,imgRange,imgDil,imgErode;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    
    
    vector<Vec3f> circles;
    //收集圆的坐标
    resize(img,imgRange,img.size());
    resize(img,imgHsv,img.size());
    resize(img,imgBlur,img.size());
    //最高值
    int high_H=77, high_S=255, high_V=255;
    Scalar green_high = Scalar(77, 255, 255);
    //最低值
    Scalar green_low = Scalar(35, 43, 36);

    medianBlur(img,imgBlur,(3,3));//中值滤波
    
    cvtColor(imgBlur, imgHsv, COLOR_BGR2HSV);
    //BGR转化为HSV
    
    inRange(imgHsv,  green_low, green_high,imgRange);
    findContours(imgDil, contours,hierarchy, RETR_TREE, CHAIN_APPROX_TC89_KCOS);
    
    
    //HoughCircles(imgRange, circles, HOUGH_GRADIENT, 1, 500, 15, 3,20,50);
    //找圆



    for (int i = 0; i < 2; i++)
    {   float peri =arcLength(contours[i],true);
        circle(img, Point(circles[0][0], circles[0][1]), circles[0][2], Scalar(0, 0, 255), 5);
        // 画圆；
    }

    return img;
}
int main() 
{
	VideoCapture video;
        //用VideoCapture来读取摄像头
	Mat picture,img;
        
    
    
    //namedWindow("imput");
    video.open(0);            // 括号的0表示使用电脑自带的摄像头
    if (!video.isOpened())    //判断摄像头是否读取成功
	{
		return -1;   //返回一个代数值，表示函数失败（若为return 1，则表示ture）
	}
	while(1)   //（读取成功，使用循环语句将视频一帧一帧地展示出来）
    {
		video >> picture;   //词条将video中的数据流向picture
        img = Pretreat(picture);
        imshow("imput", img); // 使用imshow语句将图片显示出来
        waitKey(30);   
	}
	return 0;
}