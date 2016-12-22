#ifndef COMPUTE_H
#define COMPUTE_H

#include <opencv2/core.hpp>
#include <pthread.h>

class VideoSource;


typedef std::vector<cv::Vec4i> Lines;

struct OutputData {
    cv::Mat image;
    Lines lines;
    OutputData() {}
    OutputData(int w, int h): image(h, w, CV_8UC3) {}
};

class Compute {
public:
    Compute(VideoSource* c);
    ~Compute();

    void Start();
    void Stop();
    void BackgroundLoop();

    void SwapOutputData(OutputData& data);

private:
    VideoSource* cap;
    OutputData outputData;
    pthread_mutex_t dataMutex;
    pthread_t thread;
};

#endif // COMPUTE_H