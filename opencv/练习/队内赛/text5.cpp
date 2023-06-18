#include<opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat src_blue,src_red,src_green,frame;
        
void blue(Mat frame) 
{
    cvtColor(frame,src_blue,COLOR_BGR2HSV);
    inRange(src_blue,Scalar(90,70,70),Scalar(130,255,255),src_blue);
    medianBlur(src_blue,src_blue,(3,3));
    Canny(src_blue,src_blue,0,100,3);
    vector<vector<Point>>contours;
    vector<Vec4i>hierarchy;
    findContours(src_blue,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE);
    int area;
    for (size_t i = 0; i < hierarchy.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours[i], 5, true);
	    area = contourArea(contours[i]);//计算轮廓面积
	    if (area > 1500)
        {
		    Point2f rect[4];
			RotatedRect box1 = minAreaRect(Mat(contours[i]));//获取最小外接矩阵
			box1.points(rect);  //把最小外接矩形四个端点复制给rect数组
		    for (int j = 0; j < 4; j++)
		    {
			    line(frame, rect[j], rect[(j + 1) % 4], Scalar(0, 255, 0), 2, 8);               
            }	    
        }
    }
}

void red(Mat frame) 
{
    cvtColor(frame,src_red,COLOR_BGR2HSV);
    inRange(src_red,Scalar(0,43,46),Scalar(10,255,255),src_red);
    medianBlur(src_red,src_red,(3,3));
    Canny(src_red,src_red,0,100,3);
    vector<vector<Point>>contours;
    vector<Vec4i>hierarchy;
    findContours(src_red,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE);
    int area;
    for (size_t i = 0; i < hierarchy.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours[i], 5, true);
		area = contourArea(contours[i]);//计算轮廓面积
		if (area > 1500)
		{
			Point2f rect[4];
			RotatedRect box1 = minAreaRect(Mat(contours[i]));//获取最小外接矩阵
			box1.points(rect);  //把最小外接矩形四个端点复制给rect数组
			for (int j = 0; j < 4; j++)
			{
				line(frame, rect[j], rect[(j + 1) % 4], Scalar(0, 255, 0), 2, 8);
            }	    
        }
    }
}

void green(Mat frame) 
{
    cvtColor(frame,src_green,COLOR_BGR2HSV);
    inRange(src_green,Scalar(35,43,46),Scalar(77,255,255),src_green);
    medianBlur(src_green,src_green,(3,3));
    Canny(src_green,src_green,0,100,3);
    vector<vector<Point>>contours;
    vector<Vec4i>hierarchy;
    findContours(src_green,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE);
    int area;
    for (size_t i = 0; i < hierarchy.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours[i], 5, true);
		area = contourArea(contours[i]);//计算轮廓面积
		if (area > 1500)
		{
			Point2f rect[4];
			RotatedRect box1 = minAreaRect(Mat(contours[i]));//获取最小外接矩阵
			box1.points(rect);  //把最小外接矩形四个端点复制给rect数组
			for (int j = 0; j < 4; j++)
			{
				line(frame, rect[j], rect[(j + 1) % 4], Scalar(0, 255, 0), 2, 8);
            }	    
        }
    }
}

int main()
{
    VideoCapture capture(0);
    while(true)
    {
        Mat frame;
        capture >> frame;
        
        blue(frame);
        red(frame);
        green(frame);
       
        imshow("",frame);
        waitKey(30);
    }

    return 0;
}
