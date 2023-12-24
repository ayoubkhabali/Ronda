// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include "deckofcards.h"
#include <QList>
#include <QRandomGenerator>

class Player
{
public:
    Player(DeckOfCards& deck, QString playerName);

    QList<Card>& getHand() ;
    int getEarning() const ;
    void setEarning(int earning);
     QString getPlayerName()  ;
    void shuffleCards();
     void playCard(const Card& card) ;
    void updateEarning(int value) ;
    void drawInitialCards();
    int handSize = 4;




private:
    DeckOfCards& deck;
    mutable QList<Card> hand;
    QString playerName;
    mutable int totalEarning=0;


};

#endif // PLAYER_H
