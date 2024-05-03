#include <gtest/gtest.h>
#include "data_structures/LinkedList.hpp"

class LinkedListTest : public ::testing::Test {
protected:
  LinkedListTest() {
    list1.insertStart(5);
    list1.insertStart(2);
    list1.insertEnd(7);

    list2.insertEnd(5.0);
  }
  dsa_cpp::LinkedList<int> list1;
  dsa_cpp::LinkedList<float> list2;
  dsa_cpp::LinkedList<int> list3; //stays empty
};

// some test cases for now, add more later
TEST_F(LinkedListTest, GetValTest) {
    EXPECT_EQ(list1.getVal(0), 2);
    EXPECT_EQ(list1.getVal(1), 5);
    EXPECT_EQ(list1.getVal(2), 7);
    EXPECT_THROW(list1.getVal(-1), std::out_of_range);
    EXPECT_THROW(list1.getVal(20), std::out_of_range);
    EXPECT_THROW(list3.getVal(0), std::out_of_range);
}
