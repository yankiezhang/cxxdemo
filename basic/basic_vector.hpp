//
//  basic_vector.h
//  cxxdemo
//
//  Created by Yang Zhang on 2023/1/4.
//

#ifndef basic_vector_hpp
#define basic_vector_hpp

#include <string.h>

namespace zy {

void test();

template <typename Type, int Size>
class basic_vector {
    
    friend void test() {
        basic_vector<int, 10> a;
        basic_vector<int, 10> b(1);
        
        a = b;
    }
    
public:
    basic_vector(const Type& a = 0) {
        memset(_array, a, sizeof(_array));
    }
    
    basic_vector(const basic_vector<Type, Size>& v) {
        for (int i=0; i<Size; i++) {
            _array[i] = v[i];
        }
    }
    
    const Type& operator[](int i)const { return _array[i]; }
    const basic_vector<Type, Size>& operator=(const basic_vector<Type, Size>& v) {
        for (int i=0; i<Size; i++) {
            _array[i] = v[i];
        }
        return *this;
    }
    
    
private:
    Type _array[Size];
};

}

#endif /* basic_vector_hpp */
