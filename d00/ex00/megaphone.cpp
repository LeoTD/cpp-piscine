#include <iostream>

#define NL std::endl
#define SOUT std::cout << 

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	else
		return (c);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		SOUT "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << NL;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j] != '\0'; j++)
		{
			av[i][j] = to_upper(av[i][j]);
		}
		SOUT av[i];
	}
	SOUT NL;
	return (0);
}