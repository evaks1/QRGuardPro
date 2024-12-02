// DataHarvester.cpp
#include "../include/DataHarvester.h"
#include <QDebug>

DataHarvester::DataHarvester(QObject *parent)
    : QObject(parent),
      tcpServer(new QTcpServer(this)),
      serverPort(8080),
      logFilePath("harvest_log.txt") 
{
    // Starting the server upon initialization
    if (!startServer(serverPort)) {
        qDebug() << "Failed to start DataHarvester server on port" << serverPort;
    } else {
        qDebug() << "DataHarvester server started on port" << serverPort;
    }
}

DataHarvester::~DataHarvester() {
    if (tcpServer->isListening()) {
        tcpServer->close();
        qDebug() << "DataHarvester server stopped.";
    }
}
// Starts the TCP server on the specified port
bool DataHarvester::startServer(quint16 port) {
    connect(tcpServer, &QTcpServer::newConnection, this, &DataHarvester::onNewConnection);
    if (!tcpServer->listen(QHostAddress::Any, port)) {
        qDebug() << "DataHarvester failed to listen on port" << port << ":" << tcpServer->errorString();
        return false;
    }
    serverPort = port;
    return true;
}

QString DataHarvester::getServerURL() const {
    // For demonstration, assuming the server is running on the local machine.
    // Replace 'localhost' with the actual IP if needed.
    QString ipAddress = "172.20.10.4";
    // To make it accessible externally, replace LocalHost with your machine's IP address.
    // For example, "http://192.168.1.100:8080"
    return QString("http://%1:%2").arg(ipAddress).arg(serverPort);
}

std::string DataHarvester::harvest(const std::string& inputData) {
    // Placeholder: Simply return the input data
    // Implement actual data harvesting logic here (e.g., extract URLs)
    return inputData;
}
// Slot triggered when a new client connects to the server
void DataHarvester::onNewConnection() {
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QTcpSocket::readyRead, this, &DataHarvester::onReadyRead);
    connect(clientConnection, &QTcpSocket::disconnected, clientConnection, &QTcpSocket::deleteLater);
}
// Slot triggered when a client sends data to the server
void DataHarvester::onReadyRead() {
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (!client)
        return;

    // Read the incoming data
    QByteArray requestData = client->readAll();
    QString requestString = QString::fromUtf8(requestData);

    // Simple HTTP request parsing
    QStringList requestLines = requestString.split("\r\n");
    if (requestLines.isEmpty())
        return;

    // Parse the request line
    QString requestLine = requestLines.at(0);
    QStringList requestParts = requestLine.split(" ");
    if (requestParts.size() < 2)
        return;

    QString method = requestParts.at(0);
    QString path = requestParts.at(1);

    // Parse headers
    QString userAgent;
    QString clientIP = client->peerAddress().toString();

    for (const QString &line : requestLines) {
        if (line.startsWith("User-Agent:")) {
            userAgent = line.section(":", 1).trimmed();
            break;
        }
    }

    // Log the request 
    logRequest(clientIP, userAgent, path);

    // Send a simple HTTP response
    QString httpResponse = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: text/html\r\n"
                           "Connection: close\r\n\r\n"
                           "<html><body><h1>Data Harvested</h1></body></html>";
    client->write(httpResponse.toUtf8());
    client->disconnectFromHost();
}

void DataHarvester::logRequest(const QString &clientIP, const QString &userAgent, const QString &requestedPath) {
    QFile logFile(logFilePath);
    if (!logFile.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Unable to open log file for writing.";
        return;
    }

    QTextStream out(&logFile);
    QString timestamp = QDateTime::currentDateTime().toString(Qt::ISODate);
    out << "Timestamp: " << timestamp << "\n"
        << "Client IP: " << clientIP << "\n"
        << "User-Agent: " << userAgent << "\n"
        << "Requested Path: " << requestedPath << "\n"
        << "--------------------------\n";

    qDebug() << "Logged request from" << clientIP;
}
