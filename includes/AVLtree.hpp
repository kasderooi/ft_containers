#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <algorithm>
#define LEFT 0
#define RIGHT 1

namespace ft{

	template< class Pair >
	class AVLtree{

		public:

			typedef Pair value_type;
			typedef size_t size_type;
			typedef std::allocator< Pair > allocator_type;
			typedef AVLtree *pointer;
			typedef AVLtree &reference;
			typedef const AVLtree *const_pointer;
			typedef const AVLtree &const_reference;

		private:

			value_type _input;
			size_type _height;
			pointer _parent;
			pointer _left;
			pointer _right;

		public:

			//-------(De-)Constructors-------//
			AVLtree( void ) : _input( 0 ), _height( 1 ), _parent(NULL), _left( NULL ), _right( NULL ){ return; }

			AVLtree( value_type input ) : _input( input ), _height( 1 ), _parent(NULL), _left( NULL ), _right( NULL ){ return; }

			~AVLtree( void ){ return; }

			AVLtree< Pair >& operator=( const AVLtree &original ){
				_input = original._input;
				_height = original._height;
				_parent = original._parent;
				_left = original._left;
				_right = original._right;
			}

			//-------Rotators-------//
			pointer left_rotation( void ){
				_right->_parent = _parent;
				_parent = _right;
				_right = _parent->_left;
				_parent->_left = this;
				_height = std::max( _left->_height, _right->_height );
				_parent->_height = std::max( _left->_height, _right->_height );
				return _parent;
			}

			pointer right_rotation( void ){
				_left->_parent = _parent;
				_parent = _left;
				_left = _parent->_right;
				_parent->_right = this;
				_height = std::max( _left->_height, _right->_height );
				_parent->_height = std::max( _left->_height, _right->_height );
				return _parent;
			}

			//-------Capacity-------//
			size_type difference( void ){
				if ( !_left && !_right )
					return 0;
				if ( !_left )
					return _right->_height;
				if ( !_right )
					return _left->_height;
				return _left->_height - _right->_height;
			}

			//-------Modifiers-------//
			void insert( pointer node ){
				size_type difference;

				if ( node->input.first > this->_input->_first ){
					if ( _right )
						_right->insert( node );
					else{
						_right = node;
						node->_parent = this;
					}
				} else if ( node->_input->_first < this->_input->_first ){
					if ( _left )
						_left->insert( node );
					else{
						_left = node;
						node->_parent = this;
					}
				} else
					return;
				_height = 1 + std::max( _left->_height, _right->_height );
				difference = this->difference();
				if ( difference > 1 && )
			}

	};
}


#endif //AVLTREE_HPP
