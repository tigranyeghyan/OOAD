#pragma once

class IntArray
{
private:
	int* ptr;
	int m_cap;
public:
	IntArray();
	IntArray(int);
	IntArray(const IntArray&);
	IntArray(IntArray&&);
	IntArray& operator=(const IntArray&);
	IntArray& operator=(IntArray&&);   
	~IntArray();
};
