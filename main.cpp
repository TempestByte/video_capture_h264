#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

int main() 
{

    // 1) Open camera
    cv::VideoCapture video(0);
    if (!video.isOpened()) {
        std::cerr << "ERROR: Could not open camera\n";
        return -1;
    }

    // 2) Input resolution
    int inW = static_cast<int>(video.get(cv::CAP_PROP_FRAME_WIDTH));
    int inH = static_cast<int>(video.get(cv::CAP_PROP_FRAME_HEIGHT));

    // 3) Set your desired scale factor here
    double scaleFactor = 0.5;  // e.g. shrink to 50%
    int outW = static_cast<int>(inW * scaleFactor);
    int outH = static_cast<int>(inH * scaleFactor);

    // 4) Open H.264-encoded writer 
    cv::VideoWriter output(
        "output.mp4",
        cv::VideoWriter::fourcc('H','2','6','4'),
        30.0, //30 FPS
        cv::Size(outW, outH)
    );
    if (!output.isOpened()) {
        std::cerr << "ERROR: Could not open output file for write\n";
        return -1;
    }

    cv::Mat frame, scaled, processed;
    while (true) {
        // 5) Grab frame
        if (!video.read(frame)) break;

        // 6) Scale
        cv::resize(frame, scaled, cv::Size(outW, outH));

        // 7) Invert colors
        cv::bitwise_not(scaled, processed);

        // 8) Flip both axes (flipCode = -1). Use 0 for x-axis only, 1 for y-axis only.
        cv::flip(processed, processed, -1);

        // 9) Show & write
        cv::imshow("Processed Video", processed);
        output.write(processed);

        // Break on any key
        if (cv::waitKey(25) >= 0) break;
    }

    video.release();
    output.release();
    cv::destroyAllWindows();
    return 0;
}
