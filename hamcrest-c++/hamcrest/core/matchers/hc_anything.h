#ifndef HAMCREST_ANYTHING_H
#define HAMCREST_ANYTHING_H

#ifndef HAMCREST_DESCRIPTION_H
#include "hc_description.h"
#endif

#ifndef HAMCREST_MATCHER_H
#include "hc_matcher.h"
#endif

namespace hamcrest {


/**
    A matcher that always returns true
*/
template <typename T>
struct anything : public matcher<T>
{
    /**
        Create matcher that always evaluates to true

        @param description A meaningful string used when describing itself.
    */
    explicit anything(const std::string& description = "ANYTHING") : description_m(description) { }

    bool operator()(const T& /*item*/) const { return true; }
    
    void describe_to(description_t& description) const { description.append_text(description_m); }

    matcher<T>* copy() const { return new anything(*this); }

    std::string description_m;
};

HAMCREST_TAG_MATCHER(anything);


}   // namespace hamcrest

#endif  // HAMCREST_ANYTHING_H
