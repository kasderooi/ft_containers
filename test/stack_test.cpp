//
// Created by Kester kas De rooij on 1/24/21.
//

#include "catch.hpp"
#include "ft_stack.hpp"
#include "ft_vector.hpp"
#include <stack>
#include <vector>

#define MAX_VAL 2345

TEST_CASE( "vector iterators", "[vector]" ){
	std::deque< int > mydeque( 3, 100 );
	std::vector< int > std_vec1( 3, 100 );
	ft::vector< int > ft_vec1( 3, 100 );
	std::stack< int, std::vector< int > > std_stack1( std_vec1 );
	ft::stack< int, ft::vector< int > > ft_stack1( ft_vec1 );
	std::stack< int > std_stack3;
	std::stack< int > std_stack4;
	ft::stack< int > ft_stack3;
	ft::stack< int > ft_stack4;

	SECTION( "begin/end ++/--" ){
		REQUIRE( std_stack1.empty() == ft_stack1.empty());
		REQUIRE( std_stack3.empty() == ft_stack3.empty());
		REQUIRE( std_stack1.top() == ft_stack1.top());
	}
	std_stack1.top() += 13;
	ft_stack1.top() += 13;
	SECTION( "begin/end ++/--" ){
		REQUIRE( std_stack1.top() == ft_stack1.top());
	}
	for ( int i = 0; i < 10; i++ ){
		ft_stack3.push( i );
		ft_stack4.push( i );
	}
	SECTION ( "Equal" ){
		REQUIRE( ft_stack3 == ft_stack4 );
		REQUIRE( ft_stack3 <= ft_stack4 );
		REQUIRE( ft_stack3 >= ft_stack4 );
	}
	ft_stack3.push( 9 );
	SECTION ( "Bigger" ){
		REQUIRE( ft_stack3 != ft_stack4 );
		REQUIRE( ft_stack3 >= ft_stack4 );
		REQUIRE( ft_stack3 > ft_stack4 );
	}
	ft_stack3.pop();
	SECTION ( "Smaller" ){
		REQUIRE( ft_stack3 == ft_stack4 );
		REQUIRE( ft_stack3 <= ft_stack4 );
		REQUIRE( ft_stack3 >= ft_stack4 );
	}
}
