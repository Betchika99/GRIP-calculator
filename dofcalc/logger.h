#ifndef LOGGER_H
#define LOGGER_H

#include <QString>

void InitLog();
void Log(QString line);
void Log(const char *format, ...);
void Log(void *data, size_t size);
void CloseLog();

#endif // LOGGER_H
