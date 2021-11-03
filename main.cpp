#include <HTML/HTML.h>

#include <iostream>
#include <fstream>
#include <string>

#include "maddy/parser.h"


#include <filesystem>
namespace fs = std::filesystem;

#if 1
    auto &output = std::cout;
#else
    auto output = std::fstream("index.html", std::ios::out);
#endif

int main()
{
    HTML::Document document("blog-posts");
    document.addAttribute("lang", "en");

    auto config = std::make_shared<maddy::ParserConfig>();
    auto parser = std::make_shared<maddy::Parser>(config);

    std::string path = "posts";
    for (const auto &entry : fs::directory_iterator(path))
    {
        std::fstream file(entry.path(), std::ios::in);
        document << HTML::Text(parser->Parse(file));
    }

    output << document;
    return 0;
}
