#pragma once
template <typename T>
class List
{
protected:
	int size = 0;

public:
	virtual int Size()
	{
		return size;
	}
	virtual void Push_back(T data) = 0;
	virtual void Pop_back() = 0;
	virtual void Clear() = 0;
	virtual void Set(int pos, T data) = 0;
	virtual void Print() = 0;
	virtual T Peek() = 0;
	virtual bool Empty()
	{
		if (!size) return true;
			return false;
	}
};