project(cxx-coding-project)
# file(GLOB sources "${CMAKE_CURRENT_LIST_DIR}/01_externsion_c/02_cout_format/*.cpp")
#add_subdirectory(01_externsion_c 01_out)

message(STATUS "this is cxx project")
message(STATUS "CMAKE_BINARY_DIR = " ${CMAKE_BINARY_DIR})
message(STATUS "CMAKE_CURRENT_BINARY_DIR = " ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS "CMAKE_CURRENT_LIST_DIR = " ${CMAKE_CURRENT_LIST_DIR})
message(STATUS "CMAKE_CXX_STANDARD = " ${CMAKE_CXX_STANDARD})
message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")

# 获得路径的文件名
set(TEST_FILE /mnt/d/02-code/android-ndk-r20/build/cmake/android.toolchain.cmake)
get_filename_component(TEST_FILE_NAME ${TEST_FILE} NAME)
message(STATUS "TEST_FILE_NAME = " ${TEST_FILE_NAME})

# 增加链接库目标
add_library(str_shared SHARED 05_example/01_mystring/mystring.cpp 05_example/01_mystring/mystring.h)
add_library(str_static STATIC 05_example/01_mystring/mystring.cpp 05_example/01_mystring/mystring.h)

# 设置目标输出路径
set_target_properties(str_shared PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib_shared/)
set_target_properties(str_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib_static/)

# 设置头文件路径
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# 设置目标需要链接的库
# target_link_libraries(retinaface ncnn)

# 链接外部库，指定外部库路径
# add_library(ncnn STATIC IMPORTED)
# set_property(TARGET ncnn PROPERTY IMPORTED_LOCATION /mnt/d/02-code/ncnn/build-arm64-p16/install/lib/libncnn.a)

# 指定查找文件（find_package/find_library）优先路径
# set(CMAKE_FIND_ROOT_PATH path1 path2)

# CMake执行交叉编译指令
# cmake -DCMAKE_TOOLCHAIN_FILE=file -DANDROID_ABI="arm64-v8a" -DANDROID_ARM_NEON=ON -DANDROID_PLATFORM=android-29

add_subdirectory(01_externsion_c)
add_subdirectory(02_namespace)
add_subdirectory(03_class_objects)
add_subdirectory(04_templates)
add_subdirectory(05_example)