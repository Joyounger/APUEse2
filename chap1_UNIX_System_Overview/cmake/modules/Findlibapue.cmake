MESSAGE(STATUS "Using bundled Findlibapue.cmake...")
FIND_PATH(
    LIBAPUE_INCLUDE_DIR
    apue.h 
    /usr/include/ 
    /usr/local/include/ 
)

FIND_LIBRARY(
   LIBAPUE_LIBRARIES NAMES  apue
   PATHS /usr/lib/ /usr/local/lib/
)


#在开发软件的时候我们会用到一些函数库,这些函数库在不同的系统中安装的位置可能不同,编译的时候需要首先找到这些软件包的头文件以及链接库所在的目录以便生成编译选项。
#在项目的根目录中创建目录 cmake/modules/ ，在 cmake/modules/ 下创建文件 Findlibdb_cxx.cmake ，内容如下：

#文件 Findlibdb_cxx.cmake 的命名要符合规范: FindlibNAME.cmake ,其中NAME 是函数库的名称。Findlibdb_cxx.cmake 的语法与 CMakeLists.txt 相同。这里使用了三个命令： MESSAGE ， FIND_PATH 和 FIND_LIBRARY 。
#命令 MESSAGE 会将参数的内容输出到终端。
#命令 FIND_PATH 指明头文件查找的路径，原型如下：
#find_path(<VAR> name1 [path1 path2 ...]) 该命令在参数 path* 指示的目录中查找文件 name1 并将查找到的路径保存在变量 VAR 中。清单5第3－8行的意思是在 /usr/include/ 和 /usr/local/include/ 中查找文件db_cxx.h ,并将db_cxx.h 所在的路径保存在 LIBDB_CXX_INCLUDE_DIR中。
#命令 FIND_LIBRARY 同 FIND_PATH 类似,用于查找链接库并将结果保存在变量中。清单5第10－13行的意思是在目录 /usr/lib/ 和 /usr/local/lib/ 中寻找名称为 db_cxx 的链接库,并将结果保存在 LIBDB_CXX_LIBRARIES。
