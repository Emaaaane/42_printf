#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
}

void ft_putnbr(int n)
{
    if(n == -2147483648)
    {
        write(1, "-2147483648", 11);
    }
    else if(n < 0)
    {
        n = -n;
        ft_putchar('-');
        ft_putnbr(n);
    }
    else if(n > 9)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
        ft_putchar(n + 48);
    
}

int main()
{
    int i = 2147483648;
    ft_putnbr(i);
}
