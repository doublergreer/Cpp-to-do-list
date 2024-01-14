#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Element
{
    public:
        //constructors
        Element();
        Element(string name);
        Element(string name, string description);
        Element(string name, string description, int priority_level);
        
        //setters and getters
        void setName(string name);
        void setDesc(string description);
        void setPriority(int priority);

        string getName();
        string getDesc();
        int getPriority();

        //other functions
        //linked list
        void setNextElement(Element* next);
        Element* getNextElement();
        void appendElement (Element* e);

        //UI functions
        void welcome(string username, bool firstTime);
        void prettyPrint();
        void printMenu();
        void addFirstItem();
        void addItem();

        //csv i/o functions
        //callee is assumed to be head of LL
        string readData(string file_name);
        void writeData(string file_name, string username);
    

    private:
    //vars
        string name_, description_;
        int priority_level_;
        Element *next_;

};

#endif