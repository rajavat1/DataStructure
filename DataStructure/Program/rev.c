
#include <stdio.h>
void fun(int x)
{
    if (x > 0)
    {
        printf("%d \n", x);
        fun(x - 1);
    }
}

void main()
{
    fun(4);
}
