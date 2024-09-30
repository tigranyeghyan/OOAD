#pragma once

template <typename T>
class ControlBlock;

template <typename T>
class Shared_ptr {
public:
	Shared_ptr() : ptr {nullptr}, cptr {nullptr}
	{
		std::cout << "Default Ctor Shared_ptr" << std::endl;
	}
    
	explicit Shared_ptr(T* p) : ptr {p}, cptr {new ControlBlock<T>()} 
	{
		std::cout << "Parametrized Ctor Shared_ptr" << std::endl;
	}
	
	Shared_ptr(const Shared_ptr<T>& other) : ptr {other.ptr}, cptr {other.cptr}
	{
		std::cout << "Copy Ctor Shared_ptr" << std::endl;
        	if (cptr) 
		{
            		cptr -> add_reference();
        	}
    	}
    
	Shared_ptr(Shared_ptr<T>&& other) noexcept : ptr {other.ptr}, cptr {other.cptr} 
	{
		std::cout << "Move Ctor Shared_ptr" << std::endl;
		other.ptr = nullptr;
		other.cptr = nullptr;
	}

	~Shared_ptr() 
	{
		std::cout << "Dtor Shared_ptr" << std::endl;
       		if (cptr) 
		{
          		if (cptr -> getReferenceCount() == 0) 
			{
           			delete ptr;                
				ptr = nullptr;
           		}
	        	cptr -> release();
			cptr = nullptr;
        	}
    	}

    	Shared_ptr<T>& operator=(const Shared_ptr<T>& other) 
	{
		std::cout << "Copy Assignment Shared_ptr" << std::endl;
        	if (this != &other) 
		{
			if (cptr) 
			{
           			cptr -> release();
            			if (cptr -> getReferenceCount == 0) 
				{
               				delete ptr;                
					ptr = nullptr;
            			}
            			cptr = nullptr;
        		}
			ptr = other.ptr;
            		cptr = other.cptr;
            		other.ptr = nullptr;
			other.cptr = nullptr;
        	}
        	return *this;
    	}
    	
	Shared_ptr<T>& operator=(Shared_ptr<T>&& other) 
	{
		std::cout << "Move Assignment Shared_ptr" << std::endl;
        	if (this != &other) 
		{
			if (cptr) 
			{
           			cptr -> release();
            			if (cptr -> getReferenceCount() == 0) 
				{
               				delete ptr;                
					ptr = nullptr;
            			}
            			cptr = nullptr;
        		}
            		ptr = other.ptr;
            		cptr = other.cptr;
            		if (cptr) 
			{
                		cptr -> add_reference();
            		}
        	}
        	return *this;
    	}
    	
	T& operator*() const 
	{
        	return *ptr;
    	}

    	T* operator->() const 
	{
        	return ptr;
    	}

    	unsigned use_count() const 
	{
        	return cptr ? cptr -> getReferenceCount : 0;
    	}

private:
	T* ptr;
    	ControlBlock<T>* cptr;
};


template <typename T>
class ControlBlock 
{
private:
    	unsigned int ReferenceCount;
public:
  	ControlBlock() : ReferenceCount {1} { }

    	void add_reference() 
	{
        	++ReferenceCount;
    	}
	unsigned int getReferenceCount() const
	{
		return ReferenceCount;
	}
	void release() 
	{
        	--ReferenceCount;
       		if (ReferenceCount == 0) 
		{
            		delete this;
        	}
    	}
};
