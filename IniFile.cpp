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

string IniFile::str()
{
    stringstream ss;
    for (auto it = m_sections.begin(); it != m_sections.end(); it++)
    {
        ss << "[" << it->first << "]" << std::endl;
        for (auto subIt = it->second.begin(); subIt != it->second.end(); subIt++)
        {
            ss << subIt->first << " = " << string(subIt->second) << std::endl;
        }
        ss << std::endl;
    }
    return ss.str();
}

IniFile::IniFile()
{
}

bool IniFile::load(const string &filename)
{
    m_filename = filename;
    // load 使用输入流
    ifstream ifs(filename);
    if (ifs.fail())
    {
        std::cout << "加载文件失败" << std::endl;
        return false;
    }
    // 开始读取内容
    string line;
    string section = "default";
    while (std::getline(ifs, line))
    {
        // trim两头
        // 读取测试
        std::cout << line << std::endl;
        trim(line);
        if (line == "")
            continue;
        if (line[0] == '[')
        {
            size_t pos = line.find_first_of(']');
            section = line.substr(1, pos - 1);
            trim(section);
            m_sections[section] = Section();
        }
        else
        {
            size_t pos = line.find_first_of('=');
            string key = line.substr(0, pos);
            trim(key);
            string value = line.substr(pos + 1);
            trim(value);
            m_sections[section][key] = value;
        }
    }

    ifs.close();
    return true;
}

bool IniFile::save(const string &filename)
{
    ofstream ofs(filename);
    if (ofs.fail())
    {
        std::cout << "加载文件失败" << std::endl;
        return false;
    }
    ofs << str();
    ofs.close();
    return true;
}

Value &IniFile::get(const string &section, const string &key)
{
    return m_sections[section][key];
}

Section &IniFile::operator[](const string &str)
{
    return m_sections[str];
}

void IniFile::trim(string &str)
{
    if (str.empty())
    {
        return;
    }

    // trim left
    /*     str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch)
                                            { return std::isspace(ch); }));
        // trim right
        str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch)
                               { return std::isspace(ch); })
                      .base(),
                  str.end()); */
    str.erase(0, str.find_first_not_of(" \r\n"));
    str.erase(str.find_last_not_of(" \r\n") + 1);
}

void IniFile::set(const string &section, const string &key, const Value &value)
{
    m_sections[section][key] = value;
}

bool IniFile::has(const string &section)
{
    return m_sections.find(section) != m_sections.end();
}

bool IniFile::has(const string &section, const string &key)
{
    auto it = m_sections.find(section);
    if (it == m_sections.end())
        return false;

    // auto subIt = m_sections[section].find(key);
    // return subIt != m_sections[section].end();

    return it->second.find(key) != it->second.end();
}

void IniFile::remove(const string &section)
{
    m_sections.erase(section);
}

void IniFile::remove(const string &section, const string &key)
{
    auto it = m_sections.find(section);
    if (it != m_sections.end())
    {
        it->second.erase(key);
    }
}

void IniFile::clear()
{
    m_sections.clear();
}

void IniFile::display()
{
    std::cout << str();
}