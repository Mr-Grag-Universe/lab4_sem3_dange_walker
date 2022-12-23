#ifndef KILL_EVENT_CLASS
#define KILL_EVENT_CLASS

#include "EventType.hpp"
#include "Event.hpp"

class Kill : public Event
{
private:
    [[maybe_unused]] EventType event_type = KILL;
public:
    Kill();
    ~Kill();

    //=========== getters ===========//

    EventType get_type() const override
    { return KILL; }

    //======== other methods ========//

    std::string what() override
    { return "some obj has been killed"; }
};


#endif // KILL_EVENT_CLASS