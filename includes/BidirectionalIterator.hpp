#ifndef FT_CONTAINERS_BidirectionalIterator_HPP
#define FT_CONTAINERS_BidirectionalIterator_HPP

#include "IteratorUtils.hpp"

namespace ft{


	template< class T, class Pointer, class Reference, class Category = bidirectional_iterator_tag >
	class BidirectionalIterator{

		public:

			typedef T value_type;
			typedef BidirectionalIterator< T, Pointer, Reference > iterator;
			typedef ptrdiff_t difference_type;
			typedef Pointer pointer;
			typedef Reference reference;
			typedef Category iterator_category;
			typedef size_t size_type;
//			typedef typename value_type::pointer pointer;

		private :

			value_type _ptr;

		public:

			BidirectionalIterator( void ) : _ptr( NULL ){ return; }

			BidirectionalIterator( value_type ptr ) : _ptr( ptr ){ return; }

			BidirectionalIterator( const iterator& original ) : _ptr( original._ptr ){ return; }

			~BidirectionalIterator( void ){ return; }

			iterator& operator=( const iterator& original ){
				this->_ptr = original._ptr;
				return ( *this );
			}

			iterator& operator++( void ){
				_ptr = _ptr->next( _ptr->_input );
				return *this;
			}

			iterator operator++( int ){
				iterator ret = *this;
				_ptr = _ptr->next( _ptr->_input );
				return ret;
			}

			//		iterator operator++( void ) { this->_ptr++; return this; }
			iterator& operator--( void ){
				_ptr = _ptr->previous( _ptr->_input );
				return *this;
			}

			iterator operator--( int ){
				iterator ret = *this;
				_ptr = _ptr->previous( _ptr->_input );
				return ret;
			}

			reference operator*( void ){ return this->_ptr->_input; }

			pointer operator->( void ){ return &this->_ptr->_input; }

			bool operator==( const iterator& subject ) const{ return _ptr == subject._ptr; }

			bool operator!=( const iterator& subject ) const{ return _ptr != subject._ptr; }

	};

}

#endif
