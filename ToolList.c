#include "ToolList.h"


// ��ȡϵͳ��ǰʱ�䣨�ַ�������С���룬ͨ�ã�
void TimeToString(char* str_ret)
{
	time_t now_time;
	time(&now_time);
	struct tm* sysTem = localtime(&now_time);
	if (strftime(str_ret, STR_TIME_MAX, "%Y-%m-%d %H:%M:%S", sysTem) == 0)
	{
		printf("ʱ��ת��ʧ�ܣ�\n");
	}
}

// ��ȡ�ļ���С
int file_size2(char* filename)
{
	struct stat statbuf;
	stat(filename, &statbuf);
	int size = statbuf.st_size;

	return size;
}

// ��ȡ����̨�ַ���
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return ret_val;
}

// ������ȡ�����
void s_rand(int* a)
{
	static int rand_start = 1;
	if (rand_start)
	{
		rand_start = 0;
		srand((unsigned)time(NULL));
	}
	*a = rand() % 9000 + 1000;
}
