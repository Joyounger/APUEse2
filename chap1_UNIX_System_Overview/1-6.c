// shows the use of these two error functions.
// date:17.5.15
// author: linyang <942510346@qq.com>

#include <apue.h>
#include <errno.h>


int main(int argc, char const *argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));

	errno = ENOENT;
	perror(argv[0]);

	exit(0);
}