
#pragma once

#include <handy/config.hpp>
#include <vector>
#include <functional>

namespace bq {

// Extend of functionality of std::vector
template <typename T>
class vector : public std::vector<T>
{
public:
    typedef typename std::vector<T> vector_t;
    
    vector() = default;
    vector(std::size_t initSize) : vector_t(initSize) {}

    // append value to vector and return its index
    std::size_t append(const T& val) {
        vector_t::push_back(val);
        return vector_t::size() - 1;    // return index
    }

    // find a value, return iterator
    typename vector_t::iterator find(const T &val) {
        return std::find(vector_t::begin(), vector_t::end(), val);
    }
    
    // try to find value. result is iterator to value. returns true if found
    bool tryFind(const T &val, typename vector_t::iterator &result) {
        result = find(val);
        return result != vector_t::end();
    }
    
    // get index of value. -1 if not found
    int indexOf(const T& val) {
        auto it = find(val);
        return it == vector_t::end() ? -1 : std::distance(vector_t::begin(), it);
    }
    
    // iterate over elements. F -> void(T&)
    template <typename F>
    void foreach(const F& fn) {
        for (auto&& it : *this)
            fn(it);
    }

    // iterate over elements with index. F -> void(T&, int)
    template <typename F>
    void foreachi(const F& fn) {
        int i(0);
        for (auto&& it : *this)
            fn(it, i++);
    }

    // remove element by value
    void remove(const T& val) {
        typename vector_t::iterator it;
        if (tryFind(val, it))
            vector_t::erase(it);
    }
    
    // remove element at index, swapping in last element
    void remove_index_swap(std::size_t index) {
        const std::size_t sz = vector_t::size();
        if (index < sz-1)
            (*this)[index] = (*this)[sz - 1];   // Swap last item into index.
        vector_t::pop_back(); // size--
    }

    // find and remove element, swapping in last element
    void remove_swap(const T &val) {
        auto it = find(val);
        BQ_ASSERT(it != this->end());
        remove_index_swap(std::distance(vector_t::begin(), it));
    }
};
    
} // namespace bq

