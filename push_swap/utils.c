#include "push_swap.h"

char	*ps_atoi(char *str, int *num_container)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*(str++) - '0');
		if (num * sign > 2147483647 || num * sign < -2147483648)
			return (NULL);
	}
	if (!(*str == ' ' || *str == '\0'))
		return (NULL);
	*num_container = num * sign;
	return (str);
}
