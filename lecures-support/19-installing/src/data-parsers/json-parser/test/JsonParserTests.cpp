#include <JsonCameraDataParser.h>

#include <gtest/gtest.h>

namespace parsers::test
{

TEST(TestCase, FailingTest)
{
    JsonCameraDataParser sut;
    FAIL();
}

} // namespace parsers::test