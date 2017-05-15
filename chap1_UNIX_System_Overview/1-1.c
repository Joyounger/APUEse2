// unix ls commmand simple version

// date:17.4.17
// author: linyang <942510346@qq.com>

#include <apue.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
	DIR           *dp;
	struct dirent *dirp;

	if(argc != 2) {
		err_quit("usage: ls directory_name");
	}
	if ((dp = opendir(argv[1])) == NULL) {
		err_sys("can't open %s", argv[1]);
	}
	while((dirp = readdir(dp)) != NULL) {
		printf("%s\n", dirp -> d_name);
	}

	return 0;
}