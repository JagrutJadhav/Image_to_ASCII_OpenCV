// Developed by Jagrut Jadhav

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat frame,dummy;
    Mat image;
    int size = 10;
    int row, col;
    frame = imread("C:/Users/Admin/Desktop/pig.png");  
    resize(frame, dummy, cv::Size(frame.cols / size, frame.rows / size));
    cvtColor(dummy, image, cv::COLOR_BGR2GRAY);
    if (!image.data)                              
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    
    cout << image.rows << image.cols << endl;
    for (row = 0; row < image.rows; row++)
    {
        for (col = 0; col < image.cols; col++)
        {
            Scalar colour = image.at<uchar>(Point(col, row));
            int val = colour.val[0];
            //cout <<" row = " << row << "col = " << col <<" Pixel colour = "<<val<< endl;

            if (val <= 150)
            {
                cout << "##";
            }
            else {
                cout << "::";
            }
        }
        cout << endl;
        //break;
    }
    namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("Display window", frame);                   

    waitKey(0);                                         
    return 0;
}
