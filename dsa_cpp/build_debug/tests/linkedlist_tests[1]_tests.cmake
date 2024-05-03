add_test([=[LinkedListTest.GetValTest]=]  /home/apollo/cpp-data-structures-algorithms/dsa_cpp/build_debug/tests/linkedlist_tests [==[--gtest_filter=LinkedListTest.GetValTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[LinkedListTest.GetValTest]=]  PROPERTIES WORKING_DIRECTORY /home/apollo/cpp-data-structures-algorithms/dsa_cpp/build_debug/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  linkedlist_tests_TESTS LinkedListTest.GetValTest)
