#include "log4fun.h"

log4Fun::log4Fun(const string &name):logMoudleName(name)
{
    log4cplus::Initializer initializer;

    logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT (name));

    fileAppender=log4cplus::SharedAppenderPtr(new log4cplus::RollingFileAppender(
                                                  LOG4CPLUS_TEXT(name+".log")
                                                  )
                                              );

    log4cplus::tstring pattern = LOG4CPLUS_TEXT("%D{%Y-%m-%d %H:%M:%S.%q}%5p[%5t|%x][%l][%c]- %m%n");

    consoleAppender=log4cplus::SharedAppenderPtr (new log4cplus::ConsoleAppender(false,true));

    consoleAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(pattern)));
    fileAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(pattern)));

    initParam();
}

void log4Fun::logInfoMessage(const string &msg)
{
    LOG4CPLUS_INFO(logger, msg);
}

void log4Fun::logWarnMessage(const string &msg)
{
    LOG4CPLUS_WARN(logger, msg);
}

void log4Fun::logErrorMessage(const string &msg)
{
    LOG4CPLUS_ERROR(logger, msg);

}

void log4Fun::logFatelMessage(const string &msg)
{
    LOG4CPLUS_FATAL(logger, msg);
}

string &log4Fun::getModouleName()
{
    return logMoudleName;
}

void log4Fun::initParam()
{
    logger.addAppender(fileAppender);
    logger.addAppender(consoleAppender);
}
