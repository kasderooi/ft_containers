#ifndef FT_INPUTITERATOR_HPP
#define FT_INPUTITERATOR_HPP

namespace ft {

	template < class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&, class Category = ft::input_iterator_tag >
	class InputIterator {

		public:

			typedef Category	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;

		private:


	};
}

#endif
