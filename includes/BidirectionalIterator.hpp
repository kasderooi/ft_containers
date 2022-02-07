#ifndef FT_CONTAINERS_BidirectionalIterator_HPP
#define FT_CONTAINERS_BidirectionalIterator_HPP

#include "IteratorUtils.hpp"

namespace ft{


	template< class T, class Pointer = T *, class Reference = T &, class Category = ft::bidirectional_iterator_tag >
	class BidirectionalIterator{

		public:

			typedef BidirectionalIterator< T, Pointer, Reference > iterator;
			typedef T value_type;
			typedef ptrdiff_t difference_type;
			typedef Pointer pointer;
			typedef Reference reference;
			typedef Category iterator_category;
			typedef size_t size_type;

		private :

			pointer _ptr;

		public:

			BidirectionalIterator( void ) : _ptr( NULL ){ return; }

			BidirectionalIterator( pointer ptr ) : _ptr( ptr ){ return; }

			BidirectionalIterator( const iterator &original ) : _ptr( original._ptr ){ return; }

			~BidirectionalIterator( void ){ return; }

			iterator &operator=( const iterator &original ){
				this->_ptr = original._ptr;
				return ( *this );
			}

			iterator &operator++( void ){
				this->_ptr++;
				return *this;
			}

			iterator operator++( int ){
				iterator ret = *this;
				++this->_ptr;
				return ret;
			}

			//		iterator operator++( void ) { this->_ptr++; return this; }
			iterator &operator--( void ){
				this->_ptr--;
				return *this;
			}

			iterator operator--( int ){
				iterator ret = *this;
				--this->_ptr;
				return ret;
			}

			reference operator*( void ){ return *this->_ptr; }

			pointer operator->( void ){ return this->_ptr; }

			bool operator==( const iterator &subject ) const{ return this->_ptr == subject._ptr; }

			bool operator!=( const iterator &subject ) const{ return this->_ptr != subject._ptr; }

	};

}

#endif
