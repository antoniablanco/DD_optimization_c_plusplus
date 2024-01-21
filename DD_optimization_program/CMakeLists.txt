cmake_minimum_required(VERSION 3.27)
project(DD_optimization_program)

set(CMAKE_CXX_STANDARD 20)


set(CLASS_SOURCE
        Class/DDStructure/Arc.cpp
        Class/DDStructure/Arc.h
        Class/DDStructure/Node.cpp
        Class/DDStructure/Node.h
        Class/DDStructure/Graph.cpp
        Class/DDStructure/Graph.h
        Class/DDStructure/utils.h
        Class/DDStructure/utils.cpp
        Class/Problems/AbstractProblemClass.cpp
        Class/Problems/AbstractProblemClass.h
)

add_library(Class ${CLASS_SOURCE})

target_include_directories(Class PUBLIC Class/DDStructure)

add_executable(Knapsack Examples/Knapsack/KnapsackMain.cpp
        Examples/Knapsack/KnapsackProblem.cpp
        Examples/Knapsack/KnapsackProblem.h)
add_executable(IndependentSet Examples/IndependentSet/IndependentSetMain.cpp)
add_executable(SetCovering Examples/SetCovering/SetCoveringMain.cpp)

target_link_libraries(Knapsack PRIVATE Class)
target_link_libraries(IndependentSet PRIVATE Class)
target_link_libraries(SetCovering PRIVATE Class)

