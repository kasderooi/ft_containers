#include <iostream>
#include "Vector.hpp"
#include <vector>

int main() {
	std::vector<int> vec1(1000);
	ft::Vector<int> vec2(1000);
	ft::Vector<int>::iterator it1 = vec2.begin();
	ft::Vector<int>::iterator it2 = vec2.begin();
	std::vector<int>::iterator it3 = vec1.begin();
	std::vector<int>::iterator it4 = vec1.begin();
	int i = 0;

	for (std::vector<int>::iterator it = vec1.begin(); it < vec1.end(); it++) {
		*it = i;
		*it1 = i;
		it1++;
		i += 2;
	}
	it1 = vec2.begin();
	it1 += 15;
	it2 += 60;
	it3 += 15;
	it4 += 60;
	std::cout << *it1 << std::endl;
	std::cout << *it2 << std::endl;
	std::cout << it2 - it1 << std::endl;
	std::cout << *it3 << std::endl;
	std::cout << *it4 << std::endl;
	std::cout << it4 - it3 << std::endl;


}
