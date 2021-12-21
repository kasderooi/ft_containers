#ifndef FT_REVERSEITERATOR_HPP
#define FT_REVERSEITERATOR_HPP

#include "IteratorUtils.hpp"

namespace ft {

	template < class T, class Pointer = T*, class Reference = T&, class Category = ft::reverse_iterator_tag >
	class ReverseIterator {

		public:

			typedef ReverseIterator<T, Pointer, Reference>	iterator;
			typedef T			value_type;
			typedef ptrdiff_t	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
			typedef size_t 		size_type;

		private :

			pointer	_ptr;

		public:

			ReverseIterator( void ) : _ptr( NULL ) { return; }
			ReverseIterator( pointer ptr ) : _ptr( ptr ) { return; }
			ReverseIterator( const iterator& original ) : _ptr( original._ptr ) { return; }
			~ReverseIterator( void ) { return; }

			iterator& operator=( const iterator& original ) { this->_ptr = original._ptr; return (*this); }
			iterator& operator++( void ) { this->_ptr--; return *this; }
			iterator operator++( int ) { iterator ret = *this; --this->_ptr; return ret; }
	//		iterator operator++( void ) { this->_ptr++; return this; }
			iterator& operator--( void ) { this->_ptr++; return *this; }
			iterator operator--( int ) { iterator ret = *this; ++this->_ptr; return ret; }
			iterator operator+( difference_type n ) { return iterator( this->_ptr - n ); }
			size_type operator+( iterator n ) { return this->_ptr - n._ptr; }
			iterator operator-( difference_type n ) { return iterator( this->_ptr + n ); }
			size_type operator-( iterator n ) { return this->_ptr + n._ptr; }
			iterator& operator+=( difference_type n ) { this->_ptr -= n; return *this; }
			iterator& operator-=( difference_type n ) { this->_ptr += n; return *this; }
			reference operator*( void ) { return *this->_ptr; }
			pointer operator->( void ) { return this->_ptr; }
			reference operator[]( difference_type n ) const { return *(*this + n ); }
			bool operator==( const iterator& subject ) const { return this->_ptr == subject._ptr; }
			bool operator!=( const iterator& subject ) const { return this->_ptr != subject._ptr; }
			bool operator<( const iterator& subject ) const { return this->_ptr > subject._ptr; }
			bool operator>( const iterator& subject ) const { return this->_ptr < subject._ptr; }
			bool operator<=( const iterator& subject ) const { return this->_ptr >= subject._ptr; }
			bool operator>=( const iterator& subject ) const { return this->_ptr <= subject._ptr; }

	};
}

#endif
