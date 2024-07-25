#include <gtest/gtest.h>

import task;

TEST(Task, Basic)
{
    auto fn = []() -> void {

    };
    Task t1(fn);
    ASSERT_EQ(t1.GetStatus(), Task::status_type::READY);
    // ASSERT_EQ(t1.What(),fn);
    ASSERT_EQ(t1.Execute(), Task::status_type::FINISHED);

    Task t2 = t1;
    // ASSERT_EQ(t2.What(),t1.What());
    ASSERT_EQ(t2.GetStatus(), Task::status_type::READY);
}