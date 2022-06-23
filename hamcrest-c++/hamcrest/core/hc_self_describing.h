#ifndef HAMCREST_SELF_DESCRIBING_H
#define HAMCREST_SELF_DESCRIBING_H

#ifndef HAMCREST_STD_IOSFWD
#define HAMCREST_STD_IOSFWD
#include <iosfwd>
#endif

namespace hamcrest {

struct description_t;


/**
    The ability of an object to describe itself.
*/
struct self_describing
{
    virtual ~self_describing() { }
    
    /**
        Generates a description of the object

        The description may be part of a description of a larger object of which this is just a
        component, so it should be worded appropriately.
    */
    virtual void describe_to(description_t& description) const = 0;
};


std::ostream& operator<<(std::ostream& stream, const self_describing& obj);


}   // namespace hamcrest

#endif  // HAMCREST_SELF_DESCRIBING_H
