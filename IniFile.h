#pragma once

#include <string>
#include <map>
using namespace std;
class Value
{
public:
    Value();
    Value(bool value);
    Value(int value);
    Value(double value);
    Value(const char *value);
    Value(const string &value);

    // 赋值运算符
    Value &operator=(bool value);
    Value &operator=(int value);
    Value &operator=(double value);
    Value &operator=(const char *value);
    Value &operator=(const string &value);

    // 转换运算符
    operator bool();
    operator int();
    operator double();
    operator string();

private:
    string m_value;
};

typedef std::map<string, Value> Section;

class IniFile
{
public:
    IniFile();
    string str();

    bool load(const string &filename);
    bool save(const string &filename);

    Value &get(const string &section, const string &key);
    void set(const string &section, const string &key, const Value &value);
    bool has(const string &section);
    bool has(const string &section, const string &key);

    void remove(const string &section);
    void remove(const string &section, const string &key);

    void clear();

    void display();

    Section &operator[](const string &str);

private:
    void trim(string &str);

private:
    string m_filename;
    std::map<string, Section> m_sections;
};