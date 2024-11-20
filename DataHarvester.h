#ifndef DATAHARVESTER_H
#define DATAHARVESTER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <string>

/**
 * @class DataHarvester
 * @brief A class for handling TCP server operations and data harvesting.
 *
 * The DataHarvester class manages a TCP server to receive incoming connections,
 * processes data sent by clients, and logs relevant information such as client IP,
 * user agent, and requested paths.
 */
class DataHarvester : public QObject {
    Q_OBJECT
public:
    /**
     * @brief Constructor for the DataHarvester class.
     * @param parent Pointer to the parent QObject. Defaults to nullptr.
     */
    explicit DataHarvester(QObject *parent = nullptr);

    /**
     * @brief Destructor for the DataHarvester class.
     */
    ~DataHarvester();

    /**
     * @brief Starts the TCP server on the specified port.
     * @param port The port number to listen on. Defaults to 8080.
     * @return True if the server starts successfully, false otherwise.
     */
    bool startServer(quint16 port = 8080);

    /**
     * @brief Retrieves the server's URL.
     * 
     * This assumes the server is running on localhost for demonstration purposes.
     * @return A QString containing the server URL.
     */
    QString getServerURL() const;

    /**
     * @brief Processes input data to extract useful information (e.g., URLs).
     * @param inputData The raw input data as a std::string.
     * @return A std::string containing the extracted information.
     */
    std::string harvest(const std::string& inputData);

private slots:
    /**
     * @brief Slot triggered when a new client connects to the server.
     */
    void onNewConnection();

    /**
     * @brief Slot triggered when a client sends data to the server.
     */
    void onReadyRead();

private:
    QTcpServer *tcpServer;       /**< Pointer to the QTcpServer instance. */
    quint16 serverPort;          /**< The port number the server is listening on. */
    QString logFilePath;         /**< File path for storing logs. */

    /**
     * @brief Logs a client's request details.
     * @param clientIP The IP address of the client.
     * @param userAgent The user agent string sent by the client.
     * @param requestedPath The requested resource path.
     */
    void logRequest(const QString &clientIP, const QString &userAgent, const QString &requestedPath);
};

#endif // DATAHARVESTER_H