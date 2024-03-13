#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int countSubstringsWithPattern(string s, string pattern) {
    int count = 0;
    int n = s.length();
    int m = pattern.length();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int found = 0;
            for (int k = i; k <= j - m + 1; k++) {
                int match = 1;
                if (s.substr(k, m) != pattern.substr(0, m)) match = 0;
                if (match) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string s;
    string pattern;
    getline(cin, s);
    getline(cin, pattern);
    int result = countSubstringsWithPattern(s, pattern);
    printf("%d\n", result);

    return 0;
}