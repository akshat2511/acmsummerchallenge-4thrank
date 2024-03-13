#include <stdio.h>

void add(long long int arr[], long long int l, long long int r, long long int x) {
    for (long long int i = l - 1; i < r && i >= 0; i++) {
        arr[i] = arr[i] + x;
    }
}

void subtract(long long int arr[], long long int l, long long int r, long long int x) {
    for (long long int i = l - 1; i < r && i >= 0; i++) {
        arr[i] = arr[i] - x;
    }
}

void xor(long long int arr[], long long int l, long long int r, long long int x) {
    for (long long int i = l - 1; i < r && i >= 0; i++) {
        arr[i] = arr[i] ^ x;
    }
}

void multiply(long long int arr[], long long int l, long long int r, long long int x) {
    for (long long int i = l - 1; i < r && i >= 0; i++) {
        arr[i] = (arr[i] * x) % 1000000007;
    }
}

int main() {
    long long int n;
    if (scanf("%ld", &n) != 1 || n <= 0) {
        return 1;
    }

     long long int arr[n];
    for (long long int i = 0; i < n; i++) {
        if (scanf("%ld", &arr[i]) != 1) {
            return 1;
        }
    }

    long long int L1, L2, L3, L4;
    if (scanf("%ld %ld %ld %ld", &L1, &L2, &L3, &L4) != 4) {
        return 1;
    }

    while (L1--) {
        long long int l, r, x;
        if (scanf("%ld %ld %ld", &l, &r, &x) != 3) {
            return 1;
        }
        add(arr, l, r, x);
    }

    while (L2--) {
        long long int l, r, x;
        if (scanf("%ld %ld %ld", &l, &r, &x) != 3) {
            return 1;
        }
        subtract(arr, l, r, x);
    }

    while (L3--) {
        long long int l, r, x;
        if (scanf("%ld %ld %ld", &l, &r, &x) != 3) {
            return 1;
        }
        xor(arr, l, r, x);
    }

    while (L4--) {
        long long int l, r, x;
        if (scanf("%ld %ld %ld", &l, &r, &x) != 3) {
            return 1;
        }
        multiply(arr, l, r, x);
    }

    for (long long int i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }

    return 0;
}
