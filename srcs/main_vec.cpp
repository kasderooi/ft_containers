#include <iostream>
#include "ft_vector.hpp"
#include <vector>
#include <iterator>

void function2( void ) {
	ft::vector<int> ft_first(10);
	std::vector<int> std_first(10);
	ft::vector<int> ft_second(21);
	std::vector<int> std_second(21);
	ft::vector<int> ft_third(10);
	std::vector<int> std_third(10);
	for ( int i = 0; i < 10; i++ ) {
		ft_first[i] = i;
		std_first[i] = i;
	}
	ft_second.assign( ft_first.begin(), ft_first.end() );
	std_second.assign( std_first.begin(), std_first.end() );
	ft_second.assign( 42, 33 );
	std_second.assign(42, 33 );
	for (int i = 0; i < 100; i++) {
		ft_first.push_back(i);
		ft_second.push_back(i);
		std_first.push_back(i);
		std_second.push_back(i);
	}
	ft_first.pop_back();
	std_first.pop_back();
	ft::vector<int>::iterator ft_it1 = ft_first.begin();
	std::vector<int>::iterator std_it1 = std_first.begin();
	ft_it1 += 25;
	std_it1 += 25;
	std::cout << ft_first.capacity() << "\t" << std_first.capacity()<< std::endl;
	ft_first.insert( ft_it1, ft_second.begin(), ft_second.end() );
	std_first.insert( std_it1, std_second.begin(), std_second.end() );
	std::cout << ft_first.capacity() << "\t" << std_first.capacity()<< std::endl;
	ft::vector<int>::iterator ft_it3 = ft_third.begin();
	std::vector<int>::iterator std_it3 = std_first.begin();
	std::cout << ft_third.capacity() << "\t" << std_third.capacity()<< std::endl;
//	ft_third.insert( ft_it3, ft_second.begin(), ft_second.end() );
//	std_third.insert( std_it3, std_second.begin(), std_second.end() );
	std::cout << ft_third.capacity() << "\t" << std_third.capacity()<< std::endl;
	ft_it1 = ft_second.begin();
	std_it1 = std_second.begin();
	ft_it1 += 12;
	std_it1 += 12;
	std::cout << ft_second.capacity() << "\t" << std_second.capacity()<< std::endl;
	ft_second.insert( ft_it1, 999 );
	std_second.insert( std_it1, 999 );
	std::cout << ft_second.capacity() << "\t" << std_second.capacity()<< std::endl;
	std::cout << ft_second.size() << "\t" << std_second.size()<< std::endl;
	ft_second.insert( ft_it1, 222,999 );
	std_second.insert( std_it1, 222, 999 );
	std::cout << ft_second.size() << "\t" << std_second.size()<< std::endl;
	std::cout << ft_second.capacity() << "\t" << std_second.capacity()<< std::endl;
}

void std_check( std::vector<std::string> std_vec, std::vector<std::string> std_vec2 ) {
	if ( std_vec < std_vec2 )
		std::cout << "std smaller" << std::endl;
	if ( std_vec <= std_vec2 )
		std::cout << "std smaller/equal" << std::endl;
	if ( std_vec > std_vec2 )
		std::cout << "std bigger" << std::endl;
	if ( std_vec >= std_vec2 )
		std::cout << "std bigger/equal" << std::endl;
	if ( std_vec == std_vec2 )
		std::cout << "std equal" << std::endl;
	if ( std_vec != std_vec2 )
		std::cout << "std not equal" << std::endl;
}
void ft_check( ft::vector<std::string> std_vec, ft::vector<std::string> std_vec2 ) {
	if ( std_vec < std_vec2 )
		std::cout << "ft smaller" << std::endl;
	if ( std_vec <= std_vec2 )
		std::cout << "ft smaller/equal" << std::endl;
	if ( std_vec > std_vec2 )
		std::cout << "ft bigger" << std::endl;
	if ( std_vec >= std_vec2 )
		std::cout << "ft bigger/equal" << std::endl;
	if ( std_vec == std_vec2 )
		std::cout << "ft equal" << std::endl;
	if ( std_vec != std_vec2 )
		std::cout << "ft not equal" << std::endl;
}
void function3( void ) {
	std::vector<std::string> std_vec(10);
	std::vector<std::string> std_vec2(10);
	ft::vector<std::string> ft_vec(10);
	ft::vector<std::string> ft_vec2(10);

	for (int i = 0; i < 10; i++){
		std_vec[i] = "hoi";
		std_vec2[i] = "hoi";
		ft_vec[i] = "hoi";
		ft_vec2[i] = "hoi";
	}
	std_vec.push_back("aaa");
	ft_vec.push_back("aaa");
	std::cout << "pushback1 aaa" << std::endl;
	std_check( std_vec, std_vec2 );
	ft_check( ft_vec, ft_vec2 );
	std_vec2[2] = "zzz";
	ft_vec2[2] = "zzz";
	std::cout << "vec2[2] zzz" << std::endl;
	std_check( std_vec, std_vec2 );
	ft_check( ft_vec, ft_vec2 );

}

void function1( void ) {

	std::vector<int> std_vec(10);
	std::vector<int> std_vec2(100);
	ft::vector<int> ft_vec(10);
	ft::vector<int> ft_vec2(100);

	for ( int i = 0; i < 10; i++ ) {
		std_vec[i] = i;
		ft_vec[i] = i;
	}
	for ( int i = 0; i < 100; i++ ) {
		std_vec2[i] = i;
		ft_vec2[i] = i;
	}
	std::vector<int>::iterator std_it = std_vec.begin();
	ft::vector<int>::iterator ft_it = ft_vec.begin();
	std::vector<int>::iterator std_it2 = std_vec.begin();
	ft::vector<int>::iterator ft_it2 = ft_vec.begin();
	std_it++;
	ft_it++;
	std_it++;
	ft_it++;
	for (int i = 0; i < 30; i++) {
		std_it2++;
		ft_it2++;
	}
	std_vec.insert( std_it++, -1 );
	ft_vec.insert( ft_it++, -1 );


	for ( int i = 0; i < 15; i++ ) {
		std::cout << std_vec[i] << "\t" << ft_vec[i] << std::endl;
	}
	std_vec2.insert( std_it2, std_vec.begin(), std_vec.end() );
	ft_vec2.insert( ft_it2, ft_vec.begin(), ft_vec.end() );

	for ( int i = 0; i < 100; i++ ) {
		std::cout << std_vec2[i] << "\t" << ft_vec2[i] << std::endl;
	}
	std::cout << *std_it << "\t" << *ft_it << std::endl << std::endl;
	ft_it = ft_vec.begin();
	std_it = std_vec.begin();
	std_it += 5;
	ft_it += 5;
	std::cout << *std_vec.erase( std_it );
	std::cout << "\t" << *ft_vec.erase( ft_it ) << std::endl;
	for ( int i = 0; i < 10; i++ ) {
		std::cout << std_vec[i] << "\t" << ft_vec[i] << std::endl;
	}
	std::cout << std::endl;
	ft_it2 = ft_vec2.begin();
	std_it2 = std_vec2.begin();
	std_it2 += 5;
	ft_it2 += 5;
	std::cout << *std_vec2.erase( std_it2, std_vec2.end() - 5 );
	std::cout << "\t" << *ft_vec2.erase( ft_it2, ft_vec2.end() - 5 ) << std::endl << std::endl;
	for ( int i = 0; i < 10; i++ ) {
		std::cout << std_vec2[i] << "\t" << ft_vec2[i] << std::endl;
	}
}

int main() {
//	function1();
	function2();
//	function3();
	system( "leaks smalltest");
}
