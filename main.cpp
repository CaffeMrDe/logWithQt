#include "mainwindow.h"
#include <QApplication>
#include <log4cplus/log4cplus.h>
#include "messagehandler.h"
#include "qdebug.h"
#include "globalvar.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    log4cplus::Initializer initializer;

    MainWindow w;
    gloalMain = &w;
    w.show();
    qInstallMessageHandler(customMessageHandler);
    return a.exec();
}


//#include <vector>
//#include <thread>
//#include <chrono>
//#include <string>
//#include <memory>
//#include <ctime>
//#include <iomanip>

//#include <log4cplus/logger.h>
//#include <log4cplus/loggingmacros.h>
//#include <log4cplus/configurator.h>
//#include <log4cplus/initializer.h>
//#include <log4cplus/loglevel.h>
//#include <log4cplus/ndc.h>
//static log4cplus::Logger loggerPICK = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("PLACElogger.PLACE"));

//using namespace std;
//using std::chrono::system_clock;

//using namespace log4cplus;
//using namespace log4cplus::helpers;

//string getTime() {
//    system_clock::time_point tp = system_clock::now();
//    time_t raw_time = system_clock::to_time_t(tp);
//    struct tm  *timeinfo = std::localtime(&raw_time);

//    std::stringstream ss;
//    ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");

//    return ss.str();
//}

//void doTestRun(int i) {
//    log4cplus::Initializer initializer;
//    string threadName = "doRun-" + to_string(i);
//    // 使用NDC给线程设置名称
//    //log4cplus::NDCContextCreator _ndc(LOG4CPLUS_STRING_TO_TSTRING(threadName));

//    for(int i =0; i< 10 ;i++ ){
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//        // 如果不加u8，日志文件会是GB2312格式
//        string info = u8"你好：" + getTime();

//        LOG4CPLUS_WARN(loggerPICK, LOG4CPLUS_STRING_TO_TSTRING(info));

//    }
//}

//int main() {
//    log4cplus::Initializer initializer;
//    PropertyConfigurator pc(LOG4CPLUS_TEXT("/home/de/work/glogPlus/glogPlus/test.properties"));
//    pc.configure();
//    log4cplus::helpers::Properties p =pc.getProperties();
//    vector<std::thread> threadVector;

//    for (int i = 0; i < 5; i++) {
//        threadVector.emplace_back(doTestRun, i);
//    }

//    for (vector<std::thread>::iterator itr = threadVector.begin(); itr != threadVector.end(); itr++) {
//        itr->join();
//    }

//    return 0;
//}

//int main()
//{
    //用Initializer类进行初始化
    //log4cplus::Initializer initializer;

    //第1步：创建ConsoleAppender和FileAppender(参数app表示内容追加到文件)
//    log4cplus::SharedAppenderPtr consoleAppender(new log4cplus::ConsoleAppender);
//    log4cplus::SharedAppenderPtr fileAppender(new log4cplus::FileAppender(
//                                                  LOG4CPLUS_TEXT("log.log"),
//                                                  std::ios_base::app
//                                                  )
//                                              );
//    log4cplus::SharedAppenderPtr fileAppender(new log4cplus::RollingFileAppender(
//                                                  LOG4CPLUS_TEXT("log.log")
//                                                  )
//                                              );



//    //第2步：设置Appender的名称和输出格式
//    //ConsoleAppender使用SimpleLayout
//    log4cplus::tstring pattern = LOG4CPLUS_TEXT("%D{%Y-%m-%d %H:%M:%S.%q}%5p[%5t|%x][%l][%c]- %m%n");

//    //FileAppender使用PatternLayout
//    consoleAppender->setName(LOG4CPLUS_TEXT("console"));
//    consoleAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(pattern)));

//    fileAppender->setName(LOG4CPLUS_TEXT("file"));
//    fileAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(pattern)));

//    //第3步：获得一个Logger实例，并设置其日志输出等级阈值
//    log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT ("test"));
//    log4cplus::Logger logger1 = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT ("test1"));
//    logger.setLogLevel(log4cplus::INFO_LOG_LEVEL);
//    //第4步：为Logger实例添加ConsoleAppender和FileAppender
//    logger.addAppender(consoleAppender);
//    logger.addAppender(fileAppender);
//    logger1.addAppender(consoleAppender);
//    logger1.addAppender(fileAppender);
//    //第5步：使用宏将日志输出
//    LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("Hello world"));
//    LOG4CPLUS_INFO(logger1, LOG4CPLUS_TEXT("Hello world"));

//    return 0;

//}
