cmake_minimum_required(VERSION 3.10)

project(BitcoinExchange)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES
        main.cpp
        BitcoinExchange.cpp
)

add_executable(BitcoinExchange ${SOURCE_FILES})

# You can uncomment the following line if you have header files
# target_include_directories(BitcoinExchange PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# You may want to uncomment the following lines if you have additional dependencies
# find_package(YourDependency REQUIRED)
# target_link_libraries(BitcoinExchange PRIVATE YourDependency)
