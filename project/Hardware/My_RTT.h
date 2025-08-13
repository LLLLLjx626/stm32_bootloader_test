#ifndef __MY_RTT_H
#define __MY_RTT_H

#include <string.h>

/************************************???***************************************/
// 配置输出接口
#include <stdio.h>
#define LOG_PRINT(format, ...)  SEGGER_RTT_printf(0, format, ##__VA_ARGS__)

// 选择log等级，低于此等级的log不会打印
#define CURRENT_LOG_LEVEL   LOG_LEVEL_DEBUG

// 输出文件名时可能包含路径，这里只输出文件名
// 地址分隔符  Linux:'/'  Windows:'\'
#define PATH_SEPARATOR      '/'
/************************************end*****************************************/

typedef enum{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERR,
}LOG_LEVEL;

// color define
#define LOG_COLOUR_BLACK           "\x1B[2;30m"
#define LOG_COLOUR_RED             "\x1B[2;31m"
#define LOG_COLOUR_GREEN           "\x1B[2;32m"
#define LOG_COLOUR_YELLOW          "\x1B[2;33m"
#define LOG_COLOUR_BLUE            "\x1B[2;34m"
#define LOG_COLOUR_MAGENTA         "\x1B[2;35m"
#define LOG_COLOUR_CYAN            "\x1B[2;36m"
#define LOG_COLOUR_WHITE           "\x1B[2;37m"

#define LOG_COLOUR_RESET           "\x1B[0m" 

// delete the path in the _FILE_
#define GET_FILE_NAME(path) strrchr(path, PATH_SEPARATOR)?strrchr(path, PATH_SEPARATOR)+1:path

// debug log cyan
#define LOG_DEBUG(format, ...)                                                                                              \
if (CURRENT_LOG_LEVEL <= LOG_LEVEL_DEBUG)                                                                                   \
{                                                                                                                           \
    LOG_PRINT(LOG_COLOUR_CYAN "[DEBUG %s %d]" LOG_COLOUR_CYAN format, GET_FILE_NAME(__FILE__), __LINE__, ##__VA_ARGS__);   \
} 

// normal log green
#define LOG_INFO(format, ...)                                                                                               \
if (CURRENT_LOG_LEVEL <= LOG_LEVEL_INFO)                                                                                    \
{                                                                                                                           \
    LOG_PRINT(LOG_COLOUR_RESET "[INFO %s %d]" LOG_COLOUR_RESET format, GET_FILE_NAME(__FILE__), __LINE__, ##__VA_ARGS__);   \
} 

// warning log yellow
#define LOG_WARN(format, ...)                                                                                               \
if (CURRENT_LOG_LEVEL <= LOG_LEVEL_WARN)                                                                                    \
{                                                                                                                           \
    LOG_PRINT(LOG_COLOUR_YELLOW "[WARN %s %d]" LOG_COLOUR_YELLOW format, GET_FILE_NAME(__FILE__), __LINE__, ##__VA_ARGS__);  \
} 

// error log red
#define LOG_ERR(format, ...)                                                                                                \
if (CURRENT_LOG_LEVEL <= LOG_LEVEL_ERR)                                                                                     \
{                                                                                                                           \
    LOG_PRINT(LOG_COLOUR_RED "[ERR %s %d]" LOG_COLOUR_RED format, GET_FILE_NAME(__FILE__), __LINE__, ##__VA_ARGS__);  \
} 

#endif
