project(ProtoHyriseSql)
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/third_party/local")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/third_party/local/include")

add_library(hyrise_sql STATIC IMPORTED)
set_property(TARGET hyrise_sql PROPERTY IMPORTED_LOCATION "${CMAKE_PREFIX_PATH}/lib/libsqlparser.a")
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

add_executable(proto_hyrise_sql proto_hyrise_sql_main.cpp
  queryparser.h
  queryparser.cpp
  querycompiler.h
  querycompiler.cpp
  baseplannode.h
  baseplannode.cpp
  scanplannode.h
  scanplannode.cpp
  joinplannode.h
  joinplannode.cpp
)

target_link_libraries(proto_hyrise_sql hyrise_sql)

