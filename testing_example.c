#include "test.h"

//set up test variables
int tests = 0;
int asserts = 0;
int passed = 0;
int failed = 0;
const double delta = .000001;

int factorial(int number) {
    return number <= 1 ? 1 : number * factorial(number - 1);
}

void factorial_test(){
    TEST_HEADER;

    CHECK_EQ_INT(factorial(0), 1);
    CHECK_EQ_INT(factorial(1), 1);
    CHECK_EQ_INT(factorial(2), 2);
    CHECK_EQ_INT(factorial(3), 6);
    CHECK_EQ_INT(factorial(4), 24);
    CHECK_EQ_INT(factorial(5), 120);
    CHECK_EQ_INT(factorial(10), 3628800);
}

int main(int argc, char **argv) {
    RUN_TEST(factorial_test);

    TEST_RESULTS;

    return 0;
}
