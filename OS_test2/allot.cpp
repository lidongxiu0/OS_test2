//
// Created by ������ on 2018/7/5.
//
#include "filesys.h"

//���̷���
void allot(int length)
{
	int i, j, k, p;
	int m = -1;
	for (i = 0; i<length; i++)
	{
		k = 50 - super_block.sbfree;    //�������б�ʾ���п��ָ��
		m = super_block.free_block[k];   //ջ�е���Ӧ�̿�ĵ�ַ
		p = super_block.free_block[49];   //ջ�е����һ���̿�ָ��ĵ�ַ
		if (p == -1)  //û��ʣ���̿�
		{
			printf("�ڴ治��,���ܹ�����ռ�\n");
			recycle(i);//֮ǰ�ѷ����i���̿���գ�
			break;
		}
		if (super_block.sbfree == 1)
		{
			memory[m].bfree = 1;    //�����һ���̿�����
			physic[i] = m;
			super_block.free_block[49] = -1;
			super_block.sbfree = 0;
			for (j = 50 - memory[m].bfree; j<50; j++) //�����һ���̿���ȡ����һ���̿��д��ջ��
			{
				super_block.free_block[j] = memory[m].bfree_address[j];
				super_block.sbfree++;
			}
			continue;     //Ҫ�������ѭ��������������IF���Ѿ�ִ�й�
		}
		physic[i] = m;     //���ջ�г���һ���̣�ջ�е���Ӧ�̿�ĵ�ַд�� �ļ���ַ������
		memory[m].flag = 1;
		i_node[i].i_address[m] += 1;
		super_block.sbfree--;
		cout << "���̷������" << k << endl;
	}

}
