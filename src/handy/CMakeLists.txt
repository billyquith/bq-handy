
set(LIB_NAME bqutil) # misc

set(PROJECT_SOURCES
    config.hpp
    
    cyclicbuff.hpp
    vector.hpp
    objectpool.hpp
    
    bqmath.hpp
    bqmath.cpp
    )

#source_group("Twod" REGULAR_EXPRESSION ".*")

include_directories(${PROJECT_SOURCE_DIR}/src
                    ${BQTWOD_EXTERNAL_DIR}/chipmunk/include)

add_definitions(-std=c++11)

add_library(${LIB_NAME} STATIC ${PROJECT_SOURCES})

