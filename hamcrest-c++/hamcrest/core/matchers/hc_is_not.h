#ifndef HAMCREST_IS_NOT_H
#define HAMCREST_IS_NOT_H

#ifndef HAMCREST_EQUAL_TO_H
#include "hc_equal_to.h"
#endif

namespace hamcrest {


/**
    Calculates the logical negation of a matcher.
*/
template <typename T>
class is_not_t : public matcher<T>
{
public:
    template <typename Matcher>
    explicit is_not_t(const Matcher& matcher) : matcher_m(matcher.copy()) { }
    
    ~is_not_t() { delete matcher_m; }
    
    bool operator()(const T& arg) const { return !(*matcher_m)(arg); }

    void describe_to(description_t& description) const
        { description.append_text("not ").append_description_of(*matcher_m); }
    
    matcher<T>* copy() const { return new is_not_t(*matcher_m); }

private:
    matcher<T>* matcher_m;
};

HAMCREST_TAG_MATCHER(is_not_t);


/// Inverts another matcher
template <typename T>
is_not_t<typename T::argument_type> is_not_implementation(const T& arg, matcher_tag)
    { return is_not_t<typename T::argument_type>(arg); }

/**
    This is a shortcut to the frequently used is_not(equal_to(x)).
    
    For example,
        ASSERT_THAT(cheese, is_not(equal_to(smelly)))
    vs.
        ASSERT_THAT(cheese, is_not(smelly))
*/
template <typename T>
is_not_t<T> is_not_implementation(const T& arg, not_matcher_tag)
    { return is_not_t<T>(hamcrest::equal_to(arg)); }

/// Accepts either a matcher or a non-matcher
template <typename T>
is_not_t<typename matcher_traits<T>::argument> is_not(const T& arg)
    { return is_not_implementation(arg, typename matcher_traits<T>::category()); }

/**
    Convert matcher<T[]> to matcher<T*>

    (Commonly occurs with string literals.)
*/
template <typename T>
is_not_t<const T*> is_not(const T arg[]) { return is_not_implementation(arg, not_matcher_tag()); }


}   // namespace hamcrest

#endif  // HAMCREST_IS_NOT_H
