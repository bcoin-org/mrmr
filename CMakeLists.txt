# CMakeLists.txt - cmake build for mrmr
# Copyright (c) 2020, Christopher Jeffrey (MIT License).
# https://github.com/bcoin-org/mrmr

cmake_minimum_required(VERSION 3.4)
project(mrmr LANGUAGES C)

include(NodeJS)
include(TestBigEndian)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 99)

add_node_module(mrmr src/murmur3.c src/mrmr.c)

test_big_endian(MRMR_BIGENDIAN)

if(MRMR_BIGENDIAN)
  target_compile_definitions(mrmr PRIVATE WORDS_BIGENDIAN)
endif()

if(MSVC)
  target_compile_options(mrmr PRIVATE /wd4146
                                      /wd4244
                                      /wd4267
                                      /wd4334)
else()
  target_compile_options(mrmr PRIVATE -Wall
                                      -Wextra
                                      -Wno-implicit-fallthrough)
endif()
