#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"

#include <vector>

class Subject
{
public:
    Subject();
    void Notify();
    void AddObserver(Observer *o);
private:
    std::vector<Observer*> observerList;
};

#endif // SUBJECT_H
