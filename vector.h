#pragma once

template <typename T>
class Vector 
{
private:

	T* arr;
	size_t v_size;
	size_t v_cap;

public:

	Vector();
	Vector(size_t size);
	Vector(const Vector<T>& v);
	~Vector();

	size_t size();
	void reserve(size_t cap);
	void resize(size_t size);
	void push_back(T val);
	void pop_back();

	T& operator[](size_t index);
};

template <typename T>
Vector<T>::Vector() {
	arr = 0;
	v_size = 0;
	v_cap = 0;
}

template <typename T>
Vector<T>::Vector(size_t size) {
	arr = new T[size];
	v_size = size;
	v_cap = size;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& v) {
	v_size = v.v_size;
	v_cap = v.v_cap;
	for (size_t i = 0; i < v_size; i++) arr[i] = v.arr[i];
}

template <typename T>
Vector<T>::~Vector() {
	delete[] arr;
}

template <typename T>
size_t Vector<T>::size() {
	return v_size;
}

template <typename T>
void Vector<T>::reserve(size_t cap) {
	if (arr == 0) {
		v_size = 0;
		v_cap = 0;
	}

	T* buffer = new T[cap];
	unsigned int l_size = cap < v_size ? cap : v_size;
	for (size_t i = 0; i < l_size; i++) buffer[i] = arr[i];
	v_cap = cap;
	delete[] arr;
	arr = buffer;
}

template <typename T>
void Vector<T>::resize(size_t size) {
	reserve(size);
	v_size = size;
}

template <typename T>
void Vector<T>::push_back(T val) {
	if (v_size >= v_cap) reserve(v_cap + 5);
	arr[v_size++] = val;
}

template <typename T>
void Vector<T>::pop_back() {
	v_size--;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
	return arr[index];
}