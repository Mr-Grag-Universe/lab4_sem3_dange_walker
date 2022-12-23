#ifndef MONEY_CLASS
#define MONEY_CLASS

#include <algorithm>
#include <map>

#include "Loot.hpp"
#include "../enums/Money.hpp"
#include "Coin.hpp"


class Gold : public Coin {
private:
    long long _count = 0;
public:
    Gold() = default;
    Gold(long long number) : _count(number) {}
    ~Gold() = default;

    //=========== getters ==========//

    long long count() const 
    { return _count; }

    //========= operations =========//

    Gold operator+(const Gold & g) const;
    Gold operator-(const Gold & g) const;

    //========= conversions ========//

    operator long long() const;
};

class Silver : public Coin {
private:
    long long _count = 0;
public:
    Silver() = default;
    Silver(long long number) : _count(number) {}
    ~Silver() = default;

    //=========== getters ==========//

    long long count() const 
    { return _count; }

    //========= operations =========//

    Silver operator+(const Silver & g) const;
    Silver operator-(const Silver & g) const;

    //========= conversions ========//

    operator long long() const;
};


class Copper : public Coin {
private:
    long long _count = 0;
public:
    Copper() = default;
    Copper(long long number) : _count(number) {}
    ~Copper() = default;

    //=========== getters ==========//

    long long count() const 
    { return _count; }

    //========= operations =========//

    Copper operator+(const Copper & g) const;
    Copper operator-(const Copper & g) const;

    //========= conversions ========//

    operator long long() const;
};


class Money : public Loot
{
private:
    [[maybe_unused]] long long _count = 0;

    [[maybe_unused]] Gold gold = 0;
    [[maybe_unused]] Silver silver = 0;
    [[maybe_unused]] Copper copper = 0;

    std::vector <double> coeff = {1 , 10, 100 };
public:
    Money(long long);
    Money(std::vector <double> coeff = {1 , 10, 100 });
    ~Money();

    //============= getters ============//

    GameTypeSystem get_type() const override
    { return MONEY; }

    //============= setters ============//

    void set_gold(Gold & g);
    void set_silver(Silver & s);
    void set_copper(Copper & c);

    //=========== operators ============//

    Money operator+(const Money & m) const;

    //=========== conversions ==========//

    operator Gold() const;
    operator Silver() const;
    operator Copper() const;

    //========== other methods =========//

    void read(std::ifstream & ) override {}
};

#endif // MONEY_CLASS