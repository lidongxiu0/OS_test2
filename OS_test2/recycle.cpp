//
// Created by ������ on 2018/7/6.
//
#include "filesys.h"

//���̻���
void recycle(int length)
{
	int i, j, k, m;
	for (i = 0; i < length - 1; i++)
	{
		k = physic[i];    //����տ��п��ַ
		m = 49 - super_block.sbfree;   //���������λ��
		if (super_block.sbfree == 50) //������п���������Ҫ����ǰջ������д����һ��ջ
		{
			for (j = 0; j<50; j++)
			{
				memory[k].bfree_address[j] = super_block.free_block[j];
			}
			int u = 0;
			for (; u<50; u++)
			{
				super_block.free_block[u] = -1;
			}
			super_block.sbfree = 0;
			memory[k].bfree = 50;
		}
		memory[k].flag = 0;
		if (m == -1)  //���m=-1����ַ�д�Ÿղ���ջ�ĵ�ַ����Ϣ
		{
			m = 49;
		}
		super_block.free_block[m] = physic[i]; //����һ���ļ���ַ�е��̿�Ż��յ�ջ��
		super_block.sbfree++;
	}
	cout << "���̻������" << k << endl;
}