//
// Created by 王兴钰 on 2018/7/7.
//
//显示磁盘使用情况
#include "filesys.h"
void display_memory()
{
	int i, m, k = 0;
	for (i = 0; i<1024; i++)
	{
		if (memory[i].flag == 0)
			k++;
	}
	m = 1024 - k;
	cout << "空闲的盘块数是" << k << endl;
	cout << "使用的盘块数是" << m << endl;
}