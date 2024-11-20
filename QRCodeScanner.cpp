#include "QRCodeScanner.h"
#include <stdexcept>

QRCodeScanner::QRCodeScanner() {
    // Constructor implementation 
}

QRCodeScanner::~QRCodeScanner() {
    // Destructor implementation 
}

std::string QRCodeScanner::detectAndDecode(const cv::Mat& image) {
    cv::QRCodeDetector qrDecoder;
    std::string data = qrDecoder.detectAndDecode(image);
    if (data.empty()) {
        throw std::runtime_error("Failed to detect or decode QR Code.");
    }
    return data;
}

cv::Mat QRCodeScanner::qimageToMat(const QImage &image) {
    cv::Mat mat;
    switch (image.format()) {
        case QImage::Format_Grayscale8:
            mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.bits(), image.bytesPerLine());
            break;
        default:
            throw std::runtime_error("Unsupported QImage format for QR code processing.");
    }
    return mat.clone();
}