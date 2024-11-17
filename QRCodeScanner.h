// QRCodeScanner.h
#ifndef QRCODESCANNER_H
#define QRCODESCANNER_H

#include <opencv2/opencv.hpp>
#include <QImage>

class QRCodeScanner {
public:
    QRCodeScanner();
    ~QRCodeScanner();

    // Detect and decode QR Code from cv::Mat
    std::string detectAndDecode(const cv::Mat& image);

    // Convert QImage to cv::Mat
    cv::Mat qimageToMat(const QImage &image);
};

#endif // QRCODESCANNER_H