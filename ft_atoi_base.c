#include "string.h"
#include "stdio.h"

static int	ft_whitespace(const char c)
{
	if (c == ' ' || c == '\0' || c == '\v' || c == '\t' || c == '\f'
			|| c == '\r' || c == '\n')
		return (1);
	return (0);
}

static int	check_nb(int c, int str_base)
{
	char *str = "01234567890abcdef";
	char *str2 = "01234567890ABCDEF";

	while (str_base--)
	{
		if (c == str[str_base] || c == str2[str_base])
			return (1);
	}
	return (-1);
}

static int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c = 'A' + 10);
	return (0);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int res;
	int negative;
	size_t i;

	res = 0;
	negative = 1;
	while (ft_whitespace(*str))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while(check_nb(*str, str_base)&& *str)
		res = res * str_base + value_of(*str++);
		return (res * negative);
}

int main(void)
{
	char str[] = "abcd4";
	int str_base = 16;
	printf("%d", ft_atoi_base(str, str_base));
}
