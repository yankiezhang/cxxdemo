//
//  matrix.h
//  cxxdemo
//
//  Created by Yang Zhang on 2023/1/5.
//

#ifndef matrix_hpp
#define matrix_hpp

#include "basic_matrix.hpp"
#include "vector.hpp"

namespace zy {

template <typename Type, int Row, int Col>
class matrix : public basic_matrix<Type, Row, Col> {
    
    friend std::ostream& operator<<(std::ostream& out, const matrix<Type, Row, Col>& m) {
        for (int i=0; i<Row; i++) {
            for (int j=0; j<Col; j++)
                out << m[i][j] << ' ';
            out << std::endl;
        }
        return out;
    }
    
public:
    using basic_matrix<Type, Row, Col>::basic_matrix;
};

void TEST_MATRIX()
{
    matrix<float, 10, 10> f(1.0);
    std::cout << f << std::endl;
}

}


#endif /* matrix_hpp */
