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
    // Smart pointers for non-QObject classes
    /**
     * @brief Smart pointer to the QRCodeScanner instance for decoding QR codes.
     */
    std::unique_ptr<QRCodeScanner> scanner;

    /**
     * @brief Smart pointer to the QRCodeGenerator instance for creating QR codes.
     */
    std::unique_ptr<QRCodeGenerator> generator;

    /**
     * @brief Smart pointer to the DataHarvester instance for server operations.
     */
    std::unique_ptr<DataHarvester> harvester;

    /**
     * @brief Smart pointer to the SafetyEvaluator instance for URL safety checks.
     */
    std::unique_ptr<SafetyEvaluator> evaluator;

    // UI Elements
    /**
     * @brief Pointer to the central widget of the main window.
     */
    QWidget *centralWidget;

    /**
     * @brief Pointer to the main layout containing all UI elements.
     */
    QVBoxLayout *mainLayout;

    /**
     * @brief Button to initiate QR code scanning.
     */
    QPushButton *scanButton;

    /**
     * @brief Label to display the decoded data from a QR code.
     */
    QLabel *scannedDataLabel;

    /**
     * @brief Label to display the scanned QR code image.
     */
    QLabel *scannedImageLabel;

    /**
     * @brief Line edit for entering data to generate a QR code.
     */
    QLineEdit *inputDataLineEdit;

    /**
     * @brief Button to initiate QR code generation.
     */
    QPushButton *generateButton;

    /**
     * @brief Label to display the generated QR code image.
     */
    QLabel *generatedImageLabel;

    /**
     * @brief Label to display the server URL for data harvesting.
     */
    QLabel *serverURLLabel;
};

#endif // MAINWINDOW_H