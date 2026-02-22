find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(type_index
        type_index.cpp
)

enable_testing()

add_executable(bootest
        m_test.cpp
)


target_compile_definitions(bootest PRIVATE BOOST_TEST_DYN_LINK)

target_link_libraries(bootest
        PRIVATE
        Boost::unit_test_framework
)

target_include_directories(type_index
        PRIVATE
        /opt/homebrew/opt/boost/include
)

add_test(NAME my_boost_tests COMMAND bootest)