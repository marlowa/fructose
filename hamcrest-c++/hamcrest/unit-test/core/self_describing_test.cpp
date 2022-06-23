#include "hc_anything.h"
#include "UnitTest++.h"

using namespace hamcrest;

SUITE(SelfDescribingTest) {

TEST(WriteToStream)
{
    std::ostringstream stream;
    std::string description = "description";
    
    stream << anything<int>(description);
    
    CHECK_EQUAL(description, stream.str());
}

}   // SelfDescribingTest
