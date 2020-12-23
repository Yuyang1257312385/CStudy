
cmake_minimum_required(VERSION 3.10.2)

project("ndkdemo")

include_directories(cpp)

aux_source_directory(cpp DIR_SRCS)

add_executable(
        test
        ${DIR_SRCS}
)
