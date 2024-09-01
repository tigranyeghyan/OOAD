#pragma once

class Matrix
{
public:
	Matrix();
	Matrix(size_t, size_t, double** data = nullptr);
	Matrix(const Matrix&);
	Matrix(Matrix&&);
	Matrix& operator=(const Matrix&);
	Matrix& operator=(Matrix&&);
	~Matrix();
	void fill(size_t col = 3 , size_t row = 3);
	void set(size_t, size_t, double);
	double get(size_t, size_t) const;
	size_t getRows() const;
	size_t getCols() const;
	void print() const;
private:
	size_t rows_;
	size_t cols_;
	double** data_;
};
