#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;
int prime(int x)
{
    int vi = 1;
    for (int j = 2; j <= sqrt(x); j++)
    {
        if (x % j == 0)
        {
            vi=0;
        }
    }
    if (x == 1) vi = 0;
    return vi;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (prime(t)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

