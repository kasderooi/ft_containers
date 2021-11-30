#ifndef FT_INPUTITERATOR_HPP
#define FT_INPUTITERATOR_HPP

namespace ft {

	template < class T, class Pointer = T*, class Reference = T&, class Category = ft::input_iterator_tag >
	class InputIterator {

		public:

			typedef InputIterator<T, Pointer, Reference>	iterator;
			typedef T			value_type;
			typedef ptrdiff_t	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;

		protected:

			pointer	_tptr;

		public:

			InputIterator( void ) : _tptr( NULL ) { return; };
			InputIterator( pointer tptr ) : _tptr( tptr ) { return; };
			InputIterator( const iterator& original ) : _tptr( original._tptr ) { return; };
			virtual ~InputIterator( void ) { return; };

			iterator& operator=( const iterator& original ) { this->_tptr = original._tptr; return (*this); };
			iterator& operator++( void ) { _tptr++; return *this; };
			iterator operator++( value_type ) { iterator ret = *this; _tptr++; return ret; };
			void operator++( void ) { _tptr++; };
			reference operator*( void ) { return *_tptr };
			pointer operator->( void ) { return _ptr };
	};
}

#endif
