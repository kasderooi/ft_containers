#include <iostream>
#include "ft_map.hpp"
#include <map>
#include <iterator>
#include "AVLtree.hpp"


//void print_map( std::map<int, int> Map1, std::map<int, int> Map2, std::map<int, int> Map3 ) {
//	std::map<int, int>::iterator it;
//	std::cout << "Map1\nKEY\tELEMENT\n";
//	for ( it = Map1.begin(); it != Map1.end(); it++ ) {
//		std::cout << it->first << "\t" << it->second << std::endl;
//	}
//	std::cout << "Map2\nKEY\tELEMENT\n";
//	for ( it = Map2.begin(); it != Map2.end(); it++ ) {
//		std::cout << it->first << "\t" << it->second << std::endl;
//	}
//	std::cout << "Map3\nKEY\tELEMENT\n";
//	for ( it = Map3.begin(); it != Map3.end(); it++ ) {
//		std::cout << it->first << "\t" << it->second << std::endl;
//	}
//}
//
//void print_bound( std::map<int, int> Map, int nbr ) {
//	std::cout << "Map2 lower bound of " << nbr << " =\t" << Map.lower_bound(nbr)->first << "\t" << Map.lower_bound(nbr)->second << std::endl;
//	std::cout << "Map2 upper bound of " << nbr << " =\t" << Map.upper_bound(nbr)->first << "\t" << Map.upper_bound(nbr)->second << std::endl;
//}

int main() {
//	std::map<int,int> Map1;
//	Map1.insert(ft::pair<int, int>(1, 9 ) );
//	Map1.insert(ft::pair<int, int>(2, 8 ) );
//	Map1.insert(ft::pair<int, int>(3, 7 ) );
//	Map1.insert(ft::pair<int, int>(4, 6 ) );
//	Map1.insert(ft::pair<int, int>(5, 5 ) );
//	Map1.insert(ft::pair<int, int>(6, 4 ) );
//	Map1.insert(ft::pair<int, int>(7, 3 ) );
//	Map1.insert(ft::pair<int, int>(8, 2 ) );
//	Map1.insert(ft::pair<int, int>(9, 1 ) );
//	std::map<int,int> Map2( Map1 );
//	std::map<int,int> Map3( Map1.begin(), Map1.end() );
//	print_map( Map1, Map2, Map3 );
//	Map1.erase( Map1.find(3), Map1.find(6) );
//	Map2.erase( Map2.find(2), Map2.find(8) );
//	Map2.insert( ft::pair<int, int>(3, 100) );
//	Map2.insert( ft::pair<int, int>(6, 300) );
//	Map2.insert( ft::pair<int, int>(5, 400) );
//	Map2.insert( ft::pair<int, int>(7, 10) );
//	Map2.insert( ft::pair<int, int>(4, 100) );
//	Map2.insert( ft::pair<int, int>(4, 444) );
//	print_map( Map1, Map2, Map3 );
//	print_bound( Map2, 4 );
//	print_bound( Map2, 4 );
//	print_bound( Map3, 5 );
//	print_bound( Map3, 6 );
//	std::cout << Map2.count(4) << std::endl;
	ft::AVLtree< ft::pair< int, int > > *root = new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( 5, 5 ) );
	root = root->insert( new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( 3, 3 ) ) );
	root = root->insert( new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( 2, 2 ) ) );
	root = root->insert( new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( 4, 4 ) ) );
	root = root->insert( new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( 1, 1 ) ) );
	root = root->insert( new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( 8, 8 ) ) );
	root = root->insert( new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( 9, 9 ) ) );
	root = root->insert( new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( 7, 7 ) ) );
	root = root->insert( new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( 6, 6 ) ) );
	root = root->insert( new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( 10, 10 ) ) );
	root = root->insert( new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( 11, 11 ) ) );
	for ( int i = 12; i < 25; i++ )
		root = root->insert( new ft::AVLtree< ft::pair< int, int> >( ft::pair< int, int>( i, i ) ) );
	root->print();
	return 0;
}



