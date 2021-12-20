#include <iostream>
#include "ft_vector.hpp"
#include <vector>

int main() {
	std::vector<int> std_vec(1000);
	ft::vector<int> ft_vec(1000);

	std::cout << "std" << std_vec.size() << "\t" << std_vec.capacity() << std::endl;
	std_vec.resize(100);
	std::cout << "std" << std_vec.size() << "\t" << std_vec.capacity() << std::endl;
	std_vec.reserve(1023);
	std::cout << "std" << std_vec.size() << "\t" << std_vec.capacity() << std::endl;
	std::cout << "ft" << ft_vec.size() << "\t" <<ft_vec.capacity() << std::endl;
	ft_vec.resize(100);
	std::cout << "ft" << ft_vec.size() << "\t" << ft_vec.capacity() << std::endl;
	ft_vec.reserve(1023);
	std::cout << "ft" << ft_vec.size() << "\t" << ft_vec.capacity() << std::endl;
	for ( int i = 0; i < 100; i++ )
		std_vec[i] = i;
	try {
		std_vec.reserve( std_vec.max_size() + 1 );
	} catch ( const std::length_error& e ) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std_vec.at( 99 );
	} catch ( const std::out_of_range& e ) {
		std::cerr << e.what() << std::endl;
	}
	try {
		ft_vec.reserve( std_vec.max_size() + 1 );
	} catch ( const std::length_error& e ) {
		std::cerr << e.what() << std::endl;
	}
}
