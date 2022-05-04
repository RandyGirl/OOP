#include "Player.h"
#include "deck.cpp"
#include <cstring>

Player::Player()
{
    strcpy(this->name, "Random");
    this->age = 0;
    this->wins = 0;
    this->winRate= 0;
    this->crrNumPt = 0;
    this->allGames = 0;
}
Player::Player(const char _name[40], size_t _age)
{
    strcpy(this->name, _name);
    this->age = _age;
    this->wins = 0;
    this->winRate= 0;
    this->crrNumPt = 0;
    this->allGames = 0;
}
const char* Player::get_name() const
{
    return this->name;
}
size_t Player::get_age() const
{
    return this->age;
}
size_t Player::get_wins() const
{
    return this->wins;
}
void Player::add_wins()
{
    this->wins += 1;
}
double Player::get_winRate() const
{
    return this->winRate;
}
void Player::set_winrate()
{
    this->winRate = this->wins / this->allGames;
}
size_t Player::get_crrNumPt() const
{
    return this->crrNumPt;
}
void Player::set_crrNumPt(size_t points)
{
    this->crrNumPt += points;
}
size_t Player::points(const Card& current) const
{
    if(strstr(current.get_value(), "2") != nullptr) {return 2;}
    if(strstr(current.get_value(), "3") != nullptr) {return 3;}
    if(strstr(current.get_value(), "4") != nullptr) {return 4;}
    if(strstr(current.get_value(), "5") != nullptr) {return 5;}
    if(strstr(current.get_value(), "6") != nullptr) {return 6;}
    if(strstr(current.get_value(), "7") != nullptr) {return 7;}
    if(strstr(current.get_value(), "8") != nullptr) {return 8;}
    if(strstr(current.get_value(), "9") != nullptr) {return 9;}
    if(strstr(current.get_value(), "10")!= nullptr) {return 10;}
    if(strstr(current.get_value(), "J") != nullptr) {return 10;}
    if(strstr(current.get_value(), "Q") != nullptr) {return 10;}
    if(strstr(current.get_value(), "K") != nullptr) {return 10;}
    if(strstr(current.get_value(), "A") != nullptr) 
    {
        if(this->crrNumPt + 11 <= 21) {return 11;}
        if(this->crrNumPt + 1 <= 21) {return 1;}
    }
}
void Player::print_crrPt() const
{
    std::cout << "(Points: " << this->crrNumPt << ")" << std::endl;
}
void Player::addgame()
{
    this->allGames += 1;
}

std::ostream& operator<< (std::ostream& out, Player p1)
{
    std::cout << p1.get_name() << " " << p1.get_wins() << " " << p1.get_winRate() << std::endl;
    return out; 
}