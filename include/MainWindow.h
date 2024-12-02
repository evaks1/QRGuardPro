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

/**
 * @class MainWindow
 * @brief The MainWindow class provides the graphical user interface for the application.
 *
 * The MainWindow class integrates QR code generation, scanning, data harvesting,
 * and safety evaluation functionalities into a single user interface.
 * It uses smart pointers to manage non-QObject components and Qt widgets for layout and interaction.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the MainWindow object.
     * @param parent Pointer to the parent QWidget. Defaults to nullptr.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the MainWindow object and releases resources.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Slot triggered when the "Scan" button is clicked.
     *
     * Initiates the process of scanning a QR code using the QRCodeScanner instance.
     */
    void onScanButtonClicked();

    /**
     * @brief Slot triggered when the "Generate" button is clicked.
     *
     * Initiates the process of generating a QR code using the QRCodeGenerator instance.
     */
    void onGenerateButtonClicked();

private:
    std::unique_ptr<QRCodeScanner> scanner;

    std::unique_ptr<QRCodeGenerator> generator;

    std::unique_ptr<DataHarvester> harvester;

    std::unique_ptr<SafetyEvaluator> evaluator;

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