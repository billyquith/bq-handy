
set(PROJECT_SOURCES
    config.hpp
    
    cyclicbuff.hpp
    vector.hpp
    objectpool.hpp
    
    math.hpp
    math.cpp
    )

include_directories(${PROJECT_SOURCE_DIR}/src
                    ${BQTWOD_EXTERNAL_DIR}/chipmunk/include)

add_definitions(-std=c++11)

add_library(handy STATIC ${PROJECT_SOURCES})

