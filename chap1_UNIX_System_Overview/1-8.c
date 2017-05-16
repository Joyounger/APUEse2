// print user id and group id
// date:17.5.16
// author: linyang <942510346@qq.com>

#include <apue.h>
#include <sys/wait.h>

static void sig_int(int);	// our signal-catching function

int main(void)
{
	char buf[MAXLINE];	// from apue.h
	pid_t pid;
	int status;
	
	if (signal(SIGINT, sig_int) == SIG_ERR)
