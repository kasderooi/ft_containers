//
// Created by Kas on 03/02/2022.
//

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
    struct less: binary_function< T, T, bool >{
        bool operator()( const T& x, const T& y ) const{
            return x < y;
        }
    };

    template< class T >
    T min( const T& first, const T& second ) {
        return ( first < second ? first : second );
    }

	template< class T >
	T max( const T& first, const T& second ) {
	    return ( first > second ? first : second );
	}
}

#endif //FT_CONTAINERS_UTILS_HPP
