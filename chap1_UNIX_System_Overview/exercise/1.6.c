// date:17.4.17
// author: linyang <942510346@qq.com>

#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	int seconds = (int)(INT_MAX / 100) + 1;
	float days = seconds / (24 * 3600.0);
	printf("after %d seconds will overflow\n", seconds);
	printf("after %f days will overflow\n", days);

	return 0;
}


/*
kolya@asus ~/src/APUEse2/chap1/exercise $ ./1.6
after 21474837 seconds will overflow
after 248.551361 days will overflow
*/