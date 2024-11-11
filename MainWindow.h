// MainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>    // Added for QVBoxLayout
#include <QPushButton>    // Added for QPushButton
#include <QLabel>         // Added for QLabel
#include <QLineEdit>      // Added for QLineEdit
#include <QHBoxLayout>    // Added for QHBoxLayout
#include <QIcon>          // Added for QIcon

#include "QRCodeScanner.h"
#include "QRCodeGenerator.h"
#include "DataHarvester.h"
#include "SafetyEvaluator.h"

class MainWindow : public QMainWindow {
    Q_OBJECT  // Ensure this macro is present

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onScanButtonClicked();
    void onGenerateButtonClicked();

private:
    // UI Components
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;

    // Scan QR Code Section
    QPushButton *scanButton;
    QLabel *scannedDataLabel;
    QLabel *scannedImageLabel;

    // Generate QR Code Section
    QLineEdit *inputDataLineEdit;
    QPushButton *generateButton;
    QLabel *generatedImageLabel;

    // Helper Classes
    QRCodeScanner *scanner;
    QRCodeGenerator *generator;
    DataHarvester *harvester;
    SafetyEvaluator *evaluator;
};

#endif // MAINWINDOW_H