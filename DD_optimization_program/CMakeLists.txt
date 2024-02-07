cmake_minimum_required(VERSION 3.27)
project(DD_optimization_program)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/googletest)

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

set(PROBLEMS_SOURCE
        Examples/Knapsack/KnapsackProblem.h
        Examples/Knapsack/KnapsackProblem.cpp
        Examples/IndependentSet/IndependentSetProblem.h
        Examples/IndependentSet/IndependentSetProblem.cpp
        Examples/SetCovering/SetCoveringProblem.h
        Examples/SetCovering/SetCoveringProblem.cpp)

add_library(Class ${CLASS_SOURCE})
add_library(Exceptions ${EXCEPTIONS_SOURCE})
add_library(Problems ${PROBLEMS_SOURCE})

target_include_directories(Class
    PUBLIC
    Class
    Class/AnswerStructure
    Class/DDStructure
    Class/GraphVisualization
    Class/ObjectiveFunction
    Class/Problems
    Class/DDBuilder
    Class/RestrictedDDBuilder
    Class/RelaxedDDBuilder
    Class/ReduceDDBuilder
)

target_include_directories(Exceptions 
        PUBLIC 
        Exceptions)
target_include_directories(Problems PUBLIC Problems)

add_executable(Knapsack Examples/Knapsack/KnapsackMain.cpp
        Examples/Knapsack/KnapsackProblem.cpp
        Examples/Knapsack/KnapsackProblem.h)
add_executable(IndependentSet Examples/IndependentSet/IndependentSetMain.cpp
        Examples/IndependentSet/IndependentSetProblem.h
        Examples/IndependentSet/IndependentSetProblem.cpp)
add_executable(SetCovering Examples/SetCovering/SetCoveringMain.cpp
        Examples/SetCovering/SetCoveringProblem.cpp
        Examples/SetCovering/SetCoveringProblem.h)

target_link_libraries(Knapsack PRIVATE Class Exceptions)
target_link_libraries(IndependentSet PRIVATE Class Exceptions)
target_link_libraries(SetCovering PRIVATE Class Exceptions)
target_link_libraries(Class PRIVATE Exceptions)
target_link_libraries(Problems PRIVATE Class Exceptions)

add_executable(DD_optimization_program_tests
    Test/test_ProblemKnapsack.cpp
)
target_link_libraries(DD_optimization_program_tests PRIVATE 
                        Class 
                        Exceptions 
                        gtest_main 
                        Problems)

include(GoogleTest)
gtest_discover_tests(DD_optimization_program_tests)

