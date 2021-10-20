cmake_minimum_required(VERSION 3.0.0)
project(cherokee VERSION 0.1.0)

include(CTest)
enable_testing()

set(SERVER_DIR ./src)
set(INCLUDE_DIR ./includes)
set(WORKER_DIR ${SERVER_DIR}/worker)
set(UTILS_DIR ${SERVER_DIR}/utils)
set(EXCEPTION_DIR ${SERVER_DIR}/exceptions)

set(SOURCES
    ${SERVER_DIR}/server/server.cpp
)

# add boost lib
set(Boost_INCLUDE_DIR /usr/local/boost_1_75_0)
set(Boost_LIBRARY_DIR /usr/local/boost_1_75_0/stage/lib)
find_package(Boost)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
link_directories(${Boost_LIBRARY_DIR})

include_directories(${SERVER_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${UTILS_DIR})
include_directories(${EXCEPTION_DIR})
include_directories(.)

add_executable(cherokee ${SOURCES} ${SERVER_DIR}/cherokee.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
