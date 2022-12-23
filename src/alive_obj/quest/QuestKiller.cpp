#include <iostream>
#include <algorithm>
#include <string>

#include "QuestKiller.hpp"
#include "../events/event.hpp"


QuestKiller::QuestKiller() : asked_number_of_kills(1) {}

//============= other methods ============//

void QuestKiller::update_completion(std::shared_ptr<Event> ev) {
    if (ev->get_type() == KILL)
        ++number_of_kills;
    if (number_of_kills == asked_number_of_kills)
        is_complete = true;
}