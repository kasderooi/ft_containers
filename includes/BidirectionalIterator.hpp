#ifndef FT_CONTAINERS_BidirectionalIterator_HPP
#define FT_CONTAINERS_BidirectionalIterator_HPP

#include "IteratorUtils.hpp"

namespace ft{


	template< class T, class Pointer, class Reference, class Category = bidirectional_iterator_tag >
	class BidirectionalIterator{

		public:

			typedef T value_type;
			typedef Pointer pointer;
            typedef Reference reference;
            typedef AVLtree< T >* node;
            typedef BidirectionalIterator< T, Pointer, Reference > iterator;
            typedef BidirectionalIterator< T, const Pointer, const Reference > const_iterator;
			typedef ptrdiff_t difference_type;
			typedef Category iterator_category;
			typedef size_t size_type;

		protected:

            node _ptr;

		public:

			explicit BidirectionalIterator( void ) : _ptr( NULL ){ return; }

			explicit BidirectionalIterator( node ptr ) : _ptr( ptr ){ return; }

			BidirectionalIterator( const iterator& original ) : _ptr( original._ptr ){ return; }

			virtual ~BidirectionalIterator( void ){ return; }

			virtual iterator& operator=( const iterator& original ){
				this->_ptr = original._ptr;
				return ( *this );
			}

			virtual iterator& operator--( void ){
                this->_ptr = this->_ptr->previous( this->_ptr->_input );
                return *this;
			}

			iterator operator--( int ){
				iterator ret = *this;
                this->_ptr = this->_ptr->previous( this->_ptr->_input );
                return ret;
			}

			virtual iterator& operator++( void ){
                this->_ptr = this->_ptr->next( this->_ptr->_input );
                return *this;
			}

			iterator operator++( int ){
				iterator ret = *this;
                this->_ptr = this->_ptr->next( this->_ptr->_input );
                return ret;
			}

			//		iterator operator++( void ) { this->_ptr++; return this; }

			virtual reference operator*( void ){ return this->_ptr->_input; }

			virtual pointer operator->( void ){ return &this->_ptr->_input; }

			bool operator==( const iterator& subject ) const{ return _ptr == subject._ptr; }

			bool operator!=( const iterator& subject ) const{ return _ptr != subject._ptr; }

	};

}

#endif
