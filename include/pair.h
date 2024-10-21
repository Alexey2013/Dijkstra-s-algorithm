#ifndef _pair_H
#define _pair_H
#include <iostream>

template <typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
class pair {
public:
    T1 first;
    T2 second;

public:
    pair();
    pair(const T1& f, const T2& s);
};

template <typename T1, typename T2>
pair<T1, T2>::pair() : first(T1()), second(T2()) {}

template <typename T1, typename T2>
pair<T1, T2>::pair(const T1& f, const T2& s) : first(f), second(s) {}


#endif 