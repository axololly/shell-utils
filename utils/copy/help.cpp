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
    string alias = executable_name == temp ? "cp" : "copy";

    string help = format(
        "\x1b[1;36m" "Copy Tool: " "\x1b[0m" "\n"
        "    It does what it says on the tin." "\n\n"

        "\x1b[1;36m" "Description:" "\x1b[0m" "\n"
        "    This is a tool I created to copy files from within the terminal using C++." "\n\n"
        
        "    There is an alias for this called " "\x1b[38;5;93m" "{1}.exe" "\x1b[0m" "." "\n\n"
        
        "\x1b[1;36m" "Usage:" "\x1b[0m" "\n"
        "\x1b[38;5;220m" "    {0}" "\x1b[38;5;240m" " <path>" "\n"
        "\x1b[38;5;220m" "    {0}" "\x1b[32m" " -s " "\x1b[38;5;240m" "<string>" "\n\n"

        "\x1b[1;36m" "Options:" "\n"
        "\x1b[32m" "    -s, --string" "\x1b[0m" "     Copy a string to the clipboard." "\n"
        "\x1b[32m" "        --source" "\x1b[0m" "     Open this executable's source code in the browser." "\n"
        "\x1b[32m" "    -h, --help  " "\x1b[0m" "     Shows this screen." "\n\n"
        
        "\x1b[1;36m" "Source Code:" "\x1b[0m" "\n"
        "    You can see all my utilities here: https://github.com/axololly/shell-utils/." "\n\n"
        
        "Created by " "\x1b[38;5;212m" "@axololly" "\x1b[0m" " on Github.",

        executable_name,
        alias
    );

    cout << help << endl;
}