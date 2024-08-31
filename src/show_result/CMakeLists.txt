project(show_result)

# 将process.cpp 添加为动态库；动态库名称 ${PROJECT_NAME} process
add_library(${PROJECT_NAME}
SHARED
show_result.cpp # 目前只有一个.cpp 文件，就这样写了
)

# 指定这个动态库包含的目录
# target_include_directories(${PROJECT_NAME}
# PUBLIC
# ${Process_Dir}
# )

# target_link_libraries(${PROJECT_NAME}
# PUBLIC
# process # 动态库
# )

target_link_libraries(${PROJECT_NAME}
PUBLIC
easyx # 动态库
)