#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include "Vector.hpp"

template <typename T>
class Vector;

template <typename T=float>
class Matrix
{
    public:
        typedef T value_type;
    
    public:
        Matrix()
        {
            _shape[0] = 0;
            _shape[1] = 0;
            this->_data = std::vector<Vector<T>>(0); 
        }

        Matrix(std::initializer_list<Vector<T>> l)
        {
            _shape[0] = l.size();
            this->_data = std::vector<Vector<T>>(l);
            _check_data_validity();
            _shape[1] = _data[0].size();
        };
        
        Matrix(const int& m, const int& n)
        {
            _shape[0] = m;
            _shape[1] = n;
            for (int i = 0; i < m; i++)
                _data.push_back(Vector<T>(n));
        }

        Matrix(std::initializer_list<std::initializer_list<T>> l)
        {
            _shape[0] = l.size();
            long unsigned int len = 0;
            if (l.size() == 0)
                throw std::invalid_argument("Invalid argument, vectors must be of the same shape");
            this->_data = std::vector<Vector<T>>(_shape[0]);

            typename std::initializer_list<std::initializer_list<T>>::iterator it;
            it = l.begin();
            typename std::initializer_list<std::initializer_list<T>>::iterator end;
            end = l.end();

            len = it->size();

            for (int i = 0; it != end; it++, i++)
            {
                if (len != it->size())
                    throw std::invalid_argument("Invalid argument, vectors must be of the same shape");
                _data[i] = Vector<T>(*it);
            }
            _shape[1] = len;
        };
        
        Matrix(const Matrix& m)
        {
            _shape[0] = m._shape[0];
            _shape[1] = m._shape[1];
            this->_data = m._data;
        };
        
        Matrix(const std::vector<Vector<T>>& data)
        {
            _shape[0] = data.size();
            _shape[1] = data[0].size();
            this->_data = data;
            _check_data_validity();
        };

        // Basics

        const int *shape() const
        {
            return _shape;
        }

        // reshape mat into vector
        Vector<T> reshape() const
        {
            std::vector<T> v;
            for (int i = 0; i < _shape[0]; i++)
                for (int j = 0; j < _shape[1]; j++)
                    v.push_back(_data[i][j]);
            return Vector<T>(v);
        };

        bool issquare() const
        {
            if (_shape[0] == _shape[1])
                return true;
            return false;
        }

        void print() const
        {
            std::cout << "[";
            int size = _shape[0];
            for (int i = 0; i < size; i++)
            {
                std::cout << _data[i];
                if (i < size - 1)
                    std::cout << "," << std::endl;
            }
            std::cout << "]";
        }

        // ex00

        void add(const Matrix &v)
        {
            *this += v;
        } 
        void sub(const Matrix &v)
        {
            *this -= v;
        } 
        void scl(const float &k)
        {
            *this *= k;
        } 

        // Operators

        void operator = (const Matrix &m)
        {
            _shape[0] = m._shape[0];
            _shape[1] = m._shape[1];
            _data = m._data;
        };

        bool operator == (const Matrix &m) const
        {
            if (_shape[0] != m._shape[0] || _shape[1] != m._shape[1])
                return false;
            for (int i = 0; i < _shape[0]; i++)
            {
                if (_data[i] != m._data[i])
                    return false;
            }
            return true;
        };


        bool operator != (const Matrix &m) const
        {
            return !(*this == m);
        };

        Vector<T>& operator[](int i)
        {
            if (i < 0 || i >= _shape[0])
                throw std::out_of_range("Matrix index out of range");
            return _data[i];
        };

        const Vector<T>& operator[](int i) const
        {
            if (i < 0 || i >= _shape[0])
                throw std::out_of_range("Matrix index out of range");
            return _data[i];
        };

        Matrix operator + (const Matrix &m) const
        {
            this->_check_compatibility(m);
            std::vector<Vector<T>> r(_shape[0]);
            for (int i = 0; i < _shape[0]; i++)
            {
                r[i] = _data[i] + m._data[i];
            }
            return Matrix(r);
        }

        void operator += (const Matrix &m)
        {
            _check_compatibility(m);
            // std::vector<Vector<T>> r(_shape[0], 0);
            for (int i = 0; i < _shape[0]; i++)
            {
                _data[i] += m._data[i];
            }
        }

        Matrix operator - (const Matrix &m) const
        {
            _check_compatibility(m);
            std::vector<Vector<T>> r(_shape[0]);
            for (int i = 0; i < _shape[0]; i++)
            {
                r[i] = _data[i] - m._data[i];
            }
            return Matrix(r);
        }

        void operator -= (const Matrix &m)
        {
            _check_compatibility(m);
            for (int i = 0; i < _shape[0]; i++)
            {
                _data[i] -= m._data[i];
            }
        }

        Matrix operator * (const float &k) const
        {
            std::vector<Vector<T>> r(_shape[0], 0);
            for (int i = 0; i < _shape[0]; i++)
            {
                r[i] = _data[i] * k;
            }
            return Matrix(r);
        }
        
        void operator *= (const float &k)
        {
            // _check_compatibility(v);
            for (int i = 0; i < _shape[0]; i++)
            {
                _data[i] *= k;
            }
        }

        // ex07

        Matrix operator * (const Matrix& m) const
        {
            Matrix<T> r(_shape[0], m._shape[1]);
            for (int i = 0; i < r._shape[0]; i++)
                for (int j = 0; j < r._shape[1]; j++)
                    for (int k = 0; k < m._shape[0]; k++)
                        r._data[i][j] += (_data[i][k] * m[k][j]);
            return r;
        }

        Vector<T> operator * (const Vector<T>& v) const
        {
            Vector<T> r(_shape[0]);
            for (int i = 0; i < _shape[0]; i++)
                for (int j = 0; j < v.size(); j++)
                {
                    r[i] += (_data[i][j] * v[j]);
                }
            return r;
        }
        
        void operator *= (const Matrix& m)
        {
            *this = *this * m;
        }

        Matrix mul_mat(const Matrix& m) const
        {
            return *this * m;
        }

        Vector<T> mul_vec(const Vector<T>& v) const
        {
            return *this * v;
        }

        // ex08

        T trace() const
        {
            if (issquare() == false)
                throw std::invalid_argument("Trace: Cannot get trace of a non square matrix");
            
            T r = T();
            
            for (int i = 0; i < _shape[0]; i++)
                r += _data[i][i];
            return r;
        }

        Matrix row_echelon() const
        {
            Matrix<T> u(*this);
            int lead = 0;
            int m = u._shape[0];
            int n = u._shape[1];
            for (int r = 0; r < m; r++)
            {
                if (n <= lead)
                {
                    return u;
                }
                int i = r;
                while (u[i][lead] == 0)
                {
                    i++;
                    if (m == i)
                    {
                        i = r;
                        lead++;
                        if (n == lead) {
                            return u;
                        }
                    }
                }
                if (i != r)
                {
                    u._swap(i, r);
                }
                T div = u[r][lead];
                for (int j = 0; j < n; j++)
                {
                    u[r][j] /= div;
                }
                for (int j = 0; j < m; j++)
                {
                    if (j != r)
                    {
                        T sub = u[j][lead];
                        for (int k = 0; k < n; k++)
                        {
                            u[j][k] -= sub * u[r][k];
                        }
                    }
                }
                lead++;
            }
            return u;
        } 

        T determinant() const
        {
            if (!this->issquare())
                throw std::invalid_argument("Error: the matrix is not square, the determinant cannot be calculated");
            T det = 1;
            int n = this->_shape[0];
            Matrix<T> m(*this);
            for (int i = 0; i < n; i++)
            {
                int k = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (abs(m[j][i]) > abs(m[k][i]))
                    {
                        k = j;
                    }
                }
                if (k != i)
                {
                    m._swap(i, k);
                    det = -det;
                }
                if (m[i][i] == 0)
                {
                    return 0;
                }
                det *= m[i][i];
                for (int j = i + 1; j < n; j++)
                {
                    m[i][j] /= m[i][i];
                }
                for (int j = 0; j < n; j++)
                {
                    if (j != i && m[j][i] != 0)
                    {
                        for (int k = i + 1; k < n; k++)
                        {
                            m[j][k] -= m[i][k] * m[j][i];
                        }
                    }
                }
            }
            return det;
        }

        Matrix<T> inverse() const
        {
            // Concatenate matrix with its identity
            // Get row_echelon of produced matrix
            // extract righmost submatrix
            T det = this->determinant();
            if (det == 0) // is_singular
                throw std::invalid_argument("Error: the matrix is not invertible, the determinant is zero");
		    Matrix<T> res(_shape[0], _shape[0] * 2);
		    Matrix<T> inverse(_shape[0], _shape[0]);
		    for (int i = 0; i < res._shape[0]; i++)
		    {
		    	res[i][i + res._shape[0]] = (T)1;
		    	for (int j = 0; j < res._shape[0]; j++)
		    		res[i][j] = (*this)[i][j];
		    }
		    res = res.row_echelon();
                  
		    for (int i = 0; i < inverse._shape[0]; i++)
		    	for (int j = 0; j < inverse._shape[1]; j++)
		    		inverse[i][j] = res[i][j + res._shape[0]];
		    return (inverse);
        }

        int rank() const
        {
            // Matrix<T> m(*this);
            Matrix<T> m = this->row_echelon();
            int rank = 0;
            for (int i = 0; i < m.shape()[0]; i++)
            {
                for (int j = 0; j < m.shape()[1]; j++)
                {
                    if (m[i][j]!= T())
                    {
                        rank++;
                        break;
                    }
                }
            }
            return rank;
        }

        Matrix transpose() const
        {
            Matrix<T> t(_shape[1], _shape[0]);
            for (int i = 0; i < _shape[0]; i++)
            {
                for (int j =0; j < _shape[1]; j++)
                {
                    t[j][i] = _data[i][j];
                }
            }
            return t;
        }




        template<class u> friend std::ostream& operator << (std::ostream&, const Matrix<T>&);



    private:

        void _check_data_validity()
        {
            int len = 0;
            for (int i = 0; i < _shape[0]; i++)
            {
                if (i == 0)
                    len = _data[i].size();
                if (_data[i].size() != len)
                    throw std::invalid_argument("Invalid argument, vectors must be of the same shape");
            }
        }

        void _check_compatibility(const Matrix& m) const
        {
            if (_shape[0] != m._shape[0] || _shape[1] != m._shape[1])
                throw std::invalid_argument("Invalid argument, shapes must match");
        }

        void _swap(const int& i, const int& j)
        {
            Vector<T> t;
            t = _data[i];
            _data[i] = _data[j];
            _data[j] = t;
        }

        std::vector<Vector<T>> _data;
        int _shape[2];
};

template<typename T>
std::ostream& operator << (std::ostream& os, const Matrix<T>& m)
{
    os << "[";
    int size = m.shape()[0];
    for (int i = 0; i < size; i++)
    {
        os << m[i];
        if (i < size - 1)
            os << "," << std::endl;
    }
    os << "]";
    // os << std::endl;
    return os;
}

#endif