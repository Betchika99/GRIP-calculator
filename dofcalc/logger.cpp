#include <QApplication>
#include <QtCore>
#include "logger.h"

class LogSupport
{
public:
    LogSupport();
    ~LogSupport();
    void Write(QString line);
private:
    const int oldFileAge = 7;
    QFile   logFile;
    QString logPath;
};

static LogSupport *logSupport = nullptr;

LogSupport::LogSupport()
{
    QString baseName = QFileInfo(QApplication::applicationFilePath()).baseName();
    logPath = QDir::tempPath() + "/" + baseName + "/";
    QDir().mkpath(logPath);
    baseName += QDateTime().currentDateTime().toString("_yyyyMMdd-HHmmss.log");
    logFile.setFileName(logPath + baseName);
    logFile.open(QIODevice::WriteOnly|QIODevice::Unbuffered);
}

LogSupport::~LogSupport()
{
    logFile.close();
    QDateTime currentTime = QDateTime().currentDateTime();
    QDir dirBrowser(logPath, "*.log");
    for (int i = 0; i < dirBrowser.entryList().count(); i++)
    {
        QFile file(logPath + dirBrowser.entryList()[i]);
        QDateTime fileTime = file.fileTime(QFileDevice::FileModificationTime);
        if (file.size() == 0 || fileTime.daysTo(currentTime) > oldFileAge) file.remove();
    }
}

void LogSupport::Write(QString line)
{
    if (logFile.isOpen())
    {
        QTextStream stream(&logFile);
        stream << QDateTime().currentDateTime().toString("[dd.MM.yyyy-HH:mm:ss] ") << line << endl;
    }
}

void InitLog()
{
    if (!logSupport) logSupport = new LogSupport();
}

void CloseLog()
{
    delete logSupport;
    logSupport = nullptr;
}

void Log(QString line)
{
    logSupport->Write(line);
}

void Log(const char *format, ...)
{
    va_list arglist;
    va_start(arglist, format);
    logSupport->Write(QString::vasprintf(format, arglist));
}

void Log(void *data, size_t size)
{
    quint8 *p = static_cast<quint8*>(data);
    QString line;
    for (size_t i = 0; i < size;)
    {
        line += QString::asprintf("%02X,", *p++);
        if (++i % 32 == 0)
        {
            logSupport->Write(line);
            line = "";
        }
    }
    if (!line.isEmpty()) logSupport->Write(line);
}



