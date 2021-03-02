#include <stdio.h>

//类通常用于实例化对象，而类模板用于实例化类
template <class T>
class TA
{
public:
	T m_data;
	void SetData(const T &data);
};

template <class T>
void TA<T>::SetData(const T &data)
{
	m_data=data;
}

class CB
{

};

int main()
{
	TA<int> oi;
	/*
	TA<int>相当于实例化了一个如下的类：
	class TA_int
	{
	private:
		int m_data;
	};
	void TA_int::SetData(const int &data);
	{
		m_data=data;
	}
	*/

	oi.SetData(0);

	TA<CB> oc;
	/*
	TA<CB>相当于实例化了一个如下的类：
	class TA_CB
	{
	private:
		CB m_data;
	};
	void TA_CB::SetData(const CB &data);
	{
		m_data=data;
	}
	*/

	CB b;
	oc.SetData(b);
	return 0;
}