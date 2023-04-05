#include <gtest/gtest.h>

#include <stdio.h>

float TwoDevidedBy(int a) {
    return 2 / a;
}


TEST(MyFunCase, TestIsTrue) {
    EXPECT_EQ(TwoDevidedBy(2), 1);
}

int main(int argc, char *argv[]) {
    int arg = 10;
    float mean = TwoDevidedBy(arg);
    return 0;
}