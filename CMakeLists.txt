project(cxx-coding-project)
# file(GLOB sources "${CMAKE_CURRENT_LIST_DIR}/01_externsion_c/02_cout_format/*.cpp")
#add_subdirectory(01_externsion_c 01_out)

message(STATUS "this is cxx project")
message(STATUS "CMAKE_BINARY_DIR = " ${CMAKE_BINARY_DIR})
message(STATUS "CMAKE_CURRENT_LIST_DIR = " ${CMAKE_CURRENT_LIST_DIR})
message(STATUS "CMAKE_CXX_STANDARD = " ${CMAKE_CXX_STANDARD})

# 增加链接库目标
add_library(str_shared SHARED 05_example/01_mystring/mystring.cpp 05_example/01_mystring/mystring.h)
add_library(str_static STATIC 05_example/01_mystring/mystring.cpp 05_example/01_mystring/mystring.h)

# 设置目标输出路径
set_target_properties(str_shared PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib_shared/")
set_target_properties(str_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/lib_static/)

# 设置头文件路径
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# 设置目标需要链接的库
#target_link_libraries(retinaface ncnn)

# 链接外部库，指定外部库路径
# add_library(ncnn STATIC IMPORTED)
# set_property(TARGET ncnn PROPERTY IMPORTED_LOCATION /mnt/d/02-code/ncnn/build-arm64-p16/install/lib/libncnn.a)

add_subdirectory(01_externsion_c)
add_subdirectory(02_namespace)
add_subdirectory(03_class_objects)
add_subdirectory(04_templates)
add_subdirectory(05_example)