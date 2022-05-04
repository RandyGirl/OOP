#include "Card.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>


Card::Card()
{
    strcpy(this->suit, "default");
    strcpy(this->value, "0");
    strcpy(this->serialNum, "default");
}
Card::Card(const char _suit[9], const char _value[3], const char _serialNum[15])
{
    strcpy(this->suit, _suit);
    strcpy(this->value, _value);
    strcpy(this->serialNum, _serialNum);
}
const char* Card::get_suit() const
{
    return this->suit;
}
const char* Card::get_value() const
{
    return this->value;
}
void Card::set_serialNum(char _series[10])
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWSYZ";
    std::random_shuffle(alphabet, alphabet + 56);
    strcpy(this->serialNum, _series);
    strncat(this->serialNum, alphabet, 4);
    
}
void Card::print() const
{
    std::cout << this->value << "(" << this->suit << ")" << " " ;
}

void Card::operator= (const Card& other)
{
    strcpy(this->suit, other.suit);
    strcpy(this->value, other.value);
    strcpy(this->serialNum, other.serialNum);
}
