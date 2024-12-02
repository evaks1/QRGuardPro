#include <gtest/gtest.h>
#include "../include/QRCodeScanner.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

// Test Fixture for QRCodeScanner
class QRCodeScannerTest : public ::testing::Test {
protected:
    QRCodeScanner scanner;

    // Dummy QR Code image for testing
    cv::Mat createDummyQRCode() {
        cv::Mat image(100, 100, CV_8UC1, cv::Scalar(255));
        cv::rectangle(image, cv::Point(30, 30), cv::Point(70, 70), cv::Scalar(0), -1);
        return image;
    }
};

// Test: QImage to cv::Mat conversion
TEST_F(QRCodeScannerTest, QImageToMat_Conversion) {
    QImage image(100, 100, QImage::Format_RGB32);
    cv::Mat mat = scanner.qimageToMat(image);
    ASSERT_FALSE(mat.empty());
}
