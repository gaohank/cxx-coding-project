project(cmake)

# 条件编译选项
OPTION(ANDROID_FUNC "android function support" ON)
if (ANDROID_FUNC)
    MESSAGE(STATUS "ANDROID")
else()
    MESSAGE(STATUS "NO ANDROID")
endif()

# 宏
macro(myecho str)
    MESSAGE(STATUS "this is ${str}")
endmacro()

myecho("hello")
myecho("world")

# 将当前路径加入到CMAKE_MODULE_PATH中
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
find_package(Demo)

# 查找TestConfig
set(Test_DIR ${PROJECT_SOURCE_DIR})
find_package(Test)