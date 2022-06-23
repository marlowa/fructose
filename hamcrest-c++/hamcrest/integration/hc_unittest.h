#ifndef HAMCREST_UNITTEST_H
#define HAMCREST_UNITTEST_H


/// Integration with UnitTest++
#define ASSERT_THAT(actual, matcher)                                                                \
    do                                                                                              \
    {                                                                                               \
        if (!matcher(actual))                                                                       \
        {                                                                                           \
            description_t _description;                                                             \
            _description.append_text("Expected: ")                                                  \
                        .append_description_of(matcher)                                             \
                        .append_text(", got: ")                                                     \
                        .append_value(actual);                                                      \
            testResults_.OnTestFailure(UnitTest::TestDetails(m_details, __LINE__),                  \
                                        _description.description_m.c_str());                        \
        }                                                                                           \
    } while (0)


#endif  // HAMCREST_UNITTEST_H
