#ifndef HAMCREST_ANY_OF_H
#define HAMCREST_ANY_OF_H

#ifndef HAMCREST_SHORTCUT_COMBINATION_H
#include "hc_shortcut_combination.h"
#endif

namespace hamcrest {


/**
    Calculates the logical disjunction of multiple matchers

    Evaluation is shortcut, so subsequent matchers are not called if an earlier
    matcher returns true.
*/
template <typename T>
class any_of_t : public shortcut_combination<T>
{
public:
    template <typename Matcher1, typename Matcher2>
    any_of_t(const Matcher1& m1, const Matcher2& m2)
        : shortcut_combination<T>(m1, m2) { }

    template <typename Matcher1, typename Matcher2, typename Matcher3>
    any_of_t(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3)
        : shortcut_combination<T>(m1, m2, m3) { }

    template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4>
    any_of_t(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3, const Matcher4& m4)
        : shortcut_combination<T>(m1, m2, m3, m4) { }

    template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4,
                typename Matcher5>
    any_of_t(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3, const Matcher4& m4,
                const Matcher5& m5)
        : shortcut_combination<T>(m1, m2, m3, m4, m5) { }

    template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4,
                typename Matcher5, typename Matcher6>
    any_of_t(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3, const Matcher4& m4,
                const Matcher5& m5, const Matcher6& m6)
        : shortcut_combination<T>(m1, m2, m3, m4, m5, m6) { }

    bool operator()(const T& arg) const { return this->matches(arg, true); }

    void describe_to(description_t& description) const
        { shortcut_combination<T>::describe_operator(description, "or"); }

    matcher<T>* copy() const { return this->create_matcher_copies_in(new any_of_t); }

private:
    any_of_t() { }
};

HAMCREST_TAG_MATCHER(any_of_t);


// Helper functions, deducing the type:

/// Evaluates to true if ANY of the passed in matchers evaluate to true
template <typename Matcher1, typename Matcher2>
any_of_t<typename Matcher1::argument_type> any_of(const Matcher1& m1, const Matcher2& m2)
    { return any_of_t<typename Matcher1::argument_type>(m1, m2); }

/// Evaluates to true if ANY of the passed in matchers evaluate to true
template <typename Matcher1, typename Matcher2, typename Matcher3>
any_of_t<typename Matcher1::argument_type> any_of(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3)
    { return any_of_t<typename Matcher1::argument_type>(m1, m2, m3); }

/// Evaluates to true if ANY of the passed in matchers evaluate to true
template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4>
any_of_t<typename Matcher1::argument_type> any_of(const Matcher1& m1, const Matcher2& m2,
            const Matcher3& m3, const Matcher4& m4)
    { return any_of_t<typename Matcher1::argument_type>(m1, m2, m3, m4); }

/// Evaluates to true if ANY of the passed in matchers evaluate to true
template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4,
            typename Matcher5>
any_of_t<typename Matcher1::argument_type> any_of(const Matcher1& m1, const Matcher2& m2,
            const Matcher3& m3, const Matcher4& m4, const Matcher5& m5)
    { return any_of_t<typename Matcher1::argument_type>(m1, m2, m3, m4, m5); }

/// Evaluates to true if ANY of the passed in matchers evaluate to true
template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4,
            typename Matcher5, typename Matcher6>
any_of_t<typename Matcher1::argument_type> any_of(const Matcher1& m1, const Matcher2& m2,
            const Matcher3& m3, const Matcher4& m4, const Matcher5& m5, const Matcher6& m6)
    { return any_of_t<typename Matcher1::argument_type>(m1, m2, m3, m4, m5, m6); }


}   // namespace hamcrest

#endif  // HAMCREST_ANY_OF_H
