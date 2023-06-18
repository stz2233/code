#include<opencv2/opencv.hpp>
using namespace cv;
int main ()
{
    Mat a=imread("2.png");
    imshow("",a);
    waitKey(0);
    return 0;
}