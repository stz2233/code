#include <opencv2/opencv.hpp>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;
int main(){
    VideoCapture cap=VideoCapture("/home/zz/视频/vlc-record-2023-06-03-20h51m20s-2023_05_27_16_34_40.avi-.avi");
    Mat img;
    int n=0;
    char filename[100];
    if(cap.isOpened()){
        cout<<1<<endl;
        return -1;
    }
    while(true){
        cap>>img;

        // if(i==5){
        //     i=0;
            //std::sprintf(filename, "1/%d.jpg", n);
            //imwrite(filename,img);
        // }
        imshow("123",img);
        waitKey(20);
        // i++;
    }
}