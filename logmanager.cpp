#include "logmanager.h"
#include <assert.h>
#include "log4qtfun.h"
logSingleManager* logSingleManager::ptr = NULL;
logSingleManager::logSingleManager()
{
    std::shared_ptr<logBase> temp= std::make_shared<log4Fun>("cube");
    std::shared_ptr<logBase> temp2=  std::make_shared<log4QtFun>(temp);
    logGroup.insert(std::make_pair("cube",temp2));
}



std::shared_ptr<logBase> logSingleManager::getLog(const string &moudle)
{
    std::shared_ptr<logBase> ptr;
    try{
        ptr = logGroup.at(moudle);
    }catch(std::exception &e){

        std::shared_ptr<logBase> temp = std::make_shared<log4Fun>(moudle);
        std::shared_ptr<logBase> temp2=  std::make_shared<log4QtFun>(temp);
        logGroup.insert(std::make_pair(moudle,temp2));
        return temp;
    }

    return ptr;
}
