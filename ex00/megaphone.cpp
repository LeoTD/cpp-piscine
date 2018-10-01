#include <iostream>
using namespace std;

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	else
		return (c);
}

int		main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j] != '\0'; j++)
		{
			av[i][j] = to_upper(av[i][j]);
		}
		cout << av[i] << endl;
	}
}