// deckofcards.cpp
#include "deckofcards.h"
#include <QRandomGenerator>

DeckOfCards::DeckOfCards()
{
    initializeDeck();
}

 QList<Card>& DeckOfCards::getDeck()
{
    return deck;
}


Card DeckOfCards::drawCard()
{


    // Randomly select a card index
    int index = QRandomGenerator::global()->bounded(deck.size());
    Card drawnCard = deck.takeAt(index);
    return drawnCard;
}


void DeckOfCards::initializeDeck()
{
    // Add cards to the deck
    int DHAB = 1;
    int SYOUFA = 1;
    int DBOUZ = 1;
    int TWAJEN = 1;
    for (int i = 1;i<=40;i++) {
        if (i<=10 && i>=1){
            deck.append(Card(i, ":/image/cards/" + QString::number(i) + ".gif", DHAB, "DHAB"));
            DHAB++;
        }

        if (i<=20 && i>=11){
            deck.append(Card(i, ":/image/cards/" + QString::number(i) + ".gif", DBOUZ, "DBOUZ"));
            DBOUZ++;

        }
        if (i<=30 && i>=21){
            deck.append(Card(i, ":/image/cards/" + QString::number(i) + ".gif", SYOUFA, "SYOUFA"));
            SYOUFA++;
        }
        if (i<=40 && i>=31) {
            deck.append(Card(i, ":/image/cards/" + QString::number(i) + ".gif", TWAJEN, "TWAJEN"));
            TWAJEN++;
        }




    }

}
