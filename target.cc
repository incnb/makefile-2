#include <iostream>
#include <string>
#include "target.h"
using namespace std;

int Target::time = 0;

Target::Target(const string &t) : age{0}, numChildren{0}, numParents{0}, name{t} {
    parents = new Target *[10]();
    children = new Target *[10]();
}

Target::~Target() {
  delete [] parents;
  delete [] children;
}

bool Target::isLeaf() const {
   return numChildren == 0;
}

void Target::addChild(Target *t) {
   children[numChildren] = t;
   ++numChildren;
}

void Target::addParent(Target *t) {
   parents[numParents] = t; 
   ++numParents;
}

void Target::updateLeaf() {
   setTime();
   if (isLeaf()) {
     age = getTime();
     cout << name << " updated at time " << getTime() << endl;
   } else {
     cout << "Cannot update non-leaf object" << endl;
   }
}

int Target::getTime() { return time; }

void Target::setTime() { ++time; }

void Target::build(Target *t, bool reachedLeaf) {

 if (reachedLeaf) {

    if (this == t) {

       for (int i = 0; i < numChildren; ++i) {
           if (age < children[i]->age) {
             cout << "Building " << name << endl;
             age = getTime();
             return;
           }
        }
    } else {
       
       for (int i = 0; i < numChildren; ++i) {
          if (age < children[i]->age) {
             cout << "Building " << name << endl;
             age = getTime();
           }
       }
       for (int i = 0; i < numParents; ++i) {
            parents[i]->build(t, true);
      }
    }
  } else {

      for (int i = 0; i < numChildren; ++i) {
          if (children[i]->numChildren > 0) 
             children[i]->build(t, false);
          else
             children[i]->build(t, true);
      }
  }
}
