#include "print.hpp"
#include "../includes/containers/ft_vector.hpp"
#include <vector>
#include <iterator>
#include <sys/time.h>

#define MAX_SIZE 250000

long get_time( void ){
    struct timeval time_now;
    gettimeofday(&time_now, nullptr);
    return (time_now.tv_sec * 1000000) + (time_now.tv_usec);
}

void time_test(void){
    ft::vector< int > ft_vector1;
    std::vector< int > std_vector1;
    long ft_before, ft_after, std_before, std_after;
    // assign val
    ft_before = get_time();
    ft_vector1.assign( MAX_SIZE, 100 );
    ft_after = get_time();
    std_before = get_time();
    std_vector1.assign( MAX_SIZE, 100 );
    std_after = get_time();
    print( "insert val", ft_after-ft_before, std_after-std_before );
    // copy constr
    ft_before = get_time();
    ft::vector< int > ft_vector2(ft_vector1);
    ft_after = get_time();
    std_before = get_time();
    std::vector< int > std_vector2(std_vector1);
    std_after = get_time();
    print( "copy constr", ft_after-ft_before, std_after-std_before );
    // clear
    ft_before = get_time();
    ft_vector1.clear();
    ft_after = get_time();
    std_before = get_time();
    std_vector1.clear();
    std_after = get_time();
    print( "clear\t", ft_after-ft_before, std_after-std_before );
    // range insert
    ft_before = get_time();
    ft_vector1.insert( ft_vector1.begin(), ft_vector2.begin(), ft_vector2.end());
    ft_after = get_time();
    std_before = get_time();
    std_vector1.insert(std_vector1.begin(),std_vector2.begin(), std_vector2.end());
    std_after = get_time();
    print( "range insert", ft_after-ft_before, std_after-std_before );
    // erase
    ft_before = get_time();
    ft_vector2.erase(ft_vector2.begin(), ft_vector2.end());
    ft_after = get_time();
    std_before = get_time();
    std_vector2.erase(std_vector2.begin(), std_vector2.end());
    std_after = get_time();
    print( "clear\t", ft_after-ft_before, std_after-std_before );
    // swap
    ft_before = get_time();
    ft_vector1.swap( ft_vector2 );
    ft_after = get_time();
    std_before = get_time();
    std_vector1.swap( std_vector2 );
    std_after = get_time();
    print( "swap\t", ft_after-ft_before, std_after-std_before );
    // push
    ft_before = get_time();
    for( int i = 0; i < MAX_SIZE; i++)
        ft_vector1.push_back(i);
    ft_after = get_time();
    std_before = get_time();
    for( int i = 0; i < MAX_SIZE; i++)
        std_vector1.push_back(i);
    std_after = get_time();
    print( "push\t", ft_after-ft_before, std_after-std_before );
    // pop
    ft_before = get_time();
    for( int i = 0; i < MAX_SIZE; i++)
        ft_vector1.pop_back();
    ft_after = get_time();
    std_before = get_time();
    for( int i = 0; i < MAX_SIZE; i++)
        std_vector1.pop_back();
    std_after = get_time();
    print( "pop\t", ft_after-ft_before, std_after-std_before );
    // assign it
    ft_before = get_time();
    ft_vector1.assign( ft_vector2.begin(), ft_vector2.end() );
    ft_after = get_time();
    std_before = get_time();
    std_vector1.assign( std_vector2.begin(), std_vector2.end() );
    std_after = get_time();
    print( "insert it", ft_after-ft_before, std_after-std_before );
}

int main(){
    time_test();
    std::cout << std::endl;
    system("leaks time_vec");
    return 0;
}
