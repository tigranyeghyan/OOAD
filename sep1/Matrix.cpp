#include <iostream>
#include "Matrix.h"

Matrix::Matrix() : rows_ {0}, cols_ {0}, data_ {nullptr}
{
	std::cout << "Default Constructor:" << std::endl;
}

Matrix::Matrix(size_t row, size_t col, double** data) : rows_ {row}, cols_ {col}, data_ {data} 
{
	data_ = new double*[rows_];
	for(int i = 0; i < rows_; ++i)
	{
		data_[i] = new double[cols_];
	}
	std::cout << "Parametrized constructor:" << std::endl;
}

Matrix::Matrix(const Matrix& obj) 
{
	rows_ = obj.rows_;
	cols_ = obj.cols_;
	data_ = new double*[rows_];
	for(int i = 0; i < rows_; ++i)
	{
		data_[i] = new double[cols_];
	}
	for(int i = 0; i < rows_; ++i)
	{
		for(int j = 0; j < cols_; ++j)
		{
			data_[i][j] = obj.data_[i][j];
		}
	}
	std::cout << "Copy Constructor:" << std::endl;
}

Matrix::Matrix(Matrix&& obj)
{
	rows_ = obj.rows_;
	cols_ = obj.cols_;
	data_ = obj.data_;
	obj.rows_ = 0;
	obj.cols_ = 0;
	obj.data_ = nullptr;
	std::cout << "Move Constructor:" << std::endl;
}	

Matrix& Matrix::operator=(const Matrix& obj)
{
	if(this == &obj)
	{
		return *this;
	}

	for(int i = 0; i < rows_; ++i)
	{
		delete[]data_[i];
	}
	delete []data_;
	
	rows_ = obj.rows_;
	cols_ = obj.cols_;

	data_ = new double*[rows_];
	for(int i = 0; i < rows_; ++i)
	{
		data_[i] = new double[cols_];
	}

	for(int i = 0; i < rows_; ++i)
	{
		for(int j = 0; j < cols_; ++j)
		{
			data_[i][j] = obj.data_[i][j];
		}
	}
	std::cout << "Copy Assignment operator:" << std::endl;
	return *this;
}

Matrix& Matrix::operator=(Matrix&& obj)
{
	for(int i = 0; i < rows_; ++i)
	{
		delete[]data_[i];
	}
	delete []data_;

	rows_ = obj.rows_;
	cols_ = obj.cols_;
	data_ = obj.data_;
	
	obj.rows_ = 0;
	obj.cols_ = 0;
	obj.data_ = nullptr;

	return *this;
	std::cout << "Move Assignment operator:" << std::endl;
}

Matrix::~Matrix()
{
	if(data_ != nullptr)
	{
		for(int i = 0; i < rows_; ++i)
		{
			delete[]data_[i];
		}
		delete []data_;
		data_ = nullptr;
	}
}

void Matrix::fill(size_t row, size_t col)
{
	if(rows_ == 0 && cols_ == 0)
	{
		rows_ = row;
		cols_ = col;
	}
	if(data_ == nullptr)
	{
		data_ = new double*[rows_];
		for(int i = 0; i < rows_; ++i)
		{
			data_[i] = new double[cols_];
		}
	}
	else
	{
		for(int i = 0; i < rows_; ++i)
		{
			delete []data_[i];
		}
		delete []data_;
		data_ = new double*[rows_];
		for(int i = 0; i < rows_; ++i)
		{
			data_[i] = new double[cols_];
		}
	}

	for(int i = 0; i < rows_; ++i)
	{
		for(int j = 0; j < cols_; ++j)
		{
			data_[i][j] = rand() % 10; 
		}
	}
}

void Matrix::set(size_t row, size_t col, double value)
{
	if ((row >= 0 && row < rows_) && (col >= 0 && col < cols_))
	{
		data_[row][col] = value;
	}
}

double Matrix::get(size_t row, size_t col) const
{
	if ((row >= 0 && row < rows_) && (col >= 0 && col < cols_))
	{
		return data_[row][col];
	}
	else
	{
		return -1;
	}
}

size_t Matrix::getRows() const 
{
	return rows_;
}

size_t Matrix::getCols() const 
{
	return cols_;
}

void Matrix::print() const
{
	if(data_ != nullptr)
	{
		for(int i = 0; i < rows_; ++i)
		{
			for(int j = 0; j < cols_; ++j)
			{
				std::cout << data_[i][j] << " "; 
			}
			std::cout << std::endl;
		}
	}
}
