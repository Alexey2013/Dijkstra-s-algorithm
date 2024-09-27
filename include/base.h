#ifndef _BASE_H
#define _BASE_H

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

template<typename T1, typename T2>
class Pair {
private:
    T1 first;  
    T2 second;
public:
    Pair() : first(T1()), second(T2()) {}
    Pair(const T1 f, const T2 s) : first(f), second(s) {}

    Pair(const Pair& p) : first(p.get_first()), second(p.get_second()) {}

    T1 get_first() const {return first;}
    T2 get_second() const { return second;}

    void set_first(T1 f) { first = f;}
    void set_second(T2 s) { second = s; }

    friend std::ostream& operator<<(std::ostream& os, const Pair& p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
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
        delete arr;
        capacity = 0;
        size_ = 0;
    }

    void push_back(T value)
    {
        if (size_ == capacity) {
            T* temp = new T[capacity + 10];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity += 10;
            arr = temp;
        }
        arr[size_] = value;
        size_++;
    }

    void pop_back()
    {
        size_--;
    }

    int size(){return size_;}
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

};

#endif 