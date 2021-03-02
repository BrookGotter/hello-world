#include <stdio.h>

/*
int GetMax(int param1,int param2)
{
	return param1>param2? param1:param2;
}

char GetMax(char param1,char param2)
{
	return param1>param2? param1:param2;
}
*/

/*
两个重载函数仅仅是处理的数据类型不同，参数的个数
法都相同，可以用一个函数模板统一起来
注意：
1、形式类型参数列表中的参数个数与名称可以
任意，但是调用的时候，实际类型参数个数必
须与形式列表匹配；
2、函数的定义与实现，可以使用任何已知的数
据类型，也可以使用形式类型参数列表中的类型，
但是不能随意使用未知的类型。
*/
template <typename T>
T GetMax(T param1,T param2)
{
	return param1>param2? param1:param2;
}

class CB
{
public:
	int m_i;
	CB(int i):m_i(i)
	{}
	//只要类CB重载了>运算符，则
	//CB的对象也可以作为参数调用GetMax模板
	bool operator>(const CB &o2)
	{
		return m_i>o2.m_i;
	}
};

class CC{
	
};

int main()
{
	char c1='a',c2='z';
	int i1=1,i2=2;
	int iRet=GetMax<int>(i1,i2);
	CB b1(1),b2(2);
	CB bRet=GetMax<CB>(b1,b2);
	//也可以直接这么写：
	bRet=GetMax(b1,b2);
	/*
	对于模板的使用过程可以这么理解：

	第一步：
	将函数模板照抄下来
	template <typename T>
	T GetMax(T param1,T param2)
	{
		return param1>param2? param1:param2;
	}
	第二步：
	用实际类型替换形式类型
	template <typename int>
	T GetMax(T param1,T param2)
	{
		return param1>param2? param1:param2;
	}
	第三步：
	将函数定义与函数实现中所有的形式类型用实际
	类型替换.
	template <typename int>
	int GetMax(int param1,int param2)
	{
		return param1>param2? param1:param2;
	}
	第四步：
	去掉函数模板定义的关键字和类型参数列表，
	只保留替换后的函数定义
	int GetMax(int param1,int param2)
	{
		return param1>param2? param1:param2;
	}
	第五步：
	用普通的函数调用方式，调用前四步生成的函数。
	*/
	return 0;
}