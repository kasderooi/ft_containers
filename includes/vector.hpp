#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

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
		
			vector( void ) : _size( 0 ), _capacity(0), _alloc(), _vector( NULL ) { return; };
			vector( unsigned int n ) : _size( n ), _capacity(n), _alloc(), _vector( _alloc.allocate( n ) ) { return; };
			//range constructor
			vector( vector const& original ) : _size( 0 ), _capacity(0), _alloc(), _vector( NULL ) { *this = original; return ; };
			~vector( void ) { _alloc.deallocate( _vector, _capacity ); return; };

			vector<T, Alloc>& operator=( const vector& original ) {
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
			// max_size()		Return maximum size (public member function )
			// resize()			Change size (public member function )
			size_type capacity( void ) const { return _capacity; };
			// empty()			Test whether vector is empty (public member function )
			// reserve()		Request a change in capacity (public member function )
			// shrink_to_fit()	Shrink to fit (public member function )

			//-------Element access-------//
			reference operator[]( size_type n ) { return _vector[n]; };
			const_reference operator[]( size_type n ) const { return _vector[n]; };
			// at()
			// front()
			// back()
			// data()

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
//vector<bool>

#endif //FT_CONTAINERS_FT_VECTOR_HPP
