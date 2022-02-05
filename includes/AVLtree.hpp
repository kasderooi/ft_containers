#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include "ft_pair.hpp"

#define LEFT 0
#define RIGHT 1

namespace ft{

	struct AVLprint{
		int _layers;
		std::vector<int> *array;

		AVLprint( int layers ){
			_layers = layers;
			array = new std::vector<int>[layers];
		}

		void add( int layer, int input ){
			array[layer - 1].push_back(input);
		}

		void print( void ){
			while ( _layers > 0 ){
				_layers--;
				std::cout << " ";
				for ( int i = 0; i < _layers; i++ )
					std::cout << "\t";
				for ( std::vector<int>::iterator it = array[_layers].begin(); it < array[_layers].end(); it++ ){
					if ( *it )
						std::cout << *it;
					else
						std::cout << "_";
					for ( int i = 0; i <= _layers; i++ )
						std::cout << "  ";
				}
				std::cout << std::endl;
			}
		}
	};

	template< class Pair = ft::pair< class T1, class T2 > >
	class AVLtree{

		public:

			typedef Pair value_type;
			typedef T1 first_type;
			typedef T2 second_type;
			typedef AVLtree *pointer;
			typedef size_t size_type;

		private:

			value_type _input;
			size_type _height;
			pointer _parent;
			pointer _left;
			pointer _right;

		public:

			//-------(De-)Constructors-------//
			AVLtree( void ) : _input( 0 ), _height( 1 ), _parent( NULL ), _left( NULL ), _right( NULL ){ return; }

			AVLtree( value_type input ) : _input( input ), _height( 1 ), _parent( NULL ), _left( NULL ),
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
				size_type left = 0;
				size_type right = 0;
				if ( _left )
					left = _left->_height;
				if ( _right )
					right = _right->_height;
				return left - right;
			}

			//-------Modifiers-------//
			void set_height( void ){
				size_type height_left = 0;
				size_type height_right = 0;
				if ( _left )
					height_left = _left->_height;
				if ( _right )
					height_right = _right->_height;
				_height = 1 + std::max( height_left, height_right );
			}

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

			int set_print( AVLprint data, int count, int *layer ){
				data.add( *layer, _input.first );
				if ( _left ){
					(*layer)--;
					count = _left->set_print( data, ++count, layer );
				}else{
					if ( *layer > 1){
						data.add( *layer - 1, 0 );
						count++;
					}
				}
				if ( _right ){
					(*layer)--;
					count = _right->set_print( data, ++count, layer );
				}else{
					if ( *layer > 1){
						data.add( *layer - 1, 0 );
						count++;
					}
				}
				(*layer)++;
				return count;
			}

			void print( void ){
				int layer = _height;
				std::cout << _height << std::endl;
				std::cout << _left->_height << std::endl;
				std::cout << _right->_height << std::endl;
				AVLprint data(layer);
				this->set_print( data, 1, &layer );
				data.print();
			}

	};

}


#endif //AVLTREE_HPP
