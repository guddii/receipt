cmake_minimum_required(VERSION 2.8.7)
set(PROJECT_NAME_STR receipt)
project(${PROJECT_NAME_STR} C CXX)

find_package(Threads REQUIRED)
add_definitions(-Wall -ansi -Wno-deprecated -pthread -std=c++0x)

#-------------------
# set common include folder for module
#-------------------
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/lib)

#-------------------
# Module source
#-------------------
add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

#-------------------
# Test
#-------------------
add_definitions(${MSVC_COMPILER_DEFS})
enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.test.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES}
        src/ReceiptCollection.cpp src/ReceiptCollection.hpp
        src/ReceiptItem.cpp src/ReceiptItem.hpp)
add_dependencies(${PROJECT_TEST_NAME} googletest)
target_link_libraries(${PROJECT_TEST_NAME} ${GTEST_LIBS_DIR}/libgtest.a ${GTEST_LIBS_DIR}/libgtest_main.a)
target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})
add_test(test1 ${PROJECT_TEST_NAME})
