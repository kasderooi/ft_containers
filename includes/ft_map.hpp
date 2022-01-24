#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <deque>

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< pair< const Key,T > > >
	class map {

		public:

			typedef		Key						key_type;
			typedef		T						mapped_type;
			typedef		std::pair<const Key, T>	value_type;
			typedef		Compare					key_compare;
			//typedef	 nestedfunctionclass				value_compare;
			typedef		Alloc					allocator_type;
			typedef		value_type&				reference;
			typedef		const value_type&		const_reference;
			typedef		value_type*				pointer;
			typedef		const value_type*		const_pointer;
			typedef		size_t					size_type;
			typedef		ptrdiff_t 				difference_type;
//			typedef	typename ft::BidirectionalIterator< T, T*, T& > iterator;
//			typedef	typename ft::BidirectionalIterator< T, const T*, const T& > const_iterator;
//			typedef	typename ft::BidirectionalIterator< T, T*, T& > reverse_iterator;
//			typedef	typename ft::BidirectionalIterator< T, const T*, const T& > const_reverse_iterator;

		private:

			key_type		_key;
			mapped_type		_type;
			allocator_type	_alloc;
			pointer 		_map;

		public:

	//-------(De-)Constructors-------//

	//-------Capacity-------//

	//-------Element access-------//

	//-------Modifiers-------//

	//-------Operational overloads-------//
	};
	//-------Non-member function overloads-------//
}

#endif //FT_CONTAINERS_FT_MAP_HPP
