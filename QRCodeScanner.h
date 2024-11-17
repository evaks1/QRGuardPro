#ifndef QRCODESCANNER_H
#define QRCODESCANNER_H

#include <opencv2/opencv.hpp>
#include <QImage>
#include <string>

class QRCodeScanner {
public:
    QRCodeScanner();
    ~QRCodeScanner();

    // Templated process method for handling different input types
    template <typename InputType>
    std::string process(const InputType& input);

    // Decode a QR Code from a cv::Mat
    std::string detectAndDecode(const cv::Mat& image);

    // Convert QImage to cv::Mat
    cv::Mat qimageToMat(const QImage &image);
};

// Template implementation (must be in the header for visibility)
template <typename InputType>
std::string QRCodeScanner::process(const InputType& input) {
    if constexpr (std::is_same_v<InputType, cv::Mat>) {
        return detectAndDecode(input);
    } else if constexpr (std::is_same_v<InputType, QImage>) {
        cv::Mat mat = qimageToMat(input);
        return detectAndDecode(mat);
    } else {
        throw std::invalid_argument("Unsupported input type for QRCodeScanner::process");
    }
}

#endif // QRCODESCANNER_H