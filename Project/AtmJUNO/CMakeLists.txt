CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
#porject name 
PROJECT(AtmJUNO CXX C)
add_compile_options(-O2)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

#--
#Set ROOT
#--
find_package(ROOT REQUIRED COMPONENTS MathCore RIO Hist Tree Net RooStats)
if(ROOT_FOUND)
    message("ROOT FOUND")
    include(${ROOT_USE_FILE})
    include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
    add_definitions(${ROOT_CXX_FLAGS})
endif()
#--
#Set omp
#--
FIND_PACKAGE( OpenMP REQUIRED)
#if(OPENMP_FOUND)
#    message("OPENMP FOUND")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS} -lfftw3")
#endif()
#--
#Set GSL
#--
#FIND_PACKAGE( GSL REQUIRED)
#if(GSL_FOUND)
#    message("GSL FOUND")
#endif()

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
# target_include_directories()

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc ${PROJECT_SOURCE_DIR}/src/*.c)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh ${PROJECT_SOURCE_DIR}/include/*.h)

ROOT_GENERATE_DICTIONARY(AtmJUNO.hh LINKDEF Link.hh)

add_library(AtmJUNOlib SHARED AtmJUNO.cc ${sources} ${headers})
target_link_libraries(AtmJUNOlib ${ROOT_LIBRARIES} )


# Add the executable, link it to the lib
add_executable(AtmJUNO AtmJUNO.cc ${sources})
target_link_libraries(AtmJUNO AtmJUNOlib)