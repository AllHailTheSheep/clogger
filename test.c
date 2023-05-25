#include "clogger.h"

int main() {
    SET_DELETE_ON_RERUN(true);
    LOG_INIT("log.log");
    SET_LOG_LEVEL(3);
    TRACE("this is a trace message");
    DEBUG("this is a trace message");
    INFO("this is a trace message");
    WARNING("this is a trace message");
    ERROR("this is a trace message");
    FATAL("this is a trace message");

}