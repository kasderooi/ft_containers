#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include "ft_pair.hpp"
#include "AVLtree.hpp"
#include "BidirectionalIterator.hpp"

namespace ft{

	template< class Key, class T, class Compare = std::less< Key >, class Alloc = std::allocator< ft::pair< const Key, T > > >
	class map{

		public:

			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair< const Key, T > value_type;
			typedef Compare key_compare;
			//typedef	 nestedfunctionclass				value_compare;
			typedef Alloc allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef AVLtree< value_type > node;
			typedef node* node_pointer;
			typedef std::allocator< node > node_allocator_type;
			typedef typename ft::BidirectionalIterator< node, node*, node& > iterator;
			typedef typename ft::BidirectionalIterator< node, const node*, const node& > const_iterator;
			typedef typename ft::BidirectionalIterator< node, node*, node& > reverse_iterator;
			typedef typename ft::BidirectionalIterator< node, const node*, const node& > const_reverse_iterator;

			class value_compare : public std::binary_function< value_type, value_type, bool >{

				public:

					friend class map;

				protected:

					key_compare comp;

					value_compare( key_compare c );

				public:

					bool operator()( const value_type& x, const value_type& y ) const;
			};

		private:

			allocator_type _alloc;
			node_allocator_type _nalloc;
			size_type _size;
			node_pointer _root;
			node_pointer _begin;
			node_pointer _end;

		public:

			//-------(De-)Constructors-------//
			explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
					_alloc( alloc ), _nalloc( node_allocator_type()), _size( 0 ), _root( NULL ), _begin( NULL ),
					_end( NULL ){ return; }

//			template< class InputIterator >
//			map( InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
//				 const allocator_type &alloc = allocator_type());

			map( const map& x ){
				this = x;
				return;
			}

			~map( void ){ return; }

			//-------Assignment Operator-------//
//			map& operator=( const map& original ){
//
//			}

			//-------iterators-------//
			iterator begin( void ){
				return iterator( _begin );
			}

			const_iterator begin( void ) const{
				return const_iterator( _begin );
			}

			iterator end( void ){
				return iterator( _end );
			}

			const_iterator end( void ) const{
				return const_iterator( _end );
			}

			iterator rbegin( void ){
				return reverse_iterator( _begin );
			}

			const_iterator rbegin( void ) const{
				return const_reverse_iterator( _begin );
			}

			iterator rend( void ){
				return reverse_iterator( _end );
			}

			const_iterator rend( void ) const{
				return const_reverse_iterator( _end );
			}

			//-------Capacity-------//
			bool empty() const{
				if ( _size == 0 )
					return true;
				return false;
			}

			size_type size() const{
				return _size;
			}

			size_type max_size() const{
				return _nalloc.max_size();
			}

			//-------Element access-------//
//			mapped_type& operator[]( const key_type& k ){
//
//			}
//
//			mapped_type& operator[]( key_type&& k ){
//
//			}

			//-------Modifiers-------//
			pair< iterator, bool > insert( const value_type& val ){
				if ( !_root ) {
					_root = _nalloc.allocate( 1 );
					_nalloc.construct( _root, val );
					_begin = _root;
					_end = _root;
				} else {

				}
			}
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
