#include <iostream>
#include "element.h"

using namespace std;

Element::Element() {
    name_ = "";
    description_ = "";
    priority_level_ = 5;
}

Element::Element(string name) {
    name_ = name; 
    description_ = "";
    priority_level_ = 5;
}

Element::Element(string name, string description) {
    name_ = name; 
    description_ = description;
    priority_level_ = 5;
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

//prints list assuming currrent element is head
//only name of item for now
void Element::prettyPrint() {
    Element* temp = this;

    cout << " --------- TO-DO LIST --------- " << endl << "TASK NAME\tDESC" << endl;
    int i = 1;
    while (temp) {
        cout << i << ". " << temp->name_ << "\t" << temp->description_ << endl;
        temp = temp->next_;
        i++;
    }
    cout << " ------------------------------ " << endl;

}