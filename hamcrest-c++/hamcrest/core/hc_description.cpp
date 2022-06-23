#include "hc_description.h"

#include "hc_self_describing.h"

namespace hamcrest {


description_t& description_t::append_text(const std::string& text)
{
    description_m += text;
    return *this;
}


description_t& description_t::append_description_of(const self_describing& value)
{
    value.describe_to(*this);
    return *this;
}


description_t& description_t::append_value(const std::string& value)
{
    description_m += '\"';
    description_m += value;
    description_m += '\"';
    return *this;
}


description_t& description_t::append_value(const char* value)
{
    append_value(std::string(value));
    return *this;
}


}   // namespace hamcrest
