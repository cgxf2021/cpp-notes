#include "html_builder.h"

unique_ptr<HtmlBuilder> HtmlElement::create(const string &rootName)
{
    using std::make_unique;
    return make_unique<HtmlBuilder>(rootName);
}

HtmlElement::HtmlElement()
{
}

HtmlElement::HtmlElement(const string &name, const string &text) : m_name(name), m_text(text)
{
}

string HtmlElement::str(int indent) const
{
    string result;
    result += string(indent, ' ');
    result += ('<' + m_name + '>');
    if (!m_text.empty())
    {
        result += m_text;
    }
    else
    {
        result += '\n';
        for (const auto &child : m_elements)
        {
            result += child.str(indent + m_indent);
        }
    }
    result += ("</" + m_name + ">\n");

    return result;
}

HtmlBuilder::operator HtmlElement() const
{
    return m_root;
}

HtmlBuilder::HtmlBuilder(const string &rootName)
{
    m_root.m_name = rootName;
}

HtmlBuilder &HtmlBuilder::add_child(string childName, string childText)
{
    HtmlElement child(childName, childText);
    m_root.m_elements.push_back(child);
    return *this;
}
