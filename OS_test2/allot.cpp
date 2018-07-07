//
// Created by 王兴钰 on 2018/7/5.
//
#include "filesys.h"

//磁盘分配
void allot(int length)
{
	int i, j, k, p;
	int m = -1;
	for (i = 0; i<length; i++)
	{
		k = 50 - super_block.sbfree;    //超级块中表示空闲块的指针
		m = super_block.free_block[k];   //栈中的相应盘块的地址
		p = super_block.free_block[49];   //栈中的最后一个盘块指向的地址
		if (p == -1)  //没有剩余盘块
		{
			printf("内存不足,不能够分配空间\n");
			recycle(i);//之前已分配的i个盘块回收；
			break;
		}
		if (super_block.sbfree == 1)
		{
			memory[m].bfree = 1;    //将最后一个盘块分配掉
			physic[i] = m;
			super_block.free_block[49] = -1;
			super_block.sbfree = 0;
			for (j = 50 - memory[m].bfree; j<50; j++) //从最后一个盘块中取出下一组盘块号写入栈中
			{
				super_block.free_block[j] = memory[m].bfree_address[j];
				super_block.sbfree++;
			}
			continue;     //要跳过这次循环，下面的语句在IF中已经执行过
		}
		physic[i] = m;     //如果栈中超过一个盘，栈中的相应盘块的地址写进 文件地址缓冲区
		memory[m].flag = 1;
		i_node[i].i_address[m] += 1;
		super_block.sbfree--;
		cout << "磁盘分配完毕" << k << endl;
	}

}
