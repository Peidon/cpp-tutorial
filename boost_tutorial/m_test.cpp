
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

void test(const int n)
{
  if (n == 42) {
    return;
  }
  throw std::runtime_error(
    "Not the answer");
}

// clang++ -DBOOST_TEST_DYN_LINK m_test.cpp -lboost_unit_test_framework
BOOST_AUTO_TEST_CASE(my_test)
{
  BOOST_TEST_MESSAGE("Testing");
  int i = 1;
  BOOST_TEST(i); 
  BOOST_TEST(i == 2);
  BOOST_CHECK_THROW(
    test(41), std::runtime_error);
  BOOST_CHECK_NO_THROW(test(42));

  int expected = 5;
  BOOST_TEST((2 + 3) == expected);
  BOOST_CHECK((2 + 3) == expected);
}

BOOST_AUTO_TEST_CASE(null_test)
{
}