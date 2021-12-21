#ifndef FT_vector_HPP
#define FT_vector_HPP

#include <exception>
#include "RandomAccessIterator.hpp"
#include "ReverseIterator.hpp"

namespace ft {

	template<class T, class Alloc = std::allocator<T> >
	class vector {

		public:

			typedef		T					value_type;
			typedef		Alloc				allocator_type;
			typedef		size_t				size_type;
			typedef		value_type*			pointer;
			typedef		value_type&			reference;
			typedef 	const value_type*	const_pointer;
			typedef 	const value_type&	const_reference;
			typedef	typename ft::RandomAccessIterator< T, T*, T& > iterator;
			typedef	typename ft::RandomAccessIterator< T, const T*, const T& > const_iterator;
			typedef	typename ft::ReverseIterator< T, T*, T& > reverse_iterator;
			typedef	typename ft::ReverseIterator< T, const T*, const T& > const_reverse_iterator;
			//difference type

		private:

			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			pointer			_vector;
		
		public:
		
			vector( void ) : _size( 0 ), _capacity( 0 ), _alloc(), _vector( NULL ) { return; }
			vector( unsigned int n ) : _size( n ), _capacity( n ), _alloc(), _vector( _alloc.allocate( n ) ) { return; }
			template <class InputIterator>
			vector ( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() ) {
				_size = last - first;
				_capacity = _size;
				_alloc = alloc;
				_vector = _alloc.allocate( _size );
				for ( size_type i = 0; i < _size; i++ ) {
					_vector[i] = *first;
					first++;
				}
				return ;
			}
			vector( vector const& original ) : _size( 0 ), _capacity( 0 ), _alloc(), _vector( NULL ) { *this = original; return ; }
			~vector( void ) { _alloc.deallocate( _vector, _capacity ); return; }

			vector<T, Alloc>& operator=(const vector& original ) {
				_alloc.deallocate( _vector, _capacity );
				_size = original._size;
				_capacity = original._capacity;
				_vector = _alloc.allocate( _capacity );
				for ( unsigned int i = 0; i < _size; i++ ) {
					_vector[i] = original._vector[i];
				}
				return *this;
			}

			//-------Iterators-------//
			iterator begin( void ) { iterator ret( _vector ); return ret; }
			const_iterator begin( void ) const { const_iterator ret( _vector ); return ret; }
			iterator end( void ) { iterator ret( &_vector[_size] ); return ret; }
			const_iterator end( void ) const { const_iterator ret( &_vector[_size] ); return ret; }
			reverse_iterator rbegin( void ) { reverse_iterator ret( &_vector[_size - 1] ); return ret; }
			const_reverse_iterator rbegin( void ) const { const_reverse_iterator ret( &_vector[_size - 1] ); return ret; }
			reverse_iterator rend( void ) { reverse_iterator ret( _vector ); return ++ret; }
			const_reverse_iterator rend( void ) const { const_reverse_iterator ret( _vector ); return ++ret; }

			//-------Capacity-------//
			size_type size( void ) const { return _size; }
			size_type max_size( void ) const { return _alloc.max_size(); }
			void resize( size_type n, value_type val = value_type() ) {
				if ( n > _size ) {
					reserve( n );
					for ( size_type i = _size; i < n; i++ )
						_alloc.construct( &_vector[i], val );
				} else if ( n < _size ) {
					for ( size_type i = n; i < _size; i++ )
						_alloc.destroy( &_vector[i] );
				}
				_size = n;
			}
			size_type capacity( void ) const { return _capacity; }
			bool empty( void ) const { if ( _size == 0 ) return true; else return false; }
			void reserve( size_type n ) {
				if ( n <= _capacity )
					return ;
				if ( n > _alloc.max_size() )
					throw std::length_error( "allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size" );
				pointer dest = _alloc.allocate( n );
				for ( size_type i = 0; i < _size; i++ ) {
					_alloc.construct( &dest[i], _vector[i] );
					_alloc.destroy( &_vector[i] );
				}
				_alloc.deallocate( _vector, _capacity );
				_vector = dest;
				_capacity = n;
			}

			//-------Element access-------//
			reference operator[]( size_type n ) { return _vector[n]; }
			const_reference operator[]( size_type n ) const { return _vector[n]; }
			reference at( size_type n ) { if ( n >= _size ) throw std::out_of_range("out of range"); return _vector[n]; }
			const_reference at( size_type n ) const { if ( n >= _size ) throw std::out_of_range("out of range"); return _vector[n]; }
			reference front( void ) { return _vector[0]; }
			const_reference front( void ) const { return _vector[0]; }
			reference back( void ) { return _vector[_size - 1]; }
			const_reference back( void ) const { return _vector[_size - 1]; }
			pointer data( void ) { return _vector; }
			const_pointer data( void ) const { return _vector; }

			//-------Modifiers-------//
			template < class InputIterator >
			void assign ( InputIterator first, InputIterator last, typename enable_if<is_input_iterator<InputIterator>::value>::type = 0 ) { //typename enable_if<dynamic_cast<InputIterator>(first) != nullptr, int>::type* = 0 )
				resize( last - first );
				for ( size_type i = 0; first < last; i++ ) {
					_vector[i] = *first;
					first++;
				}
			}
			void assign ( size_type n, const value_type& val ) {
					resize( n );
					for ( size_type i = 0; i < n; i++ ) {
						_vector[i] = val;
					}
				}
			void push_back( const value_type& val ) {
					if ( _size == _capacity )
						reserve( 2 * _size );
					_alloc.construct( &_vector[_size], val );
					_size++;
			}
			void pop_back( void ) { _size--; _alloc.destroy( &_vector[_size] ); }
			// insert()
			// erase()
			// swap()
			// clear()

			//-------Allocator-------//
			allocator_type get_allocator( void ) const { return _alloc; }

	};
}

//-------Non-member function overloads-------//
//----relational operators----//
//swap
//vector<bool>

#endif //FT_CONTAINERS_FT_vector_HPP
