//
// Created by Kester kas De rooij on 2/14/22.
//

#ifndef FT_CONTAINERS_TREEITERATOR_HPP
#define FT_CONTAINERS_TREEITERATOR_HPP

#include "BidirectionalIterator.hpp"

namespace ft{

    template< class T, class Node, class Pointer, class Reference, class Category = bidirectional_iterator_tag >
    class TreeIterator : public BidirectionalIterator< Node, Node*, Node& >{

        public:

            typedef T value_type;
            typedef value_type* pointer;
            typedef value_type& reference;
            typedef Node node;
            typedef TreeIterator< T, Node, Pointer, Reference > iterator;
            typedef TreeIterator< T, Node, const Pointer, const Reference > const_iterator;
            typedef Category iterator_category;

        public:

            TreeIterator( void ) : BidirectionalIterator< Node, Node*, Node& >(){ return; }

            TreeIterator( Pointer val ) : BidirectionalIterator< Node, Node*, Node& >( val ){ return; }

            TreeIterator( const iterator& original ) : BidirectionalIterator< Node, Node*, Node& >( original ){ return; }

            ~TreeIterator( void ){ return; }

            iterator& operator=( const iterator& original ){
                this->_ptr = original._ptr;
                return *this;
            }

            iterator& operator++( void ) override{
                this->_ptr = this->_ptr->next( this->_ptr->_input );
                return *this;
            }

            iterator operator++( int ){
                TreeIterator< T, Node, Pointer, Reference > ret( *this );
                this->_ptr = this->_ptr->next( this->_ptr->_input );
                return ret;
            }

            //		iterator operator++( void ) { this->_ptr++; return this; }
            iterator& operator--( void ) override{
                this->_ptr = this->_ptr->previous( this->_ptr->_input );
                return *this;
            }

            iterator operator--( int ){
                TreeIterator< T, Node, Pointer, Reference > ret( *this );
                this->_ptr = this->_ptr->previous( this->_ptr->_input );
                return ret;
            }

            reference operator*( void ) override{ return this->_ptr->_input; }

            pointer operator->( void ) override{ return &(this->_ptr->_input); }

            bool operator==( const iterator& subject ) const{ return this->_ptr == subject._ptr; }

            bool operator!=( const iterator& subject ) const{ return this->_ptr != subject._ptr; }
    };

};
#endif //FT_CONTAINERS_TREEITERATOR_HPP
