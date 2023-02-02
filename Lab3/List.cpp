template <typename T>
class List
{
private: 
	int size;

public:
	virtual int Size()
	{
		return size;
	}
	virtual void Push_back() = 0;
	virtual void Pop_Back() = 0;
	virtual void Clear() = 0;
	virtual void Set(int pos, T data) = 0;
	virtual void Print();
	virtual bool Empty()
	{
		if (!size) return true;
		else
			false;
	}
};