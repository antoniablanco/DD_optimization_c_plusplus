cmake_minimum_required(VERSION 3.27)
project(DD_optimization_program)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

set(CLASS_SOURCE
        Class/AnswerStructure/ObjectiveStructure.tpp
        Class/AnswerStructure/ObjectiveStructure.h
        Class/DDBuilder/AbstractDDBuilder.tpp
        Class/DDBuilder/AbstractDDBuilder.h
        Class/DDBuilder/DDBuilder.tpp
        Class/DDBuilder/DDBuilder.h
        Class/DDStructure/Arc.tpp
        Class/DDStructure/Arc.h
        Class/DDStructure/Node.tpp
        Class/DDStructure/Node.h
        Class/DDStructure/Graph.tpp
        Class/DDStructure/Graph.h
        Class/DDStructure/Graph.tpp
        Class/DDStructure/Graph.h
        Class/DDStructure/utils.h
        Class/DDStructure/utils.cpp
        Class/GraphVisualization/GraphFile.tpp
        Class/GraphVisualization/GraphFile.h
        Class/ObjectiveFunction/AbstractObjective.tpp
        Class/ObjectiveFunction/AbstractObjective.h
        Class/ObjectiveFunction/LinearObjectiveDP.tpp
        Class/ObjectiveFunction/LinearObjectiveDP.h
        Class/ObjectiveFunction/ObjectiveFunction.tpp
        Class/ObjectiveFunction/ObjectiveFunction.h
        Class/Problems/AbstractProblemClass.tpp
        Class/Problems/AbstractProblemClass.h
        Class/ReduceDDBuilder/ReduceDDBuilder.tpp
        Class/ReduceDDBuilder/ReduceDDBuilder.h
        Class/RelaxedDDBuilder/RelaxedDDBuilder.tpp
        Class/RelaxedDDBuilder/RelaxedDDBuilder.h
        Class/RestrictedDDBuilder/RestrictedDDBuilder.tpp
        Class/RestrictedDDBuilder/RestrictedDDBuilder.h
        Class/DD.tpp
        Class/DD.h
)

set(EXCEPTIONS_SOURCE
        Exceptions/MyExceptions.h
        Exceptions/MyExceptions.cpp)

set(PROBLEMS_SOURCE
        Examples/Knapsack/KnapsackProblem.h
        Examples/Knapsack/KnapsackProblem.cpp
        Examples/IndependentSet/IndependentSetProblem.cpp
        Examples/IndependentSet/IndependentSetProblem.h
        Examples/SetCovering/SetCoveringProblem.cpp
        Examples/SetCovering/SetCoveringProblem.h)

add_library(Exceptions ${EXCEPTIONS_SOURCE})
add_library(Problems ${PROBLEMS_SOURCE})
add_library(Class ${CLASS_SOURCE})

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
target_include_directories(Exceptions PUBLIC Exceptions)
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
target_link_libraries(Problems PRIVATE Class Exceptions)

add_executable(DD_optimization_program_tests
        Test/test_ProblemKnapsack.cpp
        Test/test_ProblemIndependentSet.cpp
        Test/test_ProblemSetCovering.cpp
)
target_link_libraries(DD_optimization_program_tests PRIVATE
        Class
        Exceptions
        gtest_main
        Problems)

include(GoogleTest)
gtest_discover_tests(DD_optimization_program_tests)