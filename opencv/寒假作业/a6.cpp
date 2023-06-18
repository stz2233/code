#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;

void getContours(Mat imgDil, Mat img)
{

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    Point2f rect[4];
    findContours(imgDil, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_TC89_KCOS);
    vector<Rect> boundRect(contours.size());  // 矩形定义
    vector<RotatedRect> box(contours.size()); // 最小外接矩形定义
    for (int i = 0; i < contours.size(); i++)
    {
        int area = contourArea(contours[i]);
        cout<<area<<endl;
        
        RotatedRect Rorect = minAreaRect(contours[i]);
        if (area > 1800&&Rorect.size.width/Rorect.size.height<2.8&&Rorect.size.width/Rorect.size.height>0.4)
        {
            //cout << area << endl;
            // 最小外接矩形
            box[i] = minAreaRect(Mat(contours[i]));
            boundRect[i] = boundingRect(contours[i]);
            
            
            box[i].points(rect); // 把最小外接矩形四个端点复制给rect数组
             for (int j = 0; j < 4; j++)
            {

                line(img, rect[j], rect[(j + 1)%4 ], Scalar(0, 0, 255), 2, 8); // 绘制最小外接矩形每条边
                
            }
        }
    }

    }


int main()
{
    string path =".jpg";
    Mat img =imread(path);

    //预处理
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray,imgBlur,Size(3,3),3,0);
    Canny(imgBlur,imgCanny,25,75);
    Mat kernel=getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(imgCanny,imgDil,kernel);


    getContours(imgDil,img);
    imshow("img",img);
    waitKey(0);

}