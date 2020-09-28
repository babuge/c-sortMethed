#ifndef TOOLLIST_H_INCLUDED
#define TOOLLIST_H_INCLUDED
#pragma once
#include <stdio.h>  // printf
#include <stdlib.h> // rand
#include <time.h> // time_t
#include <sys/stat.h> // stat. etc filelength
#include <string.h>

#define STR_TIME_MAX 84

// 获取系统当前时间（字符串，最小到秒，通用）
void TimeToString(char*);
// 获取文件大小（window 、linux通用）
int file_size2(char*);
// 获取控制台字符串
char* s_gets(char*, int);
// 连续获取随机数
void s_rand(int*);


#endif // TOOLLIST_H_INCLUDED
