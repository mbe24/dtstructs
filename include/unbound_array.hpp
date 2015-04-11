#ifndef __unbound_array_hpp__
#define __unbound_array_hpp__

#include <cstddef>

namespace datastructures {

template<typename T>
class IUnboundArray {
public:
	auto pushBack(T& element) -> void = 0;
	auto popBack() -> T = 0;
	auto operator[](const int& b) -> T& = 0;
	auto size() -> size_t = 0;
	virtual ~IUnboundArray() = 0;
};

template<typename T, size_t ALPHA = 4, size_t BETA = 2>
class UnboundArray {
static_assert(ALPHA >= BETA, "ALPHA has to be greater or equal to BETA!");

private:
	size_t w; // max array size
	size_t n; // index of current element, zero-based

	T *data;

	auto reallocate(const size_t size) -> void;

public:
	UnboundArray() :
			w(1), n(0) {
		data = new T[w];
	}

	auto pushBack(T& element) -> void;
	auto popBack() -> T;
	auto operator[](const int& b) -> T&;
	auto size() -> size_t;
	~UnboundArray();
};

template<typename T, size_t ALPHA, size_t BETA>
UnboundArray<T, ALPHA, BETA>::~UnboundArray() {
	if (data) {
		delete[] data;
	}
}

template<typename T, size_t ALPHA, size_t BETA>
auto UnboundArray<T, ALPHA, BETA>::pushBack(T& element) -> void {
	if (n == w) {
		reallocate(BETA * n);
	}
	data[n++] = element;
}

template<typename T, size_t ALPHA, size_t BETA>
auto UnboundArray<T, ALPHA, BETA>::popBack() -> T {
	if ((ALPHA * n <= w) && n > 0) {
		reallocate(w / BETA);
	}
	T ret(data[--n]);
	data[n] = 0;
	return ret;
}

template<typename T, size_t ALPHA, size_t BETA>
auto UnboundArray<T, ALPHA, BETA>::operator[](const int& b) -> T& {
	return data[b];
}

template<typename T, size_t ALPHA, size_t BETA>
auto UnboundArray<T, ALPHA, BETA>::reallocate(const size_t size) -> void {
	w = size;
	T* array = new T[w];

	/* copy to new array */
	for (size_t i = 0; i < n; i++)
		array[i] = data[i];

	delete[] data;
	data = array;
}

template<typename T, size_t ALPHA, size_t BETA>
auto UnboundArray<T, ALPHA, BETA>::size() -> size_t {
	return n;
}

} // datastructures
#endif