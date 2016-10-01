
set(APP_NAME handy_test)

set(APP_SOURCES
    main.cpp
    vector.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

add_definitions(-std=c++11)

add_executable(${APP_NAME} ${APP_SOURCES})


