#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class MyString {
private:
    char* m_data;
    int m_length;

public:
    // Ĭ�Ϲ��캯��
    MyString() : m_data(nullptr), m_length(0) {}

    // �������Ĺ��캯��
    MyString(const char* str) 
    {
        m_length = std::strlen(str);
        m_data = new char[m_length + 1];
        std::strcpy(m_data, str);
    }

    // �������캯��
    MyString(const MyString& other) 
    {
        m_length = other.m_length;
        m_data = new char[m_length + 1];
        std::strcpy(m_data, other.m_data);
    }


    // ��������
    ~MyString() 
    {
        delete[] m_data;
    }

    // ��ȡ�ַ�������
    int length() const 
    {
        return m_length;
    }

    // ��ȡ�ַ������� 
    // �˺����Գ�����ʽ����˽�г�Ա���� m_data����ָ���ַ������ݵ��ַ������ָ�롣
    // ͨ�����ַ�ʽ���ⲿ������Ի���ַ������ݵ�ֻ������Ȩ�ޡ�
    // ���ڷ��ص�ָ���Ƕ�˽�г�Ա������ֱ�����ã�
    // �����Ҫ����������Ϊ������Ա������const����ȷ����������ĳ��������ϵ�������
    const char* c_str() const 
    {
        return m_data;
    }

    // ���ظ�ֵ�����
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

    // �������������
    char& operator[](int index) 
    {
        return m_data[index];
    }

    // ������������
    bool operator==(const MyString& other) const 
    {
        return (std::strcmp(m_data, other.m_data) == 0);
    }

    // ���ز��������
    bool operator!=(const MyString& other) const 
    {
        return !(*this == other);
    }

    // ���ؼӷ������
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

    // ���ؼӵ������
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

    //��ȡ�ַ�������
    const char* cString = str1.c_str();
    std::cout << "String: " << cString << std::endl;

    // ��������
    std::cout << "str1[0]: " << str1[0] << std::endl;

    // ������������
    std::cout << "str1 == str2: " << (str1 == str2) << std::endl;
    std::cout << "str1 != str2: " << (str1 != str2) << std::endl;

    // ���ؼӷ������
    MyString concat = str1 + str2;
    std::cout << "concat: " << concat.c_str() << ", length: " << concat.length() << std::endl;

    // ���ؼӵ������
    MyString added = " World!";
    concat += added;
    std::cout << "concat: " << concat.c_str() << ", length: " << concat.length() << std::endl;

    return 0;
}