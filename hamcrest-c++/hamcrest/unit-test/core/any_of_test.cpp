#include "hc_any_of.h"
#include "hc_anything.h"
#include "hc_equal_to.h"
#include "hc_is_not.h"
#include "hc_unittest.h"
#include "matcher_test.h"
#include "UnitTest++.h"

using namespace hamcrest;

SUITE(AnyOfTest) {

TEST(EvaluatesToTheTheLogicalDisjunctionOfTwoOtherMatchers)
{
    ASSERT_THAT("good", any_of(equal_to("good"), equal_to("good")));
    ASSERT_THAT("good", any_of(equal_to("bad"), equal_to("good")));
    ASSERT_THAT("good", any_of(equal_to("good"), equal_to("bad")));

    ASSERT_THAT("good", is_not(any_of(equal_to("bad"), equal_to("bad"))));
}


TEST(EvaluatesToTheTheLogicalDisjunctionOfThreeOtherMatchers)
{
    ASSERT_THAT("good", any_of(equal_to("bad"), equal_to("good"), equal_to("bad")));
    ASSERT_THAT("good", is_not(any_of(equal_to("bad"), equal_to("bad"), equal_to("bad"))));
}


TEST(EvaluatesToTheTheLogicalDisjunctionOfFourOtherMatchers)
{
    ASSERT_THAT("good", any_of(
                                equal_to("bad"),
                                equal_to("good"),
                                equal_to("bad"),
                                equal_to("bad")));
    ASSERT_THAT("good", is_not(any_of(
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("bad"))));
}


TEST(EvaluatesToTheTheLogicalDisjunctionOfFiveOtherMatchers)
{
    ASSERT_THAT("good", any_of(
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("good"),
                                equal_to("bad"),
                                equal_to("bad")));
    ASSERT_THAT("good", is_not(any_of(
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("bad"))));
}


TEST(EvaluatesToTheTheLogicalDisjunctionOfSixOtherMatchers)
{
    ASSERT_THAT("good", any_of(
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("good"),
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("bad")));
    ASSERT_THAT("good", is_not(any_of(
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("bad"),
                                equal_to("bad"))));
}


TEST(SupportsMixedTypes)
{
    ASSERT_THAT("good", any_of(anything<const char*>(),
                                equal_to("good")));

    ASSERT_THAT("good", any_of(anything<const char*>(),
                                equal_to("good"),
                                anything<const char*>()));

    ASSERT_THAT("good", any_of(anything<const char*>(),
                                equal_to("good"),
                                anything<const char*>(),
                                equal_to("good")));

    ASSERT_THAT("good", any_of(anything<const char*>(),
                                equal_to("good"),
                                anything<const char*>(),
                                equal_to("good"),
                                anything<const char*>()));
}


TEST(HasAReadableDescription)
{
    ASSERT_DESCRIPTION("(\"good\" or \"bad\" or \"ugly\")",
                        any_of(equal_to("good"), equal_to("bad"), equal_to("ugly")));
}

}	// AnyOfTest
