#ifndef  _VECTOR_H
#define  _VECTOR_H

template < typename T >
class Vector {
private:
    T* arr;
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
    T& operator[](const  size_t index);
    void push_back(const T value);
    void pop_back();
    void resize(const  size_t size);
    T& back() const;
    void clear() { size_ = 0; }
    bool empty() const { return size_ == 0; }
    size_t size() const { return size_; }
};


template < typename T >
Vector<T>::Vector() : capacity(4), size_(0) { arr = new T[capacity]; }

template < typename T >
Vector<T>::Vector(size_t n) : Vector(n, T()) {}

template < typename T >
Vector<T>::Vector(size_t n, T default_value) {
    capacity = 2 * n;
    size_ = n;
    arr = new T[capacity];
    for (size_t i = 0; i < size_; ++i) {
        arr[i] = default_value;
    }
}

template < typename T >
Vector<T>::Vector(const Vector<T>& other) {
    size_ = other.size_;
    capacity = other.capacity;
    arr = new T[capacity];
    for (size_t i = 0; i < size_; ++i) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this == &other) return *this;  
    delete[] arr;

    size_ = other.size_;
    capacity = other.capacity;
    arr = new T[capacity];
    for (size_t i = 0; i < size_; ++i) {
        arr[i] = other.arr[i];
    }

    return *this;
}

template < typename T >
Vector<T>::~Vector(){
    delete[] arr;
}

template < typename T >
T& Vector<T>::operator[](size_t index) {
    return arr[index];
}

template < typename T >
void Vector<T>::reallocate(size_t newCapacity) {
    T* newData = new T[newCapacity];

    for (size_t i = 0; i < size_; ++i) {
        newData[i] = arr[i];
    }

    delete[] arr;
    arr = newData;
    capacity = newCapacity;
}

template <typename T>
void Vector<T>::push_back(T value) {
    if (size_ == capacity) {
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
        reallocate(newCapacity);
    }
    arr[size_] = value;
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
        for (size_t i = size_; i < newSize; ++i) arr[i] = T();
    }
    size_ = newSize;
}


template < typename T >
T& Vector<T>::back() const {
    if (size_ > 0) return arr[size_ - 1];

    throw std::out_of_range("Vector is empty");
}

#endif 