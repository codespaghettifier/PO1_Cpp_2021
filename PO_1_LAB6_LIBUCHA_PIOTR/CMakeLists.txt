cmake_minimum_required (VERSION 2.6)
project (Lab6 CXX)

add_executable(Lab6 main.cpp)

set(LIBSRC include/Primitive.h src/Primitive.cpp include/Product.h src/Product.cpp include/Ratio.h src/Ratio.cpp include/Sum.h src/Sum.cpp)
add_library(library ${LIBSRC})

target_link_libraries(Lab6 library)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab6 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab6
    DEPENDS Lab6
)