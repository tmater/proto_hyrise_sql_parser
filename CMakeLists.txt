project(ProtoHyriseSql)
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/third_party/local")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/third_party/local/include" , "/opt/homebrew/Cellar/boost/1.80.0/include")

add_library(hyrise_sql STATIC IMPORTED)
set_property(TARGET hyrise_sql PROPERTY IMPORTED_LOCATION "${CMAKE_PREFIX_PATH}/lib/libsqlparser.a")
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

# Find avro executable
find_program(AVROGENCPP Avrogencpp REQUIRED)
message(STATUS "Found avrogencpp")

add_library(libavrocpp STATIC IMPORTED)
set_property(TARGET libavrocpp PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/third_party/local/lib/libavrocpp_s.a")

# Generate source from Avro schema .json files
get_filename_component(catalog_schema "${CMAKE_CURRENT_SOURCE_DIR}/src/avro_schemas/catalog_schema.json" ABSOLUTE)
get_filename_component(catalog_schema_src "${CMAKE_CURRENT_SOURCE_DIR}/src/generated/catalog_schema.cpp" ABSOLUTE)

add_custom_command(
  OUTPUT "${catalog_schema_src}"
  COMMAND export DYLD_FALLBACK_LIBRARY_PATH="${CMAKE_CURRENT_SOURCE_DIR}/third_party/local/lib" \; ${AVROGENCPP}
  -i "${catalog_schema}"
  -o "${catalog_schema_src}"
  -n cmr
  DEPENDS "${catalog_schema}")

# Link together the generated files from .proto
add_library(avro_schema
  ${catalog_schema_src})

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
  catalog.h
  catalog.cpp
  table.h
  table.cpp
)

target_link_libraries(proto_hyrise_sql hyrise_sql)
target_link_libraries(proto_hyrise_sql libavrocpp)