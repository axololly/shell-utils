#include <iostream>
#include <string>
#include "help.hpp"

using namespace std;

void display_help() {
    string help = \
        "\x1b[1;36m" "Copy Tool: " "\x1b[0m" "\n"
        "    Does what it says on the tin." "\n\n"

        "\x1b[1;36m" "Description:" "\x1b[0m" "\n"
        "    This is a tool I created to copy files from within the terminal using C++.\n\n"
        
        "    There is an alias for this called " "\x1b[38;5;93m" "cp.exe" "\x1b[0m" "." "\n\n"
        
        "\x1b[1;36m" "Usage:" "\x1b[0m" "\n"
        "\x1b[38;5;220m" "    copy" "\x1b[38;5;240m" " <path>" "\n"
        "\x1b[38;5;220m" "    copy" "\x1b[32m" " -s " "\x1b[38;5;240m" "<string>" "\n\n"

        "\x1b[1;36m" "Options:" "\n"
        "\x1b[32m" "    -s, --string" "\x1b[0m" "     Copy a string to the clipboard." "\n"
        "\x1b[32m" "    -h, --help  " "\x1b[0m" "     Shows this screen.";

    cout << help << endl;
}