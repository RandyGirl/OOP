#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "Card.h"
#include "Deck.h"
#include "Player.h"


class BlackJack
{
    private:
    Deck deck;
    Player player;

    public:
    BlackJack();
    void hit();
    double probability() const;
    void stand(Player& player);
    void play_game();
};

#endif