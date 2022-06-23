#include "hc_self_describing.h"

#include "hc_description.h"

namespace hamcrest {

std::ostream& operator<<(std::ostream& stream, const self_describing& obj)
{
    description_t description;
    obj.describe_to(description);
    stream << description.description_m;
    return stream;
}

}   // namespace hamcrest
