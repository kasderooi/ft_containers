#ifndef FT_CONTAINERS_BidirectionalIterator_HPP
#define FT_CONTAINERS_BidirectionalIterator_HPP

#include "IteratorUtils.hpp"

namespace ft{


	template< class pair, class T, class Pointer = T*, class Reference = T&, class Category = bidirectional_iterator_tag >
	class BidirectionalIterator{

		public:

			typedef BidirectionalIterator< pair, T, Pointer, Reference > iterator;
			typedef T value_type;
			typedef ptrdiff_t difference_type;
			typedef Pointer pointer;
			typedef Reference reference;
			typedef pair& p_reference;
			typedef pair* p_pointer;
			typedef Category iterator_category;
			typedef size_t size_type;

		private :

			pointer _ptr;

		public:

			BidirectionalIterator( void ) : _ptr( NULL ){ return; }

			BidirectionalIterator( pointer ptr ) : _ptr( ptr ){ return; }

			BidirectionalIterator( const iterator& original ) : _ptr( original._ptr ){ return; }

			~BidirectionalIterator( void ){ return; }

			iterator& operator=( const iterator& original ){
				this->_ptr = original._ptr;
				return ( *this );
			}

			iterator& operator++( void ){
				_ptr = _ptr->next( _ptr->_input.first );
				return *this;
			}

			iterator operator++( int ){
				iterator ret = *this;
				_ptr = _ptr->next( _ptr->_input.first );
				return ret;
			}

			//		iterator operator++( void ) { this->_ptr++; return this; }
			iterator& operator--( void ){
				_ptr = _ptr->previous( _ptr->_input.first );
				return *this;
			}

			iterator operator--( int ){
				iterator ret = *this;
				_ptr = _ptr->previous( _ptr->_input.first );
				return ret;
			}

			p_reference operator*( void ){ return *this->_ptr->_input; }

			p_pointer operator->( void ){ return this->_ptr->_input; }

			bool operator==( const iterator& subject ) const{ return _ptr == subject._ptr; }

			bool operator!=( const iterator& subject ) const{ return _ptr != subject._ptr; }

	};

}

#endif
