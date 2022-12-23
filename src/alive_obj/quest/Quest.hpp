#ifndef QUEST_CLASS
#define QUEST_CLASS

#include "../../events/event.hpp"
#include <algorithm>
#include <memory>

class World;

class Quest {
private:
protected:
    bool is_complete = false;
    bool is_passed = false;
public:
    Quest() {}
    virtual ~Quest() {}


    //=========== getters ==========//

    bool complete() const
    { return is_complete; }
    bool passed() const
    { return is_passed; }

    //=========== setters ==========//

    void pass()
    { is_passed = true; }

    virtual void update_completion(std::shared_ptr<Event> ev) = 0;

};

#endif // QUEST_CLASS