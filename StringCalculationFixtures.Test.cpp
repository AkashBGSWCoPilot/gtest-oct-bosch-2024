#include "StringCalculator.h"
#include <gtest/gtest.h>

//Fixture Class

class StringCalculatorAddFixture:public testing::Test{
  protected:
    StringCalculator *objUnderTest;
  void SetUp() override {
      objUnderTest=new StringCalculator();
  }
  void TearDown(){
        delete objUnderTest;
  }
};

TEST_F(StringCalculatorAddFixture, Returns_0_For_Empty){
    string input="";
    int expectedValue=0;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture, Returns_0_For_0){
    string input="0";
    int expectedValue=0;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture, returns_1_for_one){
    string input="1";
    int expectedValue=1;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture, two_comma_numbers_returns_their_sum){
    string input="1,2";
    int expectedValue=3;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  multiple_comma_numbers_returns_their_sum){
    string input="2,3,4";
    int expectedValue=9;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  newline_and_comma_returns_their_sum){
    string input="1\n2,3";
    int expectedValue=6;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  delimiter_returns_the_sum_based_on_that_delimiter){
    string input="//;\n1;2";
    int expectedValue=3;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  numbers_over_1000_ignore){
    string input="37,1456,6";
    int expectedValue=43;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
