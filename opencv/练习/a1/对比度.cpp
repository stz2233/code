#include<opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // 读入图像，判断读入是否成功
	VideoCapture video;
        //用VideoCapture来读取摄像头
	Mat picture,img,src;
        
    Mat dst1, dst2, dst3;
    Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();
	double alpha = 1.0;
	double beta = 0.0;
	double gama = 1.0;
	// 提示并输入 α  β  γ  的值
	cout << " Basic Linear Transforms " << endl;
	cout << "-------------------------" << endl;
	cout << "* Enter the alpha value [1.0-3.0]: ";
	alpha = 2;											  // cin >> alpha;
	cout << "* Enter the beta value [0-100]: ";
	beta = 20;											// cin >> beta;
	cout << "* Enter the gama value [-1,1]: ";
	gama = 1; // cin >> gama;
    //namedWindow("imput");
    video.open(0);            // 括号的0表示使用电脑自带的摄像头
    if (!video.isOpened())    //判断摄像头是否读取成功
	{
		return -1;   //返回一个代数值，表示函数失败（若为return 1，则表示ture）
	}
	while(1)   //（读取成功，使用循环语句将视频一帧一帧地展示出来）
    {
		video >> src;   //词条将video中的数据流向picture
	// 直接使用循环遍历每一个像素，应用公式
	//double t1 = (double)getTickCount();
	dst1 = Mat::zeros(src.size(), src.type());
	for (int row=0;row<src.rows;++row)
		for(int col=0;col<src.cols;++col)
			for (int channel = 0; channel < src.channels(); ++channel)
			{
				dst1.at<Vec3b>(row, col)[channel] = saturate_cast<uchar>(alpha * src.at<Vec3b>(row, col)[channel] + beta);
			}
	//double time1 = ((double)getTickCount() - t1) / getTickFrequency();
	//cout << "Method by pixel use time:" << time1 << "(ms)" << endl;

    // 调用 convertTo() 函数调整对比度和亮度
	//double t2 = (double)getTickCount();
	src.convertTo(dst2, -1, alpha, beta);
	//double time2 = ((double)getTickCount() - t2) / getTickFrequency();
	//cout << "Method by pixel use time:" << time2 << "(ms)" << endl;

    // 构建查找表
	
	for (int i = 0; i < 256; ++i)
		p[i] = saturate_cast<uchar>(pow(i / 255.0, gama) * 255.0);

   // 使用查找表进行对比度亮度调整
	//double t3 = (double)getTickCount();
	LUT(src, lookUpTable, dst3);
	//double time3 = ((double)getTickCount() - t3) / getTickFrequency();
	//cout << "Method by γ correct use time:" << time3 << "(ms)" << endl;

    // 调整窗体大小，显示调整效果
	//namedWindow("original", WINDOW_NORMAL);
	//resizeWindow("original", Size(src.cols /1, src.rows / 1));
	imshow("original", src);
	// namedWindow("pixel set", WINDOW_NORMAL);
	// resizeWindow("pixel set", Size(src.cols / 1, src.rows / 1));
	imshow("pixel set", dst1);
	// namedWindow("convertTo", WINDOW_NORMAL);
	// resizeWindow("convertTo", Size(src.cols /1, src.rows / 1));
	imshow("convertTo", dst2);
	// namedWindow("γ correct", WINDOW_NORMAL);
	// resizeWindow("γ correct", Size(src.cols / 1, src.rows / 1));
	imshow("γ correct", dst3);
	waitKey(30);
	//system("pause");
	
		  
	}
	return EXIT_SUCCESS;
	
}
