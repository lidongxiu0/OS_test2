#include "filesys.h"

int openfile(char filename[])
{
	int i, i_node_num, j;
	for (i = 0; i < 1024; i++)
	{
		if (strcmp(filename, dirn[i].f_name) == 0 &&
			i_node[dirn[i].i_num].i_mode == DOCUMENT &&
			i_node[dirn[i].i_num].i_Uid == uname[login].u_id &&
			strcmp(dirn[i].f_dname, cur_dir) == 0)
		{
			if (uname[login].u_open < OFile)
			{
				uname[login].u_open++;
				uname[login].u_ofile[uname[login].u_open] = dirn[i].i_num;
			}
			else
			{
				cout << "���û��ɴ��ļ����Ѵ�����" << endl;
			}
			i_node_num = dirn[i].i_num;
			break;
		}
	}
	if (i >= 1024)
	{
		cout << "���ļ������ڣ�������ѡ��" << endl;
		return -1;
	}
	string c;
	cout << "\t�ļ���\t�ļ�����\t�ļ���С\t��ȡȨ��\t�޸�ʱ��\t�ϼ�Ŀ¼\t�û�" << endl;
	for (j = 0; j < 1024; j++)
	{
		if (strcmp(filename, dirn[j].f_name) == 0 && (i_node[i_node_num].i_mode == DOCUMENT))
		{
			cout << "\t" << dirn[j].f_name;  //�ļ���
			cout << "\t�ļ�";  //�ļ�����
			cout << "\t" << i_node[i_node_num].i_size;  //�ļ���С
			switch (i_node[i_node_num].i_limit)
			{
			case 0:cout << "\t�ɶ���д";
			case 1:cout << "\t�ɶ�����д";
			case 2:cout << "\t��д���ɶ�";
				break;
			}
			cout << "\t" << i_node[i_node_num].i_time;  //�޸�ʱ��
			cout << "\t" << dirn[j].f_dname;  //�ϼ�Ŀ¼
			for (int k = 0; k < 8; k++)
			{
				if (i_node[i_node_num].i_Uid == uname[k].u_id)
				{
					c = uname[k].u_name;
				}
			}
			cout << "\t" << c;  //�����û�
			cout << endl;
			//cout << "\t�ļ������ַ\t";
			//cout << i_node[i_node_num].i_address[0] << "---" << i_node[i_node_num].i_address[i_node[i_node_num]
			//      .i_size] << endl;
			break;
		}
		else
		{
			cout << "���ļ������ڻ��������" << endl;
		}
	}
	return i_node_num;
}

void showfolder(char foldername[]/*��ʱ��ǰĿ¼��*/)
{
	int i;
	cout << "�û���" << uname[login].u_name << endl;  //��ǰ�û�
	cout << "\t�����ļ�\t�ļ�����\t�ļ���С\t�޸�ʱ��\t�ϼ�Ŀ¼" << endl;
	for (i = 0; i < 1024; i++)
	{
		if (strcmp(foldername, dirn[i].f_dname) == 0 && i_node[dirn[i].i_num].i_Uid == uname[login].u_id)
		{
			cout << "\t" << dirn[i].f_name;  //�ļ���
			switch (i_node[dirn[i].i_num].i_mode)
			{
			case FOLDER:cout << "\t�ļ���"; break;
			case DOCUMENT:cout << "\t�ļ�  "; break;
			}
			cout << "\t" << i_node[dirn[i].i_num].i_size;  //�ļ���С
			cout << "\t" << i_node[dirn[i].i_num].i_time;  //�޸�ʱ��
			cout << "\t" << dirn[i].f_dname;  //�ϼ�Ŀ¼
			cout << endl;
		}
		else
		{
			// cout << "�ļ���Ϊ��" << endl;
		}
	}
}

void openfolder(char foldername[])
{
	cout << 4 << endl;
	int i;
	for (i = 0; i < 1024; i++)
	{
		cout << foldername << "@" << cur_dir << endl;
		cout << dirn[i].f_name << "!" << dirn[i].i_num << "!" << i_node[dirn[i].i_num].i_mode << "!" << dirn[i].f_dname << endl;
		if (strcmp(foldername, dirn[i].f_name) == 0 && i_node[dirn[i].i_num].i_mode == FOLDER &&
			//i_node[dirn[i].i_num].i_Uid == uname[login].u_id &&
			strcmp(dirn[i].f_dname, cur_dir) == 0)
		{
			//���õ�ǰĿ¼��
			strcpy(cur_dir, dirn[i].f_name);

			cout << cur_dir << endl;
			//��ʾ��ǰĿ¼��
			showfolder(cur_dir);
			return;
		}
	}
	if (i >= 1024)
	{
		cout << "�ļ��в����ڻ��ļ��в����ڸ��û�" << endl;
	}
}