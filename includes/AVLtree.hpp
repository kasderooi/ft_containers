#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <algorithm>

namespace ft{

	template< class Pair >
	class AVLtree{

		public:

			typedef Pair value_type;
			typedef size_t size_type;
			typedef AVLtree *pointer;
			typedef AVLtree &reference;
			typedef const AVLtree *const_pointer;
			typedef const AVLtree &const_reference;

		private:

			value_type _input;
			size_type _balance;
			pointer _left;
			pointer _right;

		public:

			//-------(De-)Constructors-------//
			AVLtree( value_type input ) : _input( input ), _balance( 0 ), _left( NULL ), _right( NULL ){ return; }

			~AVLtree( void ){ return; }

			//-------Rotators-------//
			pointer left_rotation( pointer node ){
				pointer tmp;
				tmp = node->left;
				node->left = tmp->right;
				tmp->right = node;
				return tmp;
			}

			pointer right_rotation( pointer node ){
				pointer tmp;
				tmp = node->right;
				node->right = tmp->left;
				tmp->left = node;
				return tmp;
			}

			pointer leftright_rotation( pointer node ){
				node->left = right_rotation( node->left );
				return left_rotation( node );
			}

			pointer rightleft_rotation( pointer node ){
				node->right = left_rotation( node->right );
				return node;
			}

			//-------Capacity-------//
			size_type height( pointer node ){
				size_type ret = 0;
				if ( node != NULL ){
					ret = max( height( node->left ), height( node->right ));
					ret++;
				}
				return ret;
			}

			size_type difference( pointer node ){ return height( node->left ) - height( node->right ); }

			pointer balance( pointer node ){
				size_type dif = difference( node );
				if ( dif > 1 ){                            // left heavy
					if ( difference( node->left ) > 0 )
						node = left_rotation( node );
					else
						node = leftright_rotation( node );
				}else if ( dif < -1 ){                    // right heavy
					if ( difference( node->right ) > 0 )
						node = rightleft_rotation( node );
					else
						node = right_rotation( node );
				}
				return node;
			}

			//-------Modifiers-------//
			pointer insert( pointer node, value_type input ){
				if ( !node ){
					node =
				}
			}

	};
}


#endif //AVLTREE_HPP
