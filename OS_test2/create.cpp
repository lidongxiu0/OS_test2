//
// Created by 吴佳益 on 2018/7/5.
//

#include "filesys.h"



/*
* 函数功能：创建文件或文件夹
* 输入：文件名，文件大小，用户ID，文件类型（根据文件类型确定是文件还是文件夹）,文件权限
* 输出：无
* */
void create(char filename[], int size, int u_id, int mode, int limit)
{
	int i;
	// 当前目录下是否有重名文件
	// TODO 当前目录下查找重复的文件名
	for (i = 0; i < 1024; i++)
	{
		if (strcmp(filename, dirn[i].f_name) == 0)  //如果有文件名相同，则创建失败
		{
			cout << "有重复文件名!创建失败" << endl;
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
			allot(size);// 申请size个空闲块
			break;
		}
	}
}