#include <iostream>
#include "element.h"
using namespace std;

int main() {
    Element* root = new Element();

    //get username from first line of csv file
    // string username = "Ryan";
    string username = root->readData("listData.txt");

    root -> welcome(username, true);

    //to-do: change cin to getline for most fields (additem)
}