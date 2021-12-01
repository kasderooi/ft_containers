//
// Created by Kester kas De rooij on 11/24/21.
//

#include "catch.hpp"
#include "Vector.hpp"
#include <vector>

#define MAX_VAL 2345


TEST_CASE("Vector iterators", "[Vector]") {
	ft::Vector<int> ft1(MAX_VAL);
	std::vector<int> std1(MAX_VAL);
	ft::Vector<int>::iterator it1 = ft1.begin();
	int i = 0;

	for (std::vector<int>::iterator it2 = std1.begin(); it2 < std1.end(); it2++)
	{
		*it2 = arc4random() % 100;
		*it1 = *it2;
		it1++;
	}
	SECTION("begin/end ++/--") {
		REQUIRE(*(ft1.begin()) == *(std1.begin()));
		REQUIRE(*(++ft1.begin()) == *(++std1.begin()));
		REQUIRE(*(ft1.begin()++) == *(std1.begin()++));
		REQUIRE(ft1[0] == std1[0]);
		REQUIRE(ft1[MAX_VAL - 1] == std1[MAX_VAL - 1]);
		REQUIRE(ft1[MAX_VAL - 1] == *--ft1.end());
		REQUIRE(std1[MAX_VAL - 1] == *--std1.end());
		REQUIRE(ft1[MAX_VAL] == *ft1.end());
		REQUIRE(std1[MAX_VAL] == *std1.end());
		REQUIRE(ft1[MAX_VAL] == *ft1.end()--);
		REQUIRE(std1[MAX_VAL] == *std1.end()--);
	}

	SECTION("reverse begin/end ++/--") {
		REQUIRE(*(ft1.rbegin()) == *(std1.rbegin()));
		REQUIRE(*(++ft1.rbegin()) == *(++std1.rbegin()));
		REQUIRE(*(ft1.rbegin()++) == *(std1.rbegin()++));
		REQUIRE(ft1[0] == *--ft1.rend());
		REQUIRE(std1[0] == *--std1.rend());
		REQUIRE(ft1[MAX_VAL - 1] == *ft1.rbegin());
		REQUIRE(std1[MAX_VAL - 1] == *std1.rbegin());
		REQUIRE(ft1[MAX_VAL - 1] == *ft1.rbegin()--);
		REQUIRE(std1[MAX_VAL - 1] == *std1.rbegin()--);
	}
}

TEST_CASE("Vector<int> constructors, capacity & element access", "[Vector]") {
	ft::Vector<int> ft_first;
	std::vector<int> std_first;
	ft::Vector<int> ft_second(MAX_VAL);
	std::vector<int> std_second(MAX_VAL);

	SECTION("Empty capacity") {
		REQUIRE(ft_first.capacity() == std_first.capacity());
		REQUIRE(ft_first.size() == std_first.size());
		REQUIRE(ft_first.empty() == std_first.empty());
		REQUIRE(ft_first.max_size() == std_first.max_size());
		REQUIRE(ft_second.capacity() == std_second.capacity());
		REQUIRE(ft_second.size() == std_second.size());
		REQUIRE(ft_second.empty() == std_second.empty());
		REQUIRE(ft_second.max_size() == std_second.max_size());
	}
	for ( unsigned int i = 0; i < MAX_VAL; i++ ){
		ft_second[i] = i;
		std_second[i] = i;
	}
	SECTION("Assigned constructor & [] operator") {
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE(ft_second[i] == std_second[i]);
		REQUIRE(ft_second.capacity() == std_second.capacity());
		REQUIRE(ft_second.size() == std_second.size());
		REQUIRE(ft_second.empty() == std_second.empty());
		REQUIRE(ft_second.max_size() == std_second.max_size());
	}
	ft::Vector<int> ft_third(ft_second);
	std::vector<int> std_third(std_second);
	ft_first = ft_second;
	std_first = std_second;
	for ( unsigned int i = 0; i < MAX_VAL; i++ ){
		ft_second[i] = 0;
		std_second[i] = 0;
	}
	SECTION("Assignment operator & [] operator") {
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE(ft_first[i] == std_first[i]);
		REQUIRE(ft_first.capacity() == std_first.capacity());
		REQUIRE(ft_first.size() == std_first.size());
		REQUIRE(ft_first.empty() == std_first.empty());
		REQUIRE(ft_first.max_size() == std_first.max_size());
	}
	SECTION("Copy constructor & [] operator") {
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE(ft_third[i] == std_third[i]);
		REQUIRE(ft_third.capacity() == std_third.capacity());
		REQUIRE(ft_third.size() == std_third.size());
		REQUIRE(ft_third.empty() == std_third.empty());
		REQUIRE(ft_third.max_size() == std_third.max_size());
	}
	SECTION("at") {
		REQUIRE(ft_first.at(0) == std_first.at(0));
		REQUIRE(ft_second.at(0) == std_second.at(0));
		REQUIRE(ft_third.at(0) == std_third.at(0));
		REQUIRE(ft_first.at(1000) == std_first.at(1000));
		REQUIRE(ft_second.at(1000) == std_second.at(1000));
		REQUIRE(ft_third.at(1000) == std_third.at(1000));
		REQUIRE_THROWS_AS(ft_first.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(std_first.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(ft_second.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(std_second.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(ft_third.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(std_third.at(MAX_VAL), std::out_of_range);
	}
	SECTION("front") {
		REQUIRE(ft_first.front() == std_first.front());
		REQUIRE(ft_second.front() == std_second.front());
		REQUIRE(ft_third.front() == std_third.front());
	}
	SECTION("back") {
		REQUIRE(ft_first.back() == std_first.back());
		REQUIRE(ft_second.back() == std_second.back());
		REQUIRE(ft_third.back() == std_third.back());
	}
	SECTION("data") {
		REQUIRE(*ft_first.data() == *std_first.data());
		REQUIRE(*ft_second.data() == *std_second.data());
		REQUIRE(*ft_third.data() == *std_third.data());
	}
}

TEST_CASE("Vector<string> constructors, capacity & element access", "[Vector]") {
	ft::Vector<std::string> ft_first;
	std::vector<std::string> std_first;
	ft::Vector<std::string> ft_second(MAX_VAL);
	std::vector<std::string> std_second(MAX_VAL);
	std::string empty;

	SECTION("Empty capacity") {
		REQUIRE(ft_first.capacity() == std_first.capacity());
		REQUIRE(ft_first.size() == std_first.size());
		REQUIRE(ft_first.empty() == std_first.empty());
		REQUIRE(ft_first.max_size() == std_first.max_size());
		REQUIRE(ft_second.capacity() == std_second.capacity());
		REQUIRE(ft_second.size() == std_second.size());
		REQUIRE(ft_second.empty() == std_second.empty());
		REQUIRE(ft_second.max_size() == std_second.max_size());
	}
	for ( unsigned int i = 0; i < MAX_VAL; i++ ){
		ft_second[i] = std::to_string(i);
		std_second[i] = std::to_string(i);
	}
	SECTION("Assigned constructor & [] operator") {
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE(ft_second[i] == std_second[i]);
		REQUIRE(ft_second.capacity() == std_second.capacity());
		REQUIRE(ft_second.size() == std_second.size());
		REQUIRE(ft_second.empty() == std_second.empty());
		REQUIRE(ft_second.max_size() == std_second.max_size());
	}
	ft::Vector<std::string> ft_third(ft_second);
	std::vector<std::string> std_third(std_second);
	ft_first = ft_second;
	std_first = std_second;
	for ( unsigned int i = 0; i < MAX_VAL; i++ ){
		ft_second[i] = empty;
		std_second[i] = empty;
	}
	SECTION("Assignment operator & [] operator") {
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE(ft_first[i] == std_first[i]);
		REQUIRE(ft_first.capacity() == std_first.capacity());
		REQUIRE(ft_first.size() == std_first.size());
		REQUIRE(ft_first.empty() == std_first.empty());
		REQUIRE(ft_first.max_size() == std_first.max_size());
	}
	SECTION("Copy constructor & [] operator") {
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE(ft_third[i] == std_third[i]);
		REQUIRE(ft_third.capacity() == std_third.capacity());
		REQUIRE(ft_third.size() == std_third.size());
		REQUIRE(ft_third.empty() == std_third.empty());
		REQUIRE(ft_third.max_size() == std_third.max_size());
	}
	SECTION("at") {
		REQUIRE(ft_first.at(0) == std_first.at(0));
		REQUIRE(ft_second.at(0) == std_second.at(0));
		REQUIRE(ft_third.at(0) == std_third.at(0));
		REQUIRE(ft_first.at(1000) == std_first.at(1000));
		REQUIRE(ft_second.at(1000) == std_second.at(1000));
		REQUIRE(ft_third.at(1000) == std_third.at(1000));
		REQUIRE_THROWS_AS(ft_first.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(std_first.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(ft_second.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(std_second.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(ft_third.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(std_third.at(MAX_VAL), std::out_of_range);
	}
	SECTION("front") {
		REQUIRE(ft_first.front() == std_first.front());
		REQUIRE(ft_second.front() == std_second.front());
		REQUIRE(ft_third.front() == std_third.front());
	}
	SECTION("back") {
		REQUIRE(ft_first.back() == std_first.back());
		REQUIRE(ft_second.back() == std_second.back());
		REQUIRE(ft_third.back() == std_third.back());
	}
	SECTION("data") {
		REQUIRE(*ft_first.data() == *std_first.data());
		REQUIRE(*ft_second.data() == *std_second.data());
		REQUIRE(*ft_third.data() == *std_third.data());
	}
}
