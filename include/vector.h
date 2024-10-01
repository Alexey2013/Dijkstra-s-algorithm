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
    Vector(const Vector& other);
    ~Vector();
public:
    T& operator[](const  size_t index);
    void push_back(const T value);
    void pop_back();
    void erase(const size_t index);
    T& back() const;
    void clear() { size_ = 0; }
    bool empty() const { return size_ == 0; }
    size_t size() const { return size_; }
};


template < typename T >
Vector<T>::Vector() : capacity(4), size_(0) { arr = new T[4]; }

template < typename T >
Vector<T>::Vector(size_t n) : Vector(n, T()) {}

template < typename T >
Vector<T>::Vector(size_t n, T default_value) {
    capacity = 2 * n;
    size_ = n;
    arr = new T[size_];
    for (size_t i = 0; i < size_; ++i) {
        arr[i] = default_value;
    }
}

template < typename T >
Vector<T>::Vector(const Vector& other) {
    size_ = other.size_;
    capacity = other.capacity;
    arr = new T[capacity];

    for (size_t i = 0; i < size_; ++i) {
        arr[i] = other.arr[i];
    }
}

template < typename T >
Vector<T>::~Vector()
{
    delete[] arr;
    capacity = 0;
    size_ = 0;
}

template < typename T >
T& Vector<T>::operator[](size_t index) {
    return arr[index];
}

template < typename T >
void Vector<T>::push_back(T value)
{
    if (size_ == capacity) {
        T* temp = new T[capacity + 4];
        for (size_t i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        capacity += 4;
        arr = temp;
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

template < typename T >
void Vector<T>::erase(size_t index) {
    if (index < size_) {
        for (size_t i = index; i < size_ - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size_--;
    }
}

template < typename T >
T& Vector<T>::back() const {
    if (size_ > 0) return arr[size_ - 1];

    throw std::out_of_range("Vector is empty");
}

#endif 