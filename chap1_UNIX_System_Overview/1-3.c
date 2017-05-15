// Copy standard input to standard output, using standard I/O
// date:17.5.15
// author: linyang <942510346@qq.com>

#include <apue.h>

int main(int argc, char const *argv[])
{
	int c;

	while((c = getc(stdin)) != EOF) {
		if (putc(c, stdout) == EOF) {
			err_sys("output error");
		}
	}

	if (ferror(stdin)) {
		err_sys("input error");
	}

	exit(0);
}
