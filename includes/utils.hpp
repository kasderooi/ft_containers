#ifndef FT_CONTAINERS_UTILS_HPP
#define FT_CONTAINERS_UTILS_HPP

namespace ft{

	template< class T1, class T2, class Ret >
	struct binary_function{
		typedef T1 first_type;
		typedef T2 second_type;
		typedef Ret return_type;
	};

	template< class T >
	struct less : binary_function< T, T, bool >{
		bool operator()( const T& x, const T& y ) const{
			return x < y;
		}
	};

	template< bool cond, class T = void >
	struct enable_if{
	};
	template< class T >
	struct enable_if< true, T >{
		typedef T type;
	};

	template< class T, class Up = void >
	struct is_same{
		static const bool value = false;
	};
	template< class T >
	struct is_same< T, T >{
		static const bool value = true;
	};

	template< class T >
	T min( const T& first, const T& second ){
		return ( first < second ? first : second );
	}

	template< class T >
	T max( const T& first, const T& second ){
		return ( first > second ? first : second );
	}

	template< class T >
	void swap( T& first, T& second ){
		T tmp = first;
		first = second;
		second = tmp;
	}

	template< class _Compare, class _InputIterator1, class _InputIterator2 >
	bool lexicographical_compare( _InputIterator1 first1, _InputIterator1 last1,
								  _InputIterator2 first2, _InputIterator2 last2, _Compare comp ){
		for ( ; first2 != last2; first1++, first2++ ){
			if ( first1 == last1 || *first2 > *first1 )
				return true;
			if ( *first1 > *first2 )
				return false;
		}
		return false;
	}

}

#endif //FT_CONTAINERS_UTILS_HPP
