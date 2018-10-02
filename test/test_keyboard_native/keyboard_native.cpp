#include <unity.h>

void test_abc()
{
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_abc);
    UNITY_END();
    return 0;
}