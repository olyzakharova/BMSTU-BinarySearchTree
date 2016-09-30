//
#include "catch.hpp"
#include "binary_search_tree.h"

SCENARIO ("Size of empty tree must be 0") 
{
    GIVEN ("empty tree")
    {
        BinarySearchTree<int> tree;
                
                        WHEN("decide size")
                        {
                            THEN("size must be 0") 
                            {
                                REQUIRE(tree.size() == 0);
                            }
                        }
                
    }
}
SCENARIO ("Size of empty tree mustn't be 0")
{
    GIVEN ("not empty tree") 
    {
        BinarySearchTree <int> tree {2, 4, 6};
                
                        WHEN("decide size")
                        {
                            THEN("size mustn't be 0")
                            {
                                REQUIRE(tree.size() != 0);
                            }
                        }
                
    }
}

SCENARIO (" for constant tree and non-constant tree ")
{
    GIVEN("2 trees: constant and non-constant")
    {
        BinarySearchTree<int> tree1{1, 3, 7};
        const BinarySearchTree<int> tree{2, 4, 6};
        WHEN ("compare sizes")
        {
            THEN("sizes must be equal")
            {
                REQUIRE(tree1.size() == tree2.size());
            }
        }
    }
}
