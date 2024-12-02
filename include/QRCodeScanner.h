#ifndef QRCODESCANNER_H
#define QRCODESCANNER_H

#include <opencv2/opencv.hpp>
#include <QImage>

/**
 * @class QRCodeScanner
 * @brief A class for decoding QR codes from images.
 *
 * The QRCodeScanner class provides methods to detect and decode QR codes
 * from images, as well as convert images between Qt's QImage and OpenCV's cv::Mat formats.
 */
class QRCodeScanner {
public:
    /**
     * @brief Detects and decodes a QR code from a cv::Mat image.
     * @param image The cv::Mat image containing the QR code to decode.
     * @return A std::string containing the decoded data from the QR code.
     * @throws std::runtime_error if decoding fails or no QR code is found.
     */
    std::string detectAndDecode(const cv::Mat& image);

    /**
     * @brief Converts a QImage to an OpenCV cv::Mat format.
     * @param image The QImage to convert.
     * @return A cv::Mat representation of the input QImage.
     * @throws std::runtime_error if the QImage format is unsupported.
     */
    cv::Mat qimageToMat(const QImage &image);
};

#endif // QRCODESCANNER_H