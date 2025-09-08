#pragma once

#include <memory>
#include <string>
#include <vector>

using std::string;
using std::unique_ptr;
using std::vector;

class HtmlBuilder;
class HtmlElement;

class HtmlElement
{
  private:
    string m_name;
    string m_text;
    vector<HtmlElement> m_elements;

    const int m_indent = 2;

  protected:
    HtmlElement();

    HtmlElement(const string &name, const string &text);

  public:
    friend HtmlBuilder;

    static unique_ptr<HtmlBuilder> create(const string &rootName);

    string str(int indent = 0) const;
};

/**
 * @brief 专门用于构建HTML元素的组件
 *
 * 用于演示流式构造器模式
 */

class HtmlBuilder
{
  private:
    HtmlElement m_root;

  public:
    operator HtmlElement() const;

    HtmlBuilder(const string &rootName);

    HtmlBuilder &add_child(string childName, string childText);
};
