#ifndef HAMCREST_MATCHER_TEST_H
#define HAMCREST_MATCHER_TEST_H


#define ASSERT_MATCHES(actual, matcher)                                                             \
    do                                                                                              \
    {                                                                                               \
        if (!UnitTest::Check(matcher(actual)))                                                      \
            testResults_.OnTestFailure(UnitTest::TestDetails(m_details, __LINE__),                  \
                                        "should match");                                            \
    } while (0)


#define ASSERT_DOES_NOT_MATCH(actual, matcher)                                                      \
    do                                                                                              \
    {                                                                                               \
        if (UnitTest::Check(matcher(actual)))                                                       \
            testResults_.OnTestFailure(UnitTest::TestDetails(m_details, __LINE__),                  \
                                        "should not match");                                        \
    } while (0)


#define ASSERT_DESCRIPTION(expected, matcher)                                                       \
    do                                                                                              \
    {                                                                                               \
        description_t _description;                                                                 \
        matcher.describe_to(_description);                                                          \
        UnitTest::CheckEqual(testResults_, expected, _description.description_m,                    \
                            UnitTest::TestDetails(m_details, __LINE__));                            \
    } while (0)


#endif  // HAMCREST_MATCHER_TEST_H
