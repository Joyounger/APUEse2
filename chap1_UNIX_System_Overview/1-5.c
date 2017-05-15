// Read commands from standard input and execute them
// date:17.5.15
// author: linyang <942510346@qq.com>

#include <apue.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	char buf[MAXLINE]; //from apue.h
	pid_t pid;
	int status;

	printf("%% "); //priny prompt (print requires %% to print %)
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf) - 1] == '\n') {
			buf[strlen(buf) - 1] = 0;
		}

		if ((pid = fork()) < 0) {
			err_sys("fork error");
		} else if (pid == 0) {		// child
			execlp(buf, buf, (char *)0);
			err_ret("counldn't execute: %s", buf);
			exit(127);
		}

		//parent
		if ((pid = waitpid(pid, &status, 0)) < 0) {
			err_sys("waitpid error");
		}

		printf("%% ");
	}

	exit(0);
}