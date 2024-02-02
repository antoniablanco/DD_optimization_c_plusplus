cmake_minimum_required(VERSION 3.27)
project(DD_optimization_program)

set(CMAKE_CXX_STANDARD 20)

set(CLASS_SOURCE
        Class/AnswerStructure/ObjectiveStructure.h
        Class/AnswerStructure/ObjectiveStructure.cpp
        Class/DDBuilder/AbstractDDBuilder.h
        Class/DDBuilder/AbstractDDBuilder.cpp
        Class/DDBuilder/DDBuilder.h
        Class/DDBuilder/DDBuilder.cpp
        Class/DDStructure/Arc.cpp
        Class/DDStructure/Arc.h
        Class/DDStructure/Node.cpp
        Class/DDStructure/Node.h
        Class/DDStructure/Graph.cpp
        Class/DDStructure/Graph.h
        Class/DDStructure/utils.h
        Class/DDStructure/utils.cpp
        Class/GraphVisualization/GraphFile.h
        Class/GraphVisualization/GraphFile.cpp
        Class/ObjectiveFunction/LinearObjectiveDP.h
        Class/ObjectiveFunction/LinearObjectiveDP.cpp
        Class/ObjectiveFunction/ObjectiveFunction.h
        Class/ObjectiveFunction/ObjectiveFunction.cpp
        Class/ObjectiveFunction/AbstractObjective.h
        Class/ObjectiveFunction/AbstractObjective.cpp
        Class/Problems/AbstractProblemClass.cpp
        Class/Problems/AbstractProblemClass.h
        Class/ReduceDDBuilder/ReduceDDBuilder.h
        Class/ReduceDDBuilder/ReduceDDBuilder.cpp
        Class/RestrictedDDBuilder/RestrictedDDBuilder.h
        Class/RestrictedDDBuilder/RestrictedDDBuilder.cpp
        Class/RelaxedDDBuilder/RelaxedDDBuilder.h
        Class/RelaxedDDBuilder/RelaxedDDBuilder.cpp
        Class/DD.h
        Class/DD.cpp
)

set(EXCEPTIONS_SOURCE
        Exceptions/MyExceptions.h
        Exceptions/MyExceptions.cpp)

add_library(Class ${CLASS_SOURCE})
add_library(Exceptions ${EXCEPTIONS_SOURCE})

target_include_directories(Class PUBLIC Class)
target_include_directories(Class PUBLIC Class/AnswerStructure)
target_include_directories(Class PUBLIC Class/DDStructure)
target_include_directories(Class PUBLIC Class/GraphVisualization)
target_include_directories(Class PUBLIC Class/ObjectiveFunction)
target_include_directories(Class PUBLIC Class/Problems)
target_include_directories(Class PUBLIC Class/DDBuilder)
target_include_directories(Class PUBLIC Class/RestrictedDDBuilder)
target_include_directories(Class PUBLIC Class/RelaxedDDBuilder)
target_include_directories(Class PUBLIC Class/ReduceDDBuilder)
target_include_directories(Exceptions PUBLIC Exceptions)

add_executable(Knapsack Examples/Knapsack/KnapsackMain.cpp
        Examples/Knapsack/KnapsackProblem.cpp
        Examples/Knapsack/KnapsackProblem.h)
add_executable(IndependentSet Examples/IndependentSet/IndependentSetMain.cpp)
add_executable(SetCovering Examples/SetCovering/SetCoveringMain.cpp)

target_link_libraries(Knapsack PRIVATE Class)
target_link_libraries(Knapsack PRIVATE Exceptions)
target_link_libraries(IndependentSet PRIVATE Class)
target_link_libraries(SetCovering PRIVATE Class)

target_link_libraries(Class PRIVATE Exceptions)

