#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

// 版本1
template<typename T, typename ... Types>
void print (const T &firstArg, const Types &...args) { // 将参数分为一个和一包(一包参数递归输出)
    std::cout << firstArg << std::endl;
    std::cout << sizeof...(args) << std::endl; // 一包的个数
    print(args...);
}
// 版本2 这两个版本间并不会冲突
template<typename ... Types>
void print (const Types &...args) {

}

template<typename T>
inline void hash_combine (size_t &seed, const T &val) {
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
// 泛化
template<typename ... Types>
inline size_t hash_val (const Types &...args) {
    size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}
// 特化
template<typename T, typename ...Types>
inline void hash_val (size_t &seed, const T &val, const Types &...args) {
    hash_combine(seed, val);
    hash_val(seed, args...);
}
// 中止条件
template<typename T>
inline void hash_val (size_t &seed, const T &val) {
    hash_combine(seed, val);
}

int i;
double j{1};
int *p;

class P {
    public:
        P (int aa, int bb)
            : a(aa), b(bb) {};
        P (std::initializer_list<int> aa)
            : a(*aa.begin()), b(*aa.begin() + *(aa.begin())) {};
        int a, b;
        void print () const { std::cout << a + b; }
};
P m(1, 2);
P n{1, 2}; // 初始化列表
P o = {1, 2}; // 初始化列表但赋值临时对象

#endif //TEMPLATE_HPP
