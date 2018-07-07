//
// Created by 王兴钰 on 2018/7/6.
//
#include "filesys.h"

//磁盘回收
void recycle(int length)
{
	int i, j, k, m;
	for (i = 0; i < length - 1; i++)
	{
		k = physic[i];    //需回收空闲块地址
		m = 49 - super_block.sbfree;   //放入空闲区位置
		if (super_block.sbfree == 50) //代表空闲块已满，需要将当前栈中内容写入下一个栈
		{
			for (j = 0; j<50; j++)
			{
				memory[k].bfree_address[j] = super_block.free_block[j];
			}
			int u = 0;
			for (; u<50; u++)
			{
				super_block.free_block[u] = -1;
			}
			super_block.sbfree = 0;
			memory[k].bfree = 50;
		}
		memory[k].flag = 0;
		if (m == -1)  //如果m=-1，地址中存放刚才满栈的地址的信息
		{
			m = 49;
		}
		super_block.free_block[m] = physic[i]; //将下一个文件地址中的盘块号回收到栈中
		super_block.sbfree++;
	}
	cout << "磁盘回收完毕" << k << endl;
}