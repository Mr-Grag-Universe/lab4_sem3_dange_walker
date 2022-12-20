#ifndef STATE_CLASS
#define STATE_CLASS

#include "Series.hpp"

namespace my_asserts {
    /**
     * @brief State class, describing how asserts will be changing during time goes
     * 
     */
    class State {
    protected:
        Series s = Series();
        size_t number{};
    public:
        // constructors
        State();

        // getters
        size_t get_number() const;

        // setters
    };
};

#endif // STATE_CLASS