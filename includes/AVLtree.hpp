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
			AVLtree( void ) : _input( 0 ), _height( 0 ), _parent( NULL ), _left( NULL ), _right( NULL ){ return; }

			AVLtree( value_type input ) : _input( input ), _height( 0 ), _parent( NULL ), _left( NULL ),
										  _right( NULL ){ return; }

			~AVLtree( void ){ return; }

			AVLtree< Pair > &operator=( const AVLtree &original ){
				_input = original._input;
				_height = original._height;
				_parent = original._parent;
				_left = original._left;
				_right = original._right;
			}

			//-------Rotators-------//
			pointer left_rotation( void ){
				pointer tmp = _left;

				_left = tmp->_right;
				tmp->_right = this;

				this->set_height();
				tmp->set_height();
				return tmp;
			}

			pointer right_rotation( void ){
				pointer tmp = _right;

				_right = tmp->_left;
				tmp->_left = this;

				this->set_height();
				tmp->set_height();
				return tmp;
			}

			//-------Capacity-------//
			int difference( void ){
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
				if ( _left )
					height_left = _left->_height;
				if ( _right )
					height_right = _right->_height;
				_height = 1 + std::max( height_left, height_right );
			}

			//-------Modifiers-------//
			pointer balance( void ){
				int difference = this->difference();
				if ( difference > 1 ){
					if ( _left->difference() > 0 )
						return this->left_rotation();
					else{
						_left = _left->right_rotation();
						return this->left_rotation();
					}
				}else if ( difference < -1 ){
					if ( _right->difference() > 0 ){
						_right = _right->left_rotation();
						return this->right_rotation();
					}else
						return this->right_rotation();
				}
				return this;
			}

			pointer insert( pointer node ){
				if ( node->_input.first > this->_input.first ){
					if ( _right != NULL )
						_right = _right->insert( node );
					else{
						_right = node;
						node->_parent = this;
					}
				}else if ( node->_input.first < this->_input.first ){
					if ( _left != NULL )
						_left = _left->insert( node );
					else{
						_left = node;
						node->_parent = this;
					}
				}else
					return this;
				this->set_height();
				return this->balance();
			}

			void print( void ){
				std::cout << _input.first << " VALUE " << _input.second << std::endl;

				if ( _left ){
					std::cout << "\tLEFT ";
					_left->print();
				}else{
					std::cout << "LEFT EMPTY" << std::endl;
				}
				if ( _right ){
					std::cout << "\tRIGHT ";
					_right->print();
				}else{
					std::cout << "RIGHT EMPTY" << std::endl;
				}
			}

	};

}


#endif //AVLTREE_HPP
