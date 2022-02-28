#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "ft_vector.hpp"

namespace ft{

	template< class T, class Container = vector< T > >
	class stack{

		public:

			typedef Container container_type;
			typedef typename container_type::value_type value_type;
			typedef typename container_type::size_type size_type;
			typedef typename container_type::reference reference;
			typedef typename container_type::const_reference const_reference;

		protected:

			container_type _ctnr;

		public:

			//-------(De-)Constructors-------//
			explicit stack( const container_type& ctnr = container_type()) : _ctnr( ctnr ){ return; }

			//-------Capacity-------//
			bool empty( void ) const{ return _ctnr.empty(); }

			size_type size( void ) const{ return _ctnr.size(); }

			//-------Element access-------//
			value_type& top( void ){ return _ctnr.back(); }

			const value_type& top( void ) const{ return _ctnr.back(); }

			//-------Modifiers-------//
			void push( const value_type& val ){ _ctnr.push_back( val ); }

			void pop( void ){ _ctnr.pop_back(); }

			//-------Relational operators-------//
			template< class T1, class Container1 >
			friend bool operator==( const stack< T1, Container1 >& lhs, const stack< T1, Container1 >& rhs );

			template< class T1, class Container1 >
			friend bool operator<( const stack< T1, Container1 >& lhs, const stack< T1, Container1 >& rhs );
	};

	//-------Non-member function overloads-------//
	template< class T, class Container >
	bool operator==( const stack< T, Container >& lhs, const stack< T, Container >& rhs ){
		return lhs._ctnr == rhs._ctnr;
	}

	template< class T, class Container >
	bool operator!=( const stack< T, Container >& lhs, const stack< T, Container >& rhs ){ return !( lhs == rhs ); }

	template< class T, class Container >
	bool operator<( const stack< T, Container >& lhs, const stack< T, Container >& rhs ){
		return lhs._ctnr < rhs._ctnr;
	}

	template< class T, class Container >
	bool operator<=( const stack< T, Container >& lhs, const stack< T, Container >& rhs ){ return !( rhs < lhs ); }

	template< class T, class Container >
	bool operator>( const stack< T, Container >& lhs, const stack< T, Container >& rhs ){ return rhs <= lhs; }

	template< class T, class Container >
	bool operator>=( const stack< T, Container >& lhs, const stack< T, Container >& rhs ){ return !( lhs < rhs ); }
}

#endif //FT_CONTAINERS_FT_STACK_HPP
