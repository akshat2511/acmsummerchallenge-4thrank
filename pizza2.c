#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t, q;
    int time,time1 = 0;
    int min = 10000;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &q);
        char query[q][100];
        for (int j = 0; j < q; j++)
        {
            scanf("%s", query[j]);
        }
        for (int x = 0; x < q; x++)
        {
            for (int y = 0; y < x; y++)
            {
                time=0;
                int x1 = 0;
                int y1 = 0;
                int temp, c = 0;
            akshat:
                if (query[x][x1] == query[y][y1] && query[x][x1 + 1] == query[y][y1 + 1] && query[y][y1] != '\0' && query[x][x1] != '\0')
                {
                    x1++;
                    y1++;
                    goto akshat;
                }
                if (query[x][x1] == query[y][y1] && query[x][x1 + 1] != query[y][y1 + 1] && query[y][y1] != '\0' && query[x][x1] != '\0')
                {
                    time++;
                    y1++;
                    goto akshat;
                }
                if (query[x][x1] != query[y][y1] && query[y][y1] != '\0' && query[x][x1] != '\0')
                {
                    if (c == 0)
                        temp = y1;
                    c++;
                    y1++;
                    goto akshat;
                }
                if (query[x][x1] != query[y][y1] && query[y][y1] == '\0' && query[x][x1] != '\0')
                {
                    time++;
                    x1++;
                    y1 = temp;
                    c = 0;
                    goto akshat;
                }
                if (time < min)
                    min = time;
            }
            if(x==0)printf("%d\n",strlen(query[0]));
            else
            printf("%d\n", min-1);
            min=10000;
        }
    }
}