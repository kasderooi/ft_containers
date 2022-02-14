//
// Created by Kester kas De rooij on 2/8/22.
//

#include "catch.hpp"
#include "ft_map.hpp"
#include <map>

#define MAX_VAL 2345


TEST_CASE("vector iterators", "[vector]") {
    ft::map<char, int> ft_map1;
    std::map<char, int> std_map1;
    ft::map<char, int> ft_map2;
    std::map<char, int> std_map2;
    for ( char ch = 'a'; ch < 'z'; ch++ ){
        ft_map2.insert( ft::pair<char, int>( ch, ch ) );
        std_map2.insert( std::pair<char, int>( ch, ch ) );
    }
    ft_map1.insert( ft::pair<char,int>( 'a', 3 ) );
    std_map1.insert( std::pair<char,int>( 'a', 3 ) );
	ft_map1['b'] = 2;
	std_map1['b'] = 2;
    ft_map1['c'] = 1;
    std_map1['c'] = 1;
    ft_map1.insert( ft_map2.begin(), ft_map2.end() );
    std_map1.insert( std_map2.begin(), std_map2.end() );
    ft_map1.erase( ft_map1.begin() );
    std_map1.erase( std_map1.begin() );
    ft_map1.erase( 'z' );
    ft_map1.erase( 'z' );
    std_map1.erase( 'z' );
    std_map1.erase( 'z' );

    SECTION("begin/end ++/--") {
        REQUIRE( ft_map1.size() == std_map1.size() );
		REQUIRE( ft_map1.begin()->first == std_map1.begin()->first );
		REQUIRE( ft_map1.begin()->second == std_map1.begin()->second );
		REQUIRE( (--ft_map1.end())->first == (--std_map1.end())->first );
		REQUIRE( (--ft_map1.end())->second == (--std_map1.end())->second );
		REQUIRE( (++ft_map1.rbegin())->first == (++std_map1.rbegin())->first );
		REQUIRE( (++ft_map1.rbegin())->second == (++std_map1.rbegin())->second );
		REQUIRE( (--ft_map1.rend())->first == (--std_map1.rend())->first );
		REQUIRE( (--ft_map1.rend())->second == (--std_map1.rend())->second );
	}
}