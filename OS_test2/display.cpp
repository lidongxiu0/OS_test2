//
// Created by ������ on 2018/7/7.
//

#include "filesys.h"

void display(char filename[])        //��ʾ�ļ���Ϣ
{
	int i, j, k;
	cout << "�ļ�����  �ļ�����  �ļ�����  ��ȡȨ��  ����Ŀ¼  �����û�" << endl;
	for (i = 0; i<1024; i++)
	{
		k = dirn[i].i_num;
		if (strcmp(filename, dirn[i].f_name) == 0 && (i_node[k].i_mode == 1))
		{
			cout << dirn[i].f_name << "   ";   //�ļ���
			cout << i_node[k].i_mode << "   ";   //�ļ�������
			cout << i_node[k].i_size << "   ";   //�ļ��ĳ���
			cout << i_node[k].i_limit << "   ";
			cout << dirn[i].f_dname << "   ";    //�ļ����ڵ��ϼ�Ŀ¼
			cout << i_node[dirn[i].i_num].i_Uid << "   "; //�ļ�����user
			for (j = 0; j<i_node[k].i_size; j++)   //��ʾ�����ַ
			{
				cout << "ռ�������ַ" << i_node[i].i_address[j] << endl; //�ļ�����ռ�õ��̿��
			}
			break;
		}
	}
	if (i == 1024)
	{
		cout << "û������ļ� ��������ļ����������ļ�" << endl;
	}
}