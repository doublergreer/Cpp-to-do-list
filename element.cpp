#include <iostream>
#include "element.h"

using namespace std;

Element::Element() {
    name_ = "";
    description_ = "";
}

Element::Element(string name) {
    name_ = name; 
    description_ = "";
}

Element::Element(string name, string description) {
    name_ = name; 
    description_ = description;
}

Element::Element(string name, string description, int priority_level) {
    name_ = name; 
    description_ = description;
    priority_level_ = priority_level;
}

//setters and getters
void Element::setName(string name) {
    name_ = name;
}
void Element::setDesc(string description) {
    description_ = description;
}
void Element::setPriority(int priority) {
    priority_level_ = priority;
}

string Element::getName() {
    return name_;
}

string Element::getDesc() {
    return description_;
}

int Element::getPriority() {
    return priority_level_;
}

//linked list stuff
void Element::setNextElement(Element* next) {
    next_ = next;
}

Element* Element::getNextElement() {
    return next_;
}

void Element::appendElement (Element* e) {
    Element* temp = this;

    //for first element of todolist
    if (temp->name_ == "") {
        // cout << "First name empty, reassigning root to be: " << e->name_<<endl;
        temp->name_ = e->name_;
        temp->description_ = e->description_;
        temp->priority_level_ = e->priority_level_;
        return;
    }

    while (temp->next_) temp = temp->next_;

    //add to end of list
    temp->next_ = e;
}

int Element::welcome(string username, bool firstTime) {
    if (firstTime) {
        cout << endl << "Hello " << username << ", welcome to your new to-do list." << endl;
        return printMenu();
    }

    else {
        cout << endl << username << ", welcome back to your to-do list." << endl;
        prettyPrint();
        return printMenu();
    }
}

//prints list assuming currrent element is head
//only name of item for now
void Element::prettyPrint() {
    Element* temp = this;

    cout << " ------------------------ TO-DO LIST ------------------------ " << endl << "TASK NAME\tDESC\t\t\tPRIORITY" << endl;
    int i = 1;

    /* maybe limit name&desc to a certain number of characters to better align menu
    *   allow another option to expand details of a task
    */

    while (temp) {
        cout << i << ". " << temp->name_.substr(0,8) << "\t" << temp->description_.substr(0,4);
        
        if (!temp->priority_level_) cout << "...\t\t\t-" << endl;
        else cout << "...\t\t\t" << temp->priority_level_ << endl;

        temp = temp->next_;
        i++;
    }
    cout << " ------------------------------------------------------------ " << endl;

}


int Element::printMenu() {
    int menu = 0;
    
    while (menu != 5){
        cout << "1. Add item to list" << endl;
        cout << "2. Remove item from list" << endl;
        cout << "3. Expand details" << endl;
        cout << "4. Show list" << endl;
        cout << "5. Quit" << endl;

        
        do {
            cout << "Enter a menu choice:\t"; 
            cin >> menu;
        } while (menu > 5 || menu < 1);

        if (menu == 1) {
            if (this->name_ != "") addItem();
            else addFirstItem();
        }
        else if (menu == 2) {
            int item;

            cout << "Enter item number:\t";
            cin >> item;

            this->removeItem(item);
        }
        else if (menu == 3) {
            int item;

            cout << "Enter item number:\t";
            cin >> item;

            this->expandDetails(item);
        }
        else if (menu == 4) prettyPrint();
    }

    string cancel = "";

    cout << endl << "Saving list to hard drive. Type 'n' to cancel.";
    cin >> cancel;

    if (cancel != "n") return 1;

    return 0;
}

void Element::addFirstItem() {

    cin.ignore(256, '\n');

    cout << "-New Item-" << endl;
    cout << "Enter item name:";
    
    getline(cin, name_);

    // cin.ignore(256, '\n');

    cout << endl;

    cout << "Enter item description:";
    getline(cin, description_);

    cout << endl;

    cout << "Enter level of importance (1-5):";
    cin >> priority_level_;

    cout << endl;

    prettyPrint();
}

void Element::addItem() {
    string name, description;
    int priority;

    cin.ignore(256, '\n');

    cout << "-New Item-" << endl;
    cout << "Enter item name:";
    getline(cin, name);

    cout << endl;

    cout << "Enter item description:";
    getline(cin, description);

    cout << endl;

    cout << "Enter level of importance (1-5):";
    cin >> priority;

    cout << endl;

    Element* newItem = new Element(name, description, priority);
    appendElement(newItem);

    prettyPrint();
}

void Element::removeItem(int num) {
    //add LL destructor?
    if (num == 1) return;

    Element* item = this->findElementByNumber(num);
    Element* prev = this->findElementByNumber(num-1);

    prev->next_ = item->next_;

    delete item;

    this->prettyPrint();
}

Element* Element::findElementByNumber(int num) {
    Element* temp = this;
    int i = 1;

    while (temp) {
        if (i == num) return temp;

        temp = temp->next_;
        i++;
    }

    return nullptr;
}

void Element::expandDetails(int num) {
    Element* task = findElementByNumber(num);

    if (task == nullptr) {
        cout << "Invalid Element" << endl;
        return;
    }
    cout << endl << " ------------------------------------------------" << endl;
    cout << endl << "\tTask Name: " << task->name_ << endl;

    cout << endl << "\tDescription: " << task->description_ << endl;

    cout << endl << "\tPriority Level: " << task->priority_level_ << endl;
    cout << endl << " ------------------------------------------------" << endl;
}


//csv i/o functions
//callee is assumed to be head of LL
string Element::readData(string file_name) {
    ifstream csv;
    string username = "", line = "";

    int numReads = 0;

    // Element *root = this;
    // Element *curr = root;

    csv.open(file_name);

    if(csv.is_open()) {
        while (!csv.eof()) {
            getline(csv, line);

            if (numReads == 0) {
                username = line;
                numReads++;
                continue;
            }

            string name, desc;
            int priority_level;

            numReads++;

            if(line.length() > 0)
            {
                string temp = "";
                int i = 0;
                while (line[i] != ',') {
                    temp += line[i];
                    i++;
                }
                name = temp;
                temp = "";
                i++;

                while (line[i] != ',') {
                    temp += line[i];
                    i++;
                }
                desc = temp;
                temp = "";
                i++;

                while (line[i] != ',') {
                    temp += line[i];
                    i++;
                }
                priority_level = stoi(temp);

                Element *e = new Element(name,desc,priority_level);
                this->appendElement(e);
            }
        }
    }
    
    csv.close();

    return username;
}

void Element::writeData(string file_name, string username) {
    ofstream fout;
    fout.open(file_name);

    fout << username << endl;
    
    Element* temp = this;

    while (temp) {
        fout << temp->name_ << "," << temp->description_ << "," << temp->priority_level_ << endl;
        temp = temp->next_;
    }
}