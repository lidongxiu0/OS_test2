
#ifndef FILESYS_FILESYS_H
#define FILESYS_FILESYS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <memory.h>
using namespace std;

#define blocksize 1024  //盘块大小
#define memorysize 1024  //内存中块个数
#define NDDR 10  //每个i节点最多
#define OFile 10  //每个用户最多打开的文件数
#define OSopenfile 20  //系统打开的最大文件数
#define login_default 0  //默认登录用户号
#define FOLDER 0  //文件夹
#define DOCUMENT 1  //文件

extern int physic[100];    //文件地址缓冲区
						   // string UserName[8] = { "root","user1","user2","user3","user4","user5","user6","user7" };
						   // string PassWord[8] = { "0","1","2","3","4","5","6","7" };
extern char filename[100];  //暂存文件名
extern int login;  //登录用户号
				   //盘块
				   //盘块
struct block
{
	int bfree;     //存放的空闲盘块的个数
	int bfree_address[50];   //存放空闲盘块的地址
	int flag;   //盘块是否被占用标志
	char content[blocksize];  //块上每个字节存放的字符
};

//超级块
struct Super_Block
{
	int sbfree;  //空闲盘块个数
	int free_block[50];  //进入栈中的空闲块
	int free_inode[50];  //空闲i节点
};

//i节点
struct inode
{
	int i_mode;  //文件模式
	int i_size;  //文件大小
	int i_address[NDDR];  //物理块号
	int i_limit;  //读写权限，0：可读可写；1：可读不可写；2：可写不可读
	int i_Uid;  //所属用户
	int i_count;  //文件计数
	time_t i_time;  //文件修改时间

	bool operator==(const inode& rhs)
	{
		return(i_mode == rhs.i_mode) && (i_size == rhs.i_size) && (i_address == rhs.i_address)
			&& (i_limit == rhs.i_limit) && (i_Uid == rhs.i_Uid) && (i_count == rhs.i_count) && (i_time == rhs.i_time);
	}
};

//目录项
struct dir
{
	char f_name[20];  //文件名
	int i_num;  //文件的i节点号
	char f_dname[20];   //文件上级目录
};

//用户名
struct Username
{
	int u_id;  //用户ID
	char u_name[20];  //用户名字
	int u_open; //用户已经打开的文件数
	int u_ofile[OFile];  //用户最多打开的文件数
};

//密码
struct Password
{
	int p_id;  //用户ID
	char p_password[12];//密码
};

//文件打开表
struct file
{
	int f_count;  //引用计数
	struct inode f_inode;  //指向内存索引节点
	long f_off;  //读写指针文件当前读写到的文件位置
};

// extern string UserName[8];
// extern string PassWord[8];
extern char cur_dir[20];
extern struct block memory[memorysize];
extern struct Super_Block super_block;
extern struct inode i_node[1024];
extern struct dir dirn[1024];
extern struct Username uname[8];
extern struct Password pwd[8];
extern struct file sys_openfile[OSopenfile];




extern void initialize();  //系统初始化
extern void allot(int length);
extern void recycle(int length);
extern void display_memory();
extern void create(char filename[], int size, int u_id, int mode, int limit);
extern void display(char filename[]);
extern int openfile(char filename[]);
extern void showfolder(char foldername[]/*临时当前目录名*/);
extern void openfolder(char foldername[]);
extern int read(char filename[]);
extern int write(char filename[], char writein[]);
#endif //FILESYS_FILESYS_H
