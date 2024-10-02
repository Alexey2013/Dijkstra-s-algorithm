#ifndef _PAIR_H
#define _PAIR_H
#include <iostream>

template <typename T>
T min(const T& a, const T& b) { return (a < b) ? a : b; }

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
public:
    Pair();
    Pair(const T1 f, const T2 s);
    Pair(const Pair& p);
public:
    bool operator<(const Pair<T1, T2>& other) const {
        return first < other.first || (first == other.first && second < other.second);
    }
    bool operator>(const Pair<T1, T2>& other) const {
        return other < *this;
    }
};

template<typename T1, typename T2>
Pair<T1, T2>::Pair() : first(T1()), second(T2()) {}

template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1 f, const T2 s) : first(f), second(s) {}

template<typename T1, typename T2>
Pair<T1, T2>::Pair(const Pair& p) : first(p.first), second(p.second) {}

#endif 