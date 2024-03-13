#include <iostream>
#include <string>
using namespace std;

int main()
{
    string digi;
    for (int i = 1; i < 3500; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // string str = to_string(i - 1);
            digi.append(to_string(i ));
        }}
   
    cout << digi.size() << endl;
    //cout << digi << endl;
    }