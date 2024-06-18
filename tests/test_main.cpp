#include <iostream>
#include <cassert>

int ft_sum(int, int);

void test_sum(void)
{
	assert(ft_sum(2, 4) == 6);
	assert(ft_sum(0, 0) == 0);
	assert(ft_sum(0, 1) == 1);
	assert(ft_sum(-10, 40) == 30);
	std::cout << "All tests OK!" << std::endl;
}

int main(void) {
	test_sum();
}