#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;


    void getContours(Mat imgDil,Mat img){

        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(imgDil,contours,hierarchy,RETR_CCOMP,CHAIN_APPROX_SIMPLE);
        vector<vector<Point>> conPoly(contours.size());
        //drawContours(img,contours,-1,Scalar(255,0,255),1);
        
        for(int i=0;i<contours.size();i++)
        {
            int area=contourArea(contours[i]);
            cout<<area<<endl;
            if(area>1300&&area<1500)
            {
                float peri =arcLength(contours[i],true);
                approxPolyDP(contours[i],conPoly[i],0.02*peri,true);
                drawContours(img,conPoly,i,Scalar(255,0,255),3);
 
           }
        }

    }

Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
int main()
{
    string path ="4.jpg";
    Mat img =imread(path);
    //预处理
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray,imgBlur,Size(3,3),3,0);
    Canny(imgBlur,imgCanny,25,75);
    Mat kernel=getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(imgCanny,imgDil,kernel);


    getContours(imgCanny,img);
    imshow("img",img);
    waitKey(0);

}