#include "doctest.h"
#include <iostream>
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

TEST_CASE("chack")
{
    BinaryTree<int> t;
    int root = rand() % 100;
    CHECK_NOTHROW(t.add_root(root));
    int child;
    for (int i = 0; i < 20; i++)
    {
        child = rand();
        if (i % 2 == 0)
        {
            CHECK_NOTHROW(t.add_left(root, child));
        }
        else
        {
            CHECK_NOTHROW(t.add_right(root, child));
        }
        root = child;
    }
}