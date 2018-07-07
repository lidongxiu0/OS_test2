//
// Created by 王兴钰 on 2018/7/5.
//
#include "filesys.h"

void initialize()
{
	int i = 0, j, k = 0;
	super_block.sbfree = 50;
	login = login_default;
	for (i = 0; i < 50; i++)
	{
		super_block.free_block[i] = i; //初始化进入栈的空闲块
	}


	for (i = 0; i < 1024; i++) //目录项初始化
	{
		strcpy(dirn[i].f_name, "");
		dirn[i].i_num = -1;
	}

	for (i = 0; i < 1024; i++)          //文件结点初始化
	{
		i_node[i].i_limit = -1;
		i_node[i].i_count = 0;
		i_node[i].i_Uid = -1;
		i_node[i].i_size = -1;
		for (j = 0; j<50; j++)
		{
			i_node[i].i_address[j] = -1;       //文件地址初始化
		}

	}

	for (i = 0; i < 1024; ++i)   //存储空间初始化
	{
		memory[i].bfree = 0;
		memory[i].flag = 0;
		memset(memory[i].bfree_address, -1, sizeof(memory[i].bfree_address));
		memset(memory[i].content, '\0', sizeof(memory[i].content));
	}

	for (i = 0; i < 1024; i++)    //将空闲块的信息用成组链接的方法写进每组的最后一个块中
	{         //存储空间初始化

		if ((i + 1) % 50 == 0) {
			cout << "组号" << k << endl;
			k = i + 1;
			for (j = 0; j < 50; j++) {
				if (k < 1025) {
					memory[i].bfree_address[j] = k;//下一组空闲地址
					memory[i].bfree++;  //下一组空闲个数   注意在memory[i].n++之前要给其赋初值
					k++;
				}
				else {
					memory[i].bfree_address[j] = -1;
				}
			}
			memory[i].flag = 0;    //标记为没有使用
			continue;     //处理完用于存储下一组盘块信息的特殊盘块后，跳过本次循环
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