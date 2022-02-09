cmake_minimum_required(VERSION 3.12)
project(mqttjsdemo)

set(CMAKE_EXECUTABLE_SUFFIX ".js")

add_executable(${PROJECT_NAME} main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES 
    LINK_FLAGS "-s EXPORTED_RUNTIME_METHODS=['ccall','UTF8ToString','allocate','intArrayFromString','addFunction'] -s ALLOW_TABLE_GROWTH"
    OUTPUT_NAME "lib"
)

install(FILES ${CMAKE_BINARY_DIR}/lib.js ${CMAKE_BINARY_DIR}/lib.wasm DESTINATION .)