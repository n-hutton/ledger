################################################################################
# F E T C H   V A R I A N T   L I B R A R Y
################################################################################
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(fetch-meta)

# CMake Configuration
include(${FETCH_ROOT_CMAKE_DIR}/BuildTools.cmake)

# Compiler Configuration
setup_compiler()

setup_library(fetch-meta)
