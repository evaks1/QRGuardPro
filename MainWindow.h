// MainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <memory> // Include for smart pointers

// Forward declarations
class QRCodeScanner;
class QRCodeGenerator;
class DataHarvester;
class SafetyEvaluator;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); // Destructor declared

private slots:
    void onScanButtonClicked();
    void onGenerateButtonClicked();

private:
    // Smart pointers for non-QObject classes
    std::unique_ptr<QRCodeScanner> scanner;
    std::unique_ptr<QRCodeGenerator> generator;
    std::unique_ptr<DataHarvester> harvester;
    std::unique_ptr<SafetyEvaluator> evaluator;

    // UI Elements
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QPushButton *scanButton;
    QLabel *scannedDataLabel;
    QLabel *scannedImageLabel;
    QLineEdit *inputDataLineEdit;
    QPushButton *generateButton;
    QLabel *generatedImageLabel;
    QLabel *serverURLLabel;
};

#endif // MAINWINDOW_H
