#ifndef HAMCREST_IS_H
#define HAMCREST_IS_H

#ifndef HAMCREST_EQUAL_TO_H
#include "hc_equal_to.h"
#endif

namespace hamcrest {


/**
    Decorates another matcher, retaining the behavior but allowing tests to be slightly more
    expressive
    
    For example,
        ASSERT_THAT(cheese, equal_to(smelly))
    vs.
        ASSERT_THAT(cheese, is(equal_to(smelly)))
*/
template <typename T>
class is_t : public matcher<T>
{
public:
    template <typename Matcher>
    explicit is_t(const Matcher& matcher) : matcher_m(matcher.copy()) { }

    ~is_t() { delete matcher_m; }
    
    bool operator()(const T& arg) const { return (*matcher_m)(arg); }

    void describe_to(description_t& description) const
        { description.append_text("is ").append_description_of(*matcher_m); }
    
    matcher<T>* copy() const { return new is_t(*matcher_m); }

private:
    matcher<T>* matcher_m;
};

HAMCREST_TAG_MATCHER(is_t);


/// Decorates another matcher
template <typename T>
is_t<typename T::argument_type> is_implementation(const T& arg, matcher_tag)
    { return is_t<typename T::argument_type>(arg); }

/**
    This is a shortcut to the frequently used is(equal_to(x)).
    
    For example,
        ASSERT_THAT(cheese, is(equal_to(smelly)))
    vs.
        ASSERT_THAT(cheese, is(smelly))
*/
template <typename T>
is_t<T> is_implementation(const T& arg, not_matcher_tag)
    { return is_t<T>(hamcrest::equal_to(arg)); }

/// Accepts either a matcher or a non-matcher
template <typename T>
is_t<typename matcher_traits<T>::argument> is(const T& arg)
    { return is_implementation(arg, typename matcher_traits<T>::category()); }

/**
    Convert matcher<T[]> to matcher<T*>

    (Commonly occurs with string literals.)
*/
template <typename T>
is_t<const T*> is(const T arg[]) { return is_implementation(arg, not_matcher_tag()); }


}   // namespace hamcrest

#endif  // HAMCREST_IS_H
