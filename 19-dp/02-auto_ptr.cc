// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Elephant{
public:
    string name;
    Elephant(){
        name = "EMPTY";
    }

    Elephant(string name){
        this->name = name;
    }

    ~Elephant(){
        cout << "Dtor of Elephant called. Elephant killed...\n";
    }
};

void printElephant(Elephant *E){
    cout << "Inside void printElephant(Elephant*);" << endl;
    cout << E->name << endl;
    // delete E
}


void killElephant1(){
    // Elephant* e = new Elephant("Jumbo");
    // cout << e->name << " being killed in Africa " << endl;
    // delete e;

    auto_ptr<Elephant> e(new Elephant("Jumbo"));
    cout << e->name << " being killed in Africa " << endl;
}


auto_ptr<Elephant> killElephant2(){
    // Elephant* e = new Elephant("Jumbo");
    // cout << e->name << " being killed in Africa " << endl;
    // delete e;

    auto_ptr<Elephant> e(new Elephant("Jumbo"));
    auto_ptr<Elephant> e2 = e;
    cout << e2->name << " being killed in Africa " << endl;
    return e2;
}

void killElephant3(){
    unique_ptr<Elephant> e(new Elephant("Jumbo"));
    cout << e->name << " being killed in Africa " << endl;
}

unique_ptr<Elephant> killElephant4(){
    unique_ptr<Elephant> e(new Elephant("Jumbo"));
    cout << e->name << " being killed in Africa " << endl;
    return e;
}

unique_ptr<Elephant> killElephant5(){
    // Elephant* e = new Elephant("Jumbo");
    // cout << e->name << " being killed in Africa " << endl;
    // delete e;

    unique_ptr<Elephant> e(new Elephant("Jumbo"));
    // unique_ptr<Elephant> e2 = e; // This will give error
    cout << e->name << " being killed in Africa " << endl;
    return e;
}

void killElephant6(){
    shared_ptr<Elephant> e(new Elephant("Jumbo"));
    shared_ptr<Elephant> e2 = e;
    cout << e->name << " being killed in Africa " << endl;
}


shared_ptr<Elephant> killElephant7(){
    shared_ptr<Elephant> e(new Elephant("Jumbo"));
    shared_ptr<Elephant> e2 = e;
    cout << e->name << " being killed in Africa " << endl;
    printElephant(e2.get());
    // return e;
}

int main(){
    // killElephant1();

    // auto_ptr<Elephant> e2 = killElephant2();
    // cout << e2->name << endl;

    // killElephant3();
    // unique_ptr<Elephant> e3 = killElephant4();

    // unique_ptr<Elephant> e5 = killElephant5();
    shared_ptr<Elephant> e7 = killElephant7();
    cout << "---END of main---\n"; 
    return 0;
}