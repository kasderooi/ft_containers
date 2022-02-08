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

		public:

			//-------(De-)Constructors-------//
			explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
					_alloc( alloc ), _size( 0 ), _root( NULL ), _begin( NULL ),
					_end(){ _end._end = &_end; return; }

			template< class InputIterator >
			map( InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) : _alloc( alloc ), _size( 0 ), _root( NULL ), _begin( NULL ),
					_end(){
				InputIterator tmp = first;
				_end._end = &_end;
				while ( tmp != last ){
					this->insert( *tmp );
					tmp++;
				}
			}

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
				return iterator( &this->_end );
			}

			const_iterator end( void ) const{
				return const_iterator( &this->_end );
			}

			iterator rbegin( void ){
				return reverse_iterator( _begin );
			}

			const_iterator rbegin( void ) const{
				return const_reverse_iterator( _begin );
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
				return _root->find_node( k )->_input.second;
			}

			//-------Modifiers-------//
			pair< iterator, bool > insert( const_reference val ){
				if ( _root && _root->find_node( val.first ) )
					return ( ft::make_pair( iterator( _root->find_node( val.first ) ), false ) );
				node_pointer tmp = _alloc.allocate( 1 );
				_alloc.construct( tmp, val );
				tmp->_end = &this->_end;
                _size++;
				if ( _root ) {
                    _root = _root->insert( tmp );
                    if ( val.first < _begin->_input.first )
                        _begin = tmp;
                    if ( val.first > _end._parent->_input.first )
                        this->_end._parent = tmp;
				} else {
                    _root = tmp;
                    _begin = _root;
                    this->_end._parent = tmp;
				}
				return ( ft::make_pair( iterator( _root->find_node( val.first ) ), true ) );
			}

			iterator insert ( iterator position, const_reference val ){
                if ( _root && _root->find_node( val.first ) )
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
                pointer tmp_left = position.get_ptr()->_left;
                pointer tmp_right = position.get_ptr()->_right;
                if ( *position != _root ){                     //            what if erase root
                    if ( position.get_ptr()->_parent->_left == position.get_ptr() ) {
                        position.get_ptr()->_parent->_left = NULL;
                        position.get_ptr()->_parent->set_height();
                    } else if ( (*position)->_parent->_right == position.get_ptr() ) {
                        position.get_ptr()->_parent->_right = NULL;
                        position.get_ptr()->_parent->set_height();
                    }
                    _root = _root->insert( tmp_left )->insert( tmp_right );
                } else {
                    if ( tmp_left->_height > tmp_right->_height ){
                        _root = tmp_right;
                        _root = _root->insert( tmp_left );
                    } else {
                        _root = tmp_left;
                        _root = _root->insert( tmp_right );
                    }
                }
                _alloc.destroy( position.get_ptr() );
                _size--;
			}

			size_type erase( const key_type& key ){
                node_pointer node = _root->find_node( key );
			    if ( node )
                    erase( iterator( node ) );
			    return _size;
			}

			void  erase( iterator first, iterator last ){
                iterator tmp;
			    while ( first != last ){
                    tmp = first++;
			        erase( tmp );
                }
			}

			void clear() noexcept;

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
