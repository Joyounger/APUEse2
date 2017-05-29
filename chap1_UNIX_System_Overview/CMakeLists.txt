# date:17.5.29
# author: linyang <942510346@qq.com>
# cmake version 3.5.1
# chap1 cmake编译配置文件
# 完成 Findlibapue.cmake 和 CMakeList.txt 的编写后在项目的根目录依次执行 “cmake . ” 和 “make ” 可以进行编译


#可以查找链接库的 CMakeList.txt
PROJECT(apue_chap1)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)



#链接apue的两种方法
#方法一
SET(CMAKE_SOURCE_DIR .)
SET(CMAKE_MODULE_PATH ${CMAKE_ROOT}/Modules ${CMAKE_SOURCE_DIR}/cmake/modules) #表示到目录./cmake/modules中查找Findlibapue.cmake
#查找链接库和头文件开始，这里是链接库apue库
FIND_PACKAGE(libapue REQUIRED)#使用命令FIND_PACKAGE查找，这条命令执行后CMake会到变量CMAKE_MODULE_PATH指示的目录中查找文件 Findlibapue.cmake并执行
MARK_AS_ADVANCED(
    LIBAPUE_INCLUDE_DIR
    LIBAPUE_LIBRARIES
)
#if表示如果LIBAPUE_INCLUDE_DIR和LIBAPUE_LIBRARIES都被赋值,则设置编译时到LIBAPUE_INCLUDE_DIR寻找头文件并与库LIBAPUE_LIBRARIES链接
IF (LIBAPUE_INCLUDE_DIR AND LIBAPUE_LIBRARIES)
    MESSAGE(STATUS "Found libapue libraries")
    INCLUDE_DIRECTORIES(${LIBAPUE_INCLUDE_DIR})
    MESSAGE(${LIBAPUE_LIBRARIES})
    # TARGET_LINK_LIBRARIES(1-1 ${LIBAPUE_LIBRARIES}
    LINK_LIBRARIES(${LIBAPUE_LIBRARIES})
ENDIF (LIBAPUE_INCLUDE_DIR AND LIBAPUE_LIBRARIES)
#查找链接库和头文件结束

#方法二
#LINK_LIBRARIES(apue)


ADD_EXECUTABLE(1-1 1-1.c)
ADD_EXECUTABLE(1-2 1-2.c)
ADD_EXECUTABLE(1-3 1-3.c)
ADD_EXECUTABLE(1-4 1-4.c)
ADD_EXECUTABLE(1-5 1-5.c)
ADD_EXECUTABLE(1-6 1-6.c)
ADD_EXECUTABLE(1-7 1-7.c)
ADD_EXECUTABLE(1-8 1-8.c)

#设置属性CMAKE_RUNTIME_OUTPUT_DIRECTORY，控制编译出的可执行文件的输出路径，这里将1.5和1.6这两个elf的输出目录设为了./exercise/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./exercise/)
ADD_EXECUTABLE(1.5 ./exercise/1.5.c)
ADD_EXECUTABLE(1.6 ./exercise/1.6.c)