//
// Created by ����� on 2018/7/5.
//

#include "filesys.h"



/*
* �������ܣ������ļ����ļ���
* ���룺�ļ������ļ���С���û�ID���ļ����ͣ������ļ�����ȷ�����ļ������ļ��У�,�ļ�Ȩ��
* �������
* */
void create(char filename[], int size, int u_id, int mode, int limit)
{
	int i;
	// ��ǰĿ¼���Ƿ��������ļ�
	// TODO ��ǰĿ¼�²����ظ����ļ���
	for (i = 0; i < 1024; i++)
	{
		if (strcmp(filename, dirn[i].f_name) == 0)  //������ļ�����ͬ���򴴽�ʧ��
		{
			cout << "���ظ��ļ���!����ʧ��" << endl;
			return;
		}
	}

	for (i = 0; i <1024; i++)
	{
		if (dirn[i].i_num == -1)
		{
			dirn[i].i_num = i;
			strcpy(dirn[i].f_name, filename);
			strcpy(dirn[i].f_dname, cur_dir);
			i_node[i].i_mode = mode;
			i_node[i].i_size = size;
			i_node[i].i_Uid = u_id;
			i_node[i].i_limit = limit;
			allot(size);// ����size�����п�
			break;
		}
	}
}