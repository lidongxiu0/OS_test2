//
// Created by 王兴钰 on 2018/7/7.
//

#include "filesys.h"

void display(char filename[])        //显示文件信息
{
	int i, j, k;
	cout << "文件名字  文件类型  文件长度  读取权限  所属目录  所属用户" << endl;
	for (i = 0; i<1024; i++)
	{
		k = dirn[i].i_num;
		if (strcmp(filename, dirn[i].f_name) == 0 && (i_node[k].i_mode == 1))
		{
			cout << dirn[i].f_name << "   ";   //文件名
			cout << i_node[k].i_mode << "   ";   //文件的类型
			cout << i_node[k].i_size << "   ";   //文件的长度
			cout << i_node[k].i_limit << "   ";
			cout << dirn[i].f_dname << "   ";    //文件所在的上级目录
			cout << i_node[dirn[i].i_num].i_Uid << "   "; //文件所属user
			for (j = 0; j<i_node[k].i_size; j++)   //显示物理地址
			{
				cout << "占用物理地址" << i_node[i].i_address[j] << endl; //文件具体占用的盘块号
			}
			break;
		}
	}
	if (i == 1024)
	{
		cout << "没有这个文件 或者这个文件不是正规文件" << endl;
	}
}