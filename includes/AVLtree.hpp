#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>
#include <vector>
#include "ft_pair.hpp"
#include "utils.hpp"

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

	template< class Key, class T >
	class AVLtree{

		public:

	        typedef Key first_type;
	        typedef T second_type;
	        typedef pair< first_type, second_type> value_type;
            typedef value_type* value_pointer;
			typedef AVLtree* pointer;
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

			AVLtree< Key, T > &operator=( const AVLtree &original ){
				_input = original._input;
				_height = original._height;
				_parent = original._parent;
				_left = original._left;
				_right = original._right;
			}

			//-------Rotators-------//
			pointer left_rotation( void ){
				pointer tmp = _left;

				tmp->_parent = _parent;
				_parent = tmp;
				_left = tmp->_right;
				if ( _left )
				    _left->_parent = this;
				tmp->_right = this;
				this->set_height();
				tmp->set_height();
				return tmp;
			}

			pointer right_rotation( void ){
				pointer tmp = _right;

				tmp->_parent = _parent;
				_parent = tmp;
				_right = tmp->_left;
				if ( _right )
				    _right->_parent = this;
				tmp->_left = this;
				this->set_height();
				tmp->set_height();
				return tmp;
			}

			//-------Operations-------//
			int difference( void ){
				size_type left = 0;
				size_type right = 0;
				if ( _left )
					left = _left->_height;
				if ( _right )
					right = _right->_height;
				return left - right;
			}

			value_pointer get_pair( void ){
			    return *_input;
			}

			first_type get_key( void ) const{
			    return _input.first;
			}

			pointer find_node( first_type key ){
			    if ( key == _input.first )
			        return this;
			    if ( _left && key < _input.first )
			        return _left->find_node( key );
                if ( _right && key > _input.first )
                    return _right->find_node( key );
                return NULL;
			}

			pointer next( first_type key ){
                if( _left && _left->_input.first > key )
                    return _left->next( key );
                else if ( _right && _input.first == key )
                    return _right->next( key );
                else if ( ( _parent && _parent->_input.first > key && _parent->_input.first < _input.first ) ||
                        ( _right && _right->_input.first <= key ) ||
                        ( _input.first == key && _parent ) ) {// && _parent->_input.first < _input.first
                    if ( !_parent )
                        return NULL;
                    return _parent->next(key);
                }
			    return this;
			}

            pointer previous( first_type key ){
                if ( _right && _right->_input.first < key )
                    return _right->previous( key );
                else if ( _left && _input.first == key )
                    return _left->previous( key );
                else if ( ( _parent && _parent->_input.first < key && _parent->_input.first > _input.first ) || // && _parent->_input.first < _input.first
                        ( _left && _left->_input.first >= key ) ||
                        ( _input.first == key && _parent ) ){
                    if ( !_parent )
                        return NULL;
                    return _parent->previous(key);
                }
                return this;
            }

			//-------Modifiers-------//
			void set_height( void ){
				size_type height_left = 0;
				size_type height_right = 0;
				if ( _left )
					height_left = _left->_height;
				if ( _right )
					height_right = _right->_height;
				_height = 1 + max( height_left, height_right );
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

			pointer erase( first_type key ){
                pointer tmp = find_node( key );
                if ( !tmp )
                    return this;
                pointer tmp_left = tmp->_left;
                pointer tmp_right = tmp->_right;
//                if ( !tmp->_parent ){                                 what if erase root
//                    if ()
//                }
                if ( tmp->_parent->_left == tmp ) {
                    tmp->_parent->_left = NULL;
                    tmp->_parent->set_height();
                } else if ( tmp->_parent->_right == tmp ) {
                    tmp->_parent->_right = NULL;
                    tmp->_parent->set_height();
                }
                return this->insert( tmp_left )->insert( tmp_right );
			}

			//-------Printer-------//
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
				AVLprint data(layer);
				this->set_print( data, 1, &layer );
				data.print();
			}

			void print_nodes( void ){
			    std::cout << "this " << _input.first;
			    std::cout << " parent " << _parent->_input.first;
               if ( _left )
                   std::cout << " left " << _left->_input.first;
               if ( _right )
                   std::cout << " right " << _right->_input.first << std::endl;
			}

	};

}


#endif //AVLTREE_HPP
