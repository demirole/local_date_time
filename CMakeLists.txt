cmake_minimum_required(VERSION 3.17)
project(boost_local_date_time)

set(CMAKE_CXX_STANDARD 17)

set(CONAN_CMAKE_VERSION 0.15)
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v${CONAN_CMAKE_VERSION}/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake"
                 TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(
        REQUIRES
        date/2.4.1
        boost/1.74.0
        OPTIONS
        date:shared=True
        date:use_system_tz_db=True
        boost:header_only=True
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing
)

add_executable(boost_local_date_time main.cpp)
target_link_libraries(boost_local_date_time CONAN_PKG::date CONAN_PKG::boost)