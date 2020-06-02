#include "opencv2/opencv.hpp"
#include <iostream>
#include <chrono>

#include <ctime>

using namespace std;
using namespace cv;
using namespace chrono;


int main(int argc, char** argv)
{
    //read video
    cv::VideoCapture capture;
    capture.open("/dev/video1");
    capture.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    capture.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    double dWidth = capture.get(cv::CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
    double dHeight = capture.get(cv::CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    cout << "camera width = " << dWidth << ", height = " << dHeight << endl;

    if (!capture.isOpened()) { //check if video device has been initialised
        cout << "cannot open camera";
    }

    Mat frame;
    
    string dir = argv[1];
    int index = 0;
    while (true)
    {
        bool bSuccess = capture.read(frame); // read a new frame from video 

        //Breaking the while loop if the frames cannot be captured
        if (bSuccess == false) 
        {
            cout << "Video camera is disconnected" << endl;
            cin.get(); //Wait for any key press
            break;
        }

        //show the frame in the created window
        imshow("video", frame);

        string path = dir + std::to_string(index) + ".jpg";
        imwrite(path, frame);
        index ++;

        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop 
        //If any key is not pressed withing 10 ms, continue the loop 
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;

}


