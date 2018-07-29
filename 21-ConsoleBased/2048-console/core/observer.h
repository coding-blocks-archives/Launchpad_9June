#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public:
    Observer();
    virtual void Update() = 0;  // function overriding
};

#endif // OBSERVER_H
