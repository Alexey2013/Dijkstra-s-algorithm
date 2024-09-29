#ifndef _BASE_H
#define _BASE_H

template <typename T>
T myMin(const T& a, const T& b) { return (a < b) ? a : b; }

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
public:
    Pair() : first(T1()), second(T2()) {}
    Pair(const T1 f, const T2 s) : first(f), second(s) {}

    Pair(const Pair& p) : first(p.first), second(p.second) {}
    Pair(std::initializer_list<T1> list) {
        auto it = list.begin();
        first = *it;
        second = *(++it);
    }

    bool operator<(const Pair<T1, T2>& other) const {
        return first < other.first || (first == other.first && second < other.second);
    }

    bool operator>(const Pair<T1, T2>& other) const {
        return other < *this;
    }

};

template < typename T >
class my_vector {
private:
    T* arr;
    size_t capacity;
    size_t size_;
public:
    T& operator[](size_t index) {return arr[index]}

    my_vector()
    {
        arr = new T[4];
        capacity = 4;
        size_ = 0;
    }

    ~my_vector()
    {
        delete[] arr;
        capacity = 0;
        size_ = 0;
    }

    void push_back(T value)
    {
        if (size_ == capacity) {
            T* temp = new T[capacity + 4];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity += 4;
            arr = temp;
        }
        arr[size_] = value;
        size_++;
    }

    int size() { return size_; }


    void pop_back() {
        if (size_ > 0) {
            size_--;
        }
    }

    void clear() { size_ = 0; }
    bool empty() {return size_ == 0;}


    void erase(unsigned int index) {
        if (index < size_) {
            for (int i = index; i < size_ - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size_--;
        }
    }

    T& back() {
        if (size_ > 0) return arr[size_ - 1];

        throw std::out_of_range("Vector is empty");
    }

};

#endif 