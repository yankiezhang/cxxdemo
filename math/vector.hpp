//
//  vector.h
//  cxxdemo
//
//  Created by Yang Zhang on 2023/1/5.
//

#ifndef vector_hpp
#define vector_hpp

#include "basic_vector.hpp"

namespace  zy {

template <class Type, int Size>
class vector : public basic_vector<Type, Size> {
        
    friend std::ostream& operator<<(std::ostream& out, const vector<Type, Size>& v) {
        for (int i=0; i<Size; i++) {
            out << v[i] << ' ';
        }
        return out;
    }

public:
    
};

void TEST_VECTOR() {
    vector<int, 10> v;
    std::cout << v << std::endl;
}

}

#endif /* vector_hpp */
