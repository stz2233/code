#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;
Mat img;
img.draw_rectangle(box[0], box[1], box[0] + box[2], box[1] + box[3], color = bg_color, thickness = 2)
    img.draw_rectangle(box[0], box[1] - font_wh[1], box[0] + font_wh[0], box[1], color = bg_color, thickness = -1)
        img.draw_string(box[0], box[1] - font_wh[1], disp_str, color = font_color)
            img.draw_string(0, 30, "x=" + str(((box[0] + box[3]) / 2) - 35), color = font_color)
                img.draw_string(70, 30, "y=" + str((box[1] + box[2]) / 2), color = font_color)

                    Lm = (box[1] + box[3]) / 2 length = K * 13 / Lm img.draw_string(0, 60, "Z=" + str(length), color = font_color)
