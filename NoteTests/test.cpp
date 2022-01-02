#include "pch.h"
#include "gtest/gtest.h"						
#include "../NoteClass.cpp"
#include "../ClassSdl.cpp"

#include <SDL.h>
/*
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
*/

ClassSdl sdlC;
TEST(Test, TestName) {

	sdlC.Error("a","12",0);
	EXPECT_EQ(sdlC.errorfileTestsring, "a 12");
}