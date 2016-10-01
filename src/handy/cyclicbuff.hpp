
#pragma once

namespace bq {

template <typename T>
class CyclicBuffer
{
public:
    
    // TODO - iterators
    
    CyclicBuffer(std::size_t sz)
        :   buff_(sz)
        ,   front_(buff_.begin())
        ,   back_(buff_.begin())
        ,   count_(0)
    {}
    
    void push_back(const T& v) {
        if (count_ == buff_.size())
            pop_front();
        *back_ = v;
        ++back_;
        ++count_;
        if (back_ == buff_.end())
            back_ = buff_.begin();
    }
    
    void pop_front() {
        if (count_ > 0) {
            ++front_;
            --count_;
            if (front_ == buff_.end())
                front_ = buff_.begin();
        }
    }
    
    std::size_t size() const { return count_; }
    
    std::size_t offset() { return std::distance(buff_.begin(), front_); }
    
    const T* data() const { return buff_.data(); }
    
private:
    typedef std::vector<T> buff_t;
    typedef typename buff_t::iterator it_t;
    buff_t buff_;
    it_t front_, back_;
    uint32_t count_;
};

} // namespace bq
