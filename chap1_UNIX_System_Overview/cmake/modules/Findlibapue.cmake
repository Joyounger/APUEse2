# date:17.5.29
# author: linyang <942510346@qq.com>
# cmake version 3.5.1
# chap1 程序库说明文件

#在开发软件的时候我们会用到一些函数库,这些函数库在不同的系统中安装的位置可能不同,编译的时候需要首先找到这些软件包的头文件以及链接库所在的目录以便生成编译选项。
#在项目的根目录中创建目录 cmake/modules/ ，在 cmake/modules/ 下创建文件 Findlibapue.cmake
#文件 Findlibapue.cmake 的命名要符合规范: FindlibNAME.cmake ,其中NAME 是函数库的名称。Findlibapue.cmake 的语法与 CMakeLists.txt 相同。这里使用了三个命令： MESSAGE ， FIND_PATH 和 FIND_LIBRARY




MESSAGE(STATUS "Using bundled Findlibapue.cmake...") #命令 MESSAGE 会将参数的内容输出到终端。
#命令 FIND_PATH 指明头文件查找的路径，FIND_PATH(<VAR> name1 [path1 path2 ...]) 该命令在参数 path* 指示的目录中查找文件 name1 并将查找到的路径保存在变量 VAR 中。这里的意思是在 /usr/include/ 和 /usr/local/include/ 中查找文件apue.h ,并将apue.h 所在的路径保存在 LIBAPUE_INCLUDE_DIR中。
FIND_PATH(
    LIBAPUE_INCLUDE_DIR
    apue.h 
    /usr/include/ 
    /usr/local/include/ 
)
#命令 FIND_LIBRARY 同 FIND_PATH 类似,用于查找链接库并将结果保存在变量中。这里的意思是在目录 /usr/lib/ 和 /usr/local/lib/ 中寻找名称为 apue 的链接库,并将结果保存在LIBAPUE_LIBRARIES。
FIND_LIBRARY(
   LIBAPUE_LIBRARIES NAMES  apue
   PATHS /usr/lib/ /usr/local/lib/
)

