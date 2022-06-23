#ifndef HAMCREST_ALL_OF_H
#define HAMCREST_ALL_OF_H

#ifndef HAMCREST_SHORTCUT_COMBINATION_H
#include "hc_shortcut_combination.h"
#endif

namespace hamcrest {


/**
    Calculates the logical conjunction of multiple matchers
    
    Evaluation is shortcut, so subsequent matchers are not called if an earlier
    matcher returns false.
*/
template <typename T>
class all_of_t : public shortcut_combination<T>
{
public:
    template <typename Matcher1, typename Matcher2>
    all_of_t(const Matcher1& m1, const Matcher2& m2)
        : shortcut_combination<T>(m1, m2) { }
    
    template <typename Matcher1, typename Matcher2, typename Matcher3>
    all_of_t(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3)
        : shortcut_combination<T>(m1, m2, m3) { }
    
    template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4>
    all_of_t(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3, const Matcher4& m4)
        : shortcut_combination<T>(m1, m2, m3, m4) { }
    
    template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4,
                typename Matcher5>
    all_of_t(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3, const Matcher4& m4,
                const Matcher5& m5)
        : shortcut_combination<T>(m1, m2, m3, m4, m5) { }
    
    template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4,
                typename Matcher5, typename Matcher6>
    all_of_t(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3, const Matcher4& m4,
                const Matcher5& m5, const Matcher6& m6)
        : shortcut_combination<T>(m1, m2, m3, m4, m5, m6) { }
    
    bool operator()(const T& arg) const { return matches(arg, false); }

    void describe_to(description_t& description) const
        { this->describe_operator(description, "and"); }

    matcher<T>* copy() const { return this->create_matcher_copies_in(new all_of_t); }

private:
    all_of_t() { }
};

HAMCREST_TAG_MATCHER(all_of_t);


// Helper functions, deducing the type:

/// Evaluates to true only if ALL of the passed in matchers evaluate to true
template <typename Matcher1, typename Matcher2>
all_of_t<typename Matcher1::argument_type> all_of(const Matcher1& m1, const Matcher2& m2)
    { return all_of_t<typename Matcher1::argument_type>(m1, m2); }

/// Evaluates to true only if ALL of the passed in matchers evaluate to true
template <typename Matcher1, typename Matcher2, typename Matcher3>
all_of_t<typename Matcher1::argument_type> all_of(const Matcher1& m1, const Matcher2& m2,
            const Matcher3& m3)
    { return all_of_t<typename Matcher1::argument_type>(m1, m2, m3); }

/// Evaluates to true only if ALL of the passed in matchers evaluate to true
template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4>
all_of_t<typename Matcher1::argument_type> all_of(const Matcher1& m1, const Matcher2& m2,
            const Matcher3& m3, const Matcher4& m4)
    { return all_of_t<typename Matcher1::argument_type>(m1, m2, m3, m4); }

/// Evaluates to true only if ALL of the passed in matchers evaluate to true
template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4,
            typename Matcher5>
all_of_t<typename Matcher1::argument_type> all_of(const Matcher1& m1, const Matcher2& m2,
            const Matcher3& m3, const Matcher4& m4, const Matcher5& m5)
    { return all_of_t<typename Matcher1::argument_type>(m1, m2, m3, m4, m5); }

/// Evaluates to true only if ALL of the passed in matchers evaluate to true
template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4,
            typename Matcher5, typename Matcher6>
all_of_t<typename Matcher1::argument_type> all_of(const Matcher1& m1, const Matcher2& m2, const
            Matcher3& m3, const Matcher4& m4, const Matcher5& m5, const Matcher6& m6)
    { return all_of_t<typename Matcher1::argument_type>(m1, m2, m3, m4, m5, m6); }


}   // namespace hamcrest

#endif  // HAMCREST_ALL_OF_H
