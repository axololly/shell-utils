#include <filesystem>
#include <iostream>
#include <string>
#include "help.hpp"

using namespace std;
using namespace std::filesystem;

void display_help(char* executable_path) {
    path exec_path = path(executable_path);
    string executable_name = exec_path.stem().string();

    string temp = "copy";
    const string alias = executable_name == temp ? "cp" : "copy";
 
    string help = format(
        "{1}Copy Tool: {7}{8}{0}\n"
        "    It does exactly what it says on the tin.\n"
        "    Created by {6}@axololly{0} on GitHub.\n\n"
        
        "{1}Description:{0}\n"
        "    This is a tool I created to copy files from within the terminal using C++.\n\n"
        
        "    There is an alias for this called {2}{3}.exe{0}.\n\n"

        "{1}Options:{0}\n"
        "{4}  -s, --string {5}<text>  {0}Copy a string to the clipboard.\n"
        "{4}  -r, --read   {5}<path>  {0}Read the contents of a file and copy them to the clipboard.\n"
        "{4}      --source {5}<path>  {0}Open this executable's source code in a web browser.\n"
        "{4}  -h, --help           {0}Shows this screen.\n\n"
        
        "{1}Source Code:{0}\n"
        "    You can see all my utilities here: https://github.com/axololly/shell-utils/.\n",
        
        "\x1b[0m",
        "\x1b[1;36m",
        "\x1b[38;5;93m",
        alias,
        "\x1b[38;5;46m",
        "\x1b[38;5;241m",
        "\x1b[38;5;212m",
        "\x1b[38;5;27m",
        version
    );

    cout << help << endl;
}