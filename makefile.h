#ifndef _MAKEFILE_H_
#define _MAKEFILE_H_
#include <iostream>
#include <string>
#include "target.h"

const int maxTargets = 20;
const int maxDependencies = 10;

class Makefile {

int curTargets;
Target **targets;

public:

 Makefile();
 ~Makefile();
 void addDepend(const std::string &t, const std::string &d);
 void changeTarget(const std::string &t);
 void rebuild(const std::string &t);
 Target *contains(const std::string &t);
};

#endif
