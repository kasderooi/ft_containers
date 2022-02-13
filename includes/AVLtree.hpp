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
		std::vector< int >* array;

		AVLprint( int layers ){
			_layers = layers;
			array = new std::vector< int >[layers];
		}

		void add( int layer, int input ){
			array[layer - 1].push_back( input );
		}

		void print( void ){
			while ( _layers > 0 ){
				_layers--;
				std::cout << " ";
				for ( int i = 0; i < _layers; i++ )
					std::cout << "\t";
				for ( std::vector< int >::iterator it = array[_layers].begin(); it < array[_layers].end(); it++ ){
					if ( *it )
						std::cout << *it;
					else
						std::cout << "_";
					for ( int i = 0; i <= _layers; i++ )
						std::cout << "  ";
				}
				std::cout << std::endl;
			}
			delete[] array;
		}
	};

	template< class Pair = ft::pair< class T1, class T2 > >
//	template< class pair >
	struct AVLtree{

		typedef Pair value_type;
		typedef AVLtree* pointer;
		typedef size_t size_type;

		value_type _input;
		size_type _height;
		pointer _parent;
		pointer _left;
		pointer _right;
		pointer _begin;
		pointer _end;

		//-------(De-)Constructors-------//
		AVLtree( void ) : _input(), _height( 1 ), _parent( NULL ), _left( NULL ), _right( NULL ),
							_begin( NULL ), _end( NULL ){ return; }

		AVLtree( value_type input ) : _input( input ), _height( 1 ), _parent( NULL ), _begin( NULL ), _left( NULL ),
									  _right( NULL ), _end( NULL ){ return; }

		~AVLtree( void ){ return; }

		AVLtree< Pair >& operator=( const AVLtree& original ){
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
			return tmp->balance();
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
			return tmp->balance();
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

		pointer find_node( value_type val ){
			if ( val.first == _input.first )
				return this;
			if ( _left && val.first < _input.first )
				return _left->find_node( val );
			if ( _right && val.first > _input.first )
				return _right->find_node( val );
			return NULL;
		}

		pointer next( value_type val ){
			if ( this == _begin )
				return _parent;
			if ( _left && _left->_input.first > val.first )
				return _left->next( val );
			else if ( _right && _input.first == val.first )
				return _right->next( val );
			else if (( _parent && _parent->_input.first > val.first && _parent->_input.first < _input.first ) ||
					 ( _right && _right->_input.first <= val.first ) ||
					 ( _input.first == val.first )){
				if ( !_parent || _parent == _end )
					return _end;
				return _parent->next( val );
			}
			return this;
		}

		pointer previous( value_type val ){
			if ( this == _end )
				return _parent;
			if ( _right && _right->_input.first < val.first )
				return _right->previous( val );
			else if ( _left && _input.first == val.first )
				return _left->previous( val );
			else if (( _parent && _parent->_input.first < val.first && _parent->_input.first > _input.first ) ||
					 ( _left && _left->_input.first >= val.first ) ||
					 ( _input.first == val.first )){
				if ( !_parent || _parent == _begin )
					return _begin;
				return _parent->previous( val );
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
			if ( _left && ( _left->difference() > 1 || _left->difference() < -1 ) )
					_left = _left->balance();
			if ( _right && ( _right->difference() > 1 || _right->difference() < -1 ) )
				_right = _right->balance();
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

		pointer insert_node( pointer node ){
			if ( !node )
				return this->balance();
			if ( node->_input.first > this->_input.first ){
				if ( _right != NULL )
					_right = _right->insert_node( node );
				else{
					_right = node;
					node->_parent = this;
				}
			}else if ( node->_input.first < this->_input.first ){
				if ( _left != NULL )
					_left = _left->insert_node( node );
				else{
					_left = node;
					node->_parent = this;
				}
			}else
				return this;
			this->set_height();
			return this->balance();
		}

		void insert_right( pointer node ){
			if ( _right != NULL )
				_right = _right->insert_node( node );
			else{
				_right = node;
				node->_parent = this;
			}
		}

		void insert_left( pointer node ){
			if ( _left != NULL )
				_left = _left->insert_node( node );
			else{
				_left = node;
				node->_parent = this;
			}
		}

		pointer erase( value_type val ){
			pointer tmp = find_node( val.first );
			if ( !tmp )
				return this;
			pointer tmp_left = tmp->_left;
			pointer tmp_right = tmp->_right;
			if ( tmp->_parent->_left == tmp ){
				tmp->_parent->_left = NULL;
				tmp->_parent->set_height();
			}else if ( tmp->_parent->_right == tmp ){
				tmp->_parent->_right = NULL;
				tmp->_parent->set_height();
			}
			return this->insert_node( tmp_left )->insert_node( tmp_right );
		}

		//-------Printer-------//
		int set_print( AVLprint data, int count, int* layer ){
			data.add( *layer, _input.first );
			if ( _left ){
				( *layer )--;
				count = _left->set_print( data, ++count, layer );
			}else{
				if ( *layer > 1 ){
					data.add( *layer - 1, 0 );
					count++;
				}
			}
			if ( _right ){
				( *layer )--;
				count = _right->set_print( data, ++count, layer );
			}else{
				if ( *layer > 1 ){
					data.add( *layer - 1, 0 );
					count++;
				}
			}
			( *layer )++;
			return count;
		}

		void print( void ){
			int layer = _height;
			AVLprint data( layer );
			this->set_print( data, 1, &layer );
			data.print();
		}

		void print_nodes( void ){
			std::cout << "this " << _input.first << " Height " << _height;
			if ( _parent )
				std::cout << " parent " << _parent->_input.first;
			if ( _left )
				std::cout << " left " << _left->_input.first;
			if ( _right )
				std::cout << " right " << _right->_input.first;
			std::cout << std::endl;
		}

	};

}


#endif //AVLTREE_HPP
