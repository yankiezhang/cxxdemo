//
//  basic_matrix.h
//  cxxdemo
//
//  Created by Yang Zhang on 2023/1/4.
//

#ifndef basic_matrix_hpp
#define basic_matrix_hpp

#include "basic_vector.hpp"

namespace zy {

template <typename Type, int Row, int Col>
class basic_matrix {
    
public:
    basic_matrix(Type const& m=0) {
        for (int i=0; i<Row; i++) {
            _vectors[i] = m;
        }
    }
    
    const Type (&operator[](int i) const)[Col] { return _vectors[i]._array; }
    
    const basic_matrix<Type, Row, Col>& operator+=(const basic_matrix<Type, Row, Col>& m) {
        for (int i=0; i<Row; i++) {
            _vectors[i] += m[i];
        }
        
        return *this;
    }
    
    const basic_matrix<Type, Row, Col>& operator-=(const basic_matrix<Type, Row, Col>& m) {
        for (int i=0; i<Row; i++) {
            _vectors[i] -= m[i];
        }
        
        return *this;
    }
    
private:
    basic_vector<Type, Col> _vectors[Row];
};

}

#endif /* basic_matrix_hpp */
