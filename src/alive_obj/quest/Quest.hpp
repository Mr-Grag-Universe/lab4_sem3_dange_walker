#ifndef QUEST_CLASS
#define QUEST_CLASS

class World;

class Quest {
private:
protected:
    bool is_complete = false;
public:
    Quest() {}
    virtual ~Quest() {}


    //=========== getters ==========//

    bool complete()
    { return is_complete; }

    virtual void update_completion(World & w) = 0;
};

#endif // QUEST_CLASS