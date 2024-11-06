project(main)   # 项目名称

# 添加两个子目录(子目录下的CMakeList.txt)
add_subdirectory(pnc_map)
add_subdirectory(process)
add_subdirectory(show_result)

# 因为main函数在这一层，所以要添加可执行文件（创建名为 ${PROJECT_NAME} 的可执行文件。main.cpp 是编译这个可执行文件的源文件）
add_executable(${PROJECT_NAME} main.cpp)    # 依赖的文件是 main.cpp，生成文件名是main，后缀是CMAKE根据系统自动添加.exe

# 然后添加 头文件 和 依赖   首先让 ${PROJECT_NAME} 可执行文件包含
target_include_directories(${PROJECT_NAME}  # 指定编译目标 ${PROJECT_NAME} 需要的头文件目录
PUBLIC
${Process_Dir}
)

# 同样要链接动态库
target_link_libraries(${PROJECT_NAME}
PUBLIC
process # process 是 CMake 中定义的动态库，通常是通过 add_library 或 add_executable 创建的
)

target_include_directories(${PROJECT_NAME}  # 指定编译目标 ${PROJECT_NAME} 需要的头文件目录
PUBLIC
${Show_Result_Dir}
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
show_result
)