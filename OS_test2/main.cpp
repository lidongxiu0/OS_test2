#include <iostream>
#include "filesys.h"
using namespace std;
char cur_dir[20] = "file system";
struct dir dirn[1024];
struct inode i_node[1024];
struct Username uname[8];
struct block memory[memorysize];
struct Super_Block super_block;
struct file sys_openfile[OSopenfile];
int physic[100];    //文件地址缓冲区
int login;


int main() {
	char test[20] = "test";
	char test2[20] = "test2";
	cout << "Hello, World!" << endl;
	initialize();
	uname[1] = { 1,"user",0,10 };
	//showfolder(cur_dir/*临时当前目录名*/)
	login = 1;
	cout << 1 << endl;
	create(test, 4, 1, FOLDER, 0);
	cout << 2 << endl;
	showfolder(cur_dir/*临时当前目录名*/);
	cout << 3 << endl;
	openfolder(test);
	create(test2, 4, 1, FOLDER, 0);
	showfolder(cur_dir);
	//format();
	return 0;
}