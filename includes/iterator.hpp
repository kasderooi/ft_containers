#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

namespace ft {

	template < class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	class iterator {

		public:

			typedef Category  iterator_category;
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;

		private:

			pointer _it;

		public:


	};
}

#endif
