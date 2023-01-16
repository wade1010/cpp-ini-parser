#include "IniFile.h"
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>

Value::Value() {}

Value::Value(bool value)
{
    // if (value)
    // {
    //     m_value = "true";
    // }
    // else
    // {
    //     m_value = "false";
    // }

    m_value = value ? "true" : "false";
}

Value::Value(int value)
{
    stringstream ss;
    ss << value;
    m_value = ss.str();
}

Value::Value(double value)
{
    stringstream ss;
    ss << value;
    m_value = ss.str();
}

Value::Value(const char *value) : m_value(value)
{
}

Value::Value(const string &value) : m_value(value)
{
}

Value &Value::operator=(bool value)
{
    m_value = value ? "true" : "false";
    return *this;
}
Value &Value::operator=(int value)
{
    stringstream ss;
    ss << value;
    m_value = ss.str();
    return *this;
}
Value &Value::operator=(double value)
{
    stringstream ss;
    ss << value;
    m_value = ss.str();
    return *this;
}
Value &Value::operator=(const char *value)
{
    m_value = value;
    return *this;
}
Value &Value::operator=(const string &value)
{
    m_value = value;
    return *this;
}

Value::operator bool()
{
    return m_value == "true";
}
Value::operator int()
{
    return std::atoi(m_value.c_str());
}
Value::operator double()
{
    return std::atof(m_value.c_str());
}
Value::operator string()
{
    return m_value;
}

IniFile::IniFile()
{
}

bool IniFile::load(const string &filename)
{
    // load 使用输入流
    ifstream ifs(filename);
    if (ifs.fail())
    {
        std::cout << "加载文件失败" << std::endl;
        return false;
    }
    // 开始读取内容
    string line;
    while (std::getline(ifs, line))
    {
        // trim两头
        // 读取测试
        std::cout << line << std::endl;
        if (line == "")
            continue;
    }

    ifs.close();
    return true;
}

void IniFile::trim(string &str)
{
    // trim left
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch)
                                        { return std::isspace(ch); }));
}
