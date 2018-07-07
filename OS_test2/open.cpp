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
				cout << "该用户可打开文件数已达上限" << endl;
			}
			i_node_num = dirn[i].i_num;
			break;
		}
	}
	if (i >= 1024)
	{
		cout << "该文件不存在，请重新选择。" << endl;
		return -1;
	}
	string c;
	cout << "\t文件名\t文件类型\t文件大小\t读取权限\t修改时间\t上级目录\t用户" << endl;
	for (j = 0; j < 1024; j++)
	{
		if (strcmp(filename, dirn[j].f_name) == 0 && (i_node[i_node_num].i_mode == DOCUMENT))
		{
			cout << "\t" << dirn[j].f_name;  //文件名
			cout << "\t文件";  //文件类型
			cout << "\t" << i_node[i_node_num].i_size;  //文件大小
			switch (i_node[i_node_num].i_limit)
			{
			case 0:cout << "\t可读可写";
			case 1:cout << "\t可读不可写";
			case 2:cout << "\t可写不可读";
				break;
			}
			cout << "\t" << i_node[i_node_num].i_time;  //修改时间
			cout << "\t" << dirn[j].f_dname;  //上级目录
			for (int k = 0; k < 8; k++)
			{
				if (i_node[i_node_num].i_Uid == uname[k].u_id)
				{
					c = uname[k].u_name;
				}
			}
			cout << "\t" << c;  //所属用户
			cout << endl;
			//cout << "\t文件物理地址\t";
			//cout << i_node[i_node_num].i_address[0] << "---" << i_node[i_node_num].i_address[i_node[i_node_num]
			//      .i_size] << endl;
			break;
		}
		else
		{
			cout << "该文件不存在或存在问题" << endl;
		}
	}
	return i_node_num;
}

void showfolder(char foldername[]/*临时当前目录名*/)
{
	int i;
	cout << "用户：" << uname[login].u_name << endl;  //当前用户
	cout << "\t包含文件\t文件类型\t文件大小\t修改时间\t上级目录" << endl;
	for (i = 0; i < 1024; i++)
	{
		if (strcmp(foldername, dirn[i].f_dname) == 0 && i_node[dirn[i].i_num].i_Uid == uname[login].u_id)
		{
			cout << "\t" << dirn[i].f_name;  //文件名
			switch (i_node[dirn[i].i_num].i_mode)
			{
			case FOLDER:cout << "\t文件夹"; break;
			case DOCUMENT:cout << "\t文件  "; break;
			}
			cout << "\t" << i_node[dirn[i].i_num].i_size;  //文件大小
			cout << "\t" << i_node[dirn[i].i_num].i_time;  //修改时间
			cout << "\t" << dirn[i].f_dname;  //上级目录
			cout << endl;
		}
		else
		{
			// cout << "文件夹为空" << endl;
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
			//设置当前目录名
			strcpy(cur_dir, dirn[i].f_name);

			cout << cur_dir << endl;
			//显示当前目录项
			showfolder(cur_dir);
			return;
		}
	}
	if (i >= 1024)
	{
		cout << "文件夹不存在或文件夹不属于该用户" << endl;
	}
}