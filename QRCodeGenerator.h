// QRCodeGenerator.h
#ifndef QRCODEGENERATOR_H
#define QRCODEGENERATOR_H

#include <opencv2/opencv.hpp>
#include <QImage>
#include <string>

/**
 * @class QRCodeGenerator
 * @brief A class for generating and managing QR code images.
 *
 * The QRCodeGenerator class provides functionality for creating QR codes as images,
 * converting them between different formats, and saving them to files.
 */
class QRCodeGenerator {
public:

    /**
     * @brief Generates a QR code image based on the input data.
     * @param data The string data to encode into the QR code.
     * @param size The desired size of the QR code image in pixels.
     * @return A cv::Mat object containing the generated QR code image.
     * @throws std::runtime_error if QR code generation fails.
     */
    cv::Mat generateQRCode(const std::string& data, int size);

    /**
     * @brief Converts a cv::Mat image to a QImage.
     * @param mat The cv::Mat image to convert.
     * @return A QImage object representing the same image.
     * @throws std::runtime_error if the cv::Mat format is unsupported.
     */
    QImage matToQImage(const cv::Mat& mat);

    /**
     * @brief Saves a QR code image to a file.
     * @param mat The cv::Mat image containing the QR code.
     * @param filename The path and name of the file to save the image.
     * @throws std::runtime_error if the file cannot be saved.
     */
    void saveQRCode(const cv::Mat& mat, const std::string& filename);
};

#endif // QRCODEGENERATOR_H