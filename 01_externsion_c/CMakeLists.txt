project(externsion_c)

set(01_src ${CMAKE_CURRENT_LIST_DIR}/01_cin_cout/main.cpp)
set(02_src ${CMAKE_CURRENT_LIST_DIR}/02_cout_format/main.cpp)
set(03_src ${CMAKE_CURRENT_LIST_DIR}/03_function_overload/main.cpp)
set(04_src ${CMAKE_CURRENT_LIST_DIR}/04_operator_overload/main.cpp)

add_executable(01_cin_cout ${01_src})
add_executable(02_cout_format ${02_src})
add_executable(03_function_overload ${03_src})
add_executable(04_operator_overload ${04_src})
add_executable(05_default_paramater ${CMAKE_CURRENT_LIST_DIR}/05_default_paramater/main.cpp)
add_executable(06_reference ${CMAKE_CURRENT_LIST_DIR}/06_reference/main.cpp)
add_executable(07_new_delete ${CMAKE_CURRENT_LIST_DIR}/07_new_delete/main.cpp)
add_executable(08_inline ${CMAKE_CURRENT_LIST_DIR}/08_inline/main.cpp)
add_executable(09_const ${CMAKE_CURRENT_LIST_DIR}/09_const/main.cpp)
add_executable(10_cast ${CMAKE_CURRENT_LIST_DIR}/10_cast/main.cpp)
add_executable(11_string ${CMAKE_CURRENT_LIST_DIR}/11_string/main.cpp)
add_executable(12_struct ${CMAKE_CURRENT_LIST_DIR}/12_struct/main.cpp)
add_executable(13_exception ${CMAKE_CURRENT_LIST_DIR}/13_exception/main.cpp)
add_executable(14_extern ${CMAKE_CURRENT_LIST_DIR}/14_extern/main.cpp)
add_executable(15_io ${CMAKE_CURRENT_LIST_DIR}/15_io/main.cpp)

execute_process(COMMAND ${CMAKE_COMMAND} -E
    copy ${CMAKE_CURRENT_LIST_DIR}/15_io/test.jpg
    ${CMAKE_BINARY_DIR}/01_externsion_c/test.jpg)