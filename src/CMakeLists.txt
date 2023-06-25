cmake_minimum_required(VERSION 3.15)
project(allfiles VERSION 0.1)

add_subdirectory(FileFunctions)

add_executable(allfiles main.cxx)

target_include_directories(allfiles PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

target_link_libraries(allfiles PUBLIC filefunctions cargs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
