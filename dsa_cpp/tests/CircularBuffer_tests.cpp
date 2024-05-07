#include <gtest/gtest.h>
#include "data_structures/CircularBuffer.hpp"

class CircularBufferTest : public ::testing::Test {
protected:
  void SetUp() override {
    buffer1.push(1);
    buffer1.push(2);
    buffer1.push(3);
    buffer1.push(4);
    buffer1.push(5);

    buffer2.push(1.0);
    buffer2.push(2.0);
  }

  dsa_cpp::CircularBuffer<int, 5> buffer1;
  dsa_cpp::CircularBuffer<float, 4> buffer2;
  dsa_cpp::CircularBuffer<int, 3> buffer3; //stays empty

};

TEST_F(CircularBufferTest, PushPopTest) {
    EXPECT_EQ(buffer3.getSize(), 0);

    buffer3.push(1);
    buffer3.push(2);
    buffer3.push(3);
    EXPECT_EQ(buffer3.getSize(), 3);

    EXPECT_EQ(buffer3.pop(), 1);
    EXPECT_EQ(buffer3.pop(), 2);
    EXPECT_EQ(buffer3.pop(), 3);
    EXPECT_EQ(buffer3.getSize(), 0);
}


TEST_F(CircularBufferTest, PopOnEmptyBufferRaisesError) {
    EXPECT_EQ(buffer2.pop(), 1.0);
    EXPECT_EQ(buffer2.pop(), 2.0);
    EXPECT_THROW(buffer2.pop(), std::out_of_range);
}

TEST_F(CircularBufferTest, PushToFullBufferDiscardsOldestValue) {
    buffer1.push(20);
    buffer1.push(30);
    EXPECT_EQ(buffer1.getSize(), 5);
    
    EXPECT_EQ(buffer1.pop(), 3);
    EXPECT_EQ(buffer1.pop(), 4);
    EXPECT_EQ(buffer1.pop(), 5);
    EXPECT_EQ(buffer1.pop(), 20);
    EXPECT_EQ(buffer1.pop(), 30);
    
}



