// player.cpp
#include "player.h"
#include <algorithm>
#include <QDebug>

Player::Player(DeckOfCards& deck, QString playerName) : deck(deck), playerName(playerName)
{

        drawInitialCards();

}

void Player::setEarning(int earning) {
        this->totalEarning = earning;
}

void Player::drawInitialCards()
{
                int limit;
                deck.getDeck().size() == 4 || deck.getDeck().size() == 2 ? limit = 2 : limit = 4;
                for (int i = 0; i < limit; ++i) {
                    // Draw a card from the deck
                    const Card& drawnCard = deck.drawCard();

                    // Add the drawn card to the player's hand
                    hand.append(drawnCard);
                }




}

QList<Card>&  Player::getHand()
{
    return hand;
}

int Player::getEarning() const
{
    return totalEarning;
}
QString Player::getPlayerName()  {
    return playerName;
}

void Player::shuffleCards()
{
    // Use Qt's algorithm to shuffle the cards
    std::random_shuffle(hand.begin(), hand.end());
}

void Player::updateEarning(int value)
{
    totalEarning += value;
}

void Player::playCard(const Card& card)
{
    auto it = std::find(hand.begin(), hand.end(), card);
    if (it != hand.end())
    {
        hand.erase(it);
    }
}






