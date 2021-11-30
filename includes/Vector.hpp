#ifndef FT_vector_HPP
#define FT_vector_HPP

#include <exception>

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
			//iterator
			//const iterator
			//reverse iterator
			//const reverse iterator
			//difference type

		private:

			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			pointer			_vector;
		
		public:
		
			Vector( void ) : _size( 0 ), _capacity( 0 ), _alloc(), _vector( NULL ) { return; };
			Vector( unsigned int n ) : _size( n ), _capacity( n ), _alloc(), _vector( _alloc.allocate( n ) ) { return; };
			//range constructor
			Vector( Vector const& original ) : _size( 0 ), _capacity( 0 ), _alloc(), _vector( NULL ) { *this = original; return ; };
			~Vector( void ) { _alloc.deallocate( _vector, _capacity ); return; };

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
			// begin() 			Return iterator to beginning (public member function )
			// end() 			Return iterator to end (public member function )
			// rbegin() 		Return reverse iterator to reverse beginning (public member function )
			// rend() 			Return reverse iterator to reverse end (public member function )
			// cbegin() 		Return const_iterator to beginning (public member function )
			// cend() 			Return const_iterator to end (public member function )
			// crbegin() 		Return const_reverse_iterator to reverse beginning (public member function )
			// crend() 			Return const_reverse_iterator to reverse end (public member function )

			//-------Capacity-------//
			size_type size( void ) const { return _size; };
			size_type max_size( void ) const { return _alloc.max_size(); };
//			void resize( size_type n, value_type val ) {
//				ft::Vector<val> element(n);
//				ft::iterator it_src = this->begin();
//				ft::iterator it_dst = element.begin();
//				for ( size_type i = 0; i < n; i++ ) {
//					*it_dst = *it_src;
//					it_dst++;
//					it_src++;
//				}
//				_alloc.destroy( this );
//				_alloc.deallocate( this );
//				*this = element;
//			};
			size_type capacity( void ) const { return _capacity; };
			bool empty( void ) const { if ( _size == 0 ) return true; else return false; };
			// reserve()		Request a change in capacity (public member function )
			// shrink_to_fit()	Shrink to fit (public member function )

			//-------Element access-------//
			reference operator[]( size_type n ) { return _vector[n]; };
			const_reference operator[]( size_type n ) const { return _vector[n]; };
			reference at( size_type n ) { if ( n >= _size ) throw std::out_of_range("out of range"); return _vector[n]; };
			const_reference at( size_type n ) const { if ( n >= _size ) throw std::out_of_range("out of range"); return _vector[n]; };
			reference front( void ) { return _vector[0]; };
			const_reference front( void ) const { return _vector[0]; };
			reference back( void ) { return _vector[_size - 1]; };
			const_reference back( void ) const { return _vector[_size - 1]; };
			pointer data( void ) noexcept { return _vector; };
			const_pointer data( void ) const noexcept { return _vector; };

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
			allocator_type get_allocator( void ) const { return _alloc; };

	};
}

//-------Non-member function overloads-------//
//----relational operators----//
//swap
//Vector<bool>

#endif //FT_CONTAINERS_FT_vector_HPP
