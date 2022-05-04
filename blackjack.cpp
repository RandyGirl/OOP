#include "BlackJack.h"
#include <cstring>


const size_t SIZE = 40;
BlackJack::BlackJack()
{
     char name[SIZE];
    size_t age;

    std::cout << "Chose a player or enter a new player: ";
    std::cin.getline(name, SIZE);
    std::cout << "Enter your age: ";
    std::cin >> age;
    if(age < 18 || age > 90)
    {
        std::cout << "Sorry! This game is not for your age!";
    }
    else
    {
        this->player = Player(name, age);
        std::cout << "You will play as " << this->player.get_name() << ". Choоse the size of the deck: " << std::endl;
        size_t sizeOfDeck;
        std::cin >> sizeOfDeck;
        this->deck = Deck(sizeOfDeck, nullptr);
    }
}
void BlackJack::hit()
{
    Card current = deck.draw();
    this->player.set_crrNumPt(player.points(current));
    this->deck.print_drawnCards();
    this->player.print_crrPt();
}
double BlackJack::probability() const
{
    if(21 - this->player.get_crrNumPt() > 11) {return 0;}
    size_t pointsLeft = 21 - this->player.get_crrNumPt();
    double result = (double)deck.valueCounter(pointsLeft) / deck.numOfNotDrawn();
    return result;
}
void BlackJack::stand(Player& player)
{
    Player dealer;
    while(dealer.get_crrNumPt() < 17 && dealer.get_crrNumPt() <= 21)
    {
       Card current = this->deck.draw();
       dealer.set_crrNumPt(dealer.points(current));
       current.print();
    }
    dealer.print_crrPt();

    if(dealer.get_crrNumPt() > player.get_crrNumPt())
    {
        std::cout << "Dealer wins. You lost." << std::endl;
    }
    if(dealer.get_crrNumPt() <= player.get_crrNumPt())
    {
        std::cout << "Congratulations!!! You WON!!!" << std::endl;
        player.add_wins();
    }
}
void BlackJack::play_game()
{
    if(this->player.get_age() >= 18 && this->player.get_age() <= 90)
    {
        std::cout << "Start!" << std::endl;
        hit();

        for(size_t i = 0; i < SIZE; i++)
        {
            char choice[SIZE];
            std::cout << "Hit/Stand/Probability " << std::endl;
            std::cin >> choice;
            if(strstr(choice, "Hit") != nullptr) 
            {
                hit();
                if(this->player.get_crrNumPt() == 21)
                {
                    std::cout << "Congratulations!!! You WON!!!" << std::endl;
                    break;
                }
                if(this->player.get_crrNumPt() > 21)
                {
                    std::cout << "Dealer wins. You lost." << std::endl;
                    break;
                }
            }
            if(strstr(choice, "Probability") != nullptr) {std::cout << probability() << std::endl;}
            if(strstr(choice, "Stand") != nullptr) {stand(this->player); break;}
        }
        player.addgame();
        player.set_winrate();

        std::cout << "Thank you for playing!" << std::endl;
    }
}