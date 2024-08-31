project(process)

# 将process.cpp 添加为动态库；动态库名称 ${PROJECT_NAME} process
add_library(${PROJECT_NAME}
    SHARED
    process.cpp # 目前只有一个.cpp 文件，就这样写了
)

# 指定这个动态库包含的目录
target_include_directories(${PROJECT_NAME}
PUBLIC
${PNC_Map_Dir}
)
# 链接pnc_map的库
target_link_libraries(${PROJECT_NAME}
PUBLIC
pnc_map # 动态库
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
Eigen3::Eigen
)