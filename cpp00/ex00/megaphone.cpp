#include <iostream>

int main(int argc, char **argv)
{
int i;
int j;
char c;

if (argc == 1)
	std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
else
{
i = 1;
while (argv[i])
{
	j = 0;
	while (argv[i][j])
	{
        c = std::toupper(argv[i][j]);
		std::cout << c;
		j++;
	}
	i++;
}
}
std::cout << std::endl;
}