#include "hc_equal_to.h"
#include "hc_is_not.h"
#include "hc_unittest.h"
#include "matcher_test.h"
#include "UnitTest++.h"

using namespace hamcrest;

namespace {

struct object_t
{
    explicit object_t(const std::string& description) : description_m(description) { }
    
    bool operator==(const object_t& other) const { return description_m == other.description_m; }
    
    std::string description_m;
};

std::string to_string(const object_t& object) { return object.description_m; }

}   // namespace


SUITE(EqualToTest) {

TEST(ComparesObjectsForEquality)
{
    ASSERT_THAT("hi", equal_to("hi"));
    ASSERT_THAT("bye", is_not(equal_to("hi")));

    ASSERT_THAT(1, equal_to(1));
    ASSERT_THAT(1, is_not(equal_to(2)));
}


TEST(IncludesTheResultOfCallingToStringOnItsArgumentInTheDescription)
{
    std::string argument_description = "ARGUMENT DESCRIPTION";
    object_t argument(argument_description);
    ASSERT_DESCRIPTION("<" + argument_description + ">", equal_to(argument));
}


TEST(MembersOfCopyAreEqualButNotIdentical)
{
    equal_to_t<int> original(1);
    std::auto_ptr< equal_to_t<int> > clone(static_cast<equal_to_t<int>*>(original.copy()));
    
    CHECK(original.expected_m == clone->expected_m);
    CHECK(&original.expected_m != &clone->expected_m);
}

}	// EqualToTest
