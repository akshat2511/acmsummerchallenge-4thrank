#include <iostream>
#include <string>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void updateString(std::string &s, int *a, int *b, int n)
{   int x=n;
    char min = 'z';
    int key = 0;
    int temp=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[j] == 0)
            {
                char updatedChar = 'a' + (s[i] - 'a' + a[j]) % 26;
                if (updatedChar < min)
                {
                    min = updatedChar;
                    key = j;
                }
            }
        }
        s[i] = min;
        b[key] = 1;
        temp=b[key];
        b[key]=b[n];
        b[n]=temp;
        temp=a[key];
        a[key]=a[n];
        n=n-1;
        min = 'z';
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        b[i] = 0;
    }

    updateString(s, a, b, n);

    std::cout << s << std::endl;

    delete[] a;
    delete[] b;
    return 0;
}
