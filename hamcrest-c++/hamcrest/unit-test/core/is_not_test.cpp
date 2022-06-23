#include "hc_is_not.h"
#include "matcher_test.h"
#include "UnitTest++.h"

using namespace hamcrest;

SUITE(IsNotTest) {

TEST(EvaluatesToTheTheLogicalNegationOfAnotherMatcher)
{
    ASSERT_MATCHES("B", is_not(equal_to("A")));
    ASSERT_DOES_NOT_MATCH("B", is_not(equal_to("B")));
}


TEST(ProvidesConvenientShortcutForNotEqualTo)
{
    ASSERT_MATCHES("B", is_not("A"));
    ASSERT_MATCHES("A", is_not("B"));
    ASSERT_DOES_NOT_MATCH("A", is_not("A"));
    ASSERT_DOES_NOT_MATCH("B", is_not("B"));
}


TEST(HasAReadableDescription)
{
    ASSERT_DESCRIPTION("not \"A\"", is_not("A"));
}

}	// IsNotTest
