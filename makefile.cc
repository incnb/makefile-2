#include <iostream>
#include <string>
#include "makefile.h"
using namespace std;

Makefile::Makefile() : curTargets{0} {
    targets = new Target *[20]();
}

Makefile::~Makefile() {
    for (int i = 0; i < 20; ++i) {
        if (targets[i]) delete targets[i];
    }
    delete [] targets;
}

void Makefile::addDepend(const string &t, const string &d) {

     Target *temp_parent = contains(t);
     Target *temp_child = contains(d);

     if ((curTargets >= 20) || (curTargets == 19 && contains(t) == nullptr && contains(d) == nullptr)) {
        cerr << "Max targets exceeded" << endl;
        return;
      } else if ((temp_parent != nullptr && (temp_parent->numChildren >= 10 || temp_parent->numParents >= 10)) ||
                    (temp_child != nullptr && (temp_child->numChildren >= 10 || temp_child->numParents >= 10))) {
        cerr << "Max dependencies exceeded" << endl;
        return;   
      }

     if (temp_parent == nullptr) {
         delete targets[curTargets];
         targets[curTargets] = new Target{t};
         temp_parent = targets[curTargets];
         ++curTargets;
     }    
     if (temp_child == nullptr) {
        delete targets[curTargets];
        targets[curTargets] = new Target{d};
        temp_child = targets[curTargets];
        ++curTargets;
     }
     temp_parent->addChild(temp_child);
     temp_child->addParent(temp_parent);
}

void Makefile::changeTarget(const string &t) {
  Target *temp = contains(t);
  if (temp != nullptr) temp->updateLeaf();
}

void Makefile::rebuild(const string &t) {
    Target *temp = contains(t);
     if (temp != nullptr && ! (temp->isLeaf())) 
        temp->build(temp, false);   
     else if (temp != nullptr) 
       temp->build(temp, true); 
}

Target *Makefile::contains(const string &t) {
   for (int i = 0; i < curTargets; ++i) 
      if (targets[i]->name == t) return targets[i];
   return nullptr;
}
