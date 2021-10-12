#ifndef NEURON_NETWORK_TENSOR_HPP
#define NEURON_NETWORK_TENSOR_HPP

#include <iostream>
#include <array>
#include <cmath>
#include <random>

namespace rnd {
    std::mt19937 gen{777};
    std::uniform_real_distribution<> dis{-0.5, 0.5};
}

template<class T, size_t... sizes>
struct Tensor {
};

template<class T>
struct Tensor<T> {
    T data;
    static constexpr size_t dim = 0;

    Tensor() : data(rnd::dis(rnd::gen)) {}

    Tensor(T x) : data(x) {}

    void fill(T x = 0) {
        data = x;
    }

    Tensor<T> operator+=(const T &x) {
        data += x;
        return *this;
    }

    Tensor<T> operator-=(const T &x) {
        data -= x;
        return *this;
    }

    Tensor<T> operator*=(const T &x) {
        data *= x;
        return *this;
    }

    Tensor<T> operator/=(const T &x) {
        data /= x;
        return *this;
    }

    Tensor<T> operator+(const T &x) {
        return Tensor<T>(data + x);
    }

    Tensor<T> operator-(const T &x) {
        return Tensor<T>(data - x);
    }

    Tensor<T> operator/(const T &x) {
        return Tensor<T>(data / x);
    }

    Tensor<T> operator*(const T &x) {
        return Tensor<T>(data * x);
    }

    Tensor<T> operator+=(const Tensor<T> &t) {
        data += t.data;
        return *this;
    }

    Tensor<T> operator-=(const Tensor<T> &t) {
        data -= t.data;
        return *this;
    }

    Tensor<T> operator*=(const Tensor<T> &t) {
        data *= t.data;
        return *this;
    }

    Tensor<T> operator/=(const Tensor<T> &t) {
        data /= t.data;
        return *this;
    }

    Tensor<T> operator+(const Tensor<T> &t) {
        return Tensor<T>(data + t.data);
    }

    Tensor<T> operator-(const Tensor<T> &t) {
        return Tensor<T>(data - t.data);
    }

    Tensor<T> operator*(const Tensor<T> &t) {
        return Tensor<T>(data * t.data);
    }

    Tensor<T> operator/(const Tensor<T> &t) {
        return Tensor<T>(data / t.data);
    }

    Tensor<T> operator-() {
        return Tensor<T>(-data);
    }

    Tensor<T> operator=(T x) {
        data = x;
        return *this;
    }

    operator T() {
        return data;
    }

    operator T() const {
        return data;
    }

    size_t dimens() const {
        return 0;
    }

    size_t size() const {
        return 0;
    }
};

template<class T>
std::ostream &operator<<(std::ostream &out, const Tensor<T> &t) {
    out << t.data << ' ';
    return out;
}

template<class T>
std::istream &operator>>(std::istream &in, Tensor<T> &t) {
    in >> t.data;
    return in;
}

template<class T, size_t len, size_t... sizes>
struct Tensor<T, len, sizes...> {
    Tensor<T, sizes...> data[len];
    static constexpr size_t n = len;
    static constexpr size_t dim = sizeof...(sizes) + 1;


    Tensor(T x) {
        for (auto &e: data) e = Tensor<T, sizes...>(x);
    }

    Tensor() {}

    void fill(T x = 0) {
        for (auto &e: data) e.fill(x);
    }

    Tensor<T, len, sizes...> operator+=(const T &x) {
        for (auto &e: data) e += x;
        return *this;
    }

    Tensor<T, len, sizes...> operator-=(const T &x) {
        for (auto &e: data) e -= x;
        return *this;
    }

    Tensor<T, len, sizes...> operator*=(const T &x) {
        for (auto &e: data) e *= x;
        return *this;
    }

    Tensor<T, len, sizes...> operator/=(const T &x) {
        for (auto &e: data) e /= x;
        return *this;
    }

    Tensor<T, len, sizes...> operator+(const T &x) {
        auto N = *this;
        return (N += x);
    }

    Tensor<T, len, sizes...> operator-(const T &x) {
        auto N = *this;
        return (N -= x);
    }

    Tensor<T, len, sizes...> operator*(const T &x) {
        auto N = *this;
        return (N *= x);
    }

    Tensor<T, sizes...> operator/(const T &x) {
        auto N = *this;
        return (N /= x);
    }

    Tensor<T, sizes...> &operator[](size_t i) {
        return data[i];
    }

    const Tensor<T, sizes...> &operator[](size_t i) const {
        return data[i];
    }

    Tensor<T, len, sizes...> operator+=(const Tensor<T, len, sizes...> &t) {
        for (size_t i = 0; i < len; ++i) {
            data[i] += t.data[i];
        }
        return *this;
    }

    Tensor<T, len, sizes...> operator-=(const Tensor<T, len, sizes...> &t) {
        for (size_t i = 0; i < len; ++i) {
            data[i] -= t.data[i];
        }
        return *this;
    }

    Tensor<T, len, sizes...> operator*=(const Tensor<T, len, sizes...> &t) {
        for (size_t i = 0; i < len; ++i) {
            data[i] *= t.data[i];
        }
        return *this;
    }

    Tensor<T, len, sizes...> operator/=(const Tensor<T, len, sizes...> &t) {
        for (size_t i = 0; i < len; ++i) {
            data[i] /= t.data[i];
        }
        return *this;
    }

    Tensor<T, len, sizes...> operator+(const Tensor<T, len, sizes...> &t) {
        auto N = *this;
        return (N += t);
    }

    Tensor<T, len, sizes...> operator-(const Tensor<T, len, sizes...> &t) {
        auto N = *this;
        return (N -= t);
    }

    Tensor<T, len, sizes...> operator*(const Tensor<T, len, sizes...> &t) {
        auto N = *this;
        return (N *= t);
    }

    Tensor<T, len, sizes...> operator/(const Tensor<T, len, sizes...> &t) {
        auto N = *this;
        return (N /= t);
    }

    Tensor<T, len, sizes...> operator-() {
        return (*this) * -1.;
    }

    size_t size() const {
        return len;
    }

    size_t dimens() const {
        return (sizeof...(sizes) + 1);
    }

    template<size_t from, size_t to>
    Tensor<T, to - from, sizes...> &subtensor() {
        static_assert(from < to && to <= n);
        return *reinterpret_cast<Tensor<T, to - from, sizes...> *>(&data[from]);
    }
};

template<class T, size_t len, size_t... sizes>
std::ostream &operator<<(std::ostream &out, const Tensor<T, len, sizes...> &t) {
    for (auto &e: t.data) {
        out << e << std::endl;
    }
    return out;
}

template<class T, size_t len, size_t... sizes>
std::istream &operator>>(std::istream &in, Tensor<T, len, sizes...> &t) {
    for (auto &e: t.data) in >> e;
    return in;
}

template<class T>
struct IsTensor {
    static constexpr bool value = false;
};

template<class T, size_t... dims>
struct IsTensor<Tensor<T, dims...>> {
    static constexpr bool value = true;
};

template<class T, size_t... dims>
struct IsTensor<const Tensor<T, dims...>> {
    static constexpr bool value = true;
};

template<class T>
concept CTensor = IsTensor<T>::value;

template<size_t n, size_t m, class T>
Tensor<T, m, n> Transposition(const Tensor<T, n, m> &t) {
    Tensor<T, m, n> res(0);
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            res[j][i] = t[i][j];
    return res;
}

template<class T, size_t len, size_t len0, size_t len1>
Tensor<T, len, len1> multy(const Tensor<T, len, len0> &t0, const Tensor<T, len0, len1> &t1) {
    Tensor<T, len, len1> res(0);
    for (size_t i = 0; i < len; ++i)
        for (size_t k = 0; k < len0; ++k)
            for (size_t j = 0; j < len1; ++j) {
                res[i][j] += t0[i][k] * t1[k][j];
            }
    return res;
}

template<class T>
void powInline(Tensor<T> &a, const Tensor<T> &b) {
    a = pow(a.data, b.data);
}

template<class T>
Tensor<T> pow(Tensor<T> &a, const Tensor<T> &b) {
    return Tensor<T>(pow(a, b));
}

template<class T, size_t len, size_t... sizes>
void powInline(Tensor<T, len, sizes...> &a, const Tensor<T, len, sizes...> &b) {
    for (size_t i = 0; i < len; ++i) powInline(a[i], b[i]);
}

template<class T, size_t len, size_t... sizes>
Tensor<T, len, sizes...> pow(const Tensor<T, len, sizes...> &a, const Tensor<T, len, sizes...> &b) {
    auto N = a;
    powInline(N, b);
    return N;
}

#endif

