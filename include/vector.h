#ifndef  _VECTOR_H
#define  _VECTOR_H
#include <iostream>

template <typename T>
class vector {
private:
    T* v_;
    size_t capacity_;
    size_t size_;

public:
    vector();
    explicit vector(const size_t n);
    vector(const size_t n, const T& default_value);
    vector(const vector<T>& other);
    vector<T>& operator=(const vector<T>& other);
    ~vector();

    void reallocate(size_t new_capacity);

public:
    T& operator[](const size_t index) const;
    void push_back(const T& value);
    void pop_back();
    T& back() const;
    bool IsEmpty() const { return size_ == 0; }
    size_t size() const { return size_; }
};

template <typename T>
vector<T>::vector() : capacity_(4), size_(0) {
    v_ = new T[capacity_];
}

template <typename T>
vector<T>::vector(size_t n) : vector(n, T()) {}

template <typename T>
vector<T>::vector(size_t n, const T& default_value) {
    capacity_ = 2 * n;
    size_ = n;
    v_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        v_[i] = default_value;
    }
}

template <typename T>
vector<T>::vector(const vector<T>& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;

    if (capacity_ > 0) {
        v_ = new T[capacity_];
    }
    else {
        v_ = nullptr;
    }

    for (size_t i = 0; i < size_; ++i) {
        v_[i] = other.v_[i];
    }
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
    if (this == &other) return *this;
    delete[] v_;

    size_ = other.size_;
    capacity_ = other.capacity_;
    v_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        v_[i] = other.v_[i];
    }

    return *this;
}

template <typename T>
vector<T>::~vector() {
    delete[] v_;
}

template <typename T>
T& vector<T>::operator[](size_t index) const {
    return v_[index];
}

template <typename T>
void vector<T>::reallocate(size_t new_capacity) {
    if (new_capacity < size_) {
        throw std::runtime_error("New capacity must be greater than or equal to the current size.");
    }

    T* new_data = new T[new_capacity];

    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = std::move(v_[i]);
    }

    delete[] v_;

    v_ = new_data;
    capacity_ = new_capacity;
}

template <typename T>
void vector<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
        reallocate(new_capacity);
    }
    v_[size_] = value;
    size_++;
}

template <typename T>
void vector<T>::pop_back() {
    if (size_ > 0) {
        size_--;
    }
}

template <typename T>
T& vector<T>::back() const {
    if (size_ > 0) return v_[size_ - 1];

    throw std::out_of_range("vector is empty.");
}

#endif 