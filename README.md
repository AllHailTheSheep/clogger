# clogger
This is a basic logger header file for the C programming language, featuring minimal support and overhead.

# USAGE
 To use, simply add `#include "clogger.h"` to your file with clogger.h in the root directory.
 Then run `LOG_INIT("path/to/log.log");`.
 
# SETTINGS
SET_DELETE_ON_RERUN: specifies whether the file should be remade at run-time. The defualt is false, and results in appending to the log each run. It can be set through the `SET_DELETE_ON_RERUN()` function, passing in a bool (or int). This must be set before the LOG_INIT() function is called.

SET_LOG_LEVEL: specifies which level the logger should run on. The key is below. This can be set safely through the `SET_LOG_LEVEL()` function.

LOG LEVELS
 
0 : TRACE
 
1 : DEBUG

2 : INFO

3 : WARNING

4 : ERROR

5 : FATAL

6 : OFF
