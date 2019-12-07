#include <gtest/gtest.h>
#include "../../include/evaluateResistor.h"

/*TEST(findClosestTest, findClosest_iec1)
{
  EXPECT_DEATH(evaluateResistor::findClosest(-20, evaluateResistor::E3),
               "negative value");
}*/

TEST(findClosestTest, findClosest_vec1)
{
  EXPECT_EQ(evaluateResistor::findClosest(3.5, evaluateResistor::E6), 3.3);
}
