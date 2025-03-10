#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
int main()
{
	double x,sum=0;
	int y;
	scanf("%lf%d", &x, &y);
	if (x > 0)
	{
		if (x <= 3)
		{
			sum = 10;
		}
		if (x > 3 && x < 10)
		{
			sum = 10 + 2 * (x - 3);
		}
		if (x >= 10)
		{
			sum = 10 + 14 + 3 * (x - 10);
		}
	}
	sum += y / 5*2;
	sum = (int)((sum * 1) + 0.5) / 1.0;    //取整保留大麻烦！！！
	printf("%.0lf", sum);
}
//#include<stdio.h>
//int main()
//{
//    int m, b, c;
//    double a, n, sum;
//
//    scanf("%lf%d", &n, &m);
//
//    if (n <= 3)
//        a = 10;
//
//    else if (n <= 10)
//        a = 10 + 2 * (n - 3);
//
//    else
//        a = 24 + (n - 10) * 3;
//
//    b = m / 5 * 2;
//    sum = a + b;
//
//    c = (int)((sum * 1) + 0.5) / 1.0;
//
//    printf("%d", c);
//
//    return 0;
//}