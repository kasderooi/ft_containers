#include <iostream>
#include "Vector.hpp"
#include <vector>

int main() {
	std::vector<int> vec1(1000);
	ft::Vector<int> vec2(1000);
	ft::Vector<int>::iterator it1 = vec2.begin();
	int i = 0;

	for (std::vector<int>::iterator it = vec1.begin(); it < vec1.end(); it++) {
		*it = i;
		*it1 = i;
		it1++;
		i += 2;
	}
	std::vector<int>::reverse_iterator it3 = vec1.rbegin();
	ft::Vector<int>::reverse_iterator it4 = vec2.rbegin();

	while (it3 < vec1.rend() && it4 < vec2.rend()) {
		std::cout << *it3++ << std::endl;
		std::cout << *it4++ << std::endl;
	}
	if (it3 < vec1.rend())
		std::cout << *it3 << "it3" << std::endl;
	if (it4 < vec2.rend())
		std::cout << *it4 << "it4" << std::endl;



}
