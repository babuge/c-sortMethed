#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#pragma once
#include <stdio.h>
#include <stdlib.h>


#define FILENAME_STR "save_array.txt"


// �ļ�����˵�
void show_file_menu();
// �������鱣���ļ�
int create_arr();
// ������ϵͳ
int sort_system();
// �����ܲ˵�
void show_sort_menu();
// ���򷽷���ʼ��
int init_sort_methed(char);
// ѡ������
void sort_select_mthd(int *,int);
// ð������
void sort_bubbling_mthd(int*, int);
// ��������
void sort_exchange_mthd(int*, int);
// ��������
void sort_drop_mthd(int*, int);
// �۰����򷨣���������
void sort_bisearch_mthd(int*, int, int);

#endif // MAIN_H_INCLUDED
