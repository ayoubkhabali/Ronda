#include "card.h"
#include "player.h"
#include "deckofcards.h"
#include "cardspage.h"
#include "ui_cardspage.h"
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QPointer>
#include "clickablepixmapitem.h"


CardsPage::CardsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardsPage),
    player1(deckOfCards,"Player 1"),
    player2(deckOfCards,"Computer")
{
    ui->setupUi(this);
    initializeKa3a();



    // Initialize scenes
    cardDeckScene = new QGraphicsScene(this);
    player1CardsScene = new QGraphicsScene(this);
    player2CardsScene = new QGraphicsScene(this);

    // Set transparent background for scenes
    cardDeckScene->setBackgroundBrush(Qt::NoBrush);
    player1CardsScene->setBackgroundBrush(Qt::NoBrush);
    player2CardsScene->setBackgroundBrush(Qt::NoBrush);

    // Initialize QGraphicsViews
    cardDeckView = new QGraphicsView(cardDeckScene, this);
    player1CardsView = new QGraphicsView(player1CardsScene, this);
    player2CardsView = new QGraphicsView(player2CardsScene, this);


    cardDeckView->setFixedSize(150, 150);
    player1CardsView->setFixedSize(600, 150);
    player2CardsView->setFixedSize(600, 150);


    cardDeckView->setStyleSheet("background: transparent;border:none;");
    player1CardsView->setStyleSheet("background: transparent;border:none");
    player2CardsView->setStyleSheet("background: transparent;border:none");


    ka3aScene = new QGraphicsScene(this);

    ka3aView = new QGraphicsView(ka3aScene, this);
    ka3aView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ka3aView->setFixedHeight(150);
    ka3aView->setFixedWidth(1000);
    ka3aView->setStyleSheet("background: transparent; border: none;");
    ka3aScene->setBackgroundBrush(Qt::NoBrush);

    ka3aView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ka3aView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ka3aView->show();


    displayCards(ka3aScene, ka3a);
//     Create a QHBoxLayout for ka3aView and cardDeckView
    QHBoxLayout *ka3aAndCardDeckLayout = new QHBoxLayout;

//     Add ka3aView and cardDeckView to the layout
    ka3aAndCardDeckLayout->addWidget(ka3aView);
    ka3aAndCardDeckLayout->addWidget(cardDeckView);





    // Set scenes to QGraphicsViews
    ui->verticalLayout->addWidget(ui->player2Name,0,Qt::AlignCenter);
    ui->verticalLayout->addWidget(player2CardsView,0,Qt::AlignLeft);

    ui->verticalLayout->addStretch();
    ui->verticalLayout->addLayout(ka3aAndCardDeckLayout);  // Use the QHBoxLayout here
    ui->verticalLayout->addStretch();

    ui->verticalLayout->addWidget(player1CardsView,0,Qt::AlignRight);
    ui->verticalLayout->addWidget(ui->player1Name,0,Qt::AlignCenter);



    ui->player1Name->setText(player1.getPlayerName());
    ui->player2Name->setText(player2.getPlayerName());

    ui->player1Name->setStyleSheet(" font-size: 14px; color: blue;font-weight: 800;");
    ui->player2Name->setStyleSheet(" font-size: 14px; color: blue;font-weight: 800;");

    // Display the card deck and player cards
    displayCardDeck();
    displayPlayerCards(player1,true);
    displayPlayerCards(player2,false);
    // Inside the constructor of CardsPage
    player1ScoreLabel = new QLabel(this);
    player2ScoreLabel = new QLabel(this);

    // Set initial scores
    player1ScoreLabel->setText("Player 1 Score: 0");
    player2ScoreLabel->setText("Player 2 Score: 0");

    player1ScoreLabel->setStyleSheet("background-color: white; color: red; font-size: 16px;");
    player2ScoreLabel->setStyleSheet("background-color: white; color: red; font-size: 16px;");


    // Add labels to the layout
    ui->verticalLayout->addWidget(player1ScoreLabel, 0, Qt::AlignRight);
    ui->verticalLayout->addWidget(player2ScoreLabel, 0, Qt::AlignLeft);


}


CardsPage::~CardsPage()
{
    delete ui;
}

void CardsPage::displayPlayerCards(Player& player, bool showFaceUp)
{

    const QList<Card>& playerHand = player.getHand();

    QGraphicsScene* playerScene;
    QGraphicsView* playerView;

    if (&player == &player1) {
        playerScene = player1CardsScene;
        playerView = player1CardsView;
    } else if (&player == &player2) {
        playerScene = player2CardsScene;
        playerView = player2CardsView;
    } else {
        // Handle unexpected player instance
        return;
    }

    // Clear existing items in the scene
    playerScene->clear();

    // Set transparent background for scenes
    playerScene->setBackgroundBrush(Qt::NoBrush);

    int col = 1;
    // Display player cards
    playerView->setScene(playerScene);
    for (const Card& card : playerHand) {
        ClickablePixmapItem* cardItem;

        if (showFaceUp || &player == &player1) {
            // Display face-up cards for player1 or if explicitly requested
            cardItem = new ClickablePixmapItem(card.getImage());
        } else {
            // Display back card image for player2
            cardItem = new ClickablePixmapItem(QPixmap(":/image/cards/back.gif")); // Replace with actual path
        }

        playerScene->addItem(cardItem);
        cardItem->setPos(col * 100, 0);

        cardItem->setFlag(QGraphicsItem::ItemIsSelectable);

        if (&player == &player1) {
            // Connect the clicked signal to a lambda function
            connect(cardItem, &ClickablePixmapItem::clicked, this, [this, player, cardItem, card, playerScene, playerView]() mutable {
                // Disconnect the signal to prevent further invocations

                // Call the slot function
                onPlayerCardClicked(player, card);

                // Check if the item still belongs to the correct scene
                if (cardItem->scene() && cardItem->scene() == playerScene) {
                    // Remove the item from the scene
                    playerScene->removeItem(cardItem);

                    // Optional: Allow the scene to manage the item's memory
                    cardItem->setParent(nullptr);

                    // Optional: Explicitly delete the item if needed
                    delete cardItem;
                }
            });
        }
        col++;
    }// Set scene to QGraphicsView
}


void CardsPage::onPlayerCardClicked(Player& player, const Card& card)
{
    // Play the card (remove it from the player's hand)
    player.playCard(card);

    QList<Card> matchingCards;

    matchingCards.clear();
    // Check if the played card matches any card in ka3a
    for (auto it = ka3a.begin(); it != ka3a.end(); ) {
        const Card& ka3aCard = *it;

        if (ka3aCard.getValue() == card.getValue()) {
            matchingCards.append(ka3aCard);
            it = ka3a.erase(it);

            // Keep incrementing and checking for consecutive values
            int nextValue = card.getValue() + 1;
            while (true) {
                auto nextValueCardIt = std::find_if(ka3a.begin(), ka3a.end(),
                                                    [nextValue](const Card& c) { return c.getValue() == nextValue; });

                if (nextValueCardIt != ka3a.end()) {
                    matchingCards.append(*nextValueCardIt);
                    it = ka3a.erase(nextValueCardIt);
                    nextValue++;
                } else {
                    break;
                }
            }
        } else {
            ++it;
        }
    }

    if (matchingCards.isEmpty()) {
        ka3a.append(card);
    }
    player1.handSize--;

    // Update the player's earning based on the number of removed cards (including the played card)
    if (!matchingCards.isEmpty())
    player1.updateEarning(matchingCards.size()+1);

    // Update the display to reflect the changes
    displayPlayerCards(player, true);
    ka3aScene->clear();
    displayCards(ka3aScene, ka3a);
    matchingCards.clear();

    // If the current player is player1, let player2 play a random card
    QTimer::singleShot(900, this, [this]() {
        playRandomCard(ka3a, player2);
        player2.handSize--;
        displayPlayerCards(player2, false); // Update the display for player2
        ka3aScene->clear();
        displayCards(ka3aScene, ka3a);

        if (player1.handSize == 0) {
            player1.getHand().clear();
            player2.getHand().clear();
            player1.drawInitialCards();
            player2.drawInitialCards();
            displayPlayerCards(player1, true);
            displayPlayerCards(player2, false);
            player1.handSize = 4;
            player2.handSize = 4;
            qDebug() << "CardDeck : " << deckOfCards.getDeck().size();

        }

        if (deckOfCards.getDeck().isEmpty()) {
            cardDeckScene->clear();
        }

        player1ScoreLabel->setText("Player 1 Score: " + QString::number(player1.getEarning()));
        player2ScoreLabel->setText("Computer Score: " + QString::number(player2.getEarning()));

        if (player2.getHand().isEmpty() && deckOfCards.getDeck().isEmpty()) {
            player1.getHand().clear();
        }



        if (player1.getHand().isEmpty() && player2.getHand().isEmpty() && deckOfCards.getDeck().isEmpty()) {
            whoWin();
        }


    });





}





void CardsPage::displayCards(QGraphicsScene* scene,  QList<Card>& cards)
{
    int col = 0;

    for (const Card& card : cards) {
        QGraphicsPixmapItem *cardItem = new QGraphicsPixmapItem(card.getImage());
        scene->addItem(cardItem);
        cardItem->setPos(col * 100, 0); // Adjust spacing as needed

        cardItem->setFlag(QGraphicsItem::ItemIsSelectable);


        col++;
    }
}



void CardsPage::displayCardDeck()
{

    for (int i=1;i<5;i++) {
        QGraphicsPixmapItem *cardItem = new QGraphicsPixmapItem(QPixmap(":/image/cards/back.gif"));
        cardDeckScene->addItem(cardItem);
        cardItem->setPos(i * 2, 0); // Adjust spacing as needed
    }

}




void CardsPage::initializeKa3a()
{
    // Clear existing cards in ka3a
    ka3a.clear();

    // Keep track of unique values
    QSet<int> uniqueValues;

    // Add 4 cards with unique values
    while (ka3a.size() < 4) {
        Card newCard = deckOfCards.drawCard();
        int cardValue = newCard.getValue();

        // Check if the value is unique
        if (!uniqueValues.contains(cardValue)) {
            ka3a.append(newCard);

            // Mark the value as used
            uniqueValues.insert(cardValue);
        } else {
            deckOfCards.getDeck().append(newCard);
        }

    }


}




void CardsPage::playRandomCard(QList<Card>& ka3a, Player& player)
{
    int difficulty = selectedDifficulty;

    int randomIndex;
    QList<Card> matchingCards;

    if (difficulty == 1) {
        randomIndex = rand() % player.getHand().size();
    }

    if (difficulty == 2) {
        int matchingCardIndex = -1;

        for (int i = 0; i < player.getHand().size(); ++i) {
            const Card& playerCard = player.getHand()[i];

            auto matchingCardIt = std::find_if(ka3a.begin(), ka3a.end(),
                                               [playerCard](const Card& c) { return c.getValue() == playerCard.getValue(); });

            if (matchingCardIt != ka3a.end()) {
                matchingCardIndex = i;
                break;
            }
        }

        if (matchingCardIndex != -1) {
            // Player has a matching card, play it
            randomIndex = matchingCardIndex;
        } else {
            // No matching card found, play a random card
            randomIndex = rand() % player.getHand().size();
        }
    }


    if (difficulty == 3) {
        QList<int> playerCardValues;

        // Check if there's a card with the same value in ka3a
        for (const Card& ka3aCard : ka3a) {
            auto matchingCardIt = std::find_if(player.getHand().begin(), player.getHand().end(),
                                               [ka3aCard](const Card& c) { return c.getValue() == ka3aCard.getValue(); });

            if (matchingCardIt != player.getHand().end()) {
                // Player has a matching card, play it
                randomIndex = player.getHand().indexOf(*matchingCardIt);
                break;
            }
        }

        // If no matching card was found in player's hand, play a card that doesn't exist in player's hand
        if (matchingCards.isEmpty()) {
            for (const Card& ka3aCard : ka3a) {
                if (!playerCardValues.contains(ka3aCard.getValue())) {
                    randomIndex = rand() % player.getHand().size();
                    break;
                }
            }
        }
    }

    Card randomCard = player.getHand()[randomIndex];
    player.playCard(randomCard);

    // Check if the played card matches any card in ka3a
    for (auto it = ka3a.begin(); it != ka3a.end(); ) {
        const Card& ka3aCard = *it;

        if (ka3aCard.getValue() == randomCard.getValue()) {
            matchingCards.append(ka3aCard);
            it = ka3a.erase(it);

            // Keep incrementing and checking for consecutive values
            int nextValue = randomCard.getValue() + 1;
            while (true) {
                auto nextValueCardIt = std::find_if(ka3a.begin(), ka3a.end(),
                                                    [nextValue](const Card& c) { return c.getValue() == nextValue; });

                if (nextValueCardIt != ka3a.end()) {
                    matchingCards.append(*nextValueCardIt);
                    it = ka3a.erase(nextValueCardIt);
                    nextValue++;
                } else {
                    break;
                }
            }
        } else {
            ++it;
        }
    }

    if (matchingCards.isEmpty()) {
        ka3a.append(randomCard);
    }

    if (!matchingCards.isEmpty()) {
        player.updateEarning(matchingCards.size() + 1);
    }
}




void CardsPage::setSelectedDifficulty(int difficulty) {
    selectedDifficulty = difficulty;
}


void CardsPage::whoWin()
{
    if (player1.getHand().isEmpty() && player2.getHand().isEmpty() && cardDeckScene->items().isEmpty()) {
        int player1Score = player1.getEarning();
        int player2Score = player2.getEarning();

        QString winnerMessage;

        if (player1Score > player2Score) {
                winnerMessage = "Player 1 wins!";
        } else if (player2Score > player1Score) {
                winnerMessage = "Player 2 wins!";
        } else {
                winnerMessage = "It's a tie!";
        }

        QString scoreMessage = "Player 1 Score: " + QString::number(player1Score) +
                               "\nPlayer 2 Score: " + QString::number(player2Score);


        QMessageBox msgBox;
        msgBox.setText(winnerMessage + "\n\n" + scoreMessage);
        msgBox.setWindowTitle("Game Over");
        msgBox.setStyleSheet("QMessageBox { background-color: lightgray; }");

        // Set the size as per your requirement
        msgBox.resize(400, 600);

        connect(&msgBox, &QMessageBox::accepted, this, &CardsPage::exitGame);

        msgBox.exec();


    }
}


void CardsPage::exitGame()
{
    qApp->exit();  // Exit the application
}


