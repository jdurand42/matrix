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

        // Matrix(const int *shape)
        // {
        //     this->_data = std::vector<Vector<T>>(shape[0], shape[1]);
        //     _shape[0] = shape[0];
        //     _shape[1] = shape[1];
        // };

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
                throw std::out_of_range("Vector index out of range");
            return _data[i];
        };

        const Vector<T>& operator[](int i) const
        {
            if (i < 0 || i >= _shape[0])
                throw std::out_of_range("Vector index out of range");
            return _data[i];
        };

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