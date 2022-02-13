#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include "ft_pair.hpp"
#include "AVLtree.hpp"
#include "utils.hpp"
#include "BidirectionalIterator.hpp"
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
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef AVLtree< const Key, T > node;
			typedef node* node_pointer;
			typedef typename Alloc::template rebind<node>::other node_alloc;
			typedef typename ft::BidirectionalIterator< value_type, node, node*, node& > iterator;
			typedef typename ft::BidirectionalIterator< value_type,node, const node*, const node& > const_iterator;
			typedef typename ft::BidirectionalIterator< value_type,node, node*, node& > reverse_iterator;
			typedef typename ft::BidirectionalIterator< value_type,node, const node*, const node& > const_reverse_iterator;

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

            typedef	value_compare nestedfunctionclass;

		private:

			node_alloc _alloc;
			size_type _size;
			node_pointer _root;
			node_pointer _begin;
			node _end;
			key_compare _compare;

		public:

			//-------(De-)Constructors-------//
			explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
					_alloc( alloc ), _size( 0 ), _root( &_end ), _begin( &_end ), _end(), _compare( comp ){
				_end._end = &_end;
				return;
			}

			template< class InputIterator >
			map( InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) : _alloc( alloc ), _size( 0 ), _root( &_end ),
					 _begin( &_end ), _end(), _compare( comp ){
				InputIterator tmp = first;
				_end._end = &_end;
				while ( tmp != last ){
					this->insert( *tmp );
					tmp++;
				}
				return;
			}

			map( const map& x ) : _alloc( x._alloc ), _size( 0 ), _root( &_end ), _begin( &_end ),
								  _end(), _compare( x._compare ){
				_end._end = &_end;
				*this = x;
				return;
			}

			~map( void ){ clear(); return; }

			//-------Assignment Operator-------//
			map& operator=( const map& original ){
				clear();
				_alloc = original._alloc;
				insert( original.begin(), original.end() );
				return *this;
			}

			//-------iterators-------//
			iterator begin( void ){
				return iterator( _begin );
			}

			const_iterator begin( void ) const{
				return const_iterator( _begin );
			}

			iterator end( void ){
				return iterator( &this->_end );
			}

			const_iterator end( void ) const{
				return const_iterator( &this->_end );
			}

			iterator rbegin( void ){
				return reverse_iterator( _end._parent );
			}

			const_iterator rbegin( void ) const{
				return const_reverse_iterator( _end._parent );
			}

			iterator rend( void ){
				return reverse_iterator( &this->_end );
			}

			const_iterator rend( void ) const{
				return const_reverse_iterator( &this->_end );
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
				node_pointer find = _root->find_node( k );
				if ( find )
					return find->_input.second;
				return (*(this->insert( ft::make_pair( k, mapped_type() ) ).first)).second;
			}

			//-------Modifiers-------//
			pair< iterator, bool > insert( const_reference val ){
				if ( _root != &_end && _root->find_node( val.first ) )
					return ( ft::make_pair( iterator( _root->find_node( val.first ) ), false ) );
				node_pointer tmp = _alloc.allocate( 1 );
				_alloc.construct( tmp, val );
				tmp->_end = &this->_end;
                _size++;
				if ( _root != &_end ) {
                    _root = _root->insert_node( tmp );
                    if ( val.first < _begin->_input.first )
						this->_begin = tmp;
                    if ( val.first > _end._parent->_input.first )
                        this->_end._parent = tmp;
				} else {
                    _root = tmp;
                    _begin = tmp;
                    this->_end._parent = tmp;
				}
				return ( ft::make_pair( iterator( _root->find_node( val.first ) ), true ) );
			}

			iterator insert ( iterator position, const_reference val ){
                if ( _root != &_end && _root->find_node( val.first ) )
                    return ( iterator( _root->find_node( val.first ) ) );
			    node_pointer tmp = _alloc.allocate( 1 );
			    _alloc.construct( tmp, val );
                tmp->_end = &this->_end;
                _size++;
                if ( (*position)->_input.first < val.first )
                    (*position)->insert_right( tmp );
                else
                    (*position)->insert_left( tmp );
                _root = _root->balance();
                return iterator( tmp );
			}

			template< class InputIterator >
			void insert( InputIterator first, InputIterator last,
                         typename ft::enable_if< !is_same< InputIterator, value_type >::value, int >::type = 0 ){
                InputIterator it = first;
                while ( it != last ){
                    insert( (*it)->_input );
                    it++;
			    }
			}

			void  erase( iterator position ){
				erase( position->first );
			}

			size_type erase( const key_type& key ){
                if ( _root == &_end || !key )
                	return 0;
				node_pointer node = _root->find_node( key );
                if ( !node )
                	return _size;
				node_pointer tmp_left = node->_left ? node->_left->balance() : NULL ;
				node_pointer tmp_right = node->_right ? node->_right->balance() : NULL;
				if ( node != _root ){
					if ( node->_parent->_left == node ) {
						node->_parent->_left = NULL;
						node->_parent->set_height();
					} else if ( node->_parent->_right == node ) {
						node->_parent->_right = NULL;
						node->_parent->set_height();
					}
					if ( node == _end._parent )
						_end._parent = _root->find_node( (*(--iterator( node ))).first );
					if ( node == _begin )
						_begin = _root->find_node( (*(++iterator( node ))).first );
					_root = _root->insert_node( tmp_left )->insert_node( tmp_right );
				} else if ( tmp_right || tmp_left ) {
					size_type left_height = tmp_left ? tmp_left->_height : 0 ;
					size_type right_height = tmp_right ? tmp_right->_height : 0 ;
					if ( tmp_right && ( !tmp_left || left_height > right_height ) ){
						tmp_right->_parent = NULL;
						_root = tmp_right;
						_root = _root->insert_node( tmp_left );
					} else {
						tmp_left->_parent = NULL;
						_root = tmp_left;
						_root = _root->insert_node( tmp_right );
					}
				} else {
					_begin = &_end;
				}
				_alloc.destroy( node );
				_alloc.deallocate( node, 1 );
			    return --_size;
			}

			void  erase( iterator first, iterator last ){
                iterator tmp;
			    while ( first != last ){
                    tmp = first++;
                    erase( tmp );
                }
			}

			void clear( void ){
				erase( begin(), end() );
			}

			void print( void ){
				_root->print();
			}

			void print_node( key_type key ){
				_root->find_node( key )->print_nodes();
			}

			//-------Observers-------//
			key_compare key_comp( void ) const{
				return _compare;
			}

			value_compare value_comp( void ) const{
				return value_compare( _compare );
			}

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
