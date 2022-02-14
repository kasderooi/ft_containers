#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include "ft_pair.hpp"
#include "AVLtree.hpp"
#include "utils.hpp"
#include "BidirectionalIterator.hpp"
#include "ReverseIterator.hpp"
#include <memory>

namespace ft{

	template< class Key, class T, class Compare = ft::less< Key >, class Alloc = std::allocator< ft::pair< const Key, T > > >
	class map{

		public:

			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair< const Key, T > value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef AVLtree< value_type > node;
			typedef node* node_pointer;
			typedef const node* const_node_pointer;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename ft::BidirectionalIterator< node_pointer, pointer, reference > iterator;
			typedef typename ft::BidirectionalIterator< const_node_pointer, const_pointer, const_reference > const_iterator;
			typedef typename ft::ReverseIterator< iterator > reverse_iterator;
			typedef typename ft::ReverseIterator< const_iterator > const_reverse_iterator;
			typedef typename Alloc::template rebind< node >::other node_alloc;

			class value_compare : public binary_function< value_type, value_type, bool >{

				public:

					friend class map;

				protected:

					key_compare comp;

					value_compare( key_compare c ) : comp( c ){};

				public:

					bool operator()( const value_type& x, const value_type& y ) const{
						return comp( x.first, y.first );
					}
			};

			typedef value_compare nestedfunctionclass;

		private:

			node_alloc _alloc;
			size_type _size;
			node_pointer _root;
			node_pointer _begin;
			node_pointer _end;
			key_compare _compare;

		public:

			//-------(De-)Constructors-------//
			explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
					_alloc( alloc ), _size( 0 ), _root( NULL ), _begin( NULL ), _end( NULL ), _compare( comp ){
				set_endpoints();
				return;
			}

			template< class InputIterator >
			map( InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type()) : _alloc( alloc ), _size( 0 ), _root( NULL ),
																   _begin( NULL ), _end( NULL ), _compare( comp ){
				InputIterator tmp = first;
				set_endpoints();
				while ( tmp != last ){
					this->insert( *tmp );
					tmp++;
				}
				return;
			}

			map( const map& x ) : _alloc( x._alloc ), _size( 0 ), _root( NULL ), _begin( NULL ),
								  _end( NULL ), _compare( x._compare ){
				set_endpoints();
				*this = x;
				return;
			}

			~map( void ){
				clear();
				_alloc.destroy( _begin );
				_alloc.deallocate( _begin, 1 );
				_alloc.destroy( _end );
				_alloc.deallocate( _end, 1 );
				return;
			}

			//-------Assignment Operator-------//
			map& operator=( const map& original ){
				clear();
				_alloc = original._alloc;
				insert( original.begin(), original.end());
				return *this;
			}

			//-------iterators-------//
			iterator begin( void ){
				return iterator( _begin->_parent );
			}

			const_iterator begin( void ) const{
				return const_iterator( _begin->_parent );
			}

			iterator end( void ){
				return iterator( _end );
			}

			const_iterator end( void ) const{
				return const_iterator( _end );
			}

			reverse_iterator rbegin( void ){
				return reverse_iterator( _end->_parent );
			}

			const_reverse_iterator rbegin( void ) const{
				return const_reverse_iterator( _end->_parent );
			}

			reverse_iterator rend( void ){
				return reverse_iterator( _begin );
			}

			const_reverse_iterator rend( void ) const{
				return const_reverse_iterator( _begin );
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
				return _alloc.max_size();
			}

			//-------Element access-------//
			mapped_type& operator[]( const key_type& k ){
				node_pointer find = _root ? _root->find_node( k ) : NULL;
				if ( find )
					return find->_input.second;
				return ( *( this->insert( ft::make_pair( k, mapped_type())).first )).second;
			}

			//-------Modifiers-------//
			pair< iterator, bool > insert( const_reference val ){
				if ( _root && _root->find_node( val ))
					return ( ft::make_pair( iterator( _root->find_node( val )), false ));
				node_pointer tmp = _alloc.allocate( 1 );
				_alloc.construct( tmp, val );
				tmp->_end = this->_end;
				_size++;
				if ( _root ){
					_root = _root->insert_node( tmp );
					if ( val.first < _begin->_parent->_input.first )
						this->_begin->_parent = tmp;
					if ( val.first > _end->_parent->_input.first )
						this->_end->_parent = tmp;
				}else{
					_root = tmp;
					this->_begin->_parent = tmp;
					this->_end->_parent = tmp;
				}
				return ( ft::make_pair( iterator( _root->find_node( val )), true ));
			}

			iterator insert( iterator position, const_reference val ){
				if ( _root && _root->find_node( val ))
					return ( iterator( _root->find_node( val )));
				node_pointer tmp = _alloc.allocate( 1 );
				_alloc.construct( tmp, val );
				tmp->_begin = &this->_begin;
				tmp->_end = &this->_end;
				_size++;
				if (( *position )->_input.first < val.first )
					( *position )->insert_right( tmp );
				else
					( *position )->insert_left( tmp );
				_root = _root->balance();
				return iterator( tmp );
			}

			template< class InputIterator >
			void insert( InputIterator first, InputIterator last,
						 typename ft::enable_if< !is_same< InputIterator, value_type >::value, int >::type = 0 ){
				InputIterator it = first;
				while ( it != last ){
					insert(( *it )->_input );
					it++;
				}
			}

			void erase( iterator position ){
				erase( position->first );
			}

			size_type erase( const key_type& key ){
				if ( !_root || !key )
					return 0;
				node_pointer tmp = _root->find_node( ft::make_pair( key, mapped_type() ) );
				if ( !tmp )
					return _size;
				node_pointer tmp_left = tmp->_left ? tmp->_left->balance() : NULL;
				node_pointer tmp_right = tmp->_right ? tmp->_right->balance() : NULL;
				if ( tmp != _root ){
					if ( tmp->_parent->_left == tmp ){
						tmp->_parent->_left = NULL;
						tmp->_parent->set_height();
					}else if ( tmp->_parent->_right == tmp ){
						tmp->_parent->_right = NULL;
						tmp->_parent->set_height();
					}
					if ( tmp == _end->_parent )
						_end->_parent = _root->find_node( (*(--iterator( tmp ))).first );
					if ( tmp == _begin->_parent )
						_begin->_parent = _root->find_node( (*(++iterator( tmp ))).first );
					_root = _root->insert_node( tmp_left )->insert_node( tmp_right );
				}else if ( tmp_right || tmp_left ){
					size_type left_height = tmp_left ? tmp_left->_height : 0;
					size_type right_height = tmp_right ? tmp_right->_height : 0;
					if ( tmp_right && ( !tmp_left || left_height > right_height )){
						tmp_right->_parent = NULL;
						_root = tmp_right;
						_root = _root->insert_node( tmp_left );
					}else{
						tmp_left->_parent = NULL;
						_root = tmp_left;
						_root = _root->insert_node( tmp_right );
					}
				}else{
					_root = NULL;
					_begin->_parent = _end;
					_end->_parent = _begin;
				}
				_alloc.destroy( tmp );
				_alloc.deallocate( tmp, 1 );
				return --_size;
			}

			void erase( iterator first, iterator last ){
				iterator tmp;
				while ( first != last ){
					tmp = first++;
					erase( tmp );
				}
			}

			void swap( map& original ){
				ft::swap( this->_size, original._size );
				ft::swap( this->_alloc, original._alloc );
				ft::swap( this->_root, original._root );
				ft::swap( this->_begin, original._begin );
				ft::swap( this->_end, original._end );

			}

			void clear( void ){
				erase( begin(), end());
			}

			void print( void ){
				_root->print();
			}

			void print_node( key_type key ){
				_root->find_node( ft::make_pair( key, mapped_type() ) )->print_nodes();
			}

			//-------Observers-------//
			key_compare key_comp( void ) const{
				return _compare;
			}

			value_compare value_comp( void ) const{
				return value_compare( _compare );
			}

			//-------Map Operations-------//
			iterator find( const key_type& k ){
				node_pointer tmp = _root ? _root->find_node( k ) : NULL;
				if ( tmp )
					return iterator( tmp );
				return iterator( _end );
			}

			const_iterator find( const key_type& k ) const{
				node_pointer tmp = _root ? _root->find_node( k ) : NULL;
				if ( tmp )
					return iterator( tmp );
				return iterator( _end );
			}
//			size_type      count(const key_type& k) const;
//			iterator lower_bound(const key_type& k);
//			const_iterator lower_bound(const key_type& k) const;
//			iterator upper_bound(const key_type& k);
//			const_iterator upper_bound(const key_type& k) const;
//			pair<iterator,iterator>             equal_range(const key_type& k);
//			pair<const_iterator,const_iterator> equal_range(const key_type& k) const;

			//-------Operational overloads-------//
		private:

			void set_endpoints( void ){
				_begin = _alloc.allocate( 1 );
				_alloc.construct( _begin, ft::make_pair( key_type(), mapped_type()));
				_end = _alloc.allocate( 1 );
				_alloc.construct( _end, ft::make_pair( key_type(), mapped_type()));
				_begin->_parent = _end;
				_begin->_begin = _begin;
				_begin->_end = _end;
				_end->_parent = _begin;
				_end->_begin = _begin;
				_end->_end = _end;
			}
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
