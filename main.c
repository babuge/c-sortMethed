#include "main.h"
#include "ToolList.h"

/*用于分析 各种排序方法 对随机数组排序的性能
*/
int main()
{
	int file_size;
	FILE* fp;
	// 文件检测
	printf("检测排序文件是否有效...\n");
	if ((fp = fopen(FILENAME_STR, "ab+")) == NULL)
	{
		printf("文件读取异常！");
		return 0;
	}
	fclose(fp);
	file_size = file_size2((char *)FILENAME_STR);
	printf("文件大小是:%d字节\n", file_size);
	if (file_size == 0)
	{
		printf("是否创建数组：(Y\\n)\n>");
		char ch;
		int flag_f = 1;
		while (flag_f)
		{
			scanf("%c", &ch);
			while (getchar() != '\n')
			{
				continue;
			}
			switch (ch)
			{
				case 'Y':
					printf("创建数组！\n");
					// 异常退出
					if (create_arr() == 0)
					{
						return 0;
					}
					flag_f = 0;
					break;
				case 'N':
					printf("退出应用\n");
					return 0;
					break;
				default:
					printf("是否创建数组：(Y\\n)\n>");
					break;
			}
		}
	}

	show_file_menu();
	char ch_select;
	while (1)
	{
		printf("请输入命令:\n>");
		scanf("%c", &ch_select);
		while (getchar() != '\n')
		{
			continue;
		}
		switch (ch_select)
		{
			case 's':
				printf("选择排序方法！\n");
				if (sort_system() == 0)
				{
					return 0;
				}
				show_file_menu();
				break;
			case 'e':
				printf("重新创建数组！\n");
				// 创建数组异常
				if (create_arr() == 0)
				{
					return 0;
				}
				show_file_menu();
				break;
			case 'q':
				printf("退出应用\n");
				return 0;
				break;
			default:
				printf("输入有误请重新输入:\n");
				break;
		}
	}
}
// 文件管理菜单
void show_file_menu()
{
	printf("\n*************************\n");
	printf("*                         *\n");
	printf("* 文件管理系统            *\n");
	printf("* s-选择排序方法          *\n");
	printf("* e-重新创建数组          *\n");
	printf("* q-退出系统              *\n");
	printf("*                         *\n");
	printf("\n*************************\n");
}

// 排序功能菜单
void show_sort_menu()
{
	printf("\n*************************\n");
	printf("*                         *\n");
	printf("* 排序功能系统            *\n");
	printf("* 1-选择法排序            *\n");
	printf("* 2-冒泡法排序            *\n");
	printf("* 3-交换法排序            *\n");
	printf("* 4-插入法排序            *\n");
	printf("* 5-折半法排序(快速排序)  *\n");
	printf("* b-回到文件管理系统      *\n");
	printf("* h-查看排序功能菜单      *\n");
	printf("* q-退出系统              *\n");
	printf("*                         *\n");
	printf("*      1-5：为升序        *\n");
	printf("\n*************************\n");
}

// 创建数组保存文件
int create_arr()
{
	FILE* fp;
	if ((fp = fopen(FILENAME_STR, "wb")) == NULL)
	{
		printf("数组创建失败！\n");
		return 0;
	}
	int i,len;
	do {
		printf("请输入数组长度：(大于0的数)\n>");
		scanf("%d", &len);
	} while (len <= 0);

	while (getchar() != '\n')
	{
		continue;
	}
	int* p_arr;
	p_arr = (int*)malloc(sizeof(int) * len);
	for (i = 0; i < len; i++)
	{
		s_rand(p_arr + i);
		if (i < 20)
		{
			printf("%d ",*(p_arr+i));
		}
		if (i == 20) {
			printf("%d ...", *(p_arr + i));
		}
	}
	printf("\n");
	char str_time[STR_TIME_MAX];
	TimeToString(str_time);
	printf("数组被创建于：%s", str_time);
	fwrite(p_arr, sizeof(int) * len, 1, fp);
	free(p_arr);
	fclose(fp);
	return 1;
}

// 排序功能系统
int sort_system()
{
	// 显示排序菜单
	show_sort_menu();
	while (1)
	{

		printf("请输入命令：（输入h唤起排序菜单）\n>");
		char ch;
		scanf("%c", &ch);
		while (getchar() != '\n')
		{
			continue;
		}
		switch (ch)
		{
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
				if (init_sort_methed(ch) == 0)
				{
					return 0;
				}
				break;
			case 'b':
				printf("退回到上一级菜单！\n");
				return 1;
				break;
			case 'q':
				printf("退出应用！\n");
				return 0;
				break;
			case 'h':
				show_sort_menu();
				break;
			default:
				printf("输入命名的命名有误!\n");
		}
	}
}

// 排序方法初始化
int init_sort_methed(char ch)
{
	// 将数据读取到内存中
	int* p_arr;
	int arr_len;
	FILE* fp;
	if ((fp = fopen(FILENAME_STR, "rb")) == NULL)
	{
		printf("排序功能异常！\n");
		return 0;
	}
	arr_len = file_size2((char*)FILENAME_STR) / sizeof(int);
	if (arr_len <= 0)
	{
		printf("排序功能异常！\n");
		fclose(fp);
		return 0;
	}
	p_arr = (int*)malloc(sizeof(int) * arr_len);
	fread(p_arr, sizeof(int) * arr_len, 1, fp);
	{
		int i;
		printf("排序前：\n");
		for (i = 0; i < arr_len && i <= 20; i++)
		{
			printf("%d ", *(p_arr + i));
			if (i == 20)
			{
				printf("...");
			}
		}
		printf("\n");
	}
	// 排序开始
	{
		clock_t start, end;
		start = clock();
		switch (ch)
		{
		case '1':
			sort_select_mthd(p_arr, arr_len);
			break;
		case '2':
			sort_bubbling_mthd(p_arr, arr_len);
			break;
		case '3':
			sort_exchange_mthd(p_arr, arr_len);
			break;
		case '4':
			sort_drop_mthd(p_arr, arr_len);
			break;
		case '5':
			sort_bisearch_mthd(p_arr, 0,arr_len -1);
			break;
		}
		end = clock();
		printf("-----result-方法%c-数组长度:%d-----排序用时:=%fs\n", ch,arr_len,(end - start) / (double)CLOCKS_PER_SEC);
	}
	// 排序结束
	{
		int i;
		printf("排序后：\n");
		for (i = 0; i < arr_len && i <= 20; i++)
		{
			printf("%d ", *(p_arr + i));
			if (i == 20)
			{
				printf("...");
			}
		}
		printf("\n");
	}
	// 关闭文件
	fclose(fp);
	// 释放内存
	free(p_arr);
	return 1;
}
// 选择排序法
void sort_select_mthd(int* p_arr, int length)
{
	int i,j,k;
	int temp;
	for (i = 0; i < length-1; i++)
	{
		k = i;
		for (j = i; j < length; j++)
		{
			if (*(p_arr + k) > * (p_arr + j))
			{
				k = j;
			}
		}
		if (k != i)
		{
			temp = *(p_arr + k);
			*(p_arr + k) = *(p_arr+i);
			*(p_arr + i) = temp;
		}
	}
}

// 冒泡排序法
void sort_bubbling_mthd(int* p_arr, int length)
{
	int i, j;
	int temp;
	int flag;
	for (i = 0; i < length - 1; i++)
	{
		flag = 0;
		for (j = length-1; j > i; j--)
		{
			if (*(p_arr + j) < * (p_arr + j-1))
			{
				flag = 1;
				temp = *(p_arr + j);
				*(p_arr + j) = *(p_arr + j-1);
				*(p_arr + j -1) = temp;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

// 交换排序法
void sort_exchange_mthd(int* p_arr, int length)
{
	int i, j;
	int temp;
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (*(p_arr + i) > *(p_arr + j))
			{
				temp = *(p_arr + i);
				*(p_arr + i) = *(p_arr + j);
				*(p_arr + j) = temp;
			}
		}
	}
}

// 插入排序法
void sort_drop_mthd(int* p_arr, int length)
{
	int i, j;
	int temp;
	for (i = 1; i < length; i++)
	{
		temp = *(p_arr + i);
		j = i - 1;
		while (j >= 0 && temp < *(p_arr + j))
		{
			*(p_arr + j + 1) = *(p_arr + j);
			j--;
		}
		if (j != i - 1)
		{
			*(p_arr + j + 1) = temp;
		}
	}
}

// 折半排序法（快速排序）
void sort_bisearch_mthd(int* p_arr, int left, int right)
{
	int i, j;
	int middle, temp;
	i = left;
	j = right;
	middle = *(p_arr + (left + right) / 2);
	while (i <= j)
	{
		while (*(p_arr + i) < middle && i < right) i++;
		while (*(p_arr + j) > middle && j > left) j--;
		if (i <= j)
		{
			temp = *(p_arr + i);
			*(p_arr + i) = *(p_arr + j);
			*(p_arr + j) = temp;
			i++;
			j--;
		}
	}
	if (left < j) /* 递归左边*/
	{
		sort_bisearch_mthd(p_arr, left, j);
	}
	if (i < right) /* 递归右边*/
	{
		sort_bisearch_mthd(p_arr, i, right);
	}
}

