#include <iostream>
#include <vector>

class Vector {
public:
    Vector(std::vector<double> vec) : data(vec), size(vec.size()) {}

    int size() const { return size; }

    void print() {
        for (auto x : data) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    double operator[](int i) const {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Vector index out of range");
        }
        return data[i];
    }

    double &operator[](int i) {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Vector index out of range");
        }
        return data[i];
    }

    Vector operator+(const Vector &v) {
        if (size != v.size) {
            throw std::invalid_argument("Vectors have different sizes");
        }

        Vector res(size);
        for (int i = 0; i < size; i++) {
            res[i] = data[i] + v[i];
        }
        return res;
    }

    Vector operator-(const Vector &v) {
        if (size != v.size) {
            throw std::invalid_argument("Vectors have different sizes");
        }

        Vector res(size);
        for (int i = 0; i < size; i++) {
            res[i] = data[i] - v[i];
        }
        return res;
    }

    Vector operator*(double k) {
        Vector res(size);
        for (int i = 0; i < size; i++) {
            res[i] = data[i] * k;
        }
        return res;
    }

private:
    std::vector<double> data;
    int size;
};


#include <iostream>
#include <vector>

class Matrix {
public:
    Matrix(int rows, int cols) : data(rows, std::vector<double>(cols)), rows(rows), cols(cols) {}

    int num_rows() const { return rows; }
    int num_cols() const { return cols; }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    double operator()(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw std::out_of_range("Matrix index out of range");
        }
        return data[i][j];
    }

    double &operator()(int i, int j) {
       

// 
// 
// 

#include <vector>
#include <iostream>

class Vector {
    public:
        Vector(std::vector<double> vec) {
            data = vec;
            size = vec.size();
        }

        int size() {
            return size;
        }

        void print() {
            for (auto x : data) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }

        void reshape(int m, int n) {
            // TODO: reshape logic
        }

        double operator[](int i) {
            return data[i];
        }

        Vector operator+(Vector v) {
            std::vector<double> result;
            for (int i = 0; i < size; i++) {
                result.push_back(data[i] + v[i]);
            }
            return Vector(result);
        }

        Vector operator-(Vector v) {
            std::vector<double> result;
            for (int i = 0; i < size; i++) {
                result.push_back(data[i] - v[i]);
            }
            return Vector(result);
        }

        Vector operator*(double k) {
            std::vector<double> result;
            for (int i = 0; i < size; i++) {
                result.push_back(data[i] * k);
            }
            return Vector(result);
        }

        double sum() {
            double result = 0;
            for (auto x : data) {
                result += x;
            }
            return result;
        }

        double max() {
            double result = data[0];
            for (auto x : data) {
                if (x > result) {
                    result = x;
                }
            }
            return result;
        }

        double dot(Vector v) {
            double result = 0;
            for (int i = 0; i < size; i++) {
                result += data[i] * v[i];
            }
            return result;
        }

    private:
        std::vector<double> data;
        int size;
};

class Matrix {
    public:
        Matrix(std::vector<std::vector<double>> mat) {
            data = mat;
            rows = mat.size();
            cols = mat[0].size();
        }

        int rows;
        int cols;

        void print() {
            for (auto row : data) {
                for (auto x : row) {
                    std::cout << x << " ";
                }
                std::cout << std::endl;
            }
        }

        Matrix operator+(Matrix m) {
            std::vector<std::vector<double>> result;
            for (int i = 0; i < rows; i++) {
                std::vector<double> row;
                for (int j = 0; j < cols; j++) {
                    row.push_back(data[i][j] + m.data[i][j]);
                }
                result.push_back(
