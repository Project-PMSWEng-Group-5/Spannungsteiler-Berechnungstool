#include <gtest/gtest.h>
#include "../../include/chooseSeries.h"

TEST(findClosestTest, findClosest_iec1)
{
  EXPECT_DEATH(chooseSeries::findClosest(-20, chooseSeries::E3),
               "negative value");
}
