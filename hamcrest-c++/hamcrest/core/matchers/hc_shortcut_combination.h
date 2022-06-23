#ifndef HAMCREST_SHORTCUT_COMBINATION_H
#define HAMCREST_SHORTCUT_COMBINATION_H

#include <algorithm>

#ifndef HAMCREST_MATCHER_H
#include "hc_matcher.h"
#endif

#ifndef HAMCREST_DESCRIPTION_H
#include "hc_description.h"
#endif

#ifndef HAMCREST_STD_VECTOR
#define HAMCREST_STD_VECTOR
#include <vector>
#endif

namespace hamcrest {

/**
    Function object to copy the object pointed to
*/
template <typename T>
struct copy_object : std::unary_function<T*, T*>
{
    T* operator()(const T* object) const { return object->copy(); }
};


/**
    Function object to delete the object pointed to
*/
template <typename T>
struct delete_object : std::unary_function<T*, void>
{
    void operator()(T* object) const { delete object; }
};


template <typename T>
class shortcut_combination : public matcher<T>
{
protected:
    shortcut_combination() { }

    template <typename Matcher1, typename Matcher2>
    shortcut_combination(const Matcher1& m1, const Matcher2& m2)
    {
        push_back(m1.copy());
        push_back(m2.copy());
    }
    
    template <typename Matcher1, typename Matcher2, typename Matcher3>
    shortcut_combination(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3)
    {
        push_back(m1.copy());
        push_back(m2.copy());
        push_back(m3.copy());
    }
    
    template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4>
    shortcut_combination(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3, const Matcher4& m4)
    {
        push_back(m1.copy());
        push_back(m2.copy());
        push_back(m3.copy());
        push_back(m4.copy());
    }
    
    template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4,
                typename Matcher5>
    shortcut_combination(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3, const Matcher4& m4,
                const Matcher5& m5)
    {
        push_back(m1.copy());
        push_back(m2.copy());
        push_back(m3.copy());
        push_back(m4.copy());
        push_back(m5.copy());
    }

    template <typename Matcher1, typename Matcher2, typename Matcher3, typename Matcher4,
                typename Matcher5, typename Matcher6>
    shortcut_combination(const Matcher1& m1, const Matcher2& m2, const Matcher3& m3, const Matcher4& m4,
                const Matcher5& m5, const Matcher6& m6)
    {
        push_back(m1.copy());
        push_back(m2.copy());
        push_back(m3.copy());
        push_back(m4.copy());
        push_back(m5.copy());
        push_back(m6.copy());
    }

    ~shortcut_combination()
        { std::for_each(matchers_m.begin(), matchers_m.end(), delete_object< matcher<T> >()); }
        
    bool matches(const T& arg, bool shortcut) const
    {
        typename matchers::const_iterator first = matchers_m.begin();
        typename matchers::const_iterator last = matchers_m.end();
        while (first != last)
        {
            if ((**first)(arg) == shortcut)
                return shortcut;
            ++first;
        }
        return !shortcut;
    }

    void describe_operator(description_t& description, const std::string& op) const
    {
        std::string paddedOp = " ";
        paddedOp += op;
        paddedOp += " ";
        description.append_list("(", paddedOp, ")", matchers_m.begin(), matchers_m.end());
    }
    
    shortcut_combination* create_matcher_copies_in(shortcut_combination* other) const
    {
        std::transform(matchers_m.begin(),
                        matchers_m.end(),
                        std::back_inserter(other->matchers_m),
                        copy_object< matcher<T> >());
        return other;
    }
    
private:
    typedef std::vector< matcher<T>* > matchers;
    matchers matchers_m; 

    void push_back(matcher<T>* m) { matchers_m.push_back(m); }
};


}   // namespace hamcrest

#endif  // HAMCREST_SHORTCUT_COMBINATION_H
