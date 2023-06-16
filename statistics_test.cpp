/** Test cases for functions defined in statistics.h
@file statistics_test.cpp
@author Angel Fuentes
*/

#include "statistics.h"
#include <gtest/gtest.h>
using namespace std;

class StatisticsTest : public ::testing::Test {
 protected:
  int array1[SIZE] = {1, 2, 3};
  int n1 = 3;
  int expected_min1 = 1;
  int expected_max1 = 3;
  int expected_med1 = 2;
  int expected_avg1 = 2;

  int array2[SIZE] = {2, 5, 7, 10};
  int n2 = 4;
  int expected_min2 = 2;
  int expected_max2 = 10;
  int expected_med2 = 6;
  int expected_avg2 = 6;

  int array3[SIZE] = {2, 6, 8, 10};
  int n3 = 4;
  int expected_min3 = 2;
  int expected_max3 = 10;
  int expected_med3 = 7;
  int expected_avg3 = 6;

  int array4[SIZE] = {4, 2, 1, 7, 9};
  int n4 = 5;
  int expected_min4 = 1;
  int expected_max4 = 9;
  int expected_med4 = 4;
  int expected_avg4 = 4;

  int array5[SIZE] = {9, 3, 2, 11, 7};
  int n5 = 5;
  int expected_min5 = 2;
  int expected_max5 = 11;
  int expected_med5 = 7;
  int expected_avg5 = 6;

  // Don't change anything below this comment!
};

#define GENERATE_TEST(f, v, i)                     \
  {                                                \
    sort(array##i, array##i + n##i);               \
    EXPECT_EQ(f(array##i, n##i), expected_##v##i); \
  }

#define GENERATE_TESTS(f, v) \
  {                          \
    GENERATE_TEST(f, v, 1);  \
    GENERATE_TEST(f, v, 2);  \
    GENERATE_TEST(f, v, 3);  \
    GENERATE_TEST(f, v, 4);  \
    GENERATE_TEST(f, v, 5);  \
  }

TEST_F(StatisticsTest, MinimumTest) { GENERATE_TESTS(minimum, min); }

TEST_F(StatisticsTest, MaximumTest) { GENERATE_TESTS(maximum, max); }

TEST_F(StatisticsTest, MedianTest) { GENERATE_TESTS(median, med); }

TEST_F(StatisticsTest, AverageTest) { GENERATE_TESTS(average, avg); }

#define COND(v, i) (v != expected_##v##i)
#define CONDS(i) (COND(min, i) || COND(max, i) || COND(med, i) || COND(avg, i))

#define S1(i)                                            \
  "      Expected: all_stats(array" << i << ", " << n##i \
                                    << ", min, max, med, avg)\n"
#define S2                                                                  \
  "      Which is: min = " << min << ", max = " << max << ", med = " << med \
                           << ", avg = " << avg << "\n"
#define S3_GEN(v, i) "expected_" << #v << i << " = " << expected_##v##i
#define S3(i)                                                            \
  "To be equal to: " << S3_GEN(min, i) << ", " << S3_GEN(max, i) << ", " \
                     << S3_GEN(med, i) << ", " << S3_GEN(avg, i) << "\n"

#define GENERATE_ALLSTATS(i)                             \
  {                                                      \
    min = -1;                                            \
    max = -1;                                            \
    med = -1;                                            \
    avg = -1;                                            \
    all_stats(array##i, n##i, min, max, med, avg);       \
    if (CONDS(i)) ADD_FAILURE() << S1(i) << S2 << S3(i); \
  }

TEST_F(StatisticsTest, AllStatsTest) {
  int min, max, med, avg;

  GENERATE_ALLSTATS(1);
  GENERATE_ALLSTATS(2);
  GENERATE_ALLSTATS(3);
  GENERATE_ALLSTATS(4);
  GENERATE_ALLSTATS(5);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  return 0;
}
