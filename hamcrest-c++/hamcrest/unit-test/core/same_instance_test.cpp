#include "hc_same_instance.h"
#include "hc_is_not.h"
#include "hc_unittest.h"
#include "matcher_test.h"
#include "UnitTest++.h"

using namespace hamcrest;

SUITE(SameInstanceTest) {

TEST(EvaluatesToTrueIfArgumentIsReferenceToASpecifiedObject)
{
    int i1 = 42;
    int i2 = 42;

    ASSERT_THAT(i1, same_instance(i1));
    ASSERT_THAT(i2, is_not((same_instance(i1))));
}


TEST(HasAReadableDescription)
{
    ASSERT_DESCRIPTION("same(\"ARG\")", same_instance("ARG"));
}


TEST(MembersOfCopyAreIdentical)
{
    int i = 42;
    same_instance_t<int> original(i);
    std::auto_ptr< same_instance_t<int> > clone(static_cast<same_instance_t<int>*>(original.copy()));
    
    CHECK(&original.instance_m == &clone->instance_m);
}

}	// SameInstanceTest
