#include "hc_is.h"
#include "matcher_test.h"
#include "UnitTest++.h"

using namespace hamcrest;

SUITE(IsTest) {

TEST(JustMatchesTheSameWayTheUnderylingMatcherDoes)
{
    ASSERT_MATCHES(true, is(equal_to(true)));
    ASSERT_MATCHES(false, is(equal_to(false)));
    ASSERT_DOES_NOT_MATCH(false, is(equal_to(true)));
    ASSERT_DOES_NOT_MATCH(true, is(equal_to(false)));
}


TEST(GeneratesIsPrefixInDescription)
{
    ASSERT_DESCRIPTION("is <true>", is(equal_to(true)));
}


TEST(ProvidesConvenientShortcutForEqualTo)
{
    ASSERT_MATCHES("A", is("A"));
    ASSERT_MATCHES("B", is("B"));
    ASSERT_DOES_NOT_MATCH("B", is("A"));
    ASSERT_DOES_NOT_MATCH("A", is("B"));
    ASSERT_DESCRIPTION("is \"A\"", is("A"));
}

}	// IsTest
