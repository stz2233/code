#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;


    /// @brief 
    /// @param imgDil 
    /// @param img 
    void getContours(Mat imgDil,Mat img){

        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        Point2f rect[4];
        findContours(imgDil, contours,hierarchy, RETR_TREE, CHAIN_APPROX_TC89_KCOS);
        vector<vector<Point>> conPoly(contours.size());
        vector<Rect> boundRect(contours.size());//矩形定义
        vector<RotatedRect> box(contours.size());//最小外接矩形定义
        //drawContours(img,contours,-1,Scalar(255,0,255),1);
        for(int i=0;i<contours.size();i++)
        {
            int area=contourArea(contours[i]);
            cout<<area<<endl;
            //vector<vector<Point>> conPoly(contours.size());
            if(area>1000)
            {
                //最小外接矩形
                box[i] = minAreaRect(Mat(contours[i])); 
                boundRect[i]=boundingRect(contours[i]);
                //circle(img, Point(box[i].center.x, box[i].center.y), 5, Scalar(0, 255, 0), -1, 8);
                    //绘制最小外接矩形的中心点
                box[i].points(rect);  //把最小外接矩形四个端点复制给rect数组
                for(int j=0; j<4; j++)
                {
                    line(img, rect[j], rect[(j+1)%4], Scalar(0, 0, 255), 2, 8);  //绘制最小外接矩形每条边
                }
                // 画矩形
                //float peri =arcLength(contours[i],true);
                //approxPolyDP(contours[i],conPoly[i],0.02*peri,true);//将有规律的点变为线
                //drawContours(img,conPoly,i,Scalar(255,0,255),2);//多边形
                //boundRect[i]=boundingRect(conPoly[i]);
                //rectangle(img , boundRect[i].tl(),boundRect[i].br(),Scalar(0,255,0),3);
            }
        }

    }

Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
int main()
{
    string path ="0.jpg";
    Mat img =imread(path);
    //预处理
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray,imgBlur,Size(3,3),3,0);
    Canny(imgBlur,imgCanny,25,75);
    Mat kernel=getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(imgCanny,imgDil,kernel);


    getContours(imgCanny,img);
    imshow("img",img);
    // imshow("img Gray",imgGray);
    // imshow("img Blur",imgBlur);
    // imshow("img Canny",imgCanny);
    // imshow("img Dill",imgDil);
    waitKey(0);

}