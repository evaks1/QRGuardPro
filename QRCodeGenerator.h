// QRCodeGenerator.h
#ifndef QRCODEGENERATOR_H
#define QRCODEGENERATOR_H

#include <opencv2/opencv.hpp>
#include <QImage>
#include <string>

class QRCodeGenerator {
public:
    QRCodeGenerator();
    ~QRCodeGenerator();

    // Generate QR Code image as cv::Mat
    cv::Mat generateQRCode(const std::string& data, int size);

    // Convert cv::Mat to QImage
    QImage matToQImage(const cv::Mat& mat);

    // Save QR Code image to file
    void saveQRCode(const cv::Mat& mat, const std::string& filename);
};

#endif // QRCODEGENERATOR_H
