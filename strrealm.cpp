#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int t;
    int count = 0;
    cin >> t;
    int max = 0;

    while (t--)
    {
        int q;
        cin >> q;
        string word[q];
        for (int i = 0; i < q; i++)
        {
            int type;
            cin >> type;

            if (type == 1)
            {

                cin >> word[i];
            }
            else if (type == 2)
            {
                int km;
                cin >> km;
                for (int j = 0; j < q; j++)
                {
                    for (int k = 0; k < q; k++)
                    {
                        if (word[j].substr(0, km) == word[k].substr(0, km))
                        {
                            count++;
                        }
                    }
                    if(count>max)max = count;
                }
                cout<< max<< endl;
                max=0;
            }
        }

        return 0;
    }
}