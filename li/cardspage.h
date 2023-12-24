#ifndef CARDSPAGE_H
#define CARDSPAGE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include "player.h"
#include <QPushButton>
#include <QLabel>
#include "deckofcards.h"
#include "card.h"

namespace Ui {
class CardsPage;
}

class CardsPage : public QWidget
{
    Q_OBJECT

private slots:
    void onPlayerCardClicked(Player& player, const Card& card);
    void exitGame();


public:
    explicit CardsPage(QWidget *parent = nullptr);
    ~CardsPage();

    void displayCardDeck();
    void displayPlayerCards(Player& player, bool showFaceUp);
    void displayCards(QGraphicsScene* scene,  QList<Card>& cards);
    void initializeKa3a();
    void whoWin();
    void playRandomCard(QList<Card>& ka3a,Player& player);
    void setSelectedDifficulty(int difficulty);
    void resetGame();

private:
    Ui::CardsPage *ui;
    QGraphicsScene *cardDeckScene;
    QGraphicsScene *player1CardsScene;
    QGraphicsScene *player2CardsScene;
    QGraphicsScene *ka3aScene;
    DeckOfCards deckOfCards;
    QGraphicsView *cardDeckView;
    QGraphicsView *player1CardsView;
    QGraphicsView *player2CardsView;
    QGraphicsView *ka3aView;
    QLabel *player1ScoreLabel;
    QLabel *player2ScoreLabel;
    int selectedDifficulty;



    QList<Card> ka3a;
    Player player1;
    Player player2;


    QVBoxLayout *mainLayout;

};

#endif // CARDSPAGE_H
