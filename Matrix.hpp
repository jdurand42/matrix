#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include "Vector.hpp"

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

        void reshape()
        {
            //  Work in progress
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

template<typename T=float>
Matrix<T> lerp(const Matrix<T> &u, const Matrix<T> &v, const float &t)
{
    return u + ((v - u) * t);
}

#endif