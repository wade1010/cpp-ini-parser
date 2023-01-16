#include "IniFile.h"
#include <sstream>

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