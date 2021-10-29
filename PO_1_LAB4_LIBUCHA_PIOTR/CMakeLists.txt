cmake_minimum_required (VERSION 2.6)
project (Lab4 CXX)

add_executable(Lab4 main.cpp)

set(LIBSRC include/Funkcje.h src/Funkcje.cpp include/ZlozenieFunkcji.h src/ZlozenieFunkcji.cpp)
add_library(library ${LIBSRC})

target_link_libraries(Lab4 library)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab4 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab4
    DEPENDS Lab4
)