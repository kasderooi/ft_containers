#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "ft_pair.hpp"
#include "utils.hpp"

namespace ft{

	template< class Pair >
	struct AVLtree{

		typedef Pair value_type;
		typedef AVLtree* node;
		typedef size_t size_type;

		value_type _input;
		size_type _height;
		node _parent;
		node _left;
		node _right;
		node _begin;
		node _end;

		//-------(De-)Constructors-------//
		explicit AVLtree( void ) : _input(), _height( 1 ), _parent( NULL ), _left( NULL ), _right( NULL ),
								   _begin( NULL ), _end( NULL ){ return; }

		explicit AVLtree( value_type input ) : _input( input ), _height( 1 ), _parent( NULL ), _begin( NULL ),
											   _left( NULL ),
											   _right( NULL ), _end( NULL ){ return; }

		AVLtree( const AVLtree< Pair >& original ){
			this = original;
			return;
		}

		~AVLtree( void ){ return; }


		AVLtree< Pair >& operator=( const AVLtree& original ){
			_input = original._input;
			_height = original._height;
			_parent = original._parent;
			_left = original._left;
			_right = original._right;
			_begin = original._begin;
			_end = original._end;
		}

		//-------Rotators-------//
		node left_rotation( void ){
			node tmp = _left;

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

		node right_rotation( void ){
			node tmp = _right;

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

		node find_node( value_type val ){
			if ( val.first == _input.first )
				return this;
			if ( _left && val.first < _input.first )
				return _left->find_node( val );
			if ( _right && val.first > _input.first )
				return _right->find_node( val );
			return NULL;
		}

		node next( value_type val ){
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

		node previous( value_type val ){
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

		node balance( void ){
			if ( _left && ( _left->difference() > 1 || _left->difference() < -1 ))
				_left = _left->balance();
			if ( _right && ( _right->difference() > 1 || _right->difference() < -1 ))
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

		node insert_node( node node ){
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

		void insert_right( node node ){
			if ( _right != NULL )
				_right = _right->insert_node( node );
			else{
				_right = node;
				node->_parent = this;
			}
		}

		void insert_left( node node ){
			if ( _left != NULL )
				_left = _left->insert_node( node );
			else{
				_left = node;
				node->_parent = this;
			}
		}

		node erase( value_type val ){
			node tmp = find_node( val.first );
			if ( !tmp )
				return this;
			node tmp_left = tmp->_left;
			node tmp_right = tmp->_right;
			if ( tmp->_parent->_left == tmp ){
				tmp->_parent->_left = NULL;
				tmp->_parent->set_height();
			}else if ( tmp->_parent->_right == tmp ){
				tmp->_parent->_right = NULL;
				tmp->_parent->set_height();
			}
			return this->insert_node( tmp_left )->insert_node( tmp_right );
		}

	};

}


#endif //AVLTREE_HPP
