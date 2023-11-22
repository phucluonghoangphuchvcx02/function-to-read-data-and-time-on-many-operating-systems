# function-to-read-data-and-time-on-many-operating-systems
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cstring>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#endif

using namespace std;

int main() {
    cout << "Enter the file path: ";

    // Get the file path from the user
    string in_filePath;
    getline(cin, in_filePath);
    const char *filePath = in_filePath.c_str();

    // Open the file using cross-platform approach
#ifdef _WIN32
    HANDLE hFile = CreateFileA(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        cerr << "Unable to open the file. Error: " << GetLastError() << endl;
        return 1;
    }
#else
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Unable to open the file." << endl;
        return 1;
    }
#endif

    // Read and display the file content
    string content;
#ifdef _WIN32
    DWORD fileSize = GetFileSize(hFile, NULL);

    if (fileSize == INVALID_FILE_SIZE) {
        cerr << "Unable to get the file size. Error: " << GetLastError() << endl;
#ifdef _WIN32
        CloseHandle(hFile);
#endif
        return 1;
    }

    // Allocate a buffer to read the file content
    char *buffer = new char[fileSize];

    // Read the file content into the buffer
    DWORD bytesRead;
    if (ReadFile(hFile, buffer, fileSize, &bytesRead, NULL)) {
        // Output the file content
        content = string(buffer, bytesRead);
    } else {
        cerr << "Unable to read the file. Error: " << GetLastError() << endl;
    }
#ifdef _WIN32
    CloseHandle(hFile);
    delete[] buffer;
#endif
#else
    // Read the file content into the buffer
    content = string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
#endif

    cout << "File content:\n" << content << endl;

    // Get the current time
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);

    // Convert time to local time
    cout << "File creation time: " << ctime(&now_c);

    return 0;
}
