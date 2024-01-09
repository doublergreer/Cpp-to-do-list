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
        void prettyPrint();
        
    

    private:
    //vars
        string name_, description_;
        int priority_level_;
        Element *next_;

};

#endif