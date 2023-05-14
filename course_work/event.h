#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <thread>
#ifndef EVENT_H
#define EVENT_H

class Event {
public:
    Event(const std::string& name, int duration) : name(name), duration(duration) {}
    std::string getName() const {return name;}
    int getDuration() const {return duration;}

private:
    std::string name;
    int duration;
};

#endif // EVENT_H
