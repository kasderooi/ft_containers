#include <iostream>
#include "Vector.hpp"
#include <vector>

int main() {
	std::vector<int> vec1(1000);
	ft::Vector<int> vec2(1000);
	ft::Vector<int>::iterator it2 = vec2.begin();

	for (std::vector<int>::iterator it1 = vec1.begin(); it1 < vec1.end(); it1++)
	{
		*it1 = arc4random() % 100;
		*it2 = *it1;
		it2++;
	}
	std::cout << *(vec1.begin()) << std::endl;
	std::cout << *(vec2.begin()) << std::endl;
	std::cout << vec1[0] << std::endl;
	std::cout << vec2[0] << std::endl;
	std::cout << *((vec1.end())--) << std::endl;
	std::cout << *((vec2.end())--) << std::endl;
	std::cout << *(--(vec1.end())) << std::endl;
	std::cout << *(--(vec2.end())) << std::endl;

	std::cout << vec1[999] << std::endl;
	std::cout << vec2[999] << std::endl;
}
