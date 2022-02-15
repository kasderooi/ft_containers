#include "print.hpp"
#include "../includes/containers/ft_stack.hpp"
#include "../includes/containers/ft_vector.hpp"
#include <stack>
#include <vector>
#include <sys/time.h>

#define MAX_VAL 250000

long get_time( void ){
	struct timeval time_now;
	gettimeofday( &time_now, nullptr );
	return ( time_now.tv_sec * 1000000 ) + ( time_now.tv_usec );
}

void time_test( void ){
	// constructor
	long ft_before, ft_after, std_before, std_after;
	ft_before = get_time();
	ft::vector< int > ft_vec1( MAX_VAL, 100 );
	ft::stack< int, ft::vector< int > > ft_stack1( ft_vec1 );
	ft_after = get_time();
	std_before = get_time();
	std::vector< int > std_vec1( MAX_VAL, 100 );
	std::stack< int, std::vector< int > > std_stack1( std_vec1 );
	std_after = get_time();
	print( "constructor", ft_after - ft_before, std_after - std_before );
	// insert val
	ft::stack< int > ft_stack2;
	std::stack< int > std_stack2;
	ft_before = get_time();
	for ( int i = 0; i < MAX_VAL; i++ ){
		ft_stack2.push( i );
	}
	ft_after = get_time();
	std_before = get_time();
	for ( int i = 0; i < MAX_VAL; i++ ){
		std_stack2.push( i );
	}
	std_after = get_time();
	print( "push\t", ft_after - ft_before, std_after - std_before );
	// insert val
	ft_before = get_time();
	for ( int i = 0; i < MAX_VAL; i++ ){
		ft_stack2.pop();
	}
	ft_after = get_time();
	std_before = get_time();
	for ( int i = 0; i < MAX_VAL; i++ ){
		std_stack2.pop();
	}
	std_after = get_time();
	print( "pop\t", ft_after - ft_before, std_after - std_before );
}

int main(){
	time_test();
	std::cout << std::endl;
	system( "leaks time_sta" );
	return 0;
}
