#ifndef HAMCREST_EQUAL_TO_H
#define HAMCREST_EQUAL_TO_H

#ifndef HAMCREST_DESCRIPTION_H
#include "hc_description.h"
#endif

#ifndef HAMCREST_MATCHER_H
#include "hc_matcher.h"
#endif

namespace hamcrest {


/**
    Is the value equal to another value
*/
template <typename T>
struct equal_to_t : public matcher<T>
{
    explicit equal_to_t(const T& expected) : expected_m(expected) { }
    
    bool operator()(const T& actual) const { return actual == expected_m; }
    
    void describe_to(description_t& description) const { description.append_value(expected_m); }

    matcher<T>* copy() const { return new equal_to_t(*this); }

    T expected_m;
};

HAMCREST_TAG_MATCHER(equal_to_t);


/// Helper function, deducing the type
template <typename T>
equal_to_t<T> equal_to(const T& expected) { return equal_to_t<T>(expected); }

/**
    Convert matcher<T[]> to matcher<T*>

    (Commonly occurs with string literals.)
*/
template <typename T>
equal_to_t<const T*> equal_to(const T expected[]) { return equal_to_t<const T*>(expected); }


}   // namespace hamcrest

#endif  // HAMCREST_EQUAL_TO_H
