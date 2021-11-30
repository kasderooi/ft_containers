#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

namespace ft {

	template < class T, class Pointer = T*, class Reference = T&, class Category = ft::iterator_tag >
	class Iterator {

		public:

		typedef Iterator<T, Pointer, Reference>	iterator;
		typedef T			value_type;
		typedef ptrdiff_t	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

		protected:

		pointer	_ptr;

		public:

		Iterator( void ) : _ptr( NULL ) { return; };
		Iterator( pointer ptr ) : _ptr( ptr ) { return; };
		Iterator( const iterator& original ) : _ptr( original._ptr ) { return; };
		virtual ~Iterator( void ) { return; };

	};
}

#endif
