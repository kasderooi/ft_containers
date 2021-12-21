//
// Created by Kester kas De rooij on 11/24/21.
//

#include "catch.hpp"
#include "ft_vector.hpp"
#include <vector>

#define MAX_VAL 2345


TEST_CASE("vector iterators", "[vector]") {
	ft::vector<int> ft1(MAX_VAL);
	std::vector<int> std1(MAX_VAL);
	ft::vector<int>::iterator it_ft1 = ft1.begin();
	for (std::vector<int>::iterator it_std1 = std1.begin(); it_std1 < std1.end(); it_std1++)
	{
		*it_std1 = arc4random() % 100;
		*it_ft1 = *it_std1;
		it_ft1++;
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

	ft::vector<int> ft2(MAX_VAL);
	std::vector<int> std2(MAX_VAL);
	ft::vector<int>::reverse_iterator it_ft2 = ft2.rbegin();
	for (std::vector<int>::reverse_iterator it_std2 = std2.rbegin(); it_std2 < std2.rend(); it_std2++)
	{
		*it_std2 = arc4random() % 100;
		*it_ft2 = *it_std2;
		it_ft2++;
	}
	SECTION("reverse begin/end ++/--") {
		REQUIRE(*(ft2.rbegin()) == *(std2.rbegin()));
		REQUIRE(*(++ft2.rbegin()) == *(++std2.rbegin()));
		REQUIRE(*(ft2.rbegin()++) == *(std2.rbegin()++));
		REQUIRE(ft2[0] == std2[0]);
		REQUIRE(ft2[MAX_VAL - 1] == std2[MAX_VAL - 1]);
		REQUIRE(ft2[MAX_VAL] == *--ft2.rbegin());
		REQUIRE(std2[MAX_VAL] == *--std2.rbegin());
		REQUIRE(ft2[0] == *--ft2.rend());
		REQUIRE(std2[0] == *--std2.rend());
		REQUIRE(ft2[MAX_VAL - 1] == *ft2.rbegin());
		REQUIRE(std2[MAX_VAL - 1] == *std2.rbegin());
		REQUIRE(ft2[MAX_VAL - 1] == *ft2.rbegin()--);
		REQUIRE(std2[MAX_VAL - 1] == *std2.rbegin()--);
	}
}

TEST_CASE("vector<int> constructors, capacity & element access", "[vector]") {
	ft::vector<int> ft_first;
	std::vector<int> std_first;
	ft::vector<int> ft_second(MAX_VAL);
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
	ft::vector<int> ft_third(ft_second);
	std::vector<int> std_third(std_second);
	ft::vector<int> ft_fourth(ft_second.begin(), ft_second.end());
	std::vector<int> std_fourth(std_second.begin(), std_second.end());
	ft_first = ft_second;
	std_first = std_second;
	for ( unsigned int i = 0; i < MAX_VAL; i++ ){
		ft_second[i] = 0;
		std_second[i] = 0;
	}
	SECTION("Assignment operator & [] operator") {
		REQUIRE(ft_first.capacity() == std_first.capacity());
		REQUIRE(ft_first.size() == std_first.size());
		REQUIRE(ft_first.empty() == std_first.empty());
		REQUIRE(ft_first.max_size() == std_first.max_size());
	}
	SECTION("Copy constructor & [] operator") {
		REQUIRE(ft_third.capacity() == std_third.capacity());
		REQUIRE(ft_third.size() == std_third.size());
		REQUIRE(ft_third.empty() == std_third.empty());
		REQUIRE(ft_third.max_size() == std_third.max_size());
	}
	SECTION("Range constructor & [] operator") {
		REQUIRE(ft_fourth.capacity() == std_fourth.capacity());
		REQUIRE(ft_fourth.size() == std_fourth.size());
		REQUIRE(ft_fourth.empty() == std_fourth.empty());
		REQUIRE(ft_fourth.max_size() == std_fourth.max_size());
	}
	SECTION("at") {
		REQUIRE(ft_first.at(0) == std_first.at(0));
		REQUIRE(ft_second.at(0) == std_second.at(0));
		REQUIRE(ft_third.at(0) == std_third.at(0));
		REQUIRE(ft_fourth.at(0) == std_fourth.at(0));
		REQUIRE(ft_first.at(1000) == std_first.at(1000));
		REQUIRE(ft_second.at(1000) == std_second.at(1000));
		REQUIRE(ft_third.at(1000) == std_third.at(1000));
		REQUIRE(ft_fourth.at(1000) == std_fourth.at(1000));
		REQUIRE_THROWS_AS(ft_first.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(std_first.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(ft_second.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(std_second.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(ft_third.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(std_third.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(ft_fourth.at(MAX_VAL), std::out_of_range);
		REQUIRE_THROWS_AS(std_fourth.at(MAX_VAL), std::out_of_range);
	}
	SECTION("front") {
		REQUIRE(ft_first.front() == std_first.front());
		REQUIRE(ft_second.front() == std_second.front());
		REQUIRE(ft_third.front() == std_third.front());
		REQUIRE(ft_fourth.front() == std_fourth.front());
	}
	SECTION("back") {
		REQUIRE(ft_first.back() == std_first.back());
		REQUIRE(ft_second.back() == std_second.back());
		REQUIRE(ft_third.back() == std_third.back());
		REQUIRE(ft_fourth.back() == std_fourth.back());
	}
	SECTION("data") {
		REQUIRE(*ft_first.data() == *std_first.data());
		REQUIRE(*ft_second.data() == *std_second.data());
		REQUIRE(*ft_third.data() == *std_third.data());
		REQUIRE(*ft_fourth.data() == *std_fourth.data());
	}
	ft_first.resize( 100 );
	std_first.resize( 100 );
	SECTION("after resize") {
		REQUIRE(ft_first.capacity() == std_first.capacity());
		REQUIRE(ft_first.size() == std_first.size());
		REQUIRE(ft_first.empty() == std_first.empty());
		REQUIRE(ft_first.max_size() == std_first.max_size());
	}
	ft_first.reserve( MAX_VAL + 42 );
	std_first.reserve( MAX_VAL + 42 );
	SECTION("after reserve") {
		REQUIRE(ft_first.capacity() == std_first.capacity());
		REQUIRE(ft_first.size() == std_first.size());
		REQUIRE(ft_first.empty() == std_first.empty());
		REQUIRE(ft_first.max_size() == std_first.max_size());
	}
	SECTION("at") {
		REQUIRE(ft_first.at(0) == std_first.at(0));
		REQUIRE(ft_first.at(97) == std_first.at(97));
		REQUIRE_THROWS_AS(ft_first.at(100), std::out_of_range);
		REQUIRE_THROWS_AS(std_first.at(100), std::out_of_range);
	}
	SECTION("front/back/data") {
		REQUIRE(ft_first.front() == std_first.front());
		REQUIRE(ft_first.back() == std_first.back());
		REQUIRE(*ft_first.data() == *std_first.data());
	}
	ft_first.resize( 1010, 100 );
	std_first.resize( 1010, 100 );
	SECTION("after reserve") {
		REQUIRE(ft_first.capacity() == std_first.capacity());
		REQUIRE(ft_first.size() == std_first.size());
		REQUIRE(ft_first.empty() == std_first.empty());
		REQUIRE(ft_first.max_size() == std_first.max_size());
	}
	SECTION("at") {
		REQUIRE(ft_first.at(0) == std_first.at(0));
		REQUIRE(ft_first.at(109) == std_first.at(109));
		REQUIRE_THROWS_AS(ft_first.at(1010), std::out_of_range);
		REQUIRE_THROWS_AS(std_first.at(1010), std::out_of_range);
	}
	SECTION("front/back/data") {
		REQUIRE(ft_first.front() == std_first.front());
		REQUIRE(ft_first.back() == std_first.back());
		REQUIRE(*ft_first.data() == *std_first.data());
	}
}

TEST_CASE("vector<int> modifiers", "[vector]") {
	ft::vector<int> ft_first(10);
	std::vector<int> std_first(10);
	ft::vector<int> ft_second(21);
	std::vector<int> std_second(21);

	for ( int i = 0; i < 10; i++ ) {
		ft_first[i] = i;
		std_first[i] = i;
	}
//	ft_second.assign( ft_first.begin(), ft_first.end() );
//	std_second.assign( std_first.begin(), std_first.end() );
	SECTION("after assign") {
		REQUIRE(ft_second.capacity() == std_second.capacity());
		REQUIRE(ft_second.size() == std_second.size());
		REQUIRE(ft_second.front() == std_second.front());
		REQUIRE(ft_second.at(5) == std_second.at(5));
		REQUIRE(ft_second.back() == std_second.back());
		REQUIRE(*ft_second.data() == *std_second.data());
	}
//	ft_first.assign( 42, 33 );
//	std_second.assign(42, 33 );
}

TEST_CASE("vector<string> constructors, capacity & element access", "[vector]") {
	ft::vector<std::string> ft_first;
	std::vector<std::string> std_first;
	ft::vector<std::string> ft_second(MAX_VAL);
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
	ft::vector<std::string> ft_third(ft_second);
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
