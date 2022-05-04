#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <iostream>

class Deck
{
    private:
    Card* cards;
    size_t size;
    char series[10];
    size_t drawnCards;
    void copy(const Deck& other);
    void erase();
    void fill_deck(size_t size);
    void shuffle_deck();

    public:
    Deck();
    Deck(size_t k, const char s[10]);
    Deck(const Deck& other);
    Deck& operator=(const Deck& other);
    Card draw();
    void swap(int one, int two);
    int suit_count(const char suit[9]) const;
    size_t rank_count(const char _value[3]) const;
    size_t valueCounter(size_t pointsLeft) const;
    size_t numOfNotDrawn() const;
    void print() const;
    void print_drawnCards() const;
    ~Deck();
};


#endif