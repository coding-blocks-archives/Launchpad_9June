#include "subject.h"

Subject::Subject()
{
}

void Subject::Notify(){
    for(int i = 0; i < observerList.size(); ++i){
        Observer* curObserver = observerList[i];
        curObserver->Update();
    }
}

void Subject::AddObserver(Observer *o){
    observerList.push_back(o);
}


