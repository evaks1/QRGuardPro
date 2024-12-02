#include <gtest/gtest.h>
#include "../include/QRCodeGenerator.h"
#include <opencv2/core.hpp>

// Test Fixture for QRCodeGenerator
class QRCodeGeneratorTest : public ::testing::Test {
protected:
    QRCodeGenerator generator;
};

// Test: Generate QR Code with valid data
TEST_F(QRCodeGeneratorTest, GenerateQRCode_ValidData) {
    std::string data = "https://example.com";
    ASSERT_NO_THROW(generator.generateQRCode(data, 200));
}

// Test: Generate QR Code with empty data
TEST_F(QRCodeGeneratorTest, GenerateQRCode_EmptyData) {
    std::string data = "";
    EXPECT_THROW(generator.generateQRCode(data, 200), std::runtime_error);
}

// Test: Save QR Code to file
TEST_F(QRCodeGeneratorTest, SaveQRCode) {
    std::string data = "https://example.com";
    cv::Mat qrImage = generator.generateQRCode(data, 200);
    ASSERT_NO_THROW(generator.saveQRCode(qrImage, "test_qr_code.png"));
}
