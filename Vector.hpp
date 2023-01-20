#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

#include "Matrix.hpp"

template <typename T>
class Matrix;

template <typename T=float>
class Vector
{
    public:
        typedef T value_type;
        // typedef 

    public:
        Vector()
        {
            _size = 0;
            this->_data = std::vector<T>(0, T());
        };

        Vector(const int size)
        {
            _size = size;
            this->_data = std::vector<T>(size, T());
        };

        Vector(std::initializer_list<T> l)
        {
            _size = l.size();
            this->_data = std::vector<T>(l);
        };
        
        Vector(const Vector& v)
        {
            _size = v._size;
            this->_data = v._data;
        };
        
        Vector(const std::vector<T>& data)
        {
            _size = data.size();
            // std::cout << _data.capacity() << std::endl; 
            this->_data = data;
        };

        ~Vector()
        {
            // delete _data
        };

        // Basics

        const int &size() const
        {
            return _size;
        };

        Matrix<T> reshape(const int& m, const int& n) const
        {
            // Reshape into a matrix
            if (m * n != _size)
                throw std::invalid_argument("Error: Cammpt reshape vector. m * n must be == size of vector");
            Matrix<T> r(m, n);
            int k = 0;

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    r[i][j] = _data[k];
                    k++; 
                }
            }
            return r;
        };

        void print() const
        {
            std::cout << "[";
            for (int i = 0; i < _size; i++)
            {
                std::cout << _data[i];
                if (i < _size - 1)
                    std::cout << ", ";
            }
            std::cout << "]";
            std::cout << std::endl;
        };

        // Operators

        T& operator[](int i)
        {
            if (i < 0 || i >= _size)
                throw std::out_of_range("Vector index out of range");
            return _data[i];
        };

        const T& operator[](int i) const
        {
            if (i < 0 || i >= _size)
                throw std::out_of_range("Vector index out of range");
            return _data[i];
        };

        void operator = (const Vector &v)
        {
            _size = v._size;
            _data = v._data;
        };

        bool operator == (const Vector &v) const
        {
            if (_size != v._size)
                return false;
            for (int i = 0; i < _size; i++)
            {
                if (_data[i] != v._data[i])
                    return false;
            }
            return true;
        };

        bool operator == (const std::vector<T> &v) const
        {
            if (_size != v.size())
                return false;
            for (int i = 0; i < _size; i++)
            {
                if (_data[i] != v[i])
                    return false;
            }
            return true;
        };

        bool operator != (const Vector &v) const
        {
            return !(*this == v);
        };
        
        bool operator != (const std::vector<T> &v) const
        {
            return !(*this == v);
        };

        Vector operator + (const Vector &v) const
        {
            _check_compatibility(v);
            std::vector<T> r(_size, T());
            for (int i = 0; i < _size; i++)
            {
                r[i] = _data[i] + v._data[i];
            }
            return Vector(r);
        }

        void operator += (const Vector &v)
        {
            _check_compatibility(v);
            // std::vector<T> r(_size, 0);
            for (int i = 0; i < _size; i++)
            {
                _data[i] += v._data[i];
            }
        }

        Vector operator - (const Vector &v) const
        {
            _check_compatibility(v);
            std::vector<T> r(_size, 0);
            for (int i = 0; i < _size; i++)
            {
                r[i] = _data[i] - v._data[i];
            }
            return Vector(r);
        }

        void operator -= (const Vector &v)
        {
            _check_compatibility(v);
            for (int i = 0; i < _size; i++)
            {
                _data[i] -= v._data[i];
            }
        }

        Vector operator * (const float &k) const
        {
            std::vector<T> r(_size, 0);
            for (int i = 0; i < _size; i++)
            {
                r[i] = _data[i] * k;
            }
            return Vector(r);
        }
        
        // Vector operator * (const int &k) const
        // {
            // _check_compatibility(v);
            // std::vector<T> r(_size, 0);
            // for (int i = 0; i < _size; i++)
            // {
                // r[i] = _data[i] * k;
            // }
            // return Vector(r);
        // }
        
        void operator *= (const float &k)
        {
            // _check_compatibility(v);
            for (int i = 0; i < _size; i++)
            {
                _data[i] *= k;
            }
        }
        
        // void operator *= (const int &k) const
        // {
        //     // _check_compatibility(v);
        //     for (int i = 0; i < _size; i++)
        //     {
        //         _data[i] *= k;
        //     }
        // }

        // ex00

        void add(const Vector &v)
        {
            *this += v;
        } 
        void sub(const Vector &v)
        {
            *this -= v;
        } 
        void scl(const float &k)
        {
            *this *= k;
        } 

        // ex03

        T dot(const Vector& v) const
        {
            float res = T();
            _check_compatibility(v);
            for (int i = 0; i < _size; i++)
            {
                res += _data[i] * v._data[i];
            }
            return res;
        }

        // Ex04

        float norm() const
        {
            float r = powf(dot(*this), 0.5);
            return r;
        }

        float norm_1() const
        {
            float r = 0;

            for (int i = 0; i < _size; i++)
            {
                r += this->abs(_data[i]);
            }
            return r; 
        }

        float norm_inf() const
        {
            float max = this->abs(_data[0]);

            for (int i = 0; i < _size; i++)
            {
                if (this->abs(_data[i]) > max)
                    max = this->abs(_data[i]);
            }
            return max;
        }

        // template<typename T=float>
        template<class u> friend std::ostream& operator << (std::ostream& os, const Vector<u>& v);

    private:
        std::vector<T> _data;
        int _size;

        void _check_compatibility(const Vector &v) const
        {
            // if (this->value_type != v.value_type)
                // throw std::invalid_argument("Vector must be of same type");
            if (_size != v._size)
            {
                throw std::invalid_argument("Vector must be of the same size");
                // exit(1);
            }
        }

        T abs(const T &n) const
        {
            if (n < 0)
                return -n;
            return n;
        }
};

template<typename T=float>
std::ostream& operator << (std::ostream& os, const Vector<T>& v)
{
    os << "[";
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        os << v[i];
        if (i < size - 1)
            os << ", ";
    }
    os << "]";
    // os << std::endl;
    return os;
}

template<typename T=float>
Vector<T> linear_combination(const std::vector<Vector<T>>& us, const std::vector<T> &ks)
{
    int len = us.size();
    if (len != (int)ks.size() || us.empty())
        throw std::invalid_argument("Invalid argument: Sizes must be equals");
    
    int size = us[0].size();

    Vector<T> r(size);

    for (int i = 0; i < size; i++) {
			for (int j = 0; j < len; j++) {
				r[i] += us[j][i] * ks[j];
			}
		}
    return r;
}

template<typename T=float>
T lerp(const T &u, const T &v, const float &t)
{
    return (u + ((v - u) * t));
}

template<typename T=float>
float angle_cos(const Vector<T>& u, const Vector<T>& v)
{
    return (u.dot(v) / (u.norm() * v.norm()));
}

template<typename T=float>
Vector<T> cross_product(const Vector<T>& u, const Vector<T>& v)
{
    // [(a2 * b3 – a3 * b2), (a3 * b1 – a1 * b3), (a1 * b2 – a2 * b1)]
    if (u.size() != 3 || v.size() != 3)
        throw std::invalid_argument("Cross product: u and v must be both 3D vectors");
    return Vector<T>({u[1] * v[2] - u[2] * v[1], \
    u[2] * v[0] - u[0] * v[2], \
    u[0] * v[1] - u[1] * v[0]});    
}

#endif