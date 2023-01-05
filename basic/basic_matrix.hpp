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

void TEST_BASIC_MATRIX();

template <typename Type, int Row, int Col>
class basic_matrix {
    
    friend void TEST_BASIC_MATRIX() {
        basic_matrix<int, 10, 10> m(1);
        basic_matrix<int, 10, 10> n(-1);
        
        m += n;
        
        for (int i=0; i<Row; i++) {
            for (int j=0; j<Col; j++)
                std::cout << m[i][j] << ' ';
            std::cout << std::endl;
        }
    }
    
public:
    basic_matrix(Type const& m=0) {
        for (int i=0; i<Row; i++) {
            _vectors[i] = m;
        }
    }
    
    const basic_vector<Type, Col>& operator[](int i) const { return _vectors[i]; }
    
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
