#include "html_builder.h"
#include <iostream>

int main(int argc, char *argv[])
{
    HtmlElement e = HtmlElement::create("ul")->add_child("li", "hello").add_child("li", "world");

    std::cout << e.str() << std::endl;
    return 0;
}
