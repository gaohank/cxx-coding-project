project(example)

add_executable(01_mystring ${CMAKE_CURRENT_LIST_DIR}/01_mystring/main.cpp ${CMAKE_CURRENT_LIST_DIR}/01_mystring/mystring.cpp)
add_executable(02_review ${CMAKE_CURRENT_LIST_DIR}/02_review/main.cpp)
add_executable(03_review ${CMAKE_CURRENT_LIST_DIR}/03_review/main.cpp)
add_executable(04_vector ${CMAKE_CURRENT_LIST_DIR}/04_vector/main.cpp)
add_executable(05_dirs ${CMAKE_CURRENT_LIST_DIR}/05_dirs/main.cpp)