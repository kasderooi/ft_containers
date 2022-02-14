//
// Created by Kester kas De rooij on 2/8/22.
//

#include "catch.hpp"
#include "ft_map.hpp"
#include <map>

#define MAX_VAL 2345


TEST_CASE("map iterators", "[map]") {
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
    ft_map1.erase( --ft_map1.end() );
    std_map1.erase( --std_map1.end() );
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
	ft_map1.swap( ft_map2 );
    std_map1.swap( std_map2 );
    ft_map1.erase( 'k' );
    std_map1.erase( 'k' );
    ft_map2.clear();
    std_map2.clear();
    SECTION("after swap") {
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
    SECTION("clear"){
        REQUIRE( ft_map2.size() == std_map2.size() );
        REQUIRE( ft_map2.empty() == std_map2.empty() );
    }
    SECTION("upper/lower bound"){
        for( char ch = 'a'; ch <= 'x'; ch++ ) {
            REQUIRE(ft_map1.lower_bound( ch )->first == std_map1.lower_bound( ch )->first);
            REQUIRE(ft_map1.upper_bound( ch )->first == std_map1.upper_bound( ch )->first);
        }
    }
    SECTION("equal range"){
        for( char ch = 'a'; ch <= 'y'; ch++ ){
            ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ft_pair = ft_map1.equal_range('j');
            std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> std_pair = std_map1.equal_range('j');
            REQUIRE( ft_pair.first->first == std_pair.first->first );
            REQUIRE( ft_pair.second->first == std_pair.second->first );
        }
    }
}