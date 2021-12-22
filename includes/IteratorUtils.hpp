#ifndef FT_ITERATOR_UTILS_HPP
#define FT_ITERATOR_UTILS_HPP

namespace ft {

	struct input_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };
	struct reverse_iterator_tag { };

	template < class Iterator >
	struct iterator_traits {
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template < class T >
	struct iterator_traits< T* > {
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template < class T >
	struct iterator_traits< const T* > {
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template < bool cond, class T = void > struct enable_if { };
	template < class T > struct enable_if< true, T > { typedef T type; };

	template < class T, class Up = void > struct is_same { static const bool value = false; };
	template < class T > struct is_same< T, T > { static const bool value = true; };

	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last ) {
		typename iterator_traits<InputIterator>::difference_type diff(0);
		for (; first != last; ++first)
			++diff;
		return diff;
	}

}

#endif
