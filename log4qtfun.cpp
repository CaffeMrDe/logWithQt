#include "log4qtfun.h"
#include "qdebug.h"
log4QtFun::log4QtFun(std::shared_ptr<logBase> ptr)
{
    this->ptr = ptr;
    moudleName = QString::fromStdString('['+ptr->getModouleName()).append(']');
}

void log4QtFun::logInfoMessage(const string &msg)
{
    QString temp = moudleName;
    QString qmessage = temp.append(QString::fromStdString("- "+msg));
    qInfo()<<qmessage;
    ptr->logInfoMessage(msg);
}

void log4QtFun::logWarnMessage(const string &msg)
{
    QString temp = moudleName;
    QString qmessage = temp.append(QString::fromStdString("- "+msg));
    qWarning()<<qmessage;
    ptr->logInfoMessage(msg);
}

void log4QtFun::logErrorMessage(const string &msg)
{
    QString temp = moudleName;
    QString qmessage = temp.append(QString::fromStdString("- "+msg));
    qCritical()<<qmessage;
    ptr->logInfoMessage(msg);
}

void log4QtFun::logFatelMessage(const string &msg)
{
    QString temp = moudleName;
    QString qmessage = temp.append(QString::fromStdString("- "+msg));
    qCritical()<<qmessage;
    ptr->logInfoMessage(msg);
}

string &log4QtFun::getModouleName()
{
    return ptr->getModouleName();
}
