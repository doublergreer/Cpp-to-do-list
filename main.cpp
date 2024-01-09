#include <iostream>
#include "element.h"
using namespace std;

int main() {
    Element* e = new Element("test1", "math homework");
    Element* e1 = new Element("test2", "laundry");
    Element* e2 = new Element("test3", "clean room");
    Element* e3 = new Element("test4", "make dinner");
    Element* e4 = new Element("test5", "gym");

    e->setNextElement(e1);
    e1->setNextElement(e2);
    e2->setNextElement(e3);
    e3->setNextElement(e4);

    e->prettyPrint();
}