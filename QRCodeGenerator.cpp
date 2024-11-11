// QRCodeGenerator.cpp
#include "QRCodeGenerator.h"
#include <qrencode.h>
#include <stdexcept>

QRCodeGenerator::QRCodeGenerator() {
    // Constructor implementation (if needed)
}

QRCodeGenerator::~QRCodeGenerator() {
    // Destructor implementation (if needed)
}

cv::Mat QRCodeGenerator::generateQRCode(const std::string& data, int size) {
    QRcode* qrcode = QRcode_encodeString(data.c_str(), 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if(qrcode == nullptr) {
        throw std::runtime_error("Failed to generate QR Code.");
    }

    int qrSize = qrcode->width > 0 ? qrcode->width : 1;
    cv::Mat qrImage(qrSize, qrSize, CV_8UC1, cv::Scalar(255));

    for(int y = 0; y < qrSize; y++) {
        for(int x = 0; x < qrSize; x++) {
            unsigned char b = qrcode->data[y * qrSize + x];
            qrImage.at<uchar>(y, x) = b & 1 ? 0 : 255;
        }
    }

    QRcode_free(qrcode);

    // Resize to desired size
    cv::resize(qrImage, qrImage, cv::Size(size, size), 0, 0, cv::INTER_NEAREST);
    return qrImage;
}

QImage QRCodeGenerator::matToQImage(const cv::Mat& mat) {
    if(mat.type() == CV_8UC1) {
        QImage img(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8);
        return img.copy();
    }
    else if(mat.type() == CV_8UC3) {
        QImage img(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else {
        return QImage();
    }
}

void QRCodeGenerator::saveQRCode(const cv::Mat& mat, const std::string& filename) {
    if(!cv::imwrite(filename, mat)) {
        throw std::runtime_error("Failed to save QR Code image.");
    }
}