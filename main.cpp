#include <iostream>

extern "C" int ft_strlen();

int main(void)
{
	std::cout << "return value: " << ft_strlen() << std::endl;
}