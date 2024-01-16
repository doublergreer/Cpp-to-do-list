#include <iostream>
#include "element.h"
using namespace std;

bool fileIsEmpty(string file_name) {
    ifstream file(file_name);

    if (file.is_open()) {
        // Check if the file is empty by moving the file pointer to the end
        file.seekg(0, std::ios::end);

        if (file.tellg() == 0) {
            file.close();
            return true;
        }
        file.close();
        return false;
    }
    return true;
}

int main() {
    Element* root = new Element();

    string file_name = "listData.csv";

    bool firstTime = fileIsEmpty(file_name);
    string username;
    
    if (!firstTime) root->readData(file_name);
    else {
        cout << endl << "Enter a username for this app:\t";
        getline(cin, username);
        cin.clear();
    }

    int return_value = root -> welcome(username, firstTime);

    if (return_value == 1) root->writeData(file_name, username);
}