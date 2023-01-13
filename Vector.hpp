#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <sstream>

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
            this->_data = std::vector<T>(0, 0);
        };

        Vector(const int size)
        {
            _size = size;
            this->_data = std::vector<T>(size, 0);
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

        void reshape()
        {
            //  Work in progress
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
            std::vector<T> r(_size, 0);
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
};

template<typename T>
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


#endif