#ifndef QUEST_KILLER_CLASS
#define QUEST_KILLER_CLASS

#include "Quest.hpp"
#include "../events/event.hpp"
#include <algorithm>
#include <algorithm>

class QuestKiller : public Quest
{
private:
    [[maybe_unused]] size_t number_of_kills = 0;
    [[maybe_unused]] size_t asked_number_of_kills = 0;
public:
    QuestKiller();
    ~QuestKiller() override {}

    void update_completion(std::shared_ptr<Event> ev) override;
};

#endif // QUEST_KILLER_CLASS