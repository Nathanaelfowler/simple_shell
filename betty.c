#include <stdio.h>

/**
 * main - finding the sum of two int.
 * Return: 0
 */
int main(void)
{
	int sum, a, b;

	printf("Enter two numbers\n");
	scanf("%d %d", &a, &b);

	sum = a + b;

	printf("Sum: %d\n", sum);

	return (0);
}
