#include "stdio.h"
#include "cutest/CuTest.h"
#include "standard_calc.h"

/**************** Tests for bound_to_180() *******************/
void test_bound_basic1(CuTest *tc) {
    CuAssertDblEquals(tc, 0.0, bound_to_180(0.0), 0.0001);
    CuAssertDblEquals(tc, 90.0, bound_to_180(90.0), 0.0001);
    CuAssertDblEquals(tc, -180.0, bound_to_180(180.0), 0.0001);
    CuAssertDblEquals(tc, -179.0, bound_to_180(181.0), 0.0001);
    CuAssertDblEquals(tc, -90.0, bound_to_180(270.0), 0.0001);
    CuAssertDblEquals(tc, 0.0, bound_to_180(360.0), 0.0001);
}

/**************** Tests for is_angle_between() *******************/
void test_between_basic1(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(0, 1, 2));
    CuAssertTrue(tc, !is_angle_between(0, 3, 2));
    CuAssertTrue(tc, is_angle_between(0,45,90));
    CuAssertTrue(tc, !is_angle_between(45,90,270));
    CuAssertTrue(tc, is_angle_between(170, -175, -160));
    CuAssertTrue(tc, !is_angle_between(170, 160, -160));
    CuAssertTrue(tc, is_angle_between(30, 60, 60));
}

int main(int argc, char const *argv[]) {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, test_bound_basic1);
    SUITE_ADD_TEST(suite, test_between_basic1);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    return suite->failCount > 0 ? 1 : 0;
}
