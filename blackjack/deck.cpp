#include "Deck.h"
#include "card.cpp"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>



void Deck::copy(const Deck& other)
{
    this->size = other.size;
    this->cards = new Card[this->size];
    strcpy(this->series, other.series);
    for(size_t i = 0; i < this->size; i++)
    {
        this->cards[i] = other.cards[i];
    }
    this->drawnCards = other.drawnCards;
}
void Deck::erase()
{
    delete [] this->cards;
}
void Deck::fill_deck(size_t _size)
{
   Deck standart;
   const size_t SIZE = 100;
   size_t counter = 0;
   for(size_t i = 0; i < SIZE; i++)
   {
       for(size_t j = 0; j < 52; j++)
       {
           this->cards[counter] = standart.cards[j];
           if(counter == _size - 1)
           {
               break;
           }
           counter++;
       }
   }
   this->shuffle_deck();
}
void Deck::shuffle_deck()
{
    srand(time(NULL));
    std::random_shuffle(this->cards, cards + this->size);
}
Deck::Deck()
{
    this->size = 52;
    this->cards = new Card[this->size];
    strcpy(this->series, "Default");
    this->drawnCards = 0;

    char suits[4][9] = {"hearts", "diamonds", "clubs", "spades"};
    char values[13][3] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    
    size_t counter = 0;
    for(size_t i = 0; i < 4; i++)
    {
        for(size_t j = 0; j < 13; j++)
        {
            cards[counter] = Card(suits[i], values[j], this->series);
            counter++;
        }
    }
    this->shuffle_deck();
}
Deck::Deck(size_t k, const char s[10])
{
    this->size = k;
    this->cards = new Card[this->size];
    if(s == nullptr)
    {
        s = "Custom";
    }
    strcpy(this->series, s);
    this->fill_deck(this->size);
    for(size_t i = 0; i < this->size; i++)
    {
        this->cards[i].set_serialNum(this->series);
    }
    this->drawnCards = 0;
}
Deck::Deck(const Deck& other)
{
    this->copy(other);
}
Deck& Deck::operator=(const Deck& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}
Card Deck::draw()
{
    Card temp = this->cards[0];
    for(size_t i = 0; i < this->size - 1; i++)
    {
        this->cards[i] = this->cards[i + 1];
    }
    this->cards[this->size - 1] = temp;
    this->drawnCards++;

    return cards[this->size - 1];
}
void Deck::swap(int one, int two)
{
    if(one <= this->size-1 && two <= this->size-1)
    {
        Card temp = this->cards[one];
        this->cards[one] = this->cards[two];
        this->cards[two] = temp;
    }
}
int Deck::suit_count(const char _suit[9]) const
{
    int counter = 0;
    for(size_t i = 0; i < this->size; i++)
    {
        if(strstr(this->cards[i].get_suit(), _suit) != nullptr)
        {
            counter++;
        }
    } 
    return counter;
}
size_t Deck::rank_count(const char _value[3]) const
{
    int counter = 0;
    for(size_t i = 0; i < this->size - this->drawnCards; i++)
    {
        if(strstr(this->cards[i].get_value(), _value) != nullptr)
        {
            counter++;
        }
    }
    return counter;
}
size_t Deck::valueCounter(size_t pointsLeft) const
{
    if(pointsLeft == 1 || pointsLeft == 11) {return rank_count("A");}
    if(pointsLeft == 2) {return rank_count("2");}
    if(pointsLeft == 3) {return rank_count("3");}
    if(pointsLeft == 4) {return rank_count("4");}
    if(pointsLeft == 5) {return rank_count("5");}
    if(pointsLeft == 6) {return rank_count("6");}
    if(pointsLeft == 7) {return rank_count("7");}
    if(pointsLeft == 8) {return rank_count("8");}
    if(pointsLeft == 9) {return rank_count("9");}
    if(pointsLeft == 10) 
    {
        size_t counter = 0;
        counter += rank_count("10");
        counter += rank_count("J");
        counter += rank_count("Q");
        counter += rank_count("K");
        return counter;
    }
}
size_t Deck::numOfNotDrawn() const
{
    int counter = 0;
    for(size_t i = 0; i < this->size - this->drawnCards; i++)
    {
        counter++;
    }
    return counter;
}
void Deck::print() const
{
    for(size_t i = 0; i < this->size; i++)
    {
        this->cards[i].print();
    }
    std::cout << std::endl;
}
void Deck::print_drawnCards() const
{
    for(size_t i = this->size - this->drawnCards; i < this->size; i++)
    {
        this->cards[i].print();
    }
}
Deck::~Deck()
{
    this->erase();
}

