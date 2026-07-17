find_package(Boost CONFIG REQUIRED COMPONENTS unit_test_framework)

add_executable(type_index
        type_index.cpp
)
target_include_directories(type_index PRIVATE /opt/homebrew/opt/boost/include)

enable_testing()

add_executable(bootest
        boost_tests.cpp
        intervals.h
        heap.h
        trie.cpp
        trie.h
)

# clang++ -DBOOST_TEST_DYN_LINK boost_tests.cpp -lboost_unit_test_framework
target_compile_definitions(bootest PRIVATE BOOST_TEST_DYN_LINK)

target_link_libraries(bootest
        PRIVATE
        Boost::unit_test_framework
)

add_test(NAME my_boost_tests COMMAND bootest)