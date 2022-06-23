#include "hc_anything.h"
#include "hc_unittest.h"
#include "matcher_test.h"
#include "UnitTest++.h"

using namespace hamcrest;

SUITE(AnythingTest) {

TEST(AlwaysEvaluatesToTrue)
{
    ASSERT_THAT(42, anything<int>());
    ASSERT_THAT("hi", anything<const char*>());
}


TEST(HasUsefulDefaultDescription)
{
    ASSERT_DESCRIPTION("ANYTHING", anything<int>());
}


TEST(CanOverrideDescription)
{
    std::string description = "description";
    ASSERT_DESCRIPTION(description, anything<int>(description));
}


TEST(MembersOfCopyAreEqualButNotIdentical)
{
    anything<int> original("foo");
    std::auto_ptr< anything<int> > clone(static_cast<anything<int>*>(original.copy()));
    
    CHECK(original.description_m == clone->description_m);
    CHECK(&original.description_m != &clone->description_m);
}

}	// AnythingTest
