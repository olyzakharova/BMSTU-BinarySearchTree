#include "catch.hpp"
#include "binary_search_tree.h"

SCENARIO ("if object exist")
{
   GIVEN("object")
   {
       int object=8;
       BinarySearchTree <int> tree{1, 2, 3, 8};
       WHEN("find")
       {   tree.find(object);
           THEN(":)")
           {
               REQUIRE(tree.find(object)!=nullptr);
           }
       }
   }
}

SCENARIO("if object doesn't exist")
{
    GIVEN("object") {
        int object = 150;
        BinarySearchTree<int> tree{1, 2, 3, 4, 5, 6};
        WHEN("not find") {
            tree.find(object);
            THEN(":(") {
                REQUIRE(tree.find(object) == nullptr);
            }
        }
    }
}
SCENARIO("for constant and non-constant")
{
    GIVEN("2 objects:const and non-const")
    {
      BinarySearchTree <int> tree1 {1, 2, 3, 4, 5};
      const BinarySearchTree <int> tree2 {1, 2, 7, 9, 10};
      int object=2;
        WHEN("find")
        {
            tree1.find(object);
            tree2.find(object);
            THEN("ok")
            {
                REQUIRE(tree1.find(object)!=nullptr);
                REQUIRE(tree2.find(object)!=nullptr);
            }
            THEN("not ok")
            {
                REQUIRE(tree1.find(object)==nullptr);
                REQUIRE(tree2.find(object)==nullptr);
            }
        }
            
        }
    }


