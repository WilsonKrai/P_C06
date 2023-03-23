#include <unistd.h>
#include <stdio.h>

int	my_strcmp(char *s1, char *s2);

void	my_swap(char **a, char **b);

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc - 1)
	{
		if (my_strcmp(argv[i], argv[i + 1]) > 0)
		{
			my_swap(argv + i, argv + i + 1);
			i = 1;
		}
		else
			i++;
	}
	i = 1;
	while (i < argc - 1)
	{
		j = 0;
		while(argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\0", 1);
		i++;
	}
}

int	my_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0' && s1[x] == s2[x])
	{
		x++;
	}
	return (s1[x] - s2[x]);
}

void	my_swap(char **a, char **b)
{
	char	*swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
