#ifndef FT_STACK_HPP
#define FT_STACK_HPP

namespace ft {

	template< class T, class Container = std::deque<T> >
	class stack {

		public:

			typedef		T			value_type;
			typedef		Container	container_type;
			typedef		size_t		size_type;

		private:

			container_type _ctnr;

		public:

	//-------(De-)Constructors-------//
			explicit stack ( const container_type& ctnr = container_type() ) : _ctnr( ctnr ) { return; }

	};
}

#endif //FT_CONTAINERS_FT_STACK_HPP
