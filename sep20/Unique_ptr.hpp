#pragma once

template <typename T> class Unique_ptr
{
public:
	Unique_ptr() noexcept;
	explicit Unique_ptr(T *tptr) noexcept;
	Unique_ptr(Unique_ptr&& other) noexcept;
	Unique_ptr& operator=(Unique_ptr&& other) noexcept;
	~Unique_ptr();
	T& operator*() const;
	T* operator->() const;

	Unique_ptr(const Unique_ptr&) = delete;
	Unique_ptr& operator=(const Unique_ptr&) = delete;
private:
	T *ptr;
};

template <typename T>
Unique_ptr<T>::Unique_ptr() noexcept : ptr(nullptr) 
{
}

template <typename T>
Unique_ptr<T>::Unique_ptr(T *tptr) noexcept : ptr(tptr) 
{
}

template <typename T>
Unique_ptr<T>::Unique_ptr(Unique_ptr&& other) noexcept : ptr(other.ptr) 
{
    other.ptr = nullptr;
}

template <typename T>
Unique_ptr<T>& Unique_ptr<T>::operator=(Unique_ptr&& other) noexcept 
{
    if (this != &other) 
    {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr; 
    }
    return *this;
}

template <typename T>
Unique_ptr<T>::~Unique_ptr()
{
	if(ptr != nullptr)
	{
		delete ptr;
	}
}

template <typename T>
T& Unique_ptr<T>::operator*() const 
{
    return *ptr;
}

template <typename T>
T* Unique_ptr<T>::operator->() const {
    return ptr;
}
