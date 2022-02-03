#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <deque>

namespace ft{

	template< class Key, class T, class Compare = std::less< Key >, class Alloc = std::allocator< std::pair< const Key, T > > >
	class map{

		public:

			typedef Key key_type;
			typedef T mapped_type;
			typedef std::pair< const Key, T > value_type;
			typedef Compare key_compare;
			//typedef	 nestedfunctionclass				value_compare;
			typedef Alloc allocator_type;
//			typedef		value_type&				reference;
//			typedef		const value_type&		const_reference;
//			typedef		value_type*				pointer;
//			typedef		const value_type*		const_pointer;
//			typedef		size_t					size_type;
//			typedef		ptrdiff_t 				difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::size_type size_type;
			typedef typename allocator_type::difference_type difference_type;
//			typedef	typename ft::BidirectionalIterator< T, T*, T& > iterator;
//			typedef	typename ft::BidirectionalIterator< T, const T*, const T& > const_iterator;
//			typedef	typename ft::BidirectionalIterator< T, T*, T& > reverse_iterator;
//			typedef	typename ft::BidirectionalIterator< T, const T*, const T& > const_reverse_iterator;

			class value_compare : public std::binary_function< value_type, value_type, bool >{

				public:

					friend class map;

				protected:

					key_compare comp;

					value_compare( key_compare c );

				public:

					bool operator()( const value_type &x, const value_type &y ) const;
			};

		private:

			allocator_type _alloc;
			pointer _map;
			size_type _size;
			size_type _capacity;

		public:

			//-------(De-)Constructors-------//
//			map()
//			noexcept(
//			is_nothrow_default_constructible<allocator_type>::value &&
//			is_nothrow_default_constructible<key_compare>::value &&
//			is_nothrow_copy_constructible<key_compare>::value);
//			explicit map(const key_compare& comp);
//			map(const key_compare& comp, const allocator_type& a);
//			template <class InputIterator>
//			map(InputIterator first, InputIterator last,
//				const key_compare& comp = key_compare());
//			template <class InputIterator>
//			map(InputIterator first, InputIterator last,
//				const key_compare& comp, const allocator_type& a);
//			map(const map& m);
//			map(map&& m)
//			noexcept(
//			is_nothrow_move_constructible<allocator_type>::value &&
//			is_nothrow_move_constructible<key_compare>::value);
//			explicit map(const allocator_type& a);
//			map(const map& m, const allocator_type& a);
//			map(map&& m, const allocator_type& a);
//			map(initializer_list<value_type> il, const key_compare& comp = key_compare());
//			map(initializer_list<value_type> il, const key_compare& comp, const allocator_type& a);
//			template <class InputIterator>
//			~map();
//
//			map& operator=(const map& m);
//			map& operator=(map&& m)
//			noexcept(
//			allocator_type::propagate_on_container_move_assignment::value &&
//			is_nothrow_move_assignable<allocator_type>::value &&
//			is_nothrow_move_assignable<key_compare>::value);
//			map& operator=(initializer_list<value_type> il);

			//-------iterators-------//
//			iterator begin() noexcept;
//			const_iterator begin() const noexcept;
//			iterator end() noexcept;
//			const_iterator end()   const noexcept;
//
//			reverse_iterator rbegin() noexcept;
//			const_reverse_iterator rbegin() const noexcept;
//			reverse_iterator rend() noexcept;
//			const_reverse_iterator rend()   const noexcept;
//
//			const_iterator         cbegin()  const noexcept;
//			const_iterator         cend()    const noexcept;
//			const_reverse_iterator crbegin() const noexcept;
//			const_reverse_iterator crend()   const noexcept;

			//-------Capacity-------//
//			bool      empty()    const noexcept;
//			size_type size()     const noexcept;
//			size_type max_size() const noexcept;

			//-------Element access-------//
//			mapped_type& operator[](const key_type& k);
//			mapped_type& operator[](key_type&& k);

			//-------Modifiers-------//
//			template <class... Args>
//			pair<iterator, bool> emplace(Args&&... args);
//			template <class... Args>
//			iterator emplace_hint(const_iterator position, Args&&... args);
//			pair<iterator, bool> insert(const value_type& v);
//			template <class P>
//			pair<iterator, bool> insert(P&& p);
//			iterator insert(const_iterator position, const value_type& v);
//			template <class P>
//			iterator insert(const_iterator position, P&& p);
//			template <class InputIterator>
//			void insert(InputIterator first, InputIterator last);
//			void insert(initializer_list<value_type> il);
//
//			iterator  erase(const_iterator position);
//			size_type erase(const key_type& k);
//			iterator  erase(const_iterator first, const_iterator last);
//			void clear() noexcept;

			//-------Observers-------//
//			allocator_type get_allocator() const noexcept;
//			key_compare    key_comp()      const;
//			value_compare  value_comp()    const;

			//-------Map Operations-------//
//			iterator find(const key_type& k);
//			const_iterator find(const key_type& k) const;
//			size_type      count(const key_type& k) const;
//			iterator lower_bound(const key_type& k);
//			const_iterator lower_bound(const key_type& k) const;
//			iterator upper_bound(const key_type& k);
//			const_iterator upper_bound(const key_type& k) const;
//			pair<iterator,iterator>             equal_range(const key_type& k);
//			pair<const_iterator,const_iterator> equal_range(const key_type& k) const;

			//-------Operational overloads-------//
	};
	//-------Non-member function overloads-------//
//		template <class Key, class T, class Compare, class Allocator>
//		bool operator==(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);
//
//		template <class Key, class T, class Compare, class Allocator>
//		bool operator< (const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);
//
//		template <class Key, class T, class Compare, class Allocator>
//		bool operator!=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);
//
//		template <class Key, class T, class Compare, class Allocator>
//		bool operator> (const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);
//
//		template <class Key, class T, class Compare, class Allocator>
//		bool operator>=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);
//
//		template <class Key, class T, class Compare, class Allocator>
//		bool operator<=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);
}


#endif //FT_CONTAINERS_FT_MAP_HPP
