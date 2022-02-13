#ifndef FT_REVERSEITERATOR_HPP
#define FT_REVERSEITERATOR_HPP

#include "IteratorUtils.hpp"

namespace ft{

	template< class Iterator, class Category = ft::reverse_iterator_tag >
	class ReverseIterator{

		public:

			typedef Iterator iterator_type;
			typedef ReverseIterator< Iterator > iterator;
			typedef typename ft::iterator_traits< Iterator >::value_type value_type;
			typedef typename ft::iterator_traits< Iterator >::iterator_category iterator_category;
			typedef typename ft::iterator_traits< Iterator >::difference_type difference_type;
			typedef typename ft::iterator_traits< Iterator >::pointer pointer;
			typedef typename ft::iterator_traits< Iterator >::reference reference;

		private :

			iterator_type _ptr;

		public:

			ReverseIterator( void ) : _ptr( NULL ){ return; }

			ReverseIterator( iterator_type ptr ) : _ptr( ptr ){ return; }

			ReverseIterator( const iterator& original ) : _ptr( original._ptr ){ return; }

			~ReverseIterator( void ){ return; }

			iterator& operator=( const iterator& original ){
				this->_ptr = original._ptr;
				return ( *this );
			}

			iterator& operator++( void ){
				this->_ptr--;
				return *this;
			}

			iterator operator++( int ){
				iterator ret = *this;
				--this->_ptr;
				return ret;
			}

			//		iterator operator++( void ) { this->_ptr++; return this; }
			iterator& operator--( void ){
				this->_ptr++;
				return *this;
			}

			iterator operator--( int ){
				iterator ret = *this;
				++this->_ptr;
				return ret;
			}

			iterator operator+( difference_type n ){ return iterator( this->_ptr - n ); }

//			size_type operator+( iterator n ) { return this->_ptr - n._ptr; }
			iterator operator-( difference_type n ){ return iterator( this->_ptr + n ); }

//			size_type operator-( iterator n ) { return this->_ptr + n._ptr; }
			iterator& operator+=( difference_type n ){
				this->_ptr -= n;
				return *this;
			}

			iterator& operator-=( difference_type n ){
				this->_ptr += n;
				return *this;
			}

			reference operator*( void ){ return *this->_ptr; }

			pointer operator->( void ){ return this->_ptr; }

			reference operator[]( difference_type n ) const{ return *( *this + n ); }

			bool operator==( const iterator& subject ) const{ return this->_ptr == subject._ptr; }

			bool operator!=( const iterator& subject ) const{ return this->_ptr != subject._ptr; }

			bool operator<( const iterator& subject ) const{ return this->_ptr > subject._ptr; }

			bool operator>( const iterator& subject ) const{ return this->_ptr < subject._ptr; }

			bool operator<=( const iterator& subject ) const{ return this->_ptr >= subject._ptr; }

			bool operator>=( const iterator& subject ) const{ return this->_ptr <= subject._ptr; }

	};
}

#endif
