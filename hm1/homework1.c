#include <stdio.h>

int myAtoi(char *str) {
    int result = 0, sign = 1, i = 0;

    while (str[i] == ' ') i++;

    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int main() {
    char str[] = "   -1234";
    printf("%d\n", myAtoi(str));
    return 0;
}

