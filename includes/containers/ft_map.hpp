#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <memory>
#include "../utils/ft_pair.hpp"
#include "../utils/AVLtree.hpp"
#include "../utils/utils.hpp"
#include "../iterators/BidirectionalIterator.hpp"
#include "../iterators/ReverseIterator.hpp"

namespace ft {

    template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map {

    public:

        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const Key, T> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef AVLtree<value_type> node;
        typedef node *node_pointer;
        typedef const node *const_node_pointer;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::BidirectionalIterator<value_type, pointer, reference> iterator;
        typedef typename ft::BidirectionalIterator<value_type, const_pointer, const_reference> const_iterator;
        typedef typename ft::ReverseIterator<iterator> reverse_iterator;
        typedef typename ft::ReverseIterator<const_iterator> const_reverse_iterator;
        typedef typename Alloc::template rebind<node>::other node_alloc;

        class value_compare : public binary_function<value_type, value_type, bool> {

        public:

            friend class map;

        protected:

            key_compare comp;

            value_compare(key_compare c) : comp(c) {};

        public:

            bool operator()(const value_type &x, const value_type &y) const {
                return comp(x.first, y.first);
            }
        };

        typedef value_compare nestedfunctionclass;

    private:

        node_alloc _alloc;
        size_type _size;
        node_pointer _root;
        node_pointer _begin;
        node_pointer _end;
        key_compare _compare;

    public:

        //-------(De-)Constructors-------//
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) :
                _alloc(alloc), _size(0), _root(NULL), _begin(NULL), _end(NULL), _compare(comp) {
            set_endpoints();
            return;
        }

        template<class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(0), _root(NULL),
                                                              _begin(NULL), _end(NULL), _compare(comp) {
            InputIterator tmp = first;
            set_endpoints();
            while (tmp != last) {
                this->insert(*tmp);
                tmp++;
            }
            return;
        }

        map(const map &x) : _alloc(x._alloc), _size(0), _root(NULL), _begin(NULL),
                            _end(NULL), _compare(x._compare) {
            set_endpoints();
            *this = x;
            return;
        }

        ~map(void) {
            clear();
            clear_endpoints();
            return;
        }

        //-------Assignment Operator-------//
        map &operator=(const map &original) {
            clear();
            _alloc = original._alloc;
            this->insert(original.begin(), original.end());
            return *this;
        }

        //-------iterators-------//
        iterator begin(void) {
            return iterator(_begin->_parent);
        }

        const_iterator begin(void) const {
            return const_iterator(_begin->_parent);
        }

        iterator end(void) {
            return iterator(_end);
        }

        const_iterator end(void) const {
            return const_iterator(_end);
        }

        reverse_iterator rbegin(void) {
            return reverse_iterator(iterator(_end->_parent));
        }

        const_reverse_iterator rbegin(void) const {
            return const_reverse_iterator(iterator(_end->_parent));
        }

        reverse_iterator rend(void) {
            return reverse_iterator(iterator(_begin));
        }

        const_reverse_iterator rend(void) const {
            return const_reverse_iterator(iterator(_begin));
        }

        //-------Capacity-------//
        bool empty() const {
            if (_size == 0)
                return true;
            return false;
        }

        size_type size() const {
            return _size;
        }

        size_type max_size() const {
            return _alloc.max_size();
        }

        //-------Element access-------//
        mapped_type &operator[](const key_type &key) {
            node_pointer find = _root ? _root->find_node(ft::make_pair(key, mapped_type()), _compare) : NULL;
            if (find)
                return find->_input.second;
            return (*(this->insert(ft::make_pair(key, mapped_type())).first)).second;
        }

        //-------Modifiers-------//
        pair<iterator, bool> insert(const_reference val) {
            if (_root && _root->find_node(val, _compare))
                return (ft::make_pair(iterator(_root->find_node(val, _compare)), false));
            node_pointer tmp = build_node(val);
            _size++;
            if (_root) {
                _root = _root->insert_node(tmp, _compare);
                if (_compare(val.first, _begin->_parent->_input.first))
                    this->_begin->_parent = tmp;
                if (_compare(_end->_parent->_input.first, val.first))
                    this->_end->_parent = tmp;
            } else {
                _root = tmp;
                this->_begin->_parent = tmp;
                this->_end->_parent = tmp;
            }
            return (ft::make_pair(iterator(_root->find_node(val, _compare)), true));
        }

        iterator insert(iterator position, const_reference val) {
            if (_root && _root->find_node(val, _compare))
                return (iterator(_root->find_node(val, _compare)));
            node_pointer pos = _root->find_node(*position, _compare);
            node_pointer tmp = build_node(val);
            _size++;
            if (!pos)
                _root->insert_node(tmp, _compare);
            else if (_compare(position->first, val.first))
                pos->insert_right(tmp, _compare);
            else
                pos->insert_left(tmp, _compare);
            _root = _root->balance();
            return iterator(tmp);
        }

        template<class InputIterator>
        void insert(InputIterator first, InputIterator last,
                    typename ft::enable_if<!is_integral<InputIterator>::value, int>::type = 0) {
            InputIterator it = first;
            while (it != last) {
                this->insert(*it);
                it++;
            }
        }

        void erase(iterator position) {
            erase(position->first);
        }

        size_type erase(const key_type &key) {
            if (!_root)
                return 0;
            node_pointer tmp = _root->find_node(ft::make_pair(key, mapped_type()), _compare);
            if (!tmp)
                return 0;
            node_pointer tmp_left = tmp->_left ? tmp->_left->balance() : NULL;
            node_pointer tmp_right = tmp->_right ? tmp->_right->balance() : NULL;
            if (tmp != _root) {
                erase_node(tmp);
                _root = _root->insert_node(tmp_left, _compare)->insert_node(tmp_right, _compare);
            } else if (tmp_right || tmp_left) {
                erase_root(tmp_left, tmp_right);
            } else {
                _root = NULL;
                _begin->_parent = _end;
                _end->_parent = _begin;
            }
            _alloc.destroy(tmp);
            _alloc.deallocate(tmp, 1);
            --_size;
            return 1;
        }

        void erase(iterator first, iterator last) {
            iterator tmp;
            while (first != last) {
                tmp = first++;
                erase(tmp);
            }
        }

        void swap(map &original) {
            ft::swap(this->_size, original._size);
            ft::swap(this->_alloc, original._alloc);
            ft::swap(this->_root, original._root);
            ft::swap(this->_begin, original._begin);
            ft::swap(this->_end, original._end);

        }

        void clear(void) {
            erase(begin(), end());
        }

        //-------Observers-------//
        key_compare key_comp(void) const {
            return _compare;
        }

        value_compare value_comp(void) const {
            return value_compare(_compare);
        }

        //-------Map Operations-------//
        iterator find(const key_type &key) {
            node_pointer tmp = _root ? _root->find_node(ft::make_pair(key, mapped_type()), _compare) : NULL;
            if (tmp)
                return iterator(tmp);
            return iterator(_end);
        }

        const_iterator find(const key_type &key) const {
            node_pointer tmp = _root ? _root->find_node(ft::make_pair(key, mapped_type()), _compare) : NULL;
            if (tmp)
                return iterator(tmp);
            return iterator(_end);
        }

        size_type count(const key_type &key) const {
            node_pointer tmp = _root ? _root->find_node(ft::make_pair(key, mapped_type()), _compare) : NULL;
            if (!tmp || tmp == _end)
                return 0;
            return 1;
        }

        iterator lower_bound(const key_type &key) {
            iterator it = begin();
            while (_compare(it->first, key))
                it++;
            return it;
        }

        const_iterator lower_bound(const key_type &key) const {
            const_iterator it = begin();
            while (_compare(it->first, key))
                it++;
            return it;
        }

        iterator upper_bound(const key_type &key) {
            iterator it = lower_bound(key);
            if (_compare(key, it->first))
                return it;
            return ++it;
        }

        const_iterator upper_bound(const key_type &key) const {
            const_iterator it = lower_bound(key);
            if (_compare(key, it->first))
                return it;
            return ++it;
        }

        pair<iterator, iterator> equal_range(const key_type &key) {
            iterator it = lower_bound(key);
            if (_compare(key, it->first))
                return ft::make_pair(it, it);
            return ft::make_pair(it, ++it);
        }

        pair<const_iterator, const_iterator> equal_range(const key_type &key) const {
            const_iterator it = lower_bound(key);
            if (_compare(key, it->first))
                return ft::make_pair(it, it);
            return ft::make_pair(it, ++it);
        }

        allocator_type get_allocator() const {
            return _alloc;
        }

        //-------Relational operators-------//
        template<class Key1, class T1, class Compare1, class Alloc1>
        friend bool operator==(const map<Key1, T1, Compare1, Alloc1> &lhs, const map<Key1, T1, Compare1, Alloc1> &rhs);

        template<class Key1, class T1, class Compare1, class Alloc1>
        friend bool operator<(const map<Key1, T1, Compare1, Alloc1> &lhs, const map<Key1, T1, Compare1, Alloc1> &rhs);

    private:

        node_pointer build_node(value_type val) {
            node_pointer tmp = _alloc.allocate(1);
            _alloc.construct(tmp, val);
            tmp->_begin = this->_begin;
            tmp->_end = this->_end;
            return tmp;
        }

        void set_endpoints(void) {
            _begin = _alloc.allocate(1);
            _alloc.construct(_begin, ft::make_pair(key_type(), mapped_type()));
            _end = _alloc.allocate(1);
            _alloc.construct(_end, ft::make_pair(key_type(), mapped_type()));
            _begin->_parent = _end;
            _begin->_begin = _begin;
            _begin->_end = _end;
            _end->_parent = _begin;
            _end->_begin = _begin;
            _end->_end = _end;
        }

        void clear_endpoints(void) {
            _alloc.destroy(_begin);
            _alloc.deallocate(_begin, 1);
            _alloc.destroy(_end);
            _alloc.deallocate(_end, 1);
        }

        void erase_node(node_pointer tmp) {
            if (tmp->_parent->_left == tmp) {
                tmp->_parent->_left = NULL;
                tmp->_parent->set_height();
            } else if (tmp->_parent->_right == tmp) {
                tmp->_parent->_right = NULL;
                tmp->_parent->set_height();
            }
            if (tmp == _end->_parent)
                _end->_parent = _root->find_node(*(--iterator(tmp)), _compare);
            if (tmp == _begin->_parent)
                _begin->_parent = _root->find_node(*(++iterator(tmp)), _compare);
        }

        void erase_root(node_pointer tmp_left, node_pointer tmp_right) {
            size_type left_height = tmp_left ? tmp_left->_height : 0;
            size_type right_height = tmp_right ? tmp_right->_height : 0;
            if (tmp_right && (!tmp_left || _compare(right_height, left_height))) {
                tmp_right->_parent = NULL;
                _root = tmp_right;
                _root = _root->insert_node(tmp_left, _compare);
            } else {
                tmp_left->_parent = NULL;
                _root = tmp_left;
                _root = _root->insert_node(tmp_right, _compare);
            }
        }

    };
    //-------Non-member function overloads-------//

    template<class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        if (lhs.size() != rhs.size())
            return false;
        typename ft::map<Key, T>::const_iterator lhs_it = lhs.begin();
        typename ft::map<Key, T>::const_iterator rhs_it = rhs.begin();
        for (; lhs_it != lhs.end() && rhs_it != rhs.end(); lhs_it++, rhs_it++)
            if (*lhs_it != *rhs_it)
                return false;
        return true;
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        return !(lhs == rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        return rhs < lhs;
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        return !(lhs > rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        return !(lhs < rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) {
        x.swap(y);
    }
}


#endif //FT_CONTAINERS_FT_MAP_HPP
