# Copyright 2018 The Min-API Authors. All rights reserved.
# Use of this source code is governed by the MIT License found in the License.md file.

cmake_minimum_required(VERSION 3.0)

set(C74_MIN_API_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../min-api)
include(${C74_MIN_API_DIR}/script/min-pretarget.cmake)

include(${CMAKE_CURRENT_SOURCE_DIR}/../min-api-unittest.cmake)

include(${C74_MIN_API_DIR}/script/min-posttarget.cmake)
