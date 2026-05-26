/**
 * @author kmonjard (dowiw)
 */

#include <iostream>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			std::string s = av[i];

			if (i == ac - 1)
			{
				for (auto c : s)
					std::cout << (char)toupper(c);
			}
			else
			{
				for (auto c : s)
					std::cout << (char)toupper(c);
					std::cout << " ";
			}
		}
		std::cout << "\n";
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}
