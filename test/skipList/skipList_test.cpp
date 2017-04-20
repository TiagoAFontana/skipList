#include "../catch.hpp"
#include "../../src/skiplist.h"

TEST_CASE("A","[A]"){

    // 1.Initialize an empty Skip_list object
    SkipList s;

    // 2. insert()
    for (int i = 0; i < 50; ++i){
        s.insert(i);
    }

    // 2a. print()
    s.print();

    s.erase(15);
    s.erase(30);
    s.erase(45);

    s.print();

	REQUIRE(true);
}
