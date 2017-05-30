# APUEse2
Advanced Programming in the UNIX Environment se2 source and problem solutions


如何编译：
参考http://blog.163.com/fishing_1/blog/static/41594482013335953444/
1 在http://www.apuebook.com/下载src.tar.gz源代码的压缩包
2 修改 Make.defines.linux中的WKDIR为解压后apue.2e文件夹所在路径，如 WKDIR=/home/kolya/Downloads/
3 修改 apue.2e下 std/linux.mk,将所有nawk改为awk
4 返回apue.2e，执行make
make时会出现两个错误：
1
gcc -DLINUX -ansi -I/home/kolya/Downloads/apue.2e/include -Wall -D_GNU_SOURCE -DDEBUG  -c -o printd.o printd.c
In file included from printd.c:6:0:
ipp.h:122:17: error: expected ‘:’, ‘,’, ‘;’, ‘}’ or ‘__attribute__’ before ‘.’ token
 #define status u.st
                 ^
解决方法：
在apue.2e/ipp/ipp.h中定义了一个宏定义status和/usr/include/i386-linux-gnu/bits/timex.h中的成员status冲突
修改这个apue.2e/ipp/ipp.h文件中的宏名称，例如改为status_apue
#define status_apue u.st
然后将apue.2e/ipp/printd.c中977行的 hp->status 改为hp->status_apue

2
gcc -DLINUX -ansi -I/home/kolya/Downloads/apue.2e/include -Wall -D_GNU_SOURCE   -c -o getenv1.o getenv1.c
getenv1.c:4:20: error: ‘ARG_MAX’ undeclared here (not in a function)
 static char envbuf[ARG_MAX];
解决方法：
在apue.2e/include/apue.h中添加一行：
#define ARG_MAX 4096
打开apue.2e/threadctl/getenv1.c 和apue.2e/threadctl/getenv3.c，添加一行：
#include "apue.h"


5 把apue的头文件和库文件放入系统
make成功后会在 apue.2e/lib下生存libapue.a等文件, 执行：
sudo cp .../apue.2e/include/apue.h /usr/include
sudo cp .../apue.2e/lib/libapue.a /usr/lib/
sudo cp .../apue.2e/db/apue_db.h /usr/include
sudo cp .../apue.2e/db/libapue_db.a /usr/lib/

之后编译书中例子时，要将
#include "apue.h"
改为
#include <apue.h>
同时编译时要链接libapue，例如
kolya@asus ~/src/APUEse2/chap1_UNIX_System_Overview $ gcc 1-1.c -o 1-1 -lapue

编译第20章数据库相关程序时还要
将
#include "apue_db.h"
改为
#include <apue_db.h>
链接时除了加上libapue.a,还要链接libapue_db.a


注意 ：若-lapue 写在了源程序的前面会出现错误 eg. gcc ls1.c -o ls1 -lapue
因为.a在链接的时候，必须放在文件之后 .so在链接的时候，对位置没有要求，前后都可以