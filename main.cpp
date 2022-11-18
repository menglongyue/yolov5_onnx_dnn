#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "loguru.hpp"
#include "detector.h"
using namespace cv;
using namespace std;
/* main */

// inference images ------------------------------------------------------------------
// int main(int argc, char *argv[])
// {
//     // 默认参数
//     string model_path = argv[1];
//     string img_path = argv[2];
//     //string model_path = "3_best.onnx";
//     //string img_path = "data/images/zidane.jpg";
//     loguru::init(argc, argv);
//     Config config = {0.25f, 0.45f, model_path, "data/coco.names", Size(640, 640),false};
//     LOG_F(INFO,"Start main process");
//     Detector detector(config);
//     LOG_F(INFO,"Load model done ..");
//     Mat img = imread(img_path, IMREAD_COLOR);
//     LOG_F(INFO,"Read image from %s", img_path.c_str());
//     Detection detection = detector.detect(img);
//     LOG_F(INFO,"Detect process finished");
//     Colors cl = Colors();
//     detector.postProcess(img, detection,cl);
    
//     LOG_F(INFO,"Post process done save image to assets/output.jpg");
//     imwrite("assets/output.jpg", img);
//     cout << "detect Image And Save to assets/output.jpg" << endl;
//     return 0;
// }



int yolo_detect(char *buffer_in, int length, int w, int h, char *buffer_out)
{
    // 默认参数
    string model_path = "best.onnx";

    loguru::init(argc, argv);
    Config config = {0.25f, 0.45f, model_path, "data/visdrone.names", Size(640, 640),false};
    LOG_F(INFO,"Start main process");
    Detector detector(config);
    LOG_F(INFO,"Load model done ..");

    // string img_path = argv[2];
    // 1. ---------------------- 完成buffer_in转opencv mat图像 -------------
    Mat img = 

    // Mat img = imread(img_path, IMREAD_COLOR);
    LOG_F(INFO,"Read image from %s", img_path.c_str());
    Detection detection = detector.detect(img);
    LOG_F(INFO,"Detect process finished");
    Colors cl = Colors();
    detector.postProcess(img, detection,cl);
    
    // 2. ---------------------- 完成img转buffer out格式 ---------------
    char * buffer_out = 


    // LOG_F(INFO,"Post process done save image to assets/output.jpg");
    // imwrite("assets/output.jpg", img);
    cout << "detect Image over!!!" << endl;
    return 0;
}







// inference video ------------------------------------------------------------------
// int main(int argc, char *argv[])
// {
//     // 默认参数
//     string model_path = argv[1];
//     string img_path = argv[2];
//     //string model_path = "3_best.onnx";
//     //string img_path = "data/images/zidane.jpg";
//     loguru::init(argc, argv);
//     Config config = {0.25f, 0.45f, model_path, "data/coco.names", Size(640, 640),false};
//     LOG_F(INFO,"Start main process");
//     Detector detector(config);
//     LOG_F(INFO,"Load model done ..");
//     // ---------------------------------------
//     cv::Mat frame;
//     cv::VideoCapture capture(img_path);
//     if(!capture.isOpened())
//     {
//         std::cerr << "Error opening video file\n";
//         return -1;
//     };

//     auto start = std::chrono::high_resolution_clock::now();
//     int frame_count = 0;
//     float fps = -1;
//     int total_frames = 0;
//     while(true)
//     {
//         capture.read(frame);
//         if(frame.empty())
//         {
//             cout << "End of stream!!!\n";
//             break;
//         };

//         // Mat img = imread(img_path, IMREAD_COLOR);
//         // LOG_F(INFO,"Read image from %s", img_path.c_str());
//         LOG_F(INFO,"time start now: ------------------------------");
//         Detection detection = detector.detect(frame);
//         LOG_F(INFO,"time end -----------------------------");
//         LOG_F(INFO,"Detect process finished");
//         Colors cl = Colors();
//         detector.postProcess(frame, detection,cl);
//         frame_count++;
//         total_frames++;

//         if (frame_count >= 30)
//         {
//             auto end=std::chrono::high_resolution_clock::now();
//             fps = frame_count * 1000.0 / std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//             frame_count = 0;
//             start = std::chrono::high_resolution_clock::now();
//         };

//         if (fps > 0)
//         {
//             std::ostringstream fps_label;
//             fps_label << std::fixed << std::setprecision(2);
//             fps_label << "FPS: " << fps;
//             std::string fps_label_str = fps_label.str();
//             std::string output_file = cv::format("output_%d.jpg", total_frames);
//             cv::putText(frame, fps_label_str.c_str(), cv::Point(10, 25), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0,0,255), 2);
//             imwrite(output_file, frame);
//         };

//         if (cv::waitKey(1) != -1)
//         {
//             capture.release();
//             std::cout << "finished by user \n";
//             break;
//         };

//     };

//     cout << "Total frames: " << total_frames << "\n";
//     // Mat img = imread(img_path, IMREAD_COLOR);
//     // LOG_F(INFO,"Read image from %s", img_path.c_str());
//     // Detection detection = detector.detect(img);
//     // LOG_F(INFO,"Detect process finished");
//     // Colors cl = Colors();
//     // detector.postProcess(img, detection,cl);

    
//     LOG_F(INFO,"Post process done save image to assets/output.jpg");
//     // imwrite("assets/output.jpg", img);
//     cout << "detect Image And Save to assets/output.jpg" << endl;
//     return 0;
// }
