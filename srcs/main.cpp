#include <iostream>
#include "ft_map.hpp"
#include <map>
#include <iterator>

void test( void ){
	ft::map< char, int > ft_map1;
	ft::map< char, int > ft_map2;
	ft::pair< ft::map< char, int >::iterator, bool > ft_pair_ret;
	ft::map< char, int >::iterator ft_it;
	ft::map< char, int >::iterator ft_begin;
	size_t ft_size_ret;
	for ( char ch = 'a'; ch < 'z'; ch++ ){
		ft_map2.insert( ft::pair< char, int >( ch, ch ));
	}
	ft_pair_ret = ft_map1.insert( ft::pair< char, int >( 'a', 3 ));
	ft_begin = ft_map1.begin();
	ft_it = ft_map1.insert( ft_begin, ft::pair< char, int >( 'b', 2 ));
	std::cout << ft_it->first << " " << ft_it->second << std::endl;
	ft_map1.erase( ft_map1.begin());
	ft_it = ft_map1.insert( ft_begin, ft::pair< char, int >( 'b', 2 ));
	std::cout << ft_it->first << " " << ft_it->second << std::endl;
	ft_it = ft_map1.insert( ft_begin, ft::pair< char, int >( 'b', 2 ));
	std::cout << ft_it->first << " " << ft_it->second << std::endl;
	ft_it = ft_map1.insert( ft_begin, ft::pair< char, int >( 'a', 2 ));
	std::cout << ft_it->first << " " << ft_it->second << std::endl;
	ft_map1['b'] = 2;
	ft_map1['c'] = 1;
	ft_map1['c'] = 0;
	ft_map1.insert( ft_map2.begin(), ft_map2.end());
	ft_size_ret = ft_map1.erase( 'z' );
	ft_size_ret = ft_map1.erase( 'z' );
	ft_map1.erase( --ft_map1.end());
	ft_map1.swap( ft_map2 );
	ft_map1.erase( 'k' );
	ft_map2.clear();
	ft::map< char, int > ft_map3( ft_map1 );
	ft_map1.clear();
	ft::map< char, int > ft_map4( ft_map3.begin(), ft_map3.end());
	ft_map3.clear();
	ft::map< char, int > ft_map5;
	ft_map5 = ft_map4;
	ft_map4.clear();
	for ( char ch = 'a'; ch <= 'x'; ch++ ){
		ft_map5.count( ch );
		ft_map5.lower_bound( ch );
		ft_map5.upper_bound( ch );
	}
	for ( char ch = 'a'; ch <= 'y'; ch++ ){
		ft::pair< ft::map< char, int >::iterator, ft::map< char, int >::iterator > ft_pair = ft_map5.equal_range( ch );
	}
}

int main(){

	test();
	system( "leaks smalltest" );
	return 0;
}
