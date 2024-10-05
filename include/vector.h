#ifndef  _VECTOR_H
#define  _VECTOR_H
#include <iostream>

template < typename T >
class Vector {
private:
    T* v;
    size_t capacity;
    size_t size_;
public:
    Vector();
    Vector(const size_t n);
    Vector(const size_t n, const  T default_value);
    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);
    ~Vector();

    void reallocate(size_t newCapacity);
public:
    T& operator[](const  size_t index) const;
    void push_back(const T value);
    void pop_back();
    void resize(const  size_t size);
    T& back() const;
    void clear() { size_ = 0; }
    bool empty() const { return size_ == 0; }
    size_t size() const { return size_; }

    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
        os << "[";
        for (size_t i = 0; i < vec.size_; ++i) {
            os << vec.v[i];
            if (i < vec.size_ - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};


template < typename T >
Vector<T>::Vector() : capacity(4), size_(0) { v = new T[capacity]; }

template < typename T >
Vector<T>::Vector(size_t n) : Vector(n, T()) {}

template < typename T >
Vector<T>::Vector(size_t n, T default_value) {
    capacity = 2 * n;
    size_ = n;
    v = new T[capacity];
    for (size_t i = 0; i < size_; ++i) {
        v[i] = default_value;
    }
}

template < typename T >
Vector<T>::Vector(const Vector<T>& other) {
    size_ = other.size_;
    capacity = other.capacity;
    v = new T[capacity];
    for (size_t i = 0; i < size_; ++i) {
        v[i] = other.v[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this == &other) return *this;  
    delete[] v;

    size_ = other.size_;
    capacity = other.capacity;
    v = new T[capacity];
    for (size_t i = 0; i < size_; ++i) {
        v[i] = other.v[i];
    }

    return *this;
}

template < typename T >
Vector<T>::~Vector(){
    delete[] v;
}

template < typename T >
T& Vector<T>::operator[](size_t index) const {
    return v[index];
}

template < typename T >
void Vector<T>::reallocate(size_t newCapacity) {
    T* newData = new T[newCapacity];

    for (size_t i = 0; i < size_; ++i) {
        newData[i] = v[i];
    }

    delete[] v;
    v = newData;
    capacity = newCapacity;
}

template <typename T>
void Vector<T>::push_back(T value) {
    if (size_ == capacity) {
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
        reallocate(newCapacity);
    }
    v[size_] = value;
    size_++;
}

template < typename T >
void Vector<T>::pop_back() {
    if (size_ > 0) {
        size_--;
    }
}

template <typename T>
void Vector<T>::resize(size_t newSize) {
    if (newSize > capacity) {
        reallocate(newSize);
    }
    if (newSize > size_) {
        for (size_t i = size_; i < newSize; ++i) v[i] = T();
    }
    size_ = newSize;
}


template < typename T >
T& Vector<T>::back() const {
    if (size_ > 0) return v[size_ - 1];

    throw std::out_of_range("Vector is empty");
}

#endif 