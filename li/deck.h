// deck.h
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <QList>

class Deck
{
public:
    Deck();
    void shuffle();
    Card dealCard();

private:
    QList<Card> cards;
};

#endif // DECK_H
