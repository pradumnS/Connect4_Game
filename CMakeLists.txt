cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Connect4)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable generation of compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add main.cpp and all .cpp files from the src folder
set(SOURCES main.cpp)
file(GLOB SRC_FILES src/*.cpp)
list(APPEND SOURCES ${SRC_FILES})

# Include the include directory for headers
include_directories(include)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

#------------------------------------------------------------------------------------------------------
#   you may comment specific part of cmake if not you already have the setup at your system
#------------------------------------------------------------------------------------------------------


#------------------------------------------------------------------------------------------------------
#   GDB setup start
#------------------------------------------------------------------------------------------------------

# Set compiler flags for Debug mode
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Adding debug flags for gdb...")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

######   GDB setup end 

#-----------------------------------------------------------------------------------------------------
#   GTest setup start
#-----------------------------------------------------------------------------------------------------

# Enable testing
enable_testing()

# Include test folder
add_subdirectory(test)

####  GTest setup start  

#------------------------------------------------------------------------------------------------------
#   CPPCheck setup start
#------------------------------------------------------------------------------------------------------

# Find cppcheck
# find_program(CPPCHECK_EXECUTABLE cppcheck)

# if (CPPCHECK_EXECUTABLE)
#     add_custom_target(cppcheck
#         COMMAND ${CPPCHECK_EXECUTABLE}
#                 --enable=all
#                 --inconclusive
#                 --std=c++17
#                 --quiet
#                 --project=${CMAKE_BINARY_DIR}/compile_commands.json
#                 > cppcheck_results.txt
#         WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#         COMMENT "Running Cppcheck on the source code..."
#         VERBATIM
#     )
# else()
#     message(WARNING "Cppcheck not found! Static analysis will not be performed.")
# endif()


####   CPPCheck setup End  


#------------------------------------------------------------------------------------------------------
#   GProf setup start
#------------------------------------------------------------------------------------------------------

# Add profiling flags for gprof (only in Debug or Profiling builds)
# if (CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "Profiling")
#     message(STATUS "Enabling gprof profiling flags.")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
#     set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
# else()
#     message(STATUS "Skipping gprof profiling flags for ${CMAKE_BUILD_TYPE} build.")
# endif()

# # Add a custom target to run gprof and save analysis in the project directory
# add_custom_target(gprof_analysis
#     COMMAND ${CMAKE_BINARY_DIR}/Connect4 && gprof -b ${CMAKE_BINARY_DIR}/Connect4 ${CMAKE_BINARY_DIR}/gmon.out | grep -E "^[[:space:]]*[0-9]+\.[0-9]+[[:space:]]" > ${CMAKE_SOURCE_DIR}/gprofSummary.txt
#     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#     COMMENT "Running gprof and saving summarized analysis to gprofSummary.txt in the project directory..."
#     VERBATIM
# )
######   GProf setup start 