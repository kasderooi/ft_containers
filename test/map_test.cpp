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
    ft::pair<ft::map<char, int>::iterator,bool> ft_pair_ret;
    std::pair<std::map<char, int>::iterator,bool> std_pair_ret;
    ft::map<char, int>::iterator ft_it;
    std::map<char, int>::iterator std_it;
    ft::map<char, int>::iterator ft_begin;
    std::map<char, int>::iterator std_begin;
    size_t ft_size_ret;
    size_t std_size_ret;
    for ( char ch = 'a'; ch < 'z'; ch++ ){
        ft_map2.insert( ft::pair<char, int>( ch, ch ) );
        std_map2.insert( std::pair<char, int>( ch, ch ) );
    }
    ft_pair_ret = ft_map1.insert(ft::pair<char,int>('a', 3 ) );
    std_pair_ret = std_map1.insert(std::pair<char,int>('a', 3 ) );
    ft_begin = ft_map1.begin();
    std_begin = std_map1.begin();
    SECTION("ret test"){
        REQUIRE(ft_pair_ret.first->first == std_pair_ret.first->first );
        REQUIRE(ft_pair_ret.second == std_pair_ret.second );
    }
    ft_it = ft_map1.insert( ft_begin, ft::pair<char,int>( 'b', 2 ) );
    std_it = std_map1.insert( std_begin, std::pair<char,int>( 'b', 2 ) );
    SECTION("ret test"){
        REQUIRE( ft_it->first == std_it->first );
        REQUIRE( ft_it->second == std_it->second );
    }
    ft_it = ft_map1.insert( ft_begin, ft::pair<char,int>( 'b', 2 ) );
    std_it = std_map1.insert( std_begin, std::pair<char,int>( 'b', 2 ) );
    SECTION("ret test"){
        REQUIRE( ft_it->first == std_it->first );
        REQUIRE( ft_it->second == std_it->second );
    }
	ft_map1['b'] = 2;
	std_map1['b'] = 2;
    ft_map1['c'] = 1;
    std_map1['c'] = 1;
    ft_map1['c'] = 0;
    std_map1['c'] = 0;
    ft_map1.insert( ft_map2.begin(), ft_map2.end() );
    std_map1.insert( std_map2.begin(), std_map2.end() );
    ft_size_ret = ft_map1.erase( 'z' );
    std_size_ret = ft_map1.erase( 'z' );
    SECTION("ret test"){
        REQUIRE( ft_size_ret == std_size_ret );
    }
    ft_size_ret = ft_map1.erase( 'z' );
    std_size_ret = ft_map1.erase( 'z' );
    SECTION("ret test"){
        REQUIRE( ft_size_ret == std_size_ret );
    }
    ft_map1.erase( --ft_map1.end() );
    std_map1.erase( --std_map1.end() );
    SECTION("begin/end ++/--") {
        REQUIRE( ft_map1.size() == std_map1.size() );
        REQUIRE( ft_map1.begin()->first == std_map1.begin()->first );
        REQUIRE( ft_map1.begin()->second == std_map1.begin()->second );
        REQUIRE( (++ft_map1.begin())->first == (++std_map1.begin())->first );
        REQUIRE( (++ft_map1.begin())->second == (++std_map1.begin())->second );
        REQUIRE( (--ft_map1.end())->first == (--std_map1.end())->first );
        REQUIRE( (--ft_map1.end())->second == (--std_map1.end())->second );
        REQUIRE( (ft_map1.rbegin())->first == (std_map1.rbegin())->first );
        REQUIRE( (ft_map1.rbegin())->second == (std_map1.rbegin())->second );
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
        REQUIRE( (++ft_map1.begin())->first == (++std_map1.begin())->first );
        REQUIRE( (++ft_map1.begin())->second == (++std_map1.begin())->second );
        REQUIRE( (--ft_map1.end())->first == (--std_map1.end())->first );
        REQUIRE( (--ft_map1.end())->second == (--std_map1.end())->second );
        REQUIRE( (ft_map1.rbegin())->first == (std_map1.rbegin())->first );
        REQUIRE( (ft_map1.rbegin())->second == (std_map1.rbegin())->second );
        REQUIRE( (++ft_map1.rbegin())->first == (++std_map1.rbegin())->first );
        REQUIRE( (++ft_map1.rbegin())->second == (++std_map1.rbegin())->second );
        REQUIRE( (--ft_map1.rend())->first == (--std_map1.rend())->first );
        REQUIRE( (--ft_map1.rend())->second == (--std_map1.rend())->second );
    }
    ft::map<char, int> ft_map3(ft_map1);
    std::map<char, int> std_map3(std_map1);
    ft_map1.clear();
    std_map1.clear();
    ft::map<char, int> ft_map4(ft_map3.begin(), ft_map3.end());
    std::map<char, int> std_map4(std_map3.begin(), std_map3.end());
    ft_map3.clear();
    std_map3.clear();
    ft::map<char, int> ft_map5;
    std::map<char, int> std_map5;
    ft_map5 = ft_map4;
    std_map5 = std_map4;
    ft_map4.clear();
    std_map4.clear();
    SECTION("clear"){
        REQUIRE( ft_map1.size() == std_map1.size() );
        REQUIRE( ft_map1.empty() == std_map1.empty() );
        REQUIRE( ft_map2.size() == std_map2.size() );
        REQUIRE( ft_map2.empty() == std_map2.empty() );
        REQUIRE( ft_map3.size() == std_map3.size() );
        REQUIRE( ft_map3.empty() == std_map3.empty() );
        REQUIRE( ft_map4.size() == std_map4.size() );
        REQUIRE( ft_map4.empty() == std_map4.empty() );
    }
    SECTION("copy/range constructer & assignment operator") {
        REQUIRE(ft_map5.size() == std_map5.size() );
        REQUIRE(ft_map5.begin()->first == std_map5.begin()->first );
        REQUIRE(ft_map5.begin()->second == std_map5.begin()->second );
        REQUIRE((++ft_map5.begin())->first == (++std_map5.begin())->first );
        REQUIRE((++ft_map5.begin())->second == (++std_map5.begin())->second );
        REQUIRE((--ft_map5.end())->first == (--std_map5.end())->first );
        REQUIRE((--ft_map5.end())->second == (--std_map5.end())->second );
        REQUIRE((ft_map5.rbegin())->first == (std_map5.rbegin())->first );
        REQUIRE((ft_map5.rbegin())->second == (std_map5.rbegin())->second );
        REQUIRE((++ft_map5.rbegin())->first == (++std_map5.rbegin())->first );
        REQUIRE((++ft_map5.rbegin())->second == (++std_map5.rbegin())->second );
        REQUIRE((--ft_map5.rend())->first == (--std_map5.rend())->first );
        REQUIRE((--ft_map5.rend())->second == (--std_map5.rend())->second );
    }
    SECTION("count & upper/lower bound"){
        for( char ch = 'a'; ch <= 'x'; ch++ ) {
            REQUIRE(ft_map5.count(ch ) == std_map5.count(ch ));
            REQUIRE(ft_map5.lower_bound(ch )->first == std_map5.lower_bound(ch )->first);
            REQUIRE(ft_map5.upper_bound(ch )->first == std_map5.upper_bound(ch )->first);
        }
    }
    SECTION("equal range"){
        for( char ch = 'a'; ch <= 'y'; ch++ ){
            ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ft_pair = ft_map5.equal_range(ch);
            std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> std_pair = std_map5.equal_range(ch);
            REQUIRE( ft_pair.first->first == std_pair.first->first );
            REQUIRE( ft_pair.second->first == std_pair.second->first );
        }
    }
}