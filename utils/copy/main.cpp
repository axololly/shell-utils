#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include "utils.hpp"
#include "help.hpp"

using namespace std;

int main(int argc, char** argv) {
    vector<string> args = {};

    for (int i = 0; i < argc - 1; i++) {
        args.push_back(argv[i + 1]);
    }

    if (args.size() == 0) {
        display_help(argv[0]);
        return 0;
    }

    if (args[0] == "-h" || args[0] == "--help") {
        display_help(argv[0]);
        return 0;
    }

    if (args[0] == "--source") {
        string url = "https://github.com/axololly/shell-utils/blob/main/utils/copy";
        int exit_code = system(format("powershell.exe -c start \"{}\"", url).c_str());

        if (exit_code != 0) {
            cout << format(
                "Could not open web browser. (Exit code: {})" "\n"
                "You'll have to manually open the source code in a browser at the following URL:" "\n\n"
                
                "    \x1b[36m{}",
                
                exit_code,
                url
            );
        }

        return exit_code;
    }

    // Copying a string
    if (args[0] == "-s" || args[0] == "--string") {
        if (args.size() == 1) {
            cout << "No string provided to copy to clipboard.";
            return 1;
        }

        string result = "";
        
        for (int i = 1; i < args.size() - 2; i++) {
            result += args[i];
            result += " ";
        }

        result += args[args.size() - 1];

        copy_text(result);

        cout << "Copied string to clipboard.";
    }
    
    // Copying a path
    else {
        string target = args[0];

        if (!filesystem::exists(target)) {
            cout << "Path does not exist.";
            return 1;
        }

        copy_file(target);

        cout << "Copied file to clipboard.";
    }
    
    return 0;
}