//
// Created by lidongxiu on 2018/7/7.
//

#include"filesys.h"

int read(char filename[])
{
	int i, j;
	for (i = 0; i < 1024; i++)
	{
		if (strcmp(filename, dirn[i].f_name) == 0)
		{
			for (j = 0; j < OSopenfile; j++)
			{
				if (sys_openfile[j].f_inode == i_node[dirn[i].i_num] && i_node[dirn[i].i_num].i_Uid == uname[login].u_id)
				{
					if (i_node[dirn[i].i_num].i_limit == 0 || i_node[dirn[i].i_num].i_limit == 1)
					{
						int c, ch = 0;
						for (c = 0; c < NDDR; c++)
						{
							for (; ch < i_node[dirn[i].i_num].i_size; ch++)
							{
								sys_openfile[j].f_off = ch;
								cout << memory[i_node[dirn[i].i_num].i_address[c]].content[ch];
							}
						}
						cout << endl;
					}
					else
						cout << "���ܶ�ȡ���ļ�" << endl;
					return 0;
				}
			}
			if (j >= OSopenfile)
			{
				cout << "�ļ�δ�򿪣���򿪸��ļ�" << endl;
			}
			return 0;
		}
	}
	if (i >= 1024)
	{
		cout << "δ�ɹ��ҵ����ļ�" << endl;
	}
	return 0;
}

int write(char filename[], char writein[])
{
	int i, j;
	for (i = 0; i < 1024; i++)
	{
		if (strcmp(filename, dirn[i].f_name) == 0)
		{
			for (j = 0; j < OSopenfile; j++)
			{
				if (sys_openfile[j].f_inode == i_node[dirn[i].i_num] && i_node[dirn[i].i_num].i_Uid == uname[login].u_id)
				{
					if (i_node[dirn[i].i_num].i_limit == 0 || i_node[dirn[i].i_num].i_limit == 2)
					{
						int c, ch, in = 0;
						ch = sys_openfile[j].f_off;
						for (c = 0; c < NDDR; c++)
						{
							ch = sys_openfile[j].f_off % c;
							for (; ch < blocksize, in<sizeof(writein); ch++, in++, sys_openfile[j].f_off++)
							{
								memory[i_node[dirn[i].i_num].i_address[c]].content[ch] = writein[in];
							}
						}
						if (c <= NDDR)
						{
							cout << "�ļ��ռ�����������д��" << endl;
						}
						return 0;
					}
					else
					{
						cout << "����д����ļ�" << endl;
						return 0;
					}
				}
			}
			if (j >= OSopenfile)
			{
				cout << "�ļ�δ�򿪣���򿪸��ļ�" << endl;
			}
			return 0;
		}
	}
	if (i >= 1024)
	{
		cout << "���ļ�������" << endl;
	}
	return 0;
}