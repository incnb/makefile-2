#ifndef _TARGET_H_
#define _TARGET_H_
#include <iostream>
#include <string>

struct Target {

int age;
int numChildren;
int numParents;
std::string name;
Target **parents;
Target **children;

static int time;

Target(const std::string &t);
Target &operator=(const Target &other);
~Target();
bool isLeaf() const;
void addChild(Target *t);
void addParent(Target *t);
void updateLeaf();
void build(Target *t, bool reachedLeaf);

static int getTime();
static void setTime();

};

#endif
