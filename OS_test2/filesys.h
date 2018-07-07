
#ifndef FILESYS_FILESYS_H
#define FILESYS_FILESYS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <memory.h>
using namespace std;

#define blocksize 1024  //�̿��С
#define memorysize 1024  //�ڴ��п����
#define NDDR 10  //ÿ��i�ڵ����
#define OFile 10  //ÿ���û����򿪵��ļ���
#define OSopenfile 20  //ϵͳ�򿪵�����ļ���
#define login_default 0  //Ĭ�ϵ�¼�û���
#define FOLDER 0  //�ļ���
#define DOCUMENT 1  //�ļ�

extern int physic[100];    //�ļ���ַ������
						   // string UserName[8] = { "root","user1","user2","user3","user4","user5","user6","user7" };
						   // string PassWord[8] = { "0","1","2","3","4","5","6","7" };
extern char filename[100];  //�ݴ��ļ���
extern int login;  //��¼�û���
				   //�̿�
				   //�̿�
struct block
{
	int bfree;     //��ŵĿ����̿�ĸ���
	int bfree_address[50];   //��ſ����̿�ĵ�ַ
	int flag;   //�̿��Ƿ�ռ�ñ�־
	char content[blocksize];  //����ÿ���ֽڴ�ŵ��ַ�
};

//������
struct Super_Block
{
	int sbfree;  //�����̿����
	int free_block[50];  //����ջ�еĿ��п�
	int free_inode[50];  //����i�ڵ�
};

//i�ڵ�
struct inode
{
	int i_mode;  //�ļ�ģʽ
	int i_size;  //�ļ���С
	int i_address[NDDR];  //������
	int i_limit;  //��дȨ�ޣ�0���ɶ���д��1���ɶ�����д��2����д���ɶ�
	int i_Uid;  //�����û�
	int i_count;  //�ļ�����
	time_t i_time;  //�ļ��޸�ʱ��

	bool operator==(const inode& rhs)
	{
		return(i_mode == rhs.i_mode) && (i_size == rhs.i_size) && (i_address == rhs.i_address)
			&& (i_limit == rhs.i_limit) && (i_Uid == rhs.i_Uid) && (i_count == rhs.i_count) && (i_time == rhs.i_time);
	}
};

//Ŀ¼��
struct dir
{
	char f_name[20];  //�ļ���
	int i_num;  //�ļ���i�ڵ��
	char f_dname[20];   //�ļ��ϼ�Ŀ¼
};

//�û���
struct Username
{
	int u_id;  //�û�ID
	char u_name[20];  //�û�����
	int u_open; //�û��Ѿ��򿪵��ļ���
	int u_ofile[OFile];  //�û����򿪵��ļ���
};

//����
struct Password
{
	int p_id;  //�û�ID
	char p_password[12];//����
};

//�ļ��򿪱�
struct file
{
	int f_count;  //���ü���
	struct inode f_inode;  //ָ���ڴ������ڵ�
	long f_off;  //��дָ���ļ���ǰ��д�����ļ�λ��
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




extern void initialize();  //ϵͳ��ʼ��
extern void allot(int length);
extern void recycle(int length);
extern void display_memory();
extern void create(char filename[], int size, int u_id, int mode, int limit);
extern void display(char filename[]);
extern int openfile(char filename[]);
extern void showfolder(char foldername[]/*��ʱ��ǰĿ¼��*/);
extern void openfolder(char foldername[]);
extern int read(char filename[]);
extern int write(char filename[], char writein[]);
#endif //FILESYS_FILESYS_H
