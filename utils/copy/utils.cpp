#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <shlobj.h>
#include "utils.hpp"

using namespace std;
using namespace std::filesystem;

void copy_file(string& path) {
    if (!OpenClipboard(NULL)) {
        cout << "Could not open clipboard." "\n"
             << "Last error: 0x" << hex << GetLastError();
        exit(1);
    }

    // Allocate memory to store all the files, plus the path we need.
    // This will give back a pointer to the allocated memory.
    HGLOBAL mem = GlobalAlloc(GHND, sizeof(DROPFILES) + path.length() + 2);

    if (!mem) {
        cout << "Could not allocate global memory." "\n"
             << "Last error: 0x" << hex << GetLastError();
        exit(1);
    }

    // Make sure this memory is protected, then
    // interpret it as a DROPFILES object.
    DROPFILES* df = (DROPFILES*)GlobalLock(mem);

    if (!df) {
        cout << "Could not lock memory for dropfiles." "\n"
             << "Last error: 0x" << hex << GetLastError();
        
        GlobalFree(mem);
        exit(1);
    }

    // Customise settings
    df->pFiles = sizeof(DROPFILES);
    df->fNC = true;
    df->fWide = false;

    memcpy(&df[1], path.c_str(), path.length());

    GlobalUnlock(mem);

    // Attempt to empty the clipboard
    if (!EmptyClipboard()) {
        cout << "Could not empty clipboard." "\n"
             << "Last error: 0x" << hex << GetLastError();
        
        GlobalFree(mem);
        exit(1);
    }

    // Attempt to add the files to the clipboard.
    if (!SetClipboardData(CF_HDROP, mem)) {
        cout << "Could not set clipboard data." "\n"
             << "Last error: 0x" << hex << GetLastError();
        
        GlobalFree(mem);
        exit(1);
    }

    CloseClipboard();
}

void copy_text(string& text) {
    if (!OpenClipboard(NULL)) {
        cout << "Could not open clipboard." "\n"
             << "Last error: 0x" << hex << GetLastError();
        exit(1);
    }

    // Allocate memory to store all the files, plus the path we need.
    // This will give back a pointer to the allocated memory.
    HGLOBAL mem = GlobalAlloc(GMEM_DDESHARE, text.size() + 1);

    if (!mem) {
        cout << "Could not allocate global memory." "\n"
             << "Last error: 0x" << hex << GetLastError();
        exit(1);
    }

    // Make sure this memory is protected, then
    // interpret it as a string pointer.
    char* ptr = (char*)GlobalLock(mem);
    
    // Copy the text into the memory.
    strcpy(ptr, text.c_str());
    
    GlobalUnlock(mem);

    // Attempt to empty the clipboard
    if (!EmptyClipboard()) {
        cout << "Could not empty clipboard." "\n"
             << "Last error: 0x" << hex << GetLastError();
        
        GlobalFree(mem);
        exit(1);
    }

    // Attempt to add the text to the clipboard
    if (!SetClipboardData(CF_TEXT, mem)) {
        cout << "Could not set clipboard data." "\n"
             << "Last error: 0x" << hex << GetLastError();
        
        GlobalFree(mem);
        exit(1);
    }

    CloseClipboard();
}

void copy_file_contents(string& path) {
    // Open a stream to the file that takes in content.
    ifstream f(path);

    // Build a string from an iterator over the file.
    // (I really have no idea what the hell this does.)
    string content(
        (istreambuf_iterator<char>(f)),
        istreambuf_iterator<char>()
    );

    f.close();

    // Use one of our already created functions
    // instead of rewriting the logic.
    copy_text(content);
}