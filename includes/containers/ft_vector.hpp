#ifndef FT_vector_HPP
#define FT_vector_HPP

#include <exception>
#include <memory>
#include "../iterators/RandomAccessIterator.hpp"
#include "../iterators/ReverseIterator.hpp"
#include "../utils/utils.hpp"

namespace ft{

	template< class T, class Alloc = std::allocator< T > >
	class vector{

		public:

			typedef T value_type;
			typedef Alloc allocator_type;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename ft::RandomAccessIterator< T, pointer, reference > iterator;
			typedef typename ft::RandomAccessIterator< T, const_pointer, const_reference > const_iterator;
			typedef typename ft::ReverseIterator< iterator > reverse_iterator;
			typedef typename ft::ReverseIterator< const_iterator > const_reverse_iterator;

		private:

			size_type _size;
			size_type _capacity;
			allocator_type _alloc;
			pointer _vector;

		public:

			//-------(De-)Constructors-------//
			explicit vector( const allocator_type& alloc = allocator_type()) :
					_size( 0 ), _capacity( 0 ), _alloc( alloc ), _vector( NULL ){ return; }

			explicit vector( size_type n, const value_type& val = value_type(),
							 const allocator_type& alloc = allocator_type()) :
					_size( n ), _capacity( n ), _alloc( alloc ), _vector( _alloc.allocate( _capacity )){
				for ( size_type i = 0; i < _size; i++ )
					_alloc.construct( &_vector[i], val );
				return;
			}

			template< class InputIterator >
			vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if< !is_integral< InputIterator >::value, int >::type = 0 ) :
					_size( distance( first, last )), _capacity( _size ), _alloc( alloc ),
					_vector( _alloc.allocate( _capacity )){
				for ( size_type i = 0; i < _size; i++ )
					_alloc.construct( &_vector[i], *first++ );
				return;
			}

			vector( vector const& original ) : _size( 0 ), _capacity( 0 ), _alloc(), _vector( NULL ){
				*this = original;
				return;
			}

			~vector( void ){
				clear();
				_alloc.deallocate( _vector, _capacity );
				return;
			}

			//-------Assignment Operator-------//
			vector< T, Alloc >& operator=( const vector& original ){
				for ( size_type i = 0; i < _size; i++ )
					_alloc.destroy( &_vector[i] );
				_alloc.deallocate( _vector, _capacity );
				_alloc = original._alloc;
				_size = original._size;
				_capacity = original._capacity;
				_vector = _alloc.allocate( _capacity );
				for ( unsigned int i = 0; i < _size; i++ )
					_alloc.construct( &_vector[i], original._vector[i] );
				return *this;
			}

			//-------Iterators-------//
			iterator begin( void ){
				return iterator( _vector );
			}

			const_iterator begin( void ) const{
				return const_iterator( _vector );
			}

			iterator end( void ){
				return iterator( &_vector[_size] );
			}

			const_iterator end( void ) const{
				return const_iterator( &_vector[_size] );
			}

			reverse_iterator rbegin( void ){
				return reverse_iterator( &_vector[_size - 1] );
			}

			const_reverse_iterator rbegin( void ) const{
				return const_reverse_iterator( &_vector[_size - 1] );
			}

			reverse_iterator rend( void ){
				reverse_iterator ret( _vector );
				return ++ret;
			}

			const_reverse_iterator rend( void ) const{
				const_reverse_iterator ret( _vector );
				return ++ret;
			}

			//-------Capacity-------//
			size_type size( void ) const{ return _size; }

			size_type max_size( void ) const{ return _alloc.max_size(); }

			void resize( size_type n, value_type val = value_type()){
				if ( n > _size ){
					reserve( n );
					for ( size_type i = _size; i < n; i++ )
						_alloc.construct( &_vector[i], val );
				}else if ( n < _size ){
					for ( size_type i = n; i < _size; i++ )
						_alloc.destroy( &_vector[i] );
				}
				_size = n;
			}

			size_type capacity( void ) const{ return _capacity; }

			bool empty( void ) const{ if ( _size == 0 ) return true;else return false; }

			void reserve( size_type n ){
				if ( n <= _capacity )
					return;
				if ( n > _alloc.max_size())
					throw std::length_error( "allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size" );
				pointer dest = _alloc.allocate( n );
				for ( size_type i = 0; i < _size; i++ ){
					_alloc.construct( &dest[i], _vector[i] );
					_alloc.destroy( &_vector[i] );
				}
				_alloc.deallocate( _vector, _capacity );
				_vector = dest;
				_capacity = n;
			}

			//-------Element access-------//
			reference operator[]( size_type n ){ return _vector[n]; }

			const_reference operator[]( size_type n ) const{ return _vector[n]; }

			reference at( size_type n ){
				if ( n >= _size ) throw std::out_of_range( "out of range" );
				return _vector[n];
			}

			const_reference at( size_type n ) const{
				if ( n >= _size ) throw std::out_of_range( "out of range" );
				return _vector[n];
			}

			reference front( void ){ return _vector[0]; }

			const_reference front( void ) const{ return _vector[0]; }

			reference back( void ){ return _vector[_size - 1]; }

			const_reference back( void ) const{ return _vector[_size - 1]; }

			//-------Modifiers-------//
			template< class InputIterator >
			void assign( InputIterator first, InputIterator last,
						 typename ft::enable_if< !is_integral< InputIterator >::value, int >::type = 0 ){
				resize( distance( first, last ));
				for ( size_type i = 0; first < last; i++ ){
					_vector[i] = *first;
					first++;
				}
			}

			void assign( size_type n, const value_type& val ){
				resize( n );
				for ( size_type i = 0; i < n; i++ )
					_vector[i] = val;
			}

			void push_back( const value_type& val ){
				if ( _size == _capacity ){
					if ( _size == 0 )
						reserve( 1 );
					else
						reserve( 2 * _size );
				}
				_alloc.construct( &_vector[_size], val );
				_size++;
			}

			void pop_back( void ){
				_size--;
				_alloc.destroy( &_vector[_size] );
			}

			iterator insert( iterator position, const value_type& val ){
				difference_type index( 0 ), diff = distance( position, end());
				push_back( val );
				iterator it = end() - 1;
				while ( index++ < diff )
					*it-- = *( it - 1 );
				*it = val;
				return it;
			}

			template< class InputIterator >
			void insert( iterator position, InputIterator first, InputIterator last,
						 typename ft::enable_if< !is_integral< InputIterator >::value, int >::type = 0 ){
				difference_type index( 0 ), diff = distance( position, end());
				size_type n = distance( first, last );
				if ( _capacity > 0 )
					reserve( _size + n > _capacity ? 2 * _capacity : _size );
				else
					reserve( n );
				resize( _size + n );
				iterator it = end() - 1;
				while ( index++ < diff )
					*it-- = *( it - n );
				while ( n-- )
					*it-- = *--last;
			}

			void insert( iterator position, size_type n, const value_type& val ){
				difference_type index( 0 ), diff = distance( position, end());
				if ( _capacity > 0 )
					reserve( _size + n > _capacity ? 2 * _capacity : _size );
				else
					reserve( n );
				resize( _size + n );
				iterator it = end() - 1;
				while ( index++ < diff )
					*it-- = *( it - n );
				while ( n-- )
					*it-- = val;
			}

			iterator erase( iterator position ){
				size_type index = position - begin();
				do{
					_vector[index] = _vector[index + 1];
				}while ( ++index < _size - 1 );
				_alloc.destroy( &_vector[index] );
				_size--;
				return position;
			}

			iterator erase( iterator first, iterator last ){
				size_type index = first - begin();
				size_type n = last - first;
				do{
					_vector[index] = _vector[index + n];
				}while ( ++index < _size - n );
				do{
					_alloc.destroy( &_vector[index] );
				}while ( ++index < _size );
				_size -= n;
				return last;
			}

			void swap( vector& x ){
				allocator_type bufAlloc = x._alloc;
				pointer bufVec = x._vector;
				size_type bufCap = x._capacity;
				size_type bufSize = x._size;
				x._alloc = this->_alloc;
				x._vector = this->_vector;
				x._capacity = this->_capacity;
				x._size = this->_size;
				this->_alloc = bufAlloc;
				this->_vector = bufVec;
				this->_capacity = bufCap;
				this->_size = bufSize;
			}

			void clear( void ){
				if( _size )
					_alloc.destroy( _vector );
				_size = 0;
			}

			//-------Allocator-------//
			allocator_type get_allocator( void ) const{ return _alloc; }

			//-------Relational operators-------//
			template< class T1, class Alloc1 >
			friend bool operator==( const vector< T1, Alloc1 >& lhs, const vector< T1, Alloc1 >& rhs );

			template< class T1, class Alloc1 >
			friend bool operator<( const vector< T1, Alloc1 >& lhs, const vector< T1, Alloc1 >& rhs );

	};

	//-------Non-member function overloads-------//
	template< class T, class Alloc >
	bool operator==( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs ){
		if ( lhs.size() != rhs.size())
			return false;
		for ( size_t i = 0; i < lhs.size(); i++ )
			if ( lhs[i] != rhs[i] )
				return false;
		return true;
	}

	template< class T, class Alloc >
	bool operator!=( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs ){
		if ( lhs == rhs ) return false;
		return true;
	}

	template< class T, class Alloc >
	bool operator<( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs ){
		for ( size_t i = 0; i < lhs.size() && i < rhs.size(); i++ ){
			if ( lhs[i] < rhs[i] )
				return true;
			if ( lhs[i] > rhs[i] )
				return false;
		}
		if ( lhs.size() < rhs.size())
			return true;
		return false;
	}

	template< class T, class Alloc >
	bool operator<=( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs ){ return !( rhs < lhs ); }

	template< class T, class Alloc >
	bool operator>( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs ){ return ( rhs < lhs ); }

	template< class T, class Alloc >
	bool operator>=( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs ){ return !( lhs < rhs ); }

	template< class T, class Alloc >
	void swap( vector< T, Alloc >& x, vector< T, Alloc >& y ){ x.swap( y ); }
}

#endif //FT_CONTAINERS_FT_vector_HPP
