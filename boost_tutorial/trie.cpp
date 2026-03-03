//
// Created by Pedro's Jet on 3/3/2026.
//

#include "trie.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example0) {
    auto t = Trie();
    t.insert("apple");
    BOOST_TEST(t.search("apple"));
    BOOST_TEST(!t.search("app"));
    BOOST_TEST(t.startsWith("app"));
    t.insert("app");
    BOOST_TEST(t.search("app"));
}