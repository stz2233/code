#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>  
#include <opencv2/core/utils/logger.hpp>

using namespace cv;

int main()
{
    Mat a, b, c;
    a=imread("2.png");
    //a=imread("2.png",IMREAD_GRAYSCALE);//输出灰度图
    resize(a,b,Size(),0.6,0.6);//调大小
    //cvtColor(b,c,COLOR_BGR2HLS,0);//调换颜色空间
     Size2i i=Size(3,3);
    // GaussianBlur(b,c,i,0,0);//高斯
    //Canny(b,c,15,16,9,false);

    //Mat j =getStructuringElement(MORPH_RECT,i,Point(-1,-1));
    //dilate(b,c,j);//膨胀
    //erode(b,c,j);//侵蚀
    //c=b(Rect(0,0,400,400));//剪裁
    //putText(b,"hello",Point(300,400),FONT_HERSHEY_SIMPLEX,5.0f,Scalar(0,0,255),5,8,false);//写字
    imshow("原图",b);
    imshow("122",c);
    waitKey(0);
    return 0;
}