/*************************************************************************
    > File Name: Singleton.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年06月19日 星期六 21时30分59秒
 ************************************************************************/
template<typename T>
class Singleton
{
public:
	static T& Instance()
	{
		if (nullptr == value_)
			value_ = new T();

		return *value_;
	}

private:
	SingleTon();
	~SingleTon();

	static void init()
	{
		value_ new T();
	}

	static void destroy()
	{
		delete value_;
	}

private:
	static T* value_;
};

template<typename T>
T* Singleton<T>::value_ = nullptr;
