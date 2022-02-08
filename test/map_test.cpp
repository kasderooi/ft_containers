//
// Created by Kester kas De rooij on 2/8/22.
//

#include "catch.hpp"
#include "ft_map.hpp"
#include <map>

#define MAX_VAL 2345


TEST_CASE("vector iterators", "[vector]") {
    ft::map<int, int> ft_map1;
    std::map<int, int> std_map1;
    ft_map1.insert( ft::pair<int,int>( 3, 3 ) );
    std_map1.insert( std::pair<int,int>( 3, 3 ) );
    ft_map1.insert( ft::pair<int,int>( 2, 2 ) );
    std_map1.insert( std::pair<int,int>( 2, 2 ) );
    ft_map1.insert( ft::pair<int,int>( 1, 1 ) );
    std_map1.insert( std::pair<int,int>( 1, 1 ) );
    for ( int i = 4; i < 100; i++ ){
        ft_map1.insert( ft::pair<int,int>( i, i ) );
        std_map1.insert( std::pair<int,int>( i, i ) );
    }
    SECTION("begin/end ++/--") {
        REQUIRE();
    }
}