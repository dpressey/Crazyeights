#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

//=========================================== DECK CLASS ===========================================================//

class deck
{
    public:

        deck();
        ~deck(){/*nothing*/}
        int getCardBoard();
        int const jackSkip();
        int const deuceDraw();


    protected:

        std::vector <int> clubs;
        std::vector <int> spades;
        std::vector <int> hearts;
        std::vector <int> diamonds;

        //this is the vector that holds the cards the player and computer has played
        std::vector<int> gameBoard;

};

deck::deck()
{
    unsigned int i;
    int raise = 1;

/* this loop initializes each of the 4 vectors (the deck) with 14 cards
in each of the card suit vectors */
    for(i = 0; i <= 13; i++)
    {
        spades.push_back(raise);
        diamonds.push_back(raise);
        hearts.push_back(raise);
        clubs.push_back(raise);
        raise++;
    }

}


//======================================= DISTRIBUTE CARD CLASS ======================================================//


/*this class deals out the cards to player and computer, also includes
the draw card function if player/computer doesnt have the card suit to play, also removes a card
from deck for each last card drawn by the player or computer*/

class distributeCard : public deck
{
        public:
            distributeCard();
            ~distributeCard(){ /*nothing*/ }
            int removeCardFromDeck();
            int drawCard();
            int giveCard;

};


distributeCard::distributeCard()
{
    giveCard = (rand() %14 ) + 1;
}


//===================================== PLAYER HAND CLASS =========================================================================//

class playerHand
{
    public:
        void populateHand(std::vector<int>&, int&); //pass the vector by reference in order to add elements into it
        std::vector <int> playerHandVector;

};


void playerHand::populateHand(std::vector<int>& refHand, int& rGiveCard)
{
    for( int i = 0; i < 8; i++)
    {
        refHand.push_back(rGiveCard);
        rGiveCard = (rand()%14) +1;
        int lastCard = refHand[i];
            while (rGiveCard == lastCard)
                {
                    rGiveCard = (rand() %14) + 1;
                }
        std::cout << refHand.at(i) << " ";
    }
}



//================================== Computer Hand ========================================================================//

//================================== MAIN FUNTION ====================================================================//

int main()
{
    srand(time(0));


    distributeCard start;
    playerHand theHand;

    playerHand *pointerPHand = new playerHand;
    distributeCard *pointerDistributeCard = new distributeCard;

    theHand.populateHand(pointerPHand->playerHandVector, pointerDistributeCard->giveCard);

    delete pointerDistributeCard;
    delete pointerPHand;

    return 0;
}
