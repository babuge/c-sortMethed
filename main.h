#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#pragma once
#include <stdio.h>
#include <stdlib.h>


#define FILENAME_STR "save_array.txt"


// 文件管理菜单
void show_file_menu();
// 创建数组保存文件
int create_arr();
// 排序功能系统
int sort_system();
// 排序功能菜单
void show_sort_menu();
// 排序方法初始化
int init_sort_methed(char);
// 选择排序法
void sort_select_mthd(int *,int);
// 冒泡排序法
void sort_bubbling_mthd(int*, int);
// 交换排序法
void sort_exchange_mthd(int*, int);
// 插入排序法
void sort_drop_mthd(int*, int);
// 折半排序法（快速排序）
void sort_bisearch_mthd(int*, int, int);

#endif // MAIN_H_INCLUDED
