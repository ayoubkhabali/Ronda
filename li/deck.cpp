// deck.cpp
#include "deck.h"
#include "card.h"
#include <QTime>
#include <QtAlgorithms>

Deck::Deck()
{
    // Initialize the deck with cards
    for (int i = 0; i <= 39; i++)
    {
        Card card(QPixmap(":/image/cards/" + QString::number(i) + ".gif"), "DHAB", i, i);
        cards.append(card);
    }

    // Add the rest of the cards...

    // Ensure that the paths and filenames are correct
}

void Deck::shuffle()
{
   srand(static_cast<uint>(QTime::currentTime().msec()));
    std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::dealCard()
{
    if (cards.isEmpty())
        return Card(QPixmap(), "", 0, 0);

    Card card = cards.takeFirst();
    return card;
}
