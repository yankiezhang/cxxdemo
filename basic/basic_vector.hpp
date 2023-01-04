//
//  basic_vector.h
//  cxxdemo
//
//  Created by Yang Zhang on 2023/1/4.
//

#ifndef basic_vector_hpp
#define basic_vector_hpp

#include <iostream>
#include <string.h>

namespace zy {

template <typename Type, int Size>
class basic_vector {
    
    template <typename U, int R, int C> friend class basic_matrix;
        
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
    
    const basic_vector<Type, Size>& operator+=(const basic_vector<Type, Size>& v) {
        for (int i=0; i<Size; i++) {
            _array[i] += v[i];
        }
    }
    
    const basic_vector<Type, Size>& operator-=(const basic_vector<Type, Size>& v) {
        for (int i=0; i<Size; i++) {
            _array[i] -= v[i];
        }
    }
    
    
private:
    Type _array[Size];
};

}

#endif /* basic_vector_hpp */
