#include "clogger.h"

int main() {
    SET_DELETE_ON_RERUN(true);
    LOG_INIT("log.log");
    TRACE("this is a trace message");
}