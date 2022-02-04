#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <algorithm>
#include <iostream>
#define LEFT 0
#define RIGHT 1

namespace ft{

	template< class Pair = std::pair< class T1, class T2 > >
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

			void set_height( void ){
				size_type height_left = 0;
				size_type height_right = 0;
				if ( _left != NULL )
					height_left = _left->_height;
				if ( _right != NULL )
					height_right = _right->_height;
				_height = 1 + std::max( height_left, height_right );
			}

			//-------Modifiers-------//
			pointer insert( pointer node ){
				size_type difference;

				if ( node->_input.first > this->_input.first ){
					if ( _right != NULL )
						_right = _right->insert( node );
					else{
						_right = node;
						node->_parent = this;
					}
				} else if ( node->_input.first < this->_input.first ){
					if ( _left != NULL )
						_left = _left->insert( node );
					else{
						_left = node;
						node->_parent = this;
					}
				} else
					return this;
				this->set_height();
				difference = this->difference();
				if ( difference > 1 && _input.first < _left->_input.first )
					return this->right_rotation();
				if ( difference < -1 && _input.first > _right->_input.first )
					return this->left_rotation();
				if ( difference > 1 && _input.first > _left->_input.first ){
					_left = _left->left_rotation();
					return this->right_rotation();
				}
				if ( difference < -1 && _input.first < _right->_input.first ){
					_right = _right->right_rotation();
					return this->right_rotation();
				}
				return this;
			}

			void print( void ) {
				std::cout << "KEY " << _input.first << " VALUE " << _input.second << std::endl;
				if ( _left ){
					std::cout << "LEFT ";
					_left->print();
				} else {
					std::cout << "LEFT EMPTY" << std::endl;
				}
				if ( _right ){
					std::cout << "RIGHT ";
					_right->print();
				} else {
					std::cout << "RIGHT EMPTY" << std::endl;
				}
			}

	};
}


#endif //AVLTREE_HPP
