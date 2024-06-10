#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class MyString {
private:
    char* m_data;
    int m_length;

public:
    // 默认构造函数
    MyString() : m_data(nullptr), m_length(0) {}

    // 带参数的构造函数
    MyString(const char* str) 
    {
        m_length = std::strlen(str);
        m_data = new char[m_length + 1];
        std::strcpy(m_data, str);
    }

    // 拷贝构造函数
    MyString(const MyString& other) 
    {
        m_length = other.m_length;
        m_data = new char[m_length + 1];
        std::strcpy(m_data, other.m_data);
    }


    // 析构函数
    ~MyString() 
    {
        delete[] m_data;
    }

    // 获取字符串长度
    int length() const 
    {
        return m_length;
    }

    // 获取字符串内容 
    // 此函数以常量方式返回私有成员变量 m_data，即指向字符串内容的字符数组的指针。
    // 通过这种方式，外部代码可以获得字符串内容的只读访问权限。
    // 由于返回的指针是对私有成员变量的直接引用，
    // 因此需要将函数声明为常量成员函数（const）以确保可以在类的常量对象上调用它。
    const char* c_str() const 
    {
        return m_data;
    }

    // 重载赋值运算符
    MyString& operator=(const MyString& other) 
    {
        if (this != &other) {
            delete[] m_data;
            m_length = other.m_length;
            m_data = new char[m_length + 1];
            std::strcpy(m_data, other.m_data);
        }
        return *this;
    }

    // 重载索引运算符
    char& operator[](int index) 
    {
        return m_data[index];
    }

    // 重载相等运算符
    bool operator==(const MyString& other) const 
    {
        return (std::strcmp(m_data, other.m_data) == 0);
    }

    // 重载不等运算符
    bool operator!=(const MyString& other) const 
    {
        return !(*this == other);
    }

    // 重载加法运算符
    MyString operator+(const MyString& other) const 
    {
        int newLength = m_length + other.m_length;
        char* newData = new char[newLength + 1];

        std::strcpy(newData, m_data);
        std::strcat(newData, other.m_data);

        MyString result(newData);
        delete[] newData;

        return result;
    }

    // 重载加等运算符
    MyString& operator+=(const MyString& other) 
    {
        *this = *this + other;
        return *this;
    }
};

int main123() 
{
    MyString str1("Hello");
    std::cout << "str1: " << str1.c_str() << ", length: " << str1.length() << std::endl;

    MyString str2 = str1;
    std::cout << "str2: " << str2.c_str() << ", length: " << str2.length() << std::endl;

    MyString str3;
    str3 = str1;
    std::cout << "str3: " << str3.c_str() << ", length: " << str3.length() << std::endl;

    //获取字符串内容
    const char* cString = str1.c_str();
    std::cout << "String: " << cString << std::endl;

    // 索引访问
    std::cout << "str1[0]: " << str1[0] << std::endl;

    // 重载相等运算符
    std::cout << "str1 == str2: " << (str1 == str2) << std::endl;
    std::cout << "str1 != str2: " << (str1 != str2) << std::endl;

    // 重载加法运算符
    MyString concat = str1 + str2;
    std::cout << "concat: " << concat.c_str() << ", length: " << concat.length() << std::endl;

    // 重载加等运算符
    MyString added = " World!";
    concat += added;
    std::cout << "concat: " << concat.c_str() << ", length: " << concat.length() << std::endl;

    return 0;
}