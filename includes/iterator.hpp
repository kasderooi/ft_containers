#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

namespace ft {

	template < class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	struct iterator {
		typedef Category  iterator_category;
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
	};

	struct input_iterator_tag {
		
	};
}

#endif
