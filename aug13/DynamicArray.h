class DynamicArray
{
private:
    	int* arr;
    	int size;
    	int capacity;
public:
    	DynamicArray();
    	DynamicArray(int setcapacity);
    	DynamicArray(const DynamicArray& other);
    	~DynamicArray();

    	void push(int num);
    	void display() const;
};
