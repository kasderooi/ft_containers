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
    ft_map1.insert( ft::pair<int,int>( 'a', 3 ) );
    std_map1.insert( std::pair<int,int>( 'a', 3 ) );
	ft_map1['b'] = 2;
	std_map1['b'] = 2;

    SECTION("begin/end ++/--") {
		REQUIRE( ft_map1.begin()->first == std_map1.begin()->first );
		REQUIRE( ft_map1.begin()->second == std_map1.begin()->second );
		REQUIRE( (--ft_map1.end())->first == (--std_map1.end())->first );
		REQUIRE( (--ft_map1.end())->second == (--std_map1.end())->second );
		REQUIRE( (++ft_map1.rbegin())->first == (++std_map1.rbegin())->first );
		REQUIRE( (++ft_map1.rbegin())->second == (++std_map1.rbegin())->second );
		REQUIRE( ft_map1.rend()->first == std_map1.rend()->first );
		REQUIRE( ft_map1.rend()->second == std_map1.rend()->second );
	}
}