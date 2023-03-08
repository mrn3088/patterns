//
//  observer.hpp
//  dojo5
//
//  Created by 马瑞南 on 2023/2/11.
//

#ifndef observer_hpp
#define observer_hpp

#include <cstdio>
#include <unordered_set>
#include <iostream>
#include <algorithm>

class Subject;
class ConcreteSubject;
class ConcreteObserver;


// observer interface
class Observer {
public:
    virtual void update() = 0;
};

class Subject {
public:
    void registerObserver(Observer* anObserver) {
        observers.insert(anObserver);
    }
    
    void unregisterObserver(Observer* anObserver) {
        if (observers.find(anObserver) != observers.end()) {
            observers.erase(anObserver);
        }
    }
    
    virtual void notifyObservers() = 0;
    
protected:
    std::unordered_set<Observer*> observers;

};


class ConcreteObserver : public Observer {
public:
    virtual void update() override {
        std::cout << "updated!" << std::endl;
    }
};


class ConcreteSubject : public Subject {
public:
    virtual void notifyObservers() override  {
        std::for_each(observers.begin(), observers.end(), [](Observer* ob){
            ob -> update();
        });
    }
};


#endif /* observer_hpp */

/**
 Question 1:
 When to use virtual?
 
 Question 2:
 When to use CRTP pattern?

 Question 3:
 The default keyword?

 Question 4:
 Abstract Factory vs Factory: just another layer of abstraction?
 
 */
