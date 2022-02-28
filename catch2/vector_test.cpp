#include "catch.hpp"
#include "../includes/containers/ft_vector.hpp"
#include <vector>

#define MAX_VAL 2345

TEST_CASE( "vector iterators", "[vector]" ){
	ft::vector< int > ft1( MAX_VAL );
	std::vector< int > std1( MAX_VAL );
	ft::vector< int >::iterator it_ft1 = ft1.begin();
	for ( std::vector< int >::iterator it_std1 = std1.begin(); it_std1 < std1.end(); it_std1++ ){
		*it_std1 = arc4random() % 100;
		*it_ft1 = *it_std1;
		it_ft1++;
	}
	ft::vector< int >::const_iterator const_it_ft0 = ft1.begin();
	ft::vector< int >::iterator it_ft0 = ft1.begin();
	ft::vector< int >::const_reverse_iterator const_rit_ft0 = ft1.rbegin();
	ft::vector< int >::reverse_iterator rit_ft0 = ft1.rbegin();
	SECTION( "begin/end ++/--" ){
		REQUIRE( *const_it_ft0 == *it_ft0 );
		REQUIRE( *const_rit_ft0 == *rit_ft0 );
		REQUIRE( *( ft1.begin()) == *( std1.begin()));
		REQUIRE( *( ft1.begin() + 5 ) == *( std1.begin() + 5 ));
		REQUIRE( *( ++ft1.begin()) == *( ++std1.begin()));
		REQUIRE( *( ft1.begin()++ ) == *( std1.begin()++ ));
		REQUIRE( ft1[0] == std1[0] );
		REQUIRE( ft1[MAX_VAL - 1] == std1[MAX_VAL - 1] );
		REQUIRE( ft1[MAX_VAL - 1] == *--ft1.end());
		REQUIRE( std1[MAX_VAL - 1] == *--std1.end());
		REQUIRE( ft1[MAX_VAL] == *ft1.end());
		REQUIRE( std1[MAX_VAL] == *std1.end());
		REQUIRE( ft1[MAX_VAL] == *ft1.end()-- );
		REQUIRE( std1[MAX_VAL] == *std1.end()-- );
	}

	ft::vector< int > ft2( MAX_VAL );
	std::vector< int > std2( MAX_VAL );
	ft::vector< int >::reverse_iterator it_ft2 = ft2.rbegin();
	for ( std::vector< int >::reverse_iterator it_std2 = std2.rbegin(); it_std2 < std2.rend(); it_std2++ ){
		*it_std2 = arc4random() % 100;
		*it_ft2 = *it_std2;
		it_ft2++;
	}
	SECTION( "reverse begin/end ++/--" ){
		REQUIRE( *( ft2.rbegin()) == *( std2.rbegin()));
		REQUIRE( *( ++ft2.rbegin()) == *( ++std2.rbegin()));
		REQUIRE( *( ft2.rbegin()++ ) == *( std2.rbegin()++ ));
		REQUIRE( ft2[0] == std2[0] );
		REQUIRE( ft2[MAX_VAL - 1] == std2[MAX_VAL - 1] );
		REQUIRE( ft2[MAX_VAL] == *--ft2.rbegin());
		REQUIRE( std2[MAX_VAL] == *--std2.rbegin());
		REQUIRE( ft2[0] == *--ft2.rend());
		REQUIRE( std2[0] == *--std2.rend());
		REQUIRE( ft2[MAX_VAL - 1] == *ft2.rbegin());
		REQUIRE( std2[MAX_VAL - 1] == *std2.rbegin());
		REQUIRE( ft2[MAX_VAL - 1] == *ft2.rbegin()-- );
		REQUIRE( std2[MAX_VAL - 1] == *std2.rbegin()-- );
		REQUIRE( *( 3 + ft2.rbegin()) == *( 3 + std2.rbegin()));
		REQUIRE(( ft2.rend() - ft2.rbegin()) == ( std2.rend() - std2.rbegin()));
	}
}

TEST_CASE( "vector<int> constructors, capacity & element access", "[vector]" ){
	ft::vector< int > ft_first;
	std::vector< int > std_first;
	ft::vector< int > ft_second( MAX_VAL, 15 );
	std::vector< int > std_second( MAX_VAL, 15 );

	SECTION( "Empty capacity" ){
		REQUIRE( ft_first.capacity() == std_first.capacity());
		REQUIRE( ft_first.size() == std_first.size());
		REQUIRE( ft_first.empty() == std_first.empty());
		REQUIRE( ft_first.max_size() == std_first.max_size());
		REQUIRE( ft_second.capacity() == std_second.capacity());
		REQUIRE( ft_second.size() == std_second.size());
		REQUIRE( ft_second.empty() == std_second.empty());
		REQUIRE( ft_second.max_size() == std_second.max_size());
	}
	for ( unsigned int i = 0; i < MAX_VAL; i++ ){
		ft_second[i] = i;
		std_second[i] = i;
	}
	SECTION( "Assigned constructor & [] operator" ){
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE( ft_second[i] == std_second[i] );
		REQUIRE( ft_second.capacity() == std_second.capacity());
		REQUIRE( ft_second.size() == std_second.size());
		REQUIRE( ft_second.empty() == std_second.empty());
		REQUIRE( ft_second.max_size() == std_second.max_size());
	}
	ft::vector< int > ft_third( ft_second );
	std::vector< int > std_third( std_second );
	ft::vector< int > ft_fourth( ft_second.begin(), ft_second.end());
	std::vector< int > std_fourth( std_second.begin(), std_second.end());
	ft_first = ft_second;
	std_first = std_second;
	for ( unsigned int i = 0; i < MAX_VAL; i++ ){
		ft_second[i] = 0;
		std_second[i] = 0;
	}
	SECTION( "Assignment operator & [] operator" ){
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE( ft_first[i] == std_first[i] );
		REQUIRE( ft_first.capacity() == std_first.capacity());
		REQUIRE( ft_first.size() == std_first.size());
		REQUIRE( ft_first.empty() == std_first.empty());
		REQUIRE( ft_first.max_size() == std_first.max_size());
	} SECTION( "Copy constructor & [] operator" ){
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE( ft_third[i] == std_third[i] );
		REQUIRE( ft_third.capacity() == std_third.capacity());
		REQUIRE( ft_third.size() == std_third.size());
		REQUIRE( ft_third.empty() == std_third.empty());
		REQUIRE( ft_third.max_size() == std_third.max_size());
	} SECTION( "Range constructor & [] operator" ){
		for ( unsigned int i = 0; i < MAX_VAL; i++ )
			REQUIRE( ft_fourth[i] == std_fourth[i] );
		REQUIRE( ft_fourth.capacity() == std_fourth.capacity());
		REQUIRE( ft_fourth.size() == std_fourth.size());
		REQUIRE( ft_fourth.empty() == std_fourth.empty());
		REQUIRE( ft_fourth.max_size() == std_fourth.max_size());
	} SECTION( "at" ){
		REQUIRE( ft_first.at( 0 ) == std_first.at( 0 ));
		REQUIRE( ft_second.at( 0 ) == std_second.at( 0 ));
		REQUIRE( ft_third.at( 0 ) == std_third.at( 0 ));
		REQUIRE( ft_fourth.at( 0 ) == std_fourth.at( 0 ));
		REQUIRE( ft_first.at( 1000 ) == std_first.at( 1000 ));
		REQUIRE( ft_second.at( 1000 ) == std_second.at( 1000 ));
		REQUIRE( ft_third.at( 1000 ) == std_third.at( 1000 ));
		REQUIRE( ft_fourth.at( 1000 ) == std_fourth.at( 1000 ));
		REQUIRE_THROWS_AS( ft_first.at( MAX_VAL ), std::out_of_range );
		REQUIRE_THROWS_AS( std_first.at( MAX_VAL ), std::out_of_range );
		REQUIRE_THROWS_AS( ft_second.at( MAX_VAL ), std::out_of_range );
		REQUIRE_THROWS_AS( std_second.at( MAX_VAL ), std::out_of_range );
		REQUIRE_THROWS_AS( ft_third.at( MAX_VAL ), std::out_of_range );
		REQUIRE_THROWS_AS( std_third.at( MAX_VAL ), std::out_of_range );
		REQUIRE_THROWS_AS( ft_fourth.at( MAX_VAL ), std::out_of_range );
		REQUIRE_THROWS_AS( std_fourth.at( MAX_VAL ), std::out_of_range );
	} SECTION( "front" ){
		REQUIRE( ft_first.front() == std_first.front());
		REQUIRE( ft_second.front() == std_second.front());
		REQUIRE( ft_third.front() == std_third.front());
		REQUIRE( ft_fourth.front() == std_fourth.front());
	} SECTION( "back" ){
		REQUIRE( ft_first.back() == std_first.back());
		REQUIRE( ft_second.back() == std_second.back());
		REQUIRE( ft_third.back() == std_third.back());
		REQUIRE( ft_fourth.back() == std_fourth.back());
	}
	ft_first.resize( 100 );
	std_first.resize( 100 );
	SECTION( "after resize" ){
		REQUIRE( ft_first.capacity() == std_first.capacity());
		REQUIRE( ft_first.size() == std_first.size());
		REQUIRE( ft_first.empty() == std_first.empty());
		REQUIRE( ft_first.max_size() == std_first.max_size());
	}
	ft_first.reserve( MAX_VAL + 42 );
	std_first.reserve( MAX_VAL + 42 );
	SECTION( "after reserve" ){
		REQUIRE( ft_first.capacity() == std_first.capacity());
		REQUIRE( ft_first.size() == std_first.size());
		REQUIRE( ft_first.empty() == std_first.empty());
		REQUIRE( ft_first.max_size() == std_first.max_size());
	} SECTION( "at" ){
		REQUIRE( ft_first.at( 0 ) == std_first.at( 0 ));
		REQUIRE( ft_first.at( 97 ) == std_first.at( 97 ));
		REQUIRE_THROWS_AS( ft_first.at( 100 ), std::out_of_range );
		REQUIRE_THROWS_AS( std_first.at( 100 ), std::out_of_range );
	} SECTION( "front/back/data" ){
		REQUIRE( ft_first.front() == std_first.front());
		REQUIRE( ft_first.back() == std_first.back());
	}
	ft_first.resize( 1010, 100 );
	std_first.resize( 1010, 100 );
	SECTION( "after reserve" ){
		REQUIRE( ft_first.capacity() == std_first.capacity());
		REQUIRE( ft_first.size() == std_first.size());
		REQUIRE( ft_first.empty() == std_first.empty());
		REQUIRE( ft_first.max_size() == std_first.max_size());
	} SECTION( "at" ){
		REQUIRE( ft_first.at( 0 ) == std_first.at( 0 ));
		REQUIRE( ft_first.at( 109 ) == std_first.at( 109 ));
		REQUIRE_THROWS_AS( ft_first.at( 1010 ), std::out_of_range );
		REQUIRE_THROWS_AS( std_first.at( 1010 ), std::out_of_range );
	} SECTION( "front/back/data" ){
		REQUIRE( ft_first.front() == std_first.front());
		REQUIRE( ft_first.back() == std_first.back());
	}
}

TEST_CASE( "vector<int> modifiers", "[vector]" ){
	ft::vector< int > ft_first( 10 );
	std::vector< int > std_first( 10 );
	ft::vector< int > ft_second( 21 );
	std::vector< int > std_second( 21 );

	for ( int i = 0; i < 10; i++ ){
		ft_first[i] = i;
		std_first[i] = i;
	}
	ft_second.assign( ft_first.begin(), ft_first.end());
	std_second.assign( std_first.begin(), std_first.end());
	SECTION( "after iterator assign" ){
		REQUIRE( ft_second.capacity() == std_second.capacity());
		REQUIRE( ft_second.size() == std_second.size());
		REQUIRE( ft_second.front() == std_second.front());
		REQUIRE( ft_second.at( 5 ) == std_second.at( 5 ));
		REQUIRE( ft_second.back() == std_second.back());
	}
	ft_second.assign( 42, 33 );
	std_second.assign( 42, 33 );
	SECTION( "after nbr/val assign" ){
		REQUIRE( ft_second.capacity() == std_second.capacity());
		REQUIRE( ft_second.size() == std_second.size());
		REQUIRE( ft_second.front() == std_second.front());
		REQUIRE( ft_second.at( 23 ) == std_second.at( 23 ));
		REQUIRE( ft_second.back() == std_second.back());
	}
	for ( int i = 0; i < 100; i++ ){
		ft_first.push_back( i );
		ft_second.push_back( i );
		std_first.push_back( i );
		std_second.push_back( i );
	}
	ft_first.pop_back();
	std_first.pop_back();
	SECTION( "after popback" ){
		REQUIRE( ft_first.capacity() == std_first.capacity());
		REQUIRE( ft_first.size() == std_first.size());
		REQUIRE( ft_first.front() == std_first.front());
		REQUIRE( ft_first.at( 108 ) == std_first.at( 108 ));
		REQUIRE( ft_first.back() == std_first.back());
	} SECTION( "after pushback" ){
		REQUIRE( ft_second.capacity() == std_second.capacity());
		REQUIRE( ft_second.size() == std_second.size());
		REQUIRE( ft_second.front() == std_second.front());
		REQUIRE( ft_second.at( 133 ) == std_second.at( 133 ));
		REQUIRE( ft_second.back() == std_second.back());
	}
	ft::vector< int >::iterator ft_it = ft_second.begin();
	std::vector< int >::iterator std_it = std_second.begin();
	ft_it = ft_second.begin();
	std_it = std_second.begin();
	ft_it += 12;
	std_it += 12;
	ft_second.insert( ft_it, 999 );
	std_second.insert( std_it, 999 );
	SECTION( "after iterator insert_node" ){
		REQUIRE( ft_second.capacity() == std_second.capacity());
		REQUIRE( ft_second.size() == std_second.size());
		REQUIRE( ft_second.front() == std_second.front());
		REQUIRE( ft_second.at( 12 ) == std_second.at( 12 ));
		REQUIRE( ft_second.back() == std_second.back());
	}
	ft_second.insert( ft_it, 222, 999 );
	std_second.insert( std_it, 222, 999 );
	SECTION( "after iterator insert_node" ){
		REQUIRE( ft_second.capacity() == std_second.capacity());
		REQUIRE( ft_second.size() == std_second.size());
		REQUIRE( ft_second.front() == std_second.front());
		REQUIRE( ft_second.at( 212 ) == std_second.at( 212 ));
		REQUIRE( ft_second.back() == std_second.back());
	}
	ft_it = ft_first.begin();
	std_it = std_first.begin();
	ft_it += 25;
	std_it += 25;
	ft_first.insert( ft_it, ft_second.begin(), ft_second.end());
	std_first.insert( std_it, std_second.begin(), std_second.end());
	SECTION( "after iterator insert_node" ){
		REQUIRE( ft_first.capacity() == std_first.capacity());
		REQUIRE( ft_first.size() == std_first.size());
		REQUIRE( ft_first.front() == std_first.front());
		REQUIRE( ft_first.at( 27 ) == std_first.at( 27 ));
		REQUIRE( ft_first.back() == std_first.back());
	}
	ft_it = ft_first.begin();
	std_it = std_first.begin();
	ft_it += 14;
	std_it += 14;
	ft_first.erase( ft_it );
	std_first.erase( std_it );
	SECTION( "after erase" ){
		REQUIRE( ft_first.capacity() == std_first.capacity());
		REQUIRE( ft_first.size() == std_first.size());
		REQUIRE( ft_first.front() == std_first.front());
		REQUIRE( ft_first.at( 27 ) == std_first.at( 27 ));
		REQUIRE( ft_first.back() == std_first.back());
	}
	ft_it = ft_first.begin();
	std_it = std_first.begin();
	ft_it += 36;
	std_it += 36;
	ft::vector< int >::iterator ft_it_end = ft_it;
	std::vector< int >::iterator std_it_end = std_it;
	ft_it_end += 28;
	std_it_end += 28;
	ft_first.erase( ft_it, ft_it_end );
	std_first.erase( std_it, std_it_end );
	SECTION( "after erase long" ){
		REQUIRE( ft_first.capacity() == std_first.capacity());
		REQUIRE( ft_first.size() == std_first.size());
		REQUIRE( ft_first.front() == std_first.front());
		REQUIRE( ft_first.at( 27 ) == std_first.at( 27 ));
		REQUIRE( ft_first.back() == std_first.back());
	}
	ft_first.swap( ft_second );
	std_first.swap( std_second );
	SECTION( "after swap" ){
		for ( int i = 0; i < ft_second.size(); i++ ){
			REQUIRE( ft_second[i] == std_second[i] );
		}
		REQUIRE( ft_first.capacity() == std_first.capacity());
		REQUIRE( ft_first.size() == std_first.size());
		REQUIRE( ft_first.front() == std_first.front());
		REQUIRE( ft_first.at( 27 ) == std_first.at( 27 ));
		REQUIRE( ft_first.back() == std_first.back());
	}
	ft_first.swap( ft_second );
	std_first.swap( std_second );
	SECTION( "after swap" ){
		for ( int i = 0; i < ft_second.size(); i++ ){
			REQUIRE( ft_second[i] == std_second[i] );
		}
		REQUIRE( ft_first.capacity() == std_first.capacity());
		REQUIRE( ft_first.size() == std_first.size());
		REQUIRE( ft_first.front() == std_first.front());
		REQUIRE( ft_first.at( 27 ) == std_first.at( 27 ));
		REQUIRE( ft_first.back() == std_first.back());
	}
}

TEST_CASE( "vector<int> relational operators", "[vector]" ){
	ft::vector< int > ft_first( 10 );
	ft::vector< int > ft_second( 10 );

	for ( int i = 0; i < 10; i++ ){
		ft_first[i] = i;
		ft_second[i] = i;
	}
	SECTION ( "Equal" ){
		REQUIRE( ft_first == ft_second );
		REQUIRE( ft_first <= ft_second );
		REQUIRE( ft_first >= ft_second );
	}
	ft_first.push_back( 9 );
	SECTION ( "Bigger" ){
		REQUIRE( ft_first != ft_second );
		REQUIRE( ft_first >= ft_second );
		REQUIRE( ft_first > ft_second );
	}
	ft_first.pop_back();
	ft_first.assign( 10, 0 );
	SECTION ( "Smaller" ){
		REQUIRE( ft_first != ft_second );
		REQUIRE( ft_first <= ft_second );
		REQUIRE( ft_first < ft_second );
	}
}
