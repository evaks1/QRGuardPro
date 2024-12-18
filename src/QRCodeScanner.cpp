#include "../include/QRCodeScanner.h"
#include <stdexcept>

// Detects and decodes a QR code from a cv::Mat image.
std::string QRCodeScanner::detectAndDecode(const cv::Mat& image) {
    cv::QRCodeDetector qrDecoder;
    std::string data = qrDecoder.detectAndDecode(image);
    if (data.empty()) {
        throw std::runtime_error("Failed to detect or decode QR Code.");
    }
    return data;
}
// Converts a QImage to an OpenCV cv::Mat format
cv::Mat QRCodeScanner::qimageToMat(const QImage &image) {
    cv::Mat mat;
    switch(image.format()) {
        case QImage::Format_RGB32:
            mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
            cv::cvtColor(mat, mat, cv::COLOR_BGRA2BGR);
            break;
        case QImage::Format_RGB888:
            mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
            cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);
            break;
        case QImage::Format_Grayscale8:
            mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
            break;
        default:
            mat = cv::Mat();
            break;
    }
    return mat.clone();
}