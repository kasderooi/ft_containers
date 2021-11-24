//
// Created by Kester kas De rooij on 11/24/21.
//

#include "catch.hpp"
#include "vector.hpp"
#include <vector>

#define MAX_VAL 2345

TEST_CASE("Vector", "[Vector]") {
	ft::vector<int> ft_first;
	std::vector<int> std_first;
	ft::vector<int> ft_second(MAX_VAL);
	std::vector<int> std_second(MAX_VAL);

	for ( unsigned int i = 0; i < MAX_VAL; i++ ){
		ft_second[i] = i;
		std_second[i] = i;
	}
	SECTION("Assigned constructor") {
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE(ft_second[i] == std_second[i]);
		REQUIRE(ft_second.capacity() == std_second.capacity());
		REQUIRE(ft_second.size() == ft_second.size());
	}
	ft::vector<int> ft_third(ft_second);
	std::vector<int> std_third(std_second);
	ft_first = ft_second;
	std_first = std_second;
	for ( unsigned int i = 0; i < MAX_VAL; i++ ){
		ft_second[i] = 0;
		std_second[i] = 0;
	}
	SECTION("Assignment operator") {
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE(ft_first[i] == std_first[i]);
		REQUIRE(ft_first.capacity() == std_first.capacity());
		REQUIRE(ft_first.size() == ft_first.size());
	}
	SECTION("Copy constructor") {
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE(ft_third[i] == std_third[i]);
		REQUIRE(ft_third.capacity() == std_third.capacity());
		REQUIRE(ft_third.size() == ft_third.size());
	}
}
