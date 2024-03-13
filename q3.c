#include <stdio.h>
#include <math.h>
int adder(int n)
{
    int x = 827 + n * (n + 59);
    return x;
}
int main()
{
    int num;
    int n, j;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {

        scanf("%d", &n);
        if (n < 46)
        {
            for (j = 1; j <= 9; j++)
            {
                int y = (pow(j, 2) + j) / 2;
                int x = y - j + 1;

                if (x <= n)
                {
                    if (n <= y)
                    {
                        printf("%d\n", j);
                    }
                }
            }
        }

        else if (n >= 46 && n < 337)
        {
            if (n % 2 == 0)
            {
                printf("%d\n", 1);
            }
            else if (n < 67 && n % 2 == 1)
                printf("%d\n", 0);
            else if (n < 89 && n % 2 == 1)
                printf("%d\n", 1);
            else if (n < 113 && n % 2 == 1)
                printf("%d\n", 2);
            else if (n < 139 && n % 2 == 1)
                printf("%d\n", 3);

            else if (n < 167 && n % 2 == 1)
                printf("%d\n", 4);
            else if (n < 197 && n % 2 == 1)
                printf("%d\n", 5);
            else if (n < 229 && n % 2 == 1)
                printf("%d\n", 6);
            else if (n < 263 && n % 2 == 1)
                printf("%d\n", 7);
            else if (n < 299 && n % 2 == 1)
                printf("%d\n", 8);
            else if (n < 337 && n % 2 == 1)
                printf("%d\n", 9);
        }
        else if (n >= 337 && n < 827)
        {
            if (n < 827 && n % 2 == 0)
            {
                printf("%d\n", 2);
            }

            else if (n < 377 && n % 2 == 1)
                printf("%d\n", 0);
            else if (n < 419 && n % 2 == 1)
                printf("%d\n", 1);
            else if (n < 463 && n % 2 == 1)
                printf("%d\n", 2);
            else if (n < 509 && n % 2 == 1)
                printf("%d\n", 3);

            else if (n < 557 && n % 2 == 1)
                printf("%d\n", 4);
            else if (n < 607 && n % 2 == 1)
                printf("%d\n", 5);
            else if (n < 659 && n % 2 == 1)
                printf("%d\n", 6);
            else if (n < 713 && n % 2 == 1)
                printf("%d\n", 7);
            else if (n < 769 && n % 2 == 1)
                printf("%d\n", 8);
            else if (n < 827 && n % 2 == 1)
                printf("%d\n", 9);
        }

        else if (n >= 827 && n < 1517)
        {
            if (n % 2 == 0)
            {
                printf("%d\n", 3);
            }

            else if (n < adder(1) && n % 2 == 1)
                printf("%d\n", 0);
            else if (n < adder(2) && n % 2 == 1)
                printf("%d\n", 1);
            else if (n < adder(3) && n % 2 == 1)
                printf("%d\n", 2);
            else if (n < adder(4) && n % 2 == 1)
                printf("%d\n", 3);

            else if (n < adder(5) && n % 2 == 1)
                printf("%d\n", 4);
            else if (n < adder(6) && n % 2 == 1)
                printf("%d\n", 5);
            else if (n < adder(7) && n % 2 == 1)
                printf("%d\n", 6);
            else if (n < adder(8) && n % 2 == 1)
                printf("%d\n", 7);
            else if (n < adder(9) && n % 2 == 1)
                printf("%d\n", 8);
            else if (n < adder(10) && n % 2 == 1)
                printf("%d\n", 9);
        }
        else if (n >= adder(10) && n < adder(20))
        {
            if (n % 2 == 0)
            {
                printf("%d\n", 4);
            }
            else if (n < adder(11) && n % 2 == 1)
                printf("%d\n", 0);
            else if (n < adder(12) && n % 2 == 1)
                printf("%d\n", 1);
            else if (n < adder(13) && n % 2 == 1)
                printf("%d\n", 2);
            else if (n < adder(14) && n % 2 == 1)
                printf("%d\n", 3);

            else if (n < adder(15) && n % 2 == 1)
                printf("%d\n", 4);
            else if (n < adder(16) && n % 2 == 1)
                printf("%d\n", 5);
            else if (n < adder(17) && n % 2 == 1)
                printf("%d\n", 6);
            else if (n < adder(18) && n % 2 == 1)
                printf("%d\n", 7);
            else if (n < adder(19) && n % 2 == 1)
                printf("%d\n", 8);
            else if (n < adder(20) && n % 2 == 1)
                printf("%d\n", 9);
        }
        else if (n >= adder(20) && n < adder(30))
        {
            if (n % 2 == 0)
            {
                printf("%d\n", 5);
            }
            else if (n < adder(21) && n % 2 == 1)
                printf("%d\n", 0);
            else if (n < adder(22) && n % 2 == 1)
                printf("%d\n", 1);
            else if (n < adder(23) && n % 2 == 1)
                printf("%d\n", 2);
            else if (n < adder(24) && n % 2 == 1)
                printf("%d\n", 3);

            else if (n < adder(25) && n % 2 == 1)
                printf("%d\n", 4);
            else if (n < adder(26) && n % 2 == 1)
                printf("%d\n", 5);
            else if (n < adder(27) && n % 2 == 1)
                printf("%d\n", 6);
            else if (n < adder(28) && n % 2 == 1)
                printf("%d\n", 7);
            else if (n < adder(29) && n % 2 == 1)
                printf("%d\n", 8);
            else if (n < adder(30) && n % 2 == 1)
                printf("%d\n", 9);
        }
        else if (n >= adder(30) && n < adder(40))
        {
            if (n % 2 == 0)
            {
                printf("%d\n", 6);
            }
            else if (n < adder(31) && n % 2 == 1)
                printf("%d\n", 0);
            else if (n < adder(32) && n % 2 == 1)
                printf("%d\n", 1);
            else if (n < adder(33) && n % 2 == 1)
                printf("%d\n", 2);
            else if (n < adder(34) && n % 2 == 1)
                printf("%d\n", 3);

            else if (n < adder(35) && n % 2 == 1)
                printf("%d\n", 4);
            else if (n < adder(36) && n % 2 == 1)
                printf("%d\n", 5);
            else if (n < adder(37) && n % 2 == 1)
                printf("%d\n", 6);
            else if (n < adder(38) && n % 2 == 1)
                printf("%d\n", 7);
            else if (n < adder(39) && n % 2 == 1)
                printf("%d\n", 8);
            else if (n < adder(40) && n % 2 == 1)
                printf("%d\n", 9);
        }
        else if (n >= adder(40) && n < adder(50))
        {
            if (n % 2 == 0)
            {
                printf("%d\n", 7);
            }
            else if (n < adder(41) && n % 2 == 1)
                printf("%d\n", 0);
            else if (n < adder(42) && n % 2 == 1)
                printf("%d\n", 1);
            else if (n < adder(43) && n % 2 == 1)
                printf("%d\n", 2);
            else if (n < adder(44) && n % 2 == 1)
                printf("%d\n", 3);

            else if (n < adder(45) && n % 2 == 1)
                printf("%d\n", 4);
            else if (n < adder(46) && n % 2 == 1)
                printf("%d\n", 5);
            else if (n < adder(47) && n % 2 == 1)
                printf("%d\n", 6);
            else if (n < adder(48) && n % 2 == 1)
                printf("%d\n", 7);
            else if (n < adder(49) && n % 2 == 1)
                printf("%d\n", 8);
            else if (n < adder(50) && n % 2 == 1)
                printf("%d\n", 9);
        }
        else if (n >= adder(50) && n < adder(60))
        {
            if (n % 2 == 0)
            {
                printf("%d\n", 8);
            }
            else if (n < adder(51) && n % 2 == 1)
                printf("%d\n", 0);
            else if (n < adder(52) && n % 2 == 1)
                printf("%d\n", 1);
            else if (n < adder(53) && n % 2 == 1)
                printf("%d\n", 2);
            else if (n < adder(54) && n % 2 == 1)
                printf("%d\n", 3);

            else if (n < adder(55) && n % 2 == 1)
                printf("%d\n", 4);
            else if (n < adder(56) && n % 2 == 1)
                printf("%d\n", 5);
            else if (n < adder(57) && n % 2 == 1)
                printf("%d\n", 6);
            else if (n < adder(58) && n % 2 == 1)
                printf("%d\n", 7);
            else if (n < adder(59) && n % 2 == 1)
                printf("%d\n", 8);
            else if (n < adder(60) && n % 2 == 1)
                printf("%d\n", 9);
        }
        else if (n >= adder(60) && n < adder(70) - 1)
        {
            if (n % 2 == 0)
            {
                printf("%d\n", 9);
            }
            else if (n < adder(61) && n % 2 == 1)
                printf("%d\n", 0);
            else if (n < adder(62) && n % 2 == 1)
                printf("%d\n", 1);
            else if (n < adder(63) && n % 2 == 1)
                printf("%d\n", 2);
            else if (n < adder(64) && n % 2 == 1)
                printf("%d\n", 3);

            else if (n < adder(65) && n % 2 == 1)
                printf("%d\n", 4);
            else if (n < adder(66) && n % 2 == 1)
                printf("%d\n", 5);
            else if (n < adder(67) && n % 2 == 1)
                printf("%d\n", 6);
            else if (n < adder(68) && n % 2 == 1)
                printf("%d\n", 7);
            else if (n < adder(69) && n % 2 == 1)
                printf("%d\n", 8);
            else if (n < adder(70) && n % 2 == 1)
                printf("%d\n", 9);
        }
        else if (n >= adder(70) - 1 /*&& n < adder(70)-1 */)
        {
            if (n % 3 == 1 && n <= 54703)
                printf("%d\n", 1);
            if (n % 3 == 1 && n <= 129553)
                printf("%d\n", 2);
            if (n % 3 == 1 && n <= 234403)
                printf("%d\n", 3);
            if (n % 3 == 2 && n <= 12992)
                printf("%d\n", 0);
            if (n % 3 == 0)
                printf("%d\n", 0);
        }
    }
}
