#include <stdio.h>

int main()
{
int a, b, c;
int sum, product;
float average;
printf("Введите три числа:");
scanf("%d %d %d", &a, &b, &c);
 sum = a+b+c;
 product = a*b*c;
printf("%d+%d+%d=%d\n", a, b, c, sum);
printf("%d*%d*%d=%d\n", a, b, c, product);
average = (float)sum/3;
 printf("(%d+%d+%d)/3=%.2f\n", a, b, c, average);
return 0;
}

