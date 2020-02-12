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