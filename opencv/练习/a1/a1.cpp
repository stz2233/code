#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // 读入图像，判断读入是否成功
	string fileName = samples::findFile("4.jpg");
	Mat src = imread(fileName, IMREAD_COLOR);
	if (src.empty())
	{
		fprintf(stderr, "failed to load image: %s\n", fileName);
		system("pause");
		return EXIT_FAILURE;
	}
	Mat dst1, dst2, dst3;
	dst1 = Mat::zeros(src.size(), src.type());
	double alpha = 1.0;
	double beta = 0.0;
	double gama = 1.0;

    // 提示并输入 α  β  γ  的值
	cout << " Basic Linear Transforms " << endl;
	cout << "-------------------------" << endl;
	cout << "* Enter the alpha value [1.0-3.0]: ";
	alpha = 3;											  // cin >> alpha;
	cout << "* Enter the beta value [0-100]: ";
	beta = 50;											// cin >> beta;
	cout << "* Enter the gama value [-1,1]: ";
	gama = 1; // cin >> gama;

	// 直接使用循环遍历每一个像素，应用公式
	double t1 = (double)getTickCount();
	for (int row=0;row<src.rows;++row)
		for(int col=0;col<src.cols;++col)
			for (int channel = 0; channel < src.channels(); ++channel)
			{
				dst1.at<Vec3b>(row, col)[channel] = saturate_cast<uchar>(alpha * src.at<Vec3b>(row, col)[channel] + beta);
			}
	double time1 = ((double)getTickCount() - t1) / getTickFrequency();
	cout << "Method by pixel use time:" << time1 << "(ms)" << endl;

    // 调用 convertTo() 函数调整对比度和亮度
	double t2 = (double)getTickCount();
	src.convertTo(dst2, -1, alpha, beta);
	double time2 = ((double)getTickCount() - t2) / getTickFrequency();
	cout << "Method by pixel use time:" << time2 << "(ms)" << endl;

    // 构建查找表
	Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();
	for (int i = 0; i < 256; ++i)
		p[i] = saturate_cast<uchar>(pow(i / 255.0, gama) * 255.0);

   // 使用查找表进行对比度亮度调整
	double t3 = (double)getTickCount();
	LUT(src, lookUpTable, dst3);
	double time3 = ((double)getTickCount() - t3) / getTickFrequency();
	cout << "Method by γ correct use time:" << time3 << "(ms)" << endl;

    // 调整窗体大小，显示调整效果
	namedWindow("original", WINDOW_NORMAL);
	resizeWindow("original", Size(src.cols /1, src.rows / 1));
	imshow("original", src);
	namedWindow("pixel set", WINDOW_NORMAL);
	resizeWindow("pixel set", Size(src.cols / 1, src.rows / 1));
	imshow("pixel set", dst1);
	namedWindow("convertTo", WINDOW_NORMAL);
	resizeWindow("convertTo", Size(src.cols /1, src.rows / 1));
	imshow("convertTo", dst2);
	namedWindow("γ correct", WINDOW_NORMAL);
	resizeWindow("γ correct", Size(src.cols / 1, src.rows / 1));
	imshow("γ correct", dst3);
	waitKey(0);
	//system("pause");
	return EXIT_SUCCESS;
}
