//
// Created by ������ on 2018/7/7.
//
//��ʾ����ʹ�����
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
	cout << "���е��̿�����" << k << endl;
	cout << "ʹ�õ��̿�����" << m << endl;
}