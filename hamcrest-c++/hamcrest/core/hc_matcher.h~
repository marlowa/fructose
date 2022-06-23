#ifndef HAMCREST_MATCHER_H
#define HAMCREST_MATCHER_H

#ifndef HAMCREST_SELF_DESCRIBING_H
#include "hc_self_describing.h"
#endif

#ifndef HAMCREST_STD_FUNCTIONAL
#define HAMCREST_STD_FUNCTIONAL
#include <functional>
#endif

namespace hamcrest {


/**
    A matcher over acceptable values of T
    
    A matcher is able to describe itself to give feedback when it fails.
*/
template <typename T>
struct matcher : public std::unary_function<T, bool>, self_describing
{
    virtual ~matcher() { }
    
    /// Evaluates the matcher for argument item
    virtual bool operator()(const T& item) const = 0;
    
    /// Creates a copy of itself
    virtual matcher<T>* copy() const = 0;
};


// Traits

struct not_matcher_tag { };
struct matcher_tag { };

template <typename T>
struct matcher_traits
{
    typedef T argument;
    typedef not_matcher_tag category;
};

#define HAMCREST_TAG_MATCHER(matcher_type)      \
    template <typename T>                       \
    struct matcher_traits< matcher_type<T> >    \
    {                                           \
        typedef T argument;                     \
        typedef matcher_tag category;           \
    }


}   // namespace hamcrest

#endif  // HAMCREST_MATCHER_H
