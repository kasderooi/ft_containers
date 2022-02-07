#ifndef FT_CONTAINERS_NODEITERATOR_HPP
#define FT_CONTAINERS_NODEITERATOR_HPP

#include "IteratorUtils.hpp"

namespace ft{


    template< class T, class Pointer = T *, class Reference = T &, class Category = ft::node_iterator_tag >
    class NodeIterator{

    public:

        typedef NodeIterator< T, Pointer, Reference > iterator;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
        typedef size_t size_type;

    private :

        pointer _ptr;

    public:

        NodeIterator( void ) : _ptr( NULL ){ return; }

        NodeIterator( pointer ptr ) : _ptr( ptr ){ return; }

        NodeIterator( const iterator &original ) : _ptr( original._ptr ){ return; }

        ~NodeIterator( void ){ return; }

        iterator &operator=( const iterator &original ){
            this->_ptr = original._ptr;
            return ( *this );
        }

        iterator &operator++( void ){
            _ptr = _ptr->next( _ptr->get_key() ) ;
            return *this ;
        }

        iterator operator++( int ){
            iterator ret = *this;
            _ptr = _ptr->next( _ptr->get_key() ) ;
            return ret;
        }

        //		iterator operator++( void ) { this->_ptr++; return this; }
        iterator &operator--( void ){
            _ptr = _ptr->previous( _ptr->get_key() );
            return *this;
        }

        iterator operator--( int ){
            iterator ret = *this;
            _ptr = _ptr->previous( _ptr->get_key() );
            return ret;
        }

    };

}

#endif //FT_CONTAINERS_NODEITERATOR_HPP
