#include "push_swap.h"

int find_smaller(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int find_bigger(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

void element_swap(int *a, int *b)
{
	int temp;

	temp = (*a);
	*a = *b;
	(*b) = temp;
}