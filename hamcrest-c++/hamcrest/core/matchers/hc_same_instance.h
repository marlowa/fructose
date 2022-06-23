#ifndef HAMCREST_SAME_INSTANCE_H
#define HAMCREST_SAME_INSTANCE_H

#ifndef HAMCREST_DESCRIPTION_H
#include "hc_description.h"
#endif

#ifndef HAMCREST_MATCHER_H
#include "hc_matcher.h"
#endif

namespace hamcrest {


/**
    Is the value the same object as another value?
*/
template <typename T>
struct same_instance_t : public matcher<T>
{
    same_instance_t(const T& instance) : instance_m(instance) { }
    
    bool operator()(const T& arg) const { return &arg == &instance_m; }

    void describe_to(description_t& description) const
        { description.append_text("same(").append_value(instance_m).append_text(")"); }
    
    matcher<T>* copy() const { return new same_instance_t(*this); }

    const T& instance_m;
};

HAMCREST_TAG_MATCHER(same_instance_t);


/// Helper function, deducing the type
template <typename T>
same_instance_t<T> same_instance(const T& instance) { return same_instance_t<T>(instance); }


}   // namespace hamcrest

#endif  // HAMCREST_SAME_INSTANCE_H
