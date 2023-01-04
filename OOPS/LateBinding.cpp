#include<iostream>
using namespace std;

class Vehicle{
public:
    void move(){
        cout << "Vehicle is moving";
    }    
};

class Bike : public Vehicle{
public:
    void move(){
        cout << "Bike is moving\n";
    }
};

class Car : public Vehicle{
public:
    void move(){
        cout << "Car is moving\n";
    }
};


//  ambiguious calling of move function

class Driver : public Bike, public Car{
public:
    void drive(){
        Car c;
        c.move();
    }
};

int main(){
    Driver *d = new Driver();
    d->move();
}