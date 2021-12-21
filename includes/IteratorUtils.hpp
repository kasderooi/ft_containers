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
//
//	template <class T>
//	struct has_iterator_category
//	{
//		private:
//		struct __two {char __lx; char __lxx;};
//		template <class Up> static __two __test(...);
//		template <class Up> static char __test(typename Up::iterator_category* = 0);
//		public:
//		static const bool value = sizeof(__test<T>(0)) == 1;
//	};
//
//	template <class T, class Up, bool = has_iterator_category<iterator_traits<T> >::value>
//	struct has_iterator_category_convertible_to
//			: public integral_constant<bool, is_convertible<typename iterator_traits<T>::iterator_category, Up>::value>
//	{};


}

#endif
