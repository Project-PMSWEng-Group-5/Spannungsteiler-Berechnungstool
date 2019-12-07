#include <float.h>  //DBL_MAX
#include <gtest/gtest.h>
#include "../../include/evaluateResistor.h"

TEST(findClosestTest, findClosest_iec1)
{
  EXPECT_DEATH(
      evaluateResistor::findClosest(-DBL_MAX, evaluateResistor::E3),
      ".*evaluateResistor::findClosest.*Assertion `value > 0' failed.*");
}

TEST(findClosestTest, findClosest_iec2)
{
  EXPECT_DEATH(
      evaluateResistor::findClosest(-1, evaluateResistor::E3),
      ".*evaluateResistor::findClosest.*Assertion `value > 0' failed.*");
}

TEST(findClosestTest, findClosest_iec3)
{
  EXPECT_DEATH(
      evaluateResistor::findClosest(0, evaluateResistor::E3),
      ".*evaluateResistor::findClosest.*Assertion `value > 0' failed.*");
}

TEST(findClosestTest, findClosest_iec4)
{
  EXPECT_DEATH(
      evaluateResistor::findClosest(DBL_MAX / 100, evaluateResistor::E3),
      ".*evaluateResistor::findClosest.*Assertion `value < DBL_MAX / "
      "100' failed.*");
}

TEST(findClosestTest, findClosest_vec1)
{
  EXPECT_EQ(evaluateResistor::findClosest(1, evaluateResistor::E6), 1);
}

TEST(findClosestTest, findClosest_vec2)
{
  EXPECT_EQ(evaluateResistor::findClosest(42, evaluateResistor::E24), 43);
}

// probably not border case, but it would be a PitA to find the exact value
TEST(findClosestTest, findClosest_vec3)
{
  EXPECT_EQ(
      evaluateResistor::findClosest(DBL_MAX / 1000, evaluateResistor::E12),
      1.8e+305);
}
