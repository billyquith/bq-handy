###############################
# BQ-Handy
###############################

cmake_minimum_required(VERSION 3.1)

set(BQHANDY_VERSION_MAJOR 0)
set(BQHANDY_VERSION_MINOR 1)
set(BQHANDY_VERSION_PATCH 0)

project(handy)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_subdirectory(src)
add_subdirectory(test)


