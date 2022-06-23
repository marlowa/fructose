#ifndef HAMCREST_DESCRIPTION_H
#define HAMCREST_DESCRIPTION_H

#ifndef HAMCREST_STD_SSTREAM
#define HAMCREST_STD_SSTREAM
#include <sstream>
#endif

namespace hamcrest {

struct self_describing;

template <typename T>
std::string to_string(const T& value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}

inline std::string to_string(bool value) { return value ? "true" : "false"; }


/**
    A description of a matcher

    A matcher will describe itself to a description which can later be used for reporting.
*/
struct description_t
{
    /// Appends some plain text to the description
    description_t& append_text(const std::string& text);

    /// Appends the description of a self_describing value to this description
    description_t& append_description_of(const self_describing& value);

    /**
        Appends an arbitary value to the description

        Relies on the existence of a to_string function to convert the value into a string
    */
    template <typename T>
    description_t& append_value(const T& value)
    {
        description_m += '<';
        description_m += to_string(value);
        description_m += '>';
        return *this;
    }

    description_t& append_value(const std::string& value);
    description_t& append_value(const char* value);

    /**
        Appends a list of wrapped self_describing objects to the description.
    */
    template <typename SelfDescribingIterator>
    description_t& append_list(const std::string& start,
                                const std::string& separator,
                                const std::string& end,
                                SelfDescribingIterator first,
                                SelfDescribingIterator last)
    {
        append_text(start);
        append_description_of(**first);
        ++first;
        while (first != last)
        {
            append_text(separator);
            append_description_of(**first);
            ++first;
        }
        append_text(end);
        return *this;
    }

    friend inline void swap(description_t& x, description_t& y)
    {
        using std::swap;
        swap(x.description_m, y.description_m);
    }

    std::string description_m;
};


}   // namespace hamcrest

#endif  // HAMCREST_DESCRIPTION_H
