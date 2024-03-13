#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> p(t);
    vector<int> q(t);
    for (int l = 0; l < t; l++) {
        int i, j;
        cin >> i >> j;
        p[l] = i;
        q[l] = j;
    }

    int s = p[0];
    int y = q[0];
    for (int i = 0; i < t; i++) {
        if (p[i] > s) {
            s = p[i];
        }
    }
    for (int i = 0; i < t; i++) {
        if (q[i] > y) {
            y=q[i];
        }
    }

    vector<vector<int>> a(s + 1, vector<int>(s + 1, 0));
    a[1][1] = 1;
    a[2][1] = 1;
    a[2][2] = 1;
    for (int k = 3; k <= s; k++) {
        for (int m = 1; m <= min(k / 2 + 1, y); m++) {
            if(k%2==0&&m>k/2)
            break;
            if (m == 1) {
                a[k][k] = a[k][m] = a[k - 1][m] * 2;
            } else {

                int sum = 0;
                int temp = k - 1;
                int c = 2;
                int h = c;
                while (temp != 0) {
                    int temp1 = m;
                    c = h;
                    while (c != 0) {
                        sum += a[temp][temp1];
                        if (temp1 == 1) {
                            break;
                        }
                        temp1 -= 1;
                        c -= 1;
                    }
                    temp -= 1;
                    h = h + 1;
                }
                a[k][m] = sum;
                a[k][k - m + 1] = a[k][m];
            }
        }
    }
    for (int r = 0; r < t; r++) {
        int o = p[r];
        int u = q[r];
        cout << int(a[o][u] % static_cast<int>(pow(10, 9) + 7)) << endl;
    }
    return 0;
}