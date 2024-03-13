#include <stdio.h>

int main() {
    int n, p, l;
    scanf("%d %d %d", &n, &p, &l);

    int vi[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vi[i]);
    }

    int time = 0;
    for (int i = 0; i < p; i++) {
        int currentquery;
        scanf("%d", &currentquery);

        if (currentquery == 0) {
            int flag = 0;
            int top = 0;

            for (int j = 0; j < n; j++) {
                if (vi[j] > l) {
                    top = 1;
                } else {
                    if (top == 1) {
                        time++;
                        top = 0;
                    }
                }
            }

            if (vi[n - 1] > l) {
                time++;
            }

            printf("%d\n", time);
            time = 0;
        } else if (currentquery == 1) {
            int k, d;
            scanf("%d %d", &k, &d);
            vi[k - 1] += d;
        }
    }

    return 0;
}