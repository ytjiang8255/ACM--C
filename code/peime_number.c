#include<stdio.h>
#include<math.h>
#define MAX 1000


int prime[MAX];

int isPrimeNaive(int n)
{
    if(n <= 1)
        return 0;
    for(int i = 2; i < n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int isPrime(int n)
{
    if(n<= 1)
        return 0;
    if(n == 2)
        return 1;
    if(n%2 == 0)
        return 0;
    int limit = (int)sqrt((double)n);		//	sqrt()函数需要double 强制转换
    for(int i = 3; i <= limit; i=i+2)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

void sieve()
{
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i < MAX; i++)
        prime[i] = 1;
    int limit = (int)sqrt((double)MAX);
    for(int i = 2; i <= limit; i++)
    {
        if(prime[i])
            for(int j = i*i; j <= MAX; j+=i)
                prime[j] = 0;
    }
}

int isPrimeSieve(int n)
{
    if(prime[n])
        return 1;
    else
        return 0;
}

int main()
{
	int i;
	
    sieve();
	
	printf("input number is :\t");
	scanf("%d",i);
    printf("N=%d %d\n",i, isPrime(i));
    printf("N=%d %d\n", 2, isPrime(2));
    printf("N=%d %d\n", 3, isPrime(3));

    return 0;
}