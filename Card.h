#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card
{
    private:
    char suit[9];
    char value[3];
    char serialNum[15];

    public:
    Card();
    Card(const char _suit[9], const char _value[3], const char _serialNum[15]);
    const char* get_suit() const;
    const char* get_value() const;
    void set_serialNum(char _series[10]);
    void print() const;
    void operator= (const Card& other);
};


#endif