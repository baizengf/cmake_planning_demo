cmake_minimum_required(VERSION 3.30.2)  # cmake 最小版本号
project(planning
    VERSION 1.0.0   # 工程版本
    DESCRIPTION "a demo of cmake planning"  # 工程描述
    HOMEPAGE_URL "https://github.com/CODspielen/cmake_planning_demo"    # github仓库链接
    LANGUAGES CXX   # 指定语言
)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

# 设置变量(设置动态库以及可执行文件的目录) 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)   # 所有生成的可执行文件 存放位置


# 设置的变量在（add_subdirectory）子目录中可以直接用
set(Process_Dir ${CMAKE_SOURCE_DIR}/src/process)
set(PNC_Map_Dir ${CMAKE_SOURCE_DIR}/src/pnc_map)
set(Show_Result_Dir ${CMAKE_SOURCE_DIR}/src/show_result)


# 第三方库
set(EIGEN3_INCLUDE_DIR "F:/vscodeProject/eigen-3.4.0")
list(APPEND CMAKE_MODULE_PATH "${EIGEN3_INCLUDE_DIR}/cmake")    # 将 ${EIGEN3_INCLUDE_DIR}/cmake 添加到 CMAKE_MODULE_PATH 目录里面
message("CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}") # 打印信息

find_package(Eigen3 3.4 REQUIRED)   # 查找 Eigen3 并指定相应的版本；该库是必需的
if(TARGET Eigen3::Eigen)
message(STATUS "****** Eigen3 3.4 has been found in ${EIGEN3_INCLUDE_DIR} ******")
endif()

# 将子目录添加到当前的CMake项目中(并处理其中的CMakeLists.txt文件)
add_subdirectory(src)
add_subdirectory(test/map_test)
