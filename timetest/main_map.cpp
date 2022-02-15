#include "print.hpp"
#include "../includes/containers/ft_map.hpp"
#include <map>
#include <iterator>
#include <sys/time.h>

#define MAX_SIZE 250000

long get_time( void ){
	struct timeval time_now;
	gettimeofday( &time_now, nullptr );
	return ( time_now.tv_sec * 1000000 ) + ( time_now.tv_usec );
}

void time_test( void ){
	ft::map< int, int > ft_map1;
	std::map< int, int > std_map1;
	long ft_before, ft_after, std_before, std_after;
	// insert val
	ft_before = get_time();
	for ( int i = 0; i < MAX_SIZE; i++ )
		ft_map1.insert( ft::pair< int, int >( i, i ));
	ft_after = get_time();
	std_before = get_time();
	for ( int i = 0; i < MAX_SIZE; i++ )
		std_map1.insert( std::pair< int, int >( i, i ));
	std_after = get_time();
	print( "insert val", ft_after - ft_before, std_after - std_before );
	// copy constr
	ft_before = get_time();
	ft::map< int, int > ft_map2( ft_map1 );
	ft_after = get_time();
	std_before = get_time();
	std::map< int, int > std_map2( std_map1 );
	std_after = get_time();
	print( "copy constr", ft_after - ft_before, std_after - std_before );
	// find val
	ft_before = get_time();
	for ( int i = 0; i < MAX_SIZE; i++ )
		ft_map1.find( i );
	ft_after = get_time();
	std_before = get_time();
	for ( int i = 0; i < MAX_SIZE; i++ )
		std_map1.find( i );
	std_after = get_time();
	print( "find val", ft_after - ft_before, std_after - std_before );
	// erase val
	ft_before = get_time();
	for ( int i = 0; i < MAX_SIZE; i++ )
		ft_map1.erase( i );
	ft_after = get_time();
	std_before = get_time();
	for ( int i = 0; i < MAX_SIZE; i++ )
		std_map1.erase( i );
	std_after = get_time();
	print( "erase val", ft_after - ft_before, std_after - std_before );
	// range insert
	ft_before = get_time();
	ft_map1.insert( ft_map2.begin(), ft_map2.end());
	ft_after = get_time();
	std_before = get_time();
	std_map1.insert( std_map2.begin(), std_map2.end());
	std_after = get_time();
	print( "range insert", ft_after - ft_before, std_after - std_before );
	// clear
	ft_before = get_time();
	ft_map2.clear();
	ft_after = get_time();
	std_before = get_time();
	std_map2.clear();
	std_after = get_time();
	print( "clear\t", ft_after - ft_before, std_after - std_before );
	// [] operator
	ft_before = get_time();
	for ( int i = MAX_SIZE; i > 0; i-- )
		ft_map2[i] = i;
	ft_after = get_time();
	std_before = get_time();
	for ( int i = MAX_SIZE; i > 0; i-- )
		std_map2[i] = i;
	std_after = get_time();
	print( "[] operator", ft_after - ft_before, std_after - std_before );
	// swap
	ft_before = get_time();
	ft_map1.swap( ft_map2 );
	ft_after = get_time();
	std_before = get_time();
	std_map1.swap( std_map2 );
	std_after = get_time();
	print( "swap\t", ft_after - ft_before, std_after - std_before );
}

int main(){
	time_test();
	std::cout << std::endl;
	system( "leaks time_map" );
	return 0;
}
