#pragma once

#include <stdint.h>

namespace bq {
    
    namespace random {
        
        void init();
                
    } // namespace random
    
    uint32_t    rand();
    float       randf();                        // range: 0 -> 1
    
    // range: from -> to
    static inline float randf(float from, float to)
    {
        return randf() * (to - from) + from;
    }    

} // namespace bq
