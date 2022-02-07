#ifndef FT_CONTAINERS_FT_PAIR_HPP
#define FT_CONTAINERS_FT_PAIR_HPP

namespace ft{

	template< class T1, class T2 >
	struct pair{

		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair( void ) : first(), second(){ return; }

		pair( const first_type& _first, const second_type& _second ) : first( _first ), second( _second ){ }

		template< class U, class V >
		pair( const pair< U, V > &pr ) : first( pr.first ), second( pr.second ){ return; }

		pair< T1, T2 > &operator=( const pair &original ){
			first = original.first;
			second = original.second;
			return *this;
		}
	};

	template< class T1, class T2 >
	pair< T1, T2 > make_pair( T1 first, T2 second ){
		return ( pair< T1, T2 >( first, second ));
	}
}

#endif //FT_CONTAINERS_FT_PAIR_HPP
