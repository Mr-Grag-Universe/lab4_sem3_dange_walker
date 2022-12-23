#ifndef EVENT_CLASS_HPP
#define EVENT_CLASS_HPP

#include <string>
#include "EventType.hpp"

class Event {
private:
public:
    virtual ~Event() = 0;

    virtual EventType get_type() const = 0;

    virtual std::string what() = 0;
};

#endif // EVENT_CLASS_HPP