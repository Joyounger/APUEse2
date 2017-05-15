// print user id and group id
// date:17.5.15
// author: linyang <942510346@qq.com>


#include <apue.h>

int main(int argc, char const *argv[])
{
	printf("uid = %d, gid = %d\n", getuid(), getgid());

	exit(0);
}




/*
uid = 1000, gid = 1000
*/