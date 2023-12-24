#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <QList>
#include <QObject>
#include "card.h"

class DeckOfCards
{
public:
    DeckOfCards();

    QList<Card>& getDeck() ;
    Card drawCard();

private:
    QList<Card> deck;
    void initializeDeck();
};

#endif // DECKOFCARDS_H
