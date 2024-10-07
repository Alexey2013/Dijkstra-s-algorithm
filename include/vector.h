#ifndef  _VECTOR_H
#define  _VECTOR_H
#include <iostream>

template < typename T >
class vector {
private:
    T* v;
    size_t capacity;
    size_t size_;
public:
    vector();
    vector(const size_t n);
    vector(const size_t n, const  T default_value);
    vector(const vector<T>& other);
    vector<T>& operator=(const vector<T>& other);
    ~vector();

    void reallocate(size_t newCapacity);
public:
    T& operator[](const  size_t index) const;
    void push_back(const T value);
    void pop_back();
    T& back() const;
    bool isEmpty() const { return size_ == 0; }
    size_t size() const { return size_; }
};


template < typename T >
vector<T>::vector() : capacity(4), size_(0) { v = new T[capacity]; }

template < typename T >
vector<T>::vector(size_t n) : vector(n, T()) {}

template < typename T >
vector<T>::vector(size_t n, T default_value) {
    capacity = 2 * n;
    size_ = n;
    v = new T[capacity];
    for (size_t i = 0; i < size_; ++i) {
        v[i] = default_value;
    }
}

template <typename T>
vector<T>::vector(const vector<T>& other) {
    size_ = other.size_;
    capacity = other.capacity;

    if (capacity > 0) {
        v = new T[capacity];
    }
    else {
        v = nullptr;
    }

    for (size_t i = 0; i < size_; ++i) {
        v[i] = other.v[i];
    }
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
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
vector<T>::~vector(){
    delete[] v;
}

template < typename T >
T& vector<T>::operator[](size_t index) const {
    return v[index];
}

template <typename T>
void vector<T>::reallocate(size_t newCapacity) {
    if (newCapacity < size_) {
        throw std::runtime_error("New capacity must be greater than or equal to the current size");
    }

    T* newData = new T[newCapacity];

    for (size_t i = 0; i < size_; ++i) {
        newData[i] = std::move(v[i]); 
    }

    delete[] v;

    v = newData;
    capacity = newCapacity;
}
template <typename T>
void vector<T>::push_back(T value) {
    if (size_ == capacity) {
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
        reallocate(newCapacity);
    }
    v[size_] = value;
    size_++;
}

template < typename T >
void vector<T>::pop_back() {
    if (size_ > 0) {
        size_--;
    }
}

template < typename T >
T& vector<T>::back() const {
    if (size_ > 0) return v[size_ - 1];

    throw std::out_of_range("vector is empty");
}

#endif 