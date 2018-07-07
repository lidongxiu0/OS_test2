//
// Created by ������ on 2018/7/5.
//
#include "filesys.h"

void initialize()
{
	int i = 0, j, k = 0;
	super_block.sbfree = 50;
	login = login_default;
	for (i = 0; i < 50; i++)
	{
		super_block.free_block[i] = i; //��ʼ������ջ�Ŀ��п�
	}


	for (i = 0; i < 1024; i++) //Ŀ¼���ʼ��
	{
		strcpy(dirn[i].f_name, "");
		dirn[i].i_num = -1;
	}

	for (i = 0; i < 1024; i++)          //�ļ�����ʼ��
	{
		i_node[i].i_limit = -1;
		i_node[i].i_count = 0;
		i_node[i].i_Uid = -1;
		i_node[i].i_size = -1;
		for (j = 0; j<50; j++)
		{
			i_node[i].i_address[j] = -1;       //�ļ���ַ��ʼ��
		}

	}

	for (i = 0; i < 1024; ++i)   //�洢�ռ��ʼ��
	{
		memory[i].bfree = 0;
		memory[i].flag = 0;
		memset(memory[i].bfree_address, -1, sizeof(memory[i].bfree_address));
		memset(memory[i].content, '\0', sizeof(memory[i].content));
	}

	for (i = 0; i < 1024; i++)    //�����п����Ϣ�ó������ӵķ���д��ÿ������һ������
	{         //�洢�ռ��ʼ��

		if ((i + 1) % 50 == 0) {
			cout << "���" << k << endl;
			k = i + 1;
			for (j = 0; j < 50; j++) {
				if (k < 1025) {
					memory[i].bfree_address[j] = k;//��һ����е�ַ
					memory[i].bfree++;  //��һ����и���   ע����memory[i].n++֮ǰҪ���丳��ֵ
					k++;
				}
				else {
					memory[i].bfree_address[j] = -1;
				}
			}
			memory[i].flag = 0;    //���Ϊû��ʹ��
			continue;     //���������ڴ洢��һ���̿���Ϣ�������̿����������ѭ��
		}

		for (j = 0; j < 50; j++) {
			memory[i].bfree_address[j] = -1;
		}
		memory[i].flag = 0;
	}
	for (int i = 0; i < 100; i++) {
		physic[i] = -1;
	}
}