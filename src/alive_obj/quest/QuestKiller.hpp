#ifndef QUEST_KILLER_CLASS
#define QUEST_KILLER_CLASS

#include "Quest.hpp"
#include <algorithm>

class QuestKiller : public Quest
{
private:
    [[maybe_unused]] size_t number_of_kills = 0;
public:
    QuestKiller() {}
    ~QuestKiller() override {}

    void update_completion(World & w) override;
};

#endif // QUEST_KILLER_CLASS