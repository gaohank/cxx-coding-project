project(namespace)

set(03_dir_path ${CMAKE_CURRENT_LIST_DIR}/03_namespace_2)
set(03_src_path ${03_dir_path}/main.cpp ${03_dir_path}/cat.cpp ${03_dir_path}/dog.cpp)

add_executable(01_namespace ${CMAKE_CURRENT_LIST_DIR}/01_namespace/main.cpp)
add_executable(02_namespace ${CMAKE_CURRENT_LIST_DIR}/02_namespace_1/main.cpp)
add_executable(03_namespace ${03_src_path})