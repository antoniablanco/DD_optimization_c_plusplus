add_test([=[ProblemKnapsackTest.TestOrderedVariables]=]  /Users/antoniablanco/Desktop/DD_optimization_c-/DD_optimization_program/cmake-build-debug/DD_optimization_program_tests [==[--gtest_filter=ProblemKnapsackTest.TestOrderedVariables]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ProblemKnapsackTest.TestOrderedVariables]=]  PROPERTIES WORKING_DIRECTORY /Users/antoniablanco/Desktop/DD_optimization_c-/DD_optimization_program/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[ProblemKnapsackTest.TestVariablesDomain]=]  /Users/antoniablanco/Desktop/DD_optimization_c-/DD_optimization_program/cmake-build-debug/DD_optimization_program_tests [==[--gtest_filter=ProblemKnapsackTest.TestVariablesDomain]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ProblemKnapsackTest.TestVariablesDomain]=]  PROPERTIES WORKING_DIRECTORY /Users/antoniablanco/Desktop/DD_optimization_c-/DD_optimization_program/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  DD_optimization_program_tests_TESTS ProblemKnapsackTest.TestOrderedVariables ProblemKnapsackTest.TestVariablesDomain)