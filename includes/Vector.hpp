#ifndef FT_vector_HPP
#define FT_vector_HPP

#include <exception>
#include "RandomAccesIterator.hpp"
#include "ReverseIterator.hpp"

namespace ft {

	template<class T, class Alloc = std::allocator<T> >
	class Vector {

		public:

			typedef		T					value_type;
			typedef		Alloc				allocator_type;
			typedef		size_t				size_type;
			typedef		value_type*			pointer;
			typedef		value_type&			reference;
			typedef 	const value_type*	const_pointer;
			typedef 	const value_type&	const_reference;
			typedef	typename ft::RandomAccesIterator< T, T*, T& > iterator;
			typedef	typename ft::RandomAccesIterator< T, const T*, const T& > const_iterator;
			typedef	typename ft::ReverseIterator< T, T*, T& > reverse_iterator;
			typedef	typename ft::ReverseIterator< T, const T*, const T& > const_reverse_iterator;
			//difference type

		private:

			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			pointer			_vector;
		
		public:
		
			Vector( void ) : _size( 0 ), _capacity( 0 ), _alloc(), _vector( NULL ) { return; }
			Vector( unsigned int n ) : _size( n ), _capacity( n ), _alloc(), _vector( _alloc.allocate( n ) ) { return; }
			//range constructor
			Vector( Vector const& original ) : _size( 0 ), _capacity( 0 ), _alloc(), _vector( NULL ) { *this = original; return ; }
			~Vector( void ) { _alloc.deallocate( _vector, _capacity ); return; }

			Vector<T, Alloc>& operator=( const Vector& original ) {
				_alloc.deallocate( _vector, _capacity );
				this->_size = original._size;
				this->_capacity = original._capacity;
				this->_vector = _alloc.allocate( this->_capacity );
				for ( unsigned int i = 0; i < this->_size; i++ ){
					this->_vector[i] = original._vector[i]; 
				}
				return (*this);
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
			size_type size( void ) const { return _size; };
			size_type max_size( void ) const { return _alloc.max_size(); };
			void resize( size_type n ) {
				Vector element(n);
				iterator it_src = this->begin();
				iterator it_dst = element.begin();
				for ( size_type i = 0; i < n; i++ ) {
					*it_dst = *it_src;
					it_dst++;
					it_src++;
				}
				_alloc.destroy( this );
				_alloc.deallocate( this );
				*this = element;
			};
			size_type capacity( void ) const { return _capacity; }
			bool empty( void ) const { if ( _size == 0 ) return true; else return false; }
			// reserve()		Request a change in capacity (public member function )
			// shrink_to_fit()	Shrink to fit (public member function )

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
			// assign()
			// push_back()
			// pop_back()
			// insert()
			// erase()
			// swap()
			// clear()
			// emplace()
			// emplace_back()

			//-------Allocator-------//
			allocator_type get_allocator( void ) const { return _alloc; }

	};
}

//-------Non-member function overloads-------//
//----relational operators----//
//swap
//Vector<bool>

#endif //FT_CONTAINERS_FT_vector_HPP
