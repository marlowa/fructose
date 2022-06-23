#include "hc_all_of.h"
#include "hc_anything.h"
#include "hc_equal_to.h"
#include "hc_is_not.h"
#include "hc_unittest.h"
#include "matcher_test.h"
#include "UnitTest++.h"

using namespace hamcrest;

SUITE(AllOfTest) {

TEST(EvaluatesToTheTheLogicalConjunctionOfTwoOtherMatchers)
{
    ASSERT_THAT("good", all_of(equal_to("good"), equal_to("good")));
    
    ASSERT_THAT("good", is_not(all_of(equal_to("bad"), equal_to("good"))));
    ASSERT_THAT("good", is_not(all_of(equal_to("good"), equal_to("bad"))));
    ASSERT_THAT("good", is_not(all_of(equal_to("bad"), equal_to("bad"))));
}


TEST(EvaluatesToTheTheLogicalConjunctionOfThreeOtherMatchers)
{
    ASSERT_THAT("good", all_of(equal_to("good"), equal_to("good"), equal_to("good")));
    ASSERT_THAT("good", is_not(all_of(equal_to("good"), equal_to("bad"), equal_to("good"))));
}


TEST(EvaluatesToTheTheLogicalConjunctionOfFourOtherMatchers)
{
    ASSERT_THAT("good", all_of(
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("good")));
    ASSERT_THAT("good", is_not(all_of(
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("bad"),
                                equal_to("good"))));
}


TEST(EvaluatesToTheTheLogicalConjunctionOfFiveOtherMatchers)
{
    ASSERT_THAT("good", all_of(
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("good")));
    ASSERT_THAT("good", is_not(all_of(
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("bad"),
                                equal_to("good"),
                                equal_to("good"))));
}


TEST(EvaluatesToTheTheLogicalConjunctionOfSixOtherMatchers)
{
    ASSERT_THAT("good", all_of(
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("good")));
    ASSERT_THAT("good", is_not(all_of(
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("bad"),
                                equal_to("good"),
                                equal_to("good"),
                                equal_to("good"))));
}


TEST(SupportsMixedTypes)
{
    ASSERT_THAT("good", all_of(anything<const char*>(),
                                equal_to("good")));

    ASSERT_THAT("good", all_of(anything<const char*>(),
                                equal_to("good"),
                                anything<const char*>()));

    ASSERT_THAT("good", all_of(anything<const char*>(),
                                equal_to("good"),
                                anything<const char*>(),
                                equal_to("good")));

    ASSERT_THAT("good", all_of(anything<const char*>(),
                                equal_to("good"),
                                anything<const char*>(),
                                equal_to("good"),
                                anything<const char*>()));
}


TEST(HasAReadableDescription)
{
    ASSERT_DESCRIPTION("(\"good\" and \"bad\" and \"ugly\")",
                        all_of(equal_to("good"), equal_to("bad"), equal_to("ugly")));
}

}	// AllOfTest
