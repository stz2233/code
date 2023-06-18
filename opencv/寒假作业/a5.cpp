#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

//Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;

void getContours(Mat imgDil, Mat img)
{

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    Point2f rect[4];
    findContours(imgDil, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_TC89_KCOS);
    vector<Rect> boundRect(contours.size());  // 矩形定义
    vector<RotatedRect> box(contours.size()); // 最小外接矩形定义
    string str;//记录数据
    for (int i = 0; i < contours.size(); i++)
    {
        int area = contourArea(contours[i]);
        box[i] = minAreaRect(Mat(contours[i]));
        box[i].points(rect); // 把最小外接矩形四个端点复制给rect数组
        RotatedRect Rorect = minAreaRect(contours[i]);
        if (area > 1800&&Rorect.size.width/Rorect.size.height<2.8&&Rorect.size.width/Rorect.size.height>0.4)
        {
            //cout << area << endl;
            // 最小外接矩形
            
            boundRect[i] = boundingRect(contours[i]);
            
            float a = Rorect.size.width > Rorect.size.height ? Rorect.size.width : Rorect.size.height;
            float DistanceInches = (230 * 8) / a*10;                
            cout <<  DistanceInches<< endl;
            str=to_string(DistanceInches);
            //putText(img, str,Point(50,50),FONT_HERSHEY_SIMPLEX,5.0f,Scalar(0,0,255),1,2,false);
            
            for (int j = 0; j < 4; j++)
            {
                circle(img, rect[j%4], 3, Scalar(255, 0, 0), -1);
                line(img, rect[j], rect[(j + 1)%4 ], Scalar(0, 0, 255), 2, 3); // 绘制最小外接矩形每条边
            }
        }
    }
    putText(img, str,Point(50,50),FONT_HERSHEY_SIMPLEX,1.0f,Scalar(0,0,255),1,2,false);
    }
Mat Pretreat(Mat img)//预处理
{
    Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray,imgBlur,Size(3,3),3,0);
    Canny(imgBlur,imgCanny,25,75);
    Mat kernel=getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(imgCanny,imgDil,kernel);
    return imgDil;
}

int main()
{
    
    // string path ="0.jpg";
    // string path1 ="1.jpg";
    // string path2 ="3.jpg";
    Mat img[3] = {imread("0.jpg"), imread("1.jpg"), imread("3.jpg")};
    Mat a[3];
    for (int i = 0; i < 3;i++){
        a[i]= Pretreat(img[i]);
        //getContours(a[i], img[i]);
    }
    
    imshow("img",a[0]);
    imshow("img1",a[1]);
    imshow("img2",a[2]);
    waitKey(0);

}