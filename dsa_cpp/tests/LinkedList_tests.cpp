#include <gtest/gtest.h>
#include "data_structures/LinkedList.hpp"

class LinkedListTest : public ::testing::Test {
protected:
  void SetUp() override {
    list1.insertStart(5);
    list1.insertStart(2);
    list1.insertEnd(7);

    list2.insertEnd(5.0);

    list4.insertStart(5);
    list4.insertStart(4);
    list4.insertStart(3);
    list4.insertStart(2);
    list4.insertStart(1);
  }

  dsa_cpp::LinkedList<int> list1;
  dsa_cpp::LinkedList<float> list2;
  dsa_cpp::LinkedList<float> list3; //stays empty
  dsa_cpp::LinkedList<int> list4;
};

TEST_F(LinkedListTest, GetValTest) {
  EXPECT_EQ(list1.getVal(0), 2);
  EXPECT_EQ(list1.getVal(1), 5);
  EXPECT_EQ(list1.getVal(2), 7);
  EXPECT_THROW(list1.getVal(-1), std::out_of_range);
  EXPECT_THROW(list1.getVal(20), std::out_of_range);
  EXPECT_THROW(list3.getVal(0), std::out_of_range);
}

TEST_F(LinkedListTest, GetSizeTest) {
  EXPECT_EQ(list4.getSize(), 5);
  EXPECT_EQ(list3.getSize(), 0);
  EXPECT_EQ(list2.getSize(), 1);
  EXPECT_EQ(list1.getSize(), 3);
}

TEST_F(LinkedListTest, InsertTest) {
  EXPECT_EQ(list3.getSize(), 0);

  list3.insertEnd(5);
  EXPECT_EQ(list3.getVal(0), 5.0);
  list3.insertEnd(20);
  EXPECT_EQ(list3.getVal(1), 20.0);
  list3.insertStart(17.0);
  EXPECT_EQ(list3.getVal(0), 17.0);
  list3.insertStart(1);
  EXPECT_EQ(list3.getVal(0), 1.0);
  EXPECT_EQ(list3.getSize(), 4);

  EXPECT_EQ(list3.getVal(0), 1.0);
  EXPECT_EQ(list3.getVal(1), 17.0);
  EXPECT_EQ(list3.getVal(2), 5.0);
  EXPECT_EQ(list3.getVal(3), 20.0);
}

TEST_F(LinkedListTest, RemoveTest) {
  EXPECT_EQ(list4.getSize(), 5);

  //remove from middle
  list4.remove(2);
  EXPECT_EQ(list4.getVal(0), 1);
  EXPECT_EQ(list4.getVal(1), 2);
  EXPECT_EQ(list4.getVal(2), 4);
  EXPECT_EQ(list4.getSize(), 4);
  EXPECT_THROW(list4.getVal(4), std::out_of_range);

  //remove from head
  list4.remove(0);
  EXPECT_EQ(list4.getVal(0), 2);
  EXPECT_EQ(list4.getSize(), 3);

  //remove from tail
  list4.remove(2);
  EXPECT_EQ(list4.getVal(1), 4);
  EXPECT_EQ(list4.getSize(), 2);
}



