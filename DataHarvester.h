// DataHarvester.h
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

class DataHarvester : public QObject {
    Q_OBJECT
public:
    explicit DataHarvester(QObject *parent = nullptr);
    ~DataHarvester();

    // Start the server on the specified port
    bool startServer(quint16 port = 8080);

    // Get the server's URL (assuming localhost for demo)
    QString getServerURL() const;

    // Harvest data from input (e.g., extract URL)
    std::string harvest(const std::string& inputData);

private slots:
    void onNewConnection();
    void onReadyRead();

private:
    QTcpServer *tcpServer;
    quint16 serverPort;
    QString logFilePath;

    // Helper function to log data
    void logRequest(const QString &clientIP, const QString &userAgent, const QString &requestedPath);
};

#endif // DATAHARVESTER_H
