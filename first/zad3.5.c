#include <stdio.h>

int main()
{ 
int a, b, c, d, t, max;
printf("Введите пять чисел\n ");
scanf("%d%d%d%d%d", &a, &b, &c, &d, &t );
max = a;
if(b > max )
{
 max = b;
}
if(c > max)
{ 
max = c;
}
if(d > max)
{
 max = d;
}
if (t > max)
{
max = t;
}
 printf("Наибольшее число %d\n", max);
 return 0;
}	
