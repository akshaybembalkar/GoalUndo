/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"
 
class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(GoalUndoTest, ChechEmpty_Goal)
{
	GoalUndo goal;
	ASSERT_EQ("",goal.getGoal());
}

TEST(GoalUndoTest, undoEmptyGoal)
{
	GoalUndo goal;
	goal.undoGoal();
	ASSERT_EQ("",goal.getGoal());
}


TEST(GoalUndoTest, ChechEmpty_Operation)
{
	GoalUndo goal;
	goal.addOperation("");
	goal.addOperation("","");
	goal.addOperation("","Square");
	goal.addOperation("Triangle","");
	ASSERT_EQ("",goal.getOperations());
}

TEST(GoalUndoTest, addNewGoal)
{
	GoalUndo goal;
	goal.addOperation("Square");
	goal.addOperation("Triangle");
	ASSERT_EQ("Square",goal.getGoal());
}


TEST(GoalUndoTest, addNewOperation)
{
	GoalUndo goal;
	goal.addOperation("Square");
	goal.addOperation("Square","drawHorizontal");
	goal.addOperation("Triangle");
	std::string str = "drawHorizontal Triangle";
	ASSERT_EQ(str,goal.getOperations());
}

TEST(GoalUndoTest, undoOperation)
{
	GoalUndo goal;
	goal.undoOperation();
	goal.addOperation("Square","drawHorizontal");
	goal.undoOperation();
	goal.addOperation("Triangle","drawHorizontal");
	goal.addOperation("drawVertical");
	goal.undoOperation();
	goal.undoOperation();
	ASSERT_EQ("",goal.getGoal());
}

TEST(GoalUndoTest, undoOperation_parameterised)
{
	GoalUndo goal;
	goal.undoOperation("Square");
	goal.addOperation("Square");
	goal.addOperation("Square","drawHorizontal");
	goal.addOperation("Square","Square");
	goal.undoOperation("Triangle");
	goal.addOperation("Triangle");
	goal.undoOperation("Square");
	ASSERT_EQ("Triangle",goal.getOperations());
}


