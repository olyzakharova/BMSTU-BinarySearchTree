#include "catch.hpp"
#include "binary_search_tree.h"

SCENARIO ("delete main root")
{
    GIVEN ("root")
    {
        BinarySearchTree<int> tree1  {5, 2, 8, 12, 4, 7};
        BinarySearchTree<int> tree2  {2, 8, 12, 4, 7};
        WHEN("delete")
        {
            tree1.remove(5);
            THEN ("was deleted")
            {
                REQUIRE(tree1==tree2);
            }
        }
    }
}
SCENARIO ("hasn't sons")
{
    GIVEN("node")
    {
        BinarySearchTree<int> tree1  {5, 2, 8, 12, 4, 7};
        BinarySearchTree<int> tree2  {5, 2, 8, 12, 4};
        WHEN("delete node")
        {
            tree1.remove(7);
            THEN("was deleted")
            {
                REQUIRE(tree1 ==tree2);
            }

        }
    }

}
SCENARIO ("only left son")
{
    GIVEN("node")
    {
        BinarySearchTree<int> tree1  {5, 2, 8, 12, 4, 7};
        BinarySearchTree<int> tree2  {5, 8, 12, 4, 7};
        WHEN("delete node")
        {
        tree1.remove(2);
        THEN("was deleted")
        {
            REQUIRE(tree1 == tree2);
        }
        }
    }

}
SCENARIO ("only right son")
{
    GIVEN("node")
    {
        BinarySearchTree<int> tree1  {5, 2, 8, 12, 4, 7};
        BinarySearchTree<int> tree2  {5, 2, 12, 4, 7};
        WHEN("delete node")
        {
            tree1.remove(8);
            THEN("If it was deleted")
            {
                REQUIRE(tree1==tree2);
            }
        }
    }
}
SCENARIO("both sons")
{
     BinarySearchTree<int> tree1  {5, 2, 8, 12, 4, 7};
     BinarySearchTree<int> tree2  {5, 2, 12, 4, 7};
    WHEN("delete node")
    {
        tree1.remove(8);
        THEN("was deleted")
        {
            REQUIRE(tree1==tree2);
        }
    }

}
SCENARIO("If we want to delete non existent node")
{
    BinarySearchTree<int> tree  {5, 2, 8, 12, 4, 7};
    WHEN("delete node")
    {
        tree.remove(34);
        auto curr_size=tree.size();
        THEN("it's not in the tree")
        {
            REQUIRE(tree.size()==curr_size);
        }
    }
}
