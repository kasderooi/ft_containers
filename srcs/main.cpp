#include <iostream>
#include "ft_map.hpp"
#include <map>
#include <iterator>
#include "AVLtree.hpp"
#include "NodeIterator.hpp"


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
void print_bound( std::map<int, int> Map, int nbr ) {
	std::cout << "Map2 lower bound of " << nbr << " =\t" << Map.lower_bound(nbr)->first << "\t" << Map.lower_bound(nbr)->second << std::endl;
	std::cout << "Map2 upper bound of " << nbr << " =\t" << Map.upper_bound(nbr)->first << "\t" << Map.upper_bound(nbr)->second << std::endl;
}

//void avltest( void ){
//    ft::AVLtree< int, int > *root = new ft::AVLtree< int , int >( ft::pair< int, int>( 5, 5 ) );
//    root = root->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( 3, 3 ) ) );
//    root = root->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( 2, 2 ) ) );
//    root = root->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( 4, 4 ) ) );
//    root = root->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( 1, 1 ) ) );
//    root = root->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( 8, 8 ) ) );
//    root = root->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( 9, 9 ) ) );
//    root = root->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( 7, 7 ) ) );
//    root = root->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( 6, 6 ) ) );
//    root = root->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( 10, 10 ) ) );
//    root = root->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( 11, 11 ) ) );
//    for ( int i = 12; i <= 25; i++ )
//        root = root->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( i, i ) ) );
//    root->print();
//    root = root->erase( 17 );
//    root->print();
//    root->find_node( 16 )->print_nodes();
//    root->find_node( 19 )->print_nodes();
//    root->find_node( 18 )->print_nodes();
//    std::cout << std::endl;
//    ft::BidirectionalIterator<ft::AVLtree<int, int>> it( root->find_node(1) );
//    for ( int i = 1; i < 25; i++ ){
//        std::cout << i << " " << (*it).first << std::endl;
//        it++;
//    }
//    for ( int i = 24; i > 1; i-- ){
//        std::cout << i << " " << (*it).first << std::endl;
//        it--;
//    }
//    ft::AVLtree< int, int > *root2 = new ft::AVLtree< int , int >( ft::pair< int, int>( 1, 1 ) );
//    for ( int i = 25; i > 1; i-- )
//        root2 = root2->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( i, i ) ) );
//    root2->print();
//    ft::AVLtree< int, int > *root3 = new ft::AVLtree< int , int >( ft::pair< int, int>( 25, 25 ) );
//    for ( int i = 1; i < 25; i++ )
//        root3 = root3->insert( new ft::AVLtree< int , int >( ft::pair< int, int>( i, i ) ) );
//    root3->print();
//}

void basicmaptest( void ){
	ft::map<int, int> ft_map1;
	std::map<int, int> std_map1;
    ft_map1.insert( ft::pair<int,int>( 1, 1 ) );
    std_map1.insert( std::pair<int,int>( 1, 1 ) );
	ft::map<int,int>::iterator it = ft_map1.begin();
    std::map<int,int>::iterator it2 = std_map1.begin();
	for ( int i = 2; i < 25; i++) {
        ft_map1.insert(ft::pair<int, int>(i, i));
        std_map1.insert( std::pair<int,int>( i, i ) );
    }
	ft_map1.erase( 7 );
    std_map1.erase( 7 );
	while ( it2 != std_map1.end() ){
	    std::cout << (*it).first << "\t";
        std::cout << (*it2).first << std::endl;
        it++;
        it2++;
	}
	while ( it2 != std_map1.begin() ){
	    it--;
	    it2--;
        std::cout << (*it).first << "\t";
        std::cout << (*it2).first << std::endl;
	}
}

int main() {
	std::map<int,int> Map1;
    std::pair<int, int> pair(1, 9 );
    pair.second = 8;
	Map1.insert( pair );
	print_bound( Map1, 1 );
    pair.second = 7;
    print_bound( Map1, 1 );
    Map1[1] = 7;
    print_bound( Map1, 1 );
//    avltest();
	basicmaptest();
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

	return 0;
}



