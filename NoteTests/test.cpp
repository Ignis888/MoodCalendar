#include "pch.h"
#include "gtest/gtest.h"						
#include "../NoteClass.cpp"

class NoteClassTest : public::testing::Test
{
	public:
	NoteClass NC;
};
TEST_F(NoteClassTest, TestName) {
//	NC.inc();
	
  EXPECT_EQ(NC.var, 0);
  NC.inc();
  EXPECT_EQ(NC.var, 1);
}