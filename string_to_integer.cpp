#include "catch.hpp"

using namespace std;

int myAtoi(string str) {
    int ret = 0;
    int sign = 1, i = str.find_first_not_of(' '), base = INT_MAX / 10;
    if (str[i] == '+' || str[i] == '-') sign = str[i++] == '+' ?: -1;
    while (i < str.size() && isdigit(str[i])) {
        if (ret > base || (ret == base && str[i] - '0' > INT_MAX % 10))
            return sign > 0 ? INT_MAX : INT_MIN;
        ret = 10 * ret + (str[i++] - '0');
    }
    return sign * ret;
}


TEST_CASE("string to integer") {
    string out_of_range(100, '9'); // '999999....9999999'
    REQUIRE(myAtoi(" 1") == 1);
    REQUIRE(myAtoi(out_of_range) == INT_MAX);
    REQUIRE(myAtoi("1") == 1);
    REQUIRE(myAtoi("+1") == 1);
    REQUIRE(myAtoi("-1") == -1);
    REQUIRE(myAtoi("+1") == 1);
    REQUIRE(myAtoi("10") == 10);
}
