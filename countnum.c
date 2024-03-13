#include <stdio.h>

unsigned long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else if(n>1)
        return (n * factorial(n - 1)+1000000007)%1000000007;
}

int countOccurrences(char* str, char c) {
    int count = 0;
    while (*str) {
        if (*str == c)
            count++;
        str++;
    }
    return count;
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);

    while (numTestCases > 0) {
        char inputString[100000];
        scanf("%s", inputString);

        int targetNumber;
        scanf("%d", &targetNumber);

        int count = countOccurrences(inputString, targetNumber + '0');
        

        printf("%lu ", factorial(count));

        numTestCases--;
    }

    return 0;
}
