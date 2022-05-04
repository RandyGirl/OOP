#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include <iostream>
#include <fstream>



class Player
{
    private:
    char name[40];
    size_t age;
    size_t wins;
    double winRate;
    size_t allGames;
    size_t crrNumPt;//current number of points

    public:
    Player();
    Player(const char _name[40], size_t age);
    const char* get_name() const;
    size_t get_age() const;
    size_t get_wins() const;
    void add_wins();
    double get_winRate() const;
    void set_winrate();
    size_t get_crrNumPt() const;
    void set_crrNumPt(size_t points);
    size_t points(const Card& current) const;
    void print_crrPt() const;
    void addgame();
};

std::ostream& operator<< (std::ostream& out, Player p1);

#endif
