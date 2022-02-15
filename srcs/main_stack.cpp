#include <iostream>
#include "ft_stack.hpp"
#include "ft_vector.hpp"
#include <stack>
#include <vector>
#include <iterator>

int main(){
	std::deque< int > mydeque( 3, 100 );
	std::vector< int > std_vec1( 3, 100 );
	ft::vector< int > ft_vec1( 3, 100 );
	std::stack< int, std::vector< int > > std_stack1( std_vec1 );
	ft::stack< int, ft::vector< int > > ft_stack1( ft_vec1 );
	std::stack< int > std_stack2( mydeque );
	ft::stack< int > ft_stack2( mydeque );
	std::stack< int > std_stack3;
	ft::stack< int > ft_stack3;

	std::cout << std_stack1.empty() << std::endl;
	std::cout << ft_stack1.empty() << std::endl;
	std::cout << std_stack2.empty() << std::endl;
	std::cout << ft_stack2.empty() << std::endl;
	std::cout << std_stack3.empty() << std::endl;
	std::cout << ft_stack3.empty() << std::endl;

	std_stack1.top() += 13;
	ft_stack1.top() += 13;

	std::cout << std_stack1.top() << std::endl;
	std::cout << ft_stack1.top() << std::endl;
}
