#ifndef FT_INPUTITERATOR_HPP
#define FT_INPUTITERATOR_HPP

#include "Iterator.hpp"

namespace ft {

	template < class T, class Pointer = T*, class Reference = T&, class Category = ft::input_iterator_tag >
	class InputIterator : public ft::Iterator<T, Pointer, Reference> {

		public:

			typedef InputIterator<T, Pointer, Reference>	iterator;
			typedef T			value_type;
			typedef ptrdiff_t	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;

		public:

			InputIterator( void ) : Iterator() { return; };
			InputIterator( pointer iptr ) : Iterator( iptr ) { return; };
			InputIterator( const iterator& original ) : ft::Iterator( original ) { return; };
			virtual ~InputIterator( void ) { return; };

			iterator& operator=( const iterator& original ) { this->_ptr = original._ptr; return (*this); };
			iterator& operator++( void ) { this->_ptr++; return *this; };
			iterator operator++( value_type ) { iterator ret = *this; this->_ptr++; return ret; };
			void operator++( void ) { this->_ptr++; };
			reference operator*( void ) { return *this->_ptr };
			pointer operator->( void ) { return this->_ptr };

			bool operator==( const iterator& subject ) const { return this->_ptr == subject._ptr };
			bool operator!=( const iterator& subject ) const { return this->_ptr != subject._ptr };
	};
}

//namespace ft {
//
//	template < class T, class Pointer = T*, class Reference = T&, class Category = ft::input_iterator_tag >
//	class InputIterator {
//
//		public:
//
//		typedef InputIterator<T, Pointer, Reference>	iterator;
//		typedef T			value_type;
//		typedef ptrdiff_t	difference_type;
//		typedef Pointer		pointer;
//		typedef Reference	reference;
//		typedef Category	iterator_category;
//
//		protected:
//
//		pointer	_ptr;
//
//		public:
//
//		InputIterator( void ) : _ptr( NULL ) { return; };
//		InputIterator( pointer iptr ) : _ptr( iptr ) { return; };
//		InputIterator( const iterator& original ) : _ptr( original._ptr ) { return; };
//		virtual ~InputIterator( void ) { return; };
//
//		iterator& operator=( const iterator& original ) { this->_ptr = original._ptr; return (*this); };
//		iterator& operator++( void ) { _ptr++; return *this; };
//		iterator operator++( value_type ) { iterator ret = *this; _ptr++; return ret; };
//		void operator++( void ) { _ptr++; };
//		reference operator*( void ) { return *_ptr };
//		pointer operator->( void ) { return _ptr };
//	};
//}
#endif
