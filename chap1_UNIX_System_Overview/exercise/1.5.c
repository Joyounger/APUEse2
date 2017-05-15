// date:17.5.15
// author: linyang <942510346@qq.com>

#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	float year = (float)INT_MAX / (3600 * 24 * 365);
	printf("in %f year the 32bit signed int will overflow\n", year + 1970);

	return 0;
}


/*
in 2038.096313 year the 32bit signed int will overflow
*/