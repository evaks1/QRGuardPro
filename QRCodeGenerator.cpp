// QRCodeGenerator.cpp
#include "QRCodeGenerator.h"
#include <qrencode.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <QDebug>

QRCodeGenerator::QRCodeGenerator() {
    // Constructor implementation (if needed)
}

QRCodeGenerator::~QRCodeGenerator() {
    // Destructor implementation (if needed)
}

cv::Mat QRCodeGenerator::generateQRCode(const std::string& data, int size) {
    QRcode *qrcode = QRcode_encodeString(data.c_str(), 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        throw std::runtime_error("Failed to generate QR Code");
    }

    int qrSize = qrcode->width;
    int scale = size / qrSize;

    // Create a black and white image
    cv::Mat qrImage(qrSize * scale, qrSize * scale, CV_8UC1, cv::Scalar(255)); // White background

    for(int y = 0; y < qrSize; ++y) {
        for(int x = 0; x < qrSize; ++x) {
            if(qrcode->data[y * qrSize + x] & 1) {
                cv::rectangle(qrImage, 
                              cv::Point(x * scale, y * scale), 
                              cv::Point((x + 1) * scale - 1, (y + 1) * scale - 1), 
                              cv::Scalar(0), 
                              cv::FILLED);
            }
        }
    }

    QRcode_free(qrcode);

    // Resize to desired size if necessary
    if(qrImage.cols != size || qrImage.rows != size) {
        cv::resize(qrImage, qrImage, cv::Size(size, size), 0, 0, cv::INTER_NEAREST);
    }

    return qrImage;
}

QImage QRCodeGenerator::matToQImage(const cv::Mat& mat) {
    // Convert cv::Mat to QImage
    if (mat.type() == CV_8UC1) {
        QImage img(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8);
        return img.copy();
    } else {
        qDebug() << "Unsupported cv::Mat format for conversion to QImage.";
        return QImage();
    }
}

void QRCodeGenerator::saveQRCode(const cv::Mat& mat, const std::string& filename) {
    // Save the QR code image to a file
    if (cv::imwrite(filename, mat)) {
        qDebug() << "QR Code image saved to" << QString::fromStdString(filename);
    } else {
        qDebug() << "Failed to save QR Code image to" << QString::fromStdString(filename);
    }
}
