#include "Money.hpp"

//=========== Money ==========//

Money::Money(long long count) : _count(count) {
    gold = count / coeff[2];
    count /= coeff[2];

    silver = count / coeff[1];
    count /= coeff[1];

    copper = count / coeff[0];
    count /= coeff[0];
}
Money::Money(std::vector <double> coeff) : coeff(coeff) {

}

Money::~Money()
{
}


void Money::set_gold(Gold & g) {
    _count += g.count()*coeff[2] - gold.count();
    gold = g;
}
void Money::set_silver(Silver & s) {
    _count += s.count()*coeff[1] - silver.count();
    silver = s;
}
void Money::set_copper(Copper & c) {
    _count += c.count()*coeff[0] - copper.count();
    copper = c;
}

Money::operator Gold() const {
    return Gold(_count/coeff[2]);
}
Money::operator Silver() const {
    return Silver(_count/coeff[1]);
}
Money::operator Copper() const {
    return Copper(_count/coeff[0]);
}

Money Money::operator+(const Money & m) const {
    return Money(_count + m._count);
}

//=========== Gold ===========//

Gold Gold::operator+(const Gold & g) const {
    return Gold(g.count() + _count);
}
Gold Gold::operator-(const Gold & g) const {
    return Gold(_count - g.count());
}

Gold::operator long long() const {
    return _count;
}

//========== Silver ==========//

Silver Silver::operator+(const Silver & g) const {
    return Silver(g.count() + _count);
}
Silver Silver::operator-(const Silver & g) const {
    return Silver(_count - g.count());
}

Silver::operator long long() const {
    return _count;
}

//========== Copper ===========//

Copper Copper::operator+(const Copper & g) const {
    return Copper(g.count() + _count);
}
Copper Copper::operator-(const Copper & g) const {
    return Copper(_count - g.count());
}

Copper::operator long long() const {
    return _count;
}