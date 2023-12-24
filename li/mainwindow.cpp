#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "starterpage.h"
#include "cardspage.h"
#include <QDialog>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);

    starterPage = new StarterPage(this);
    connect(starterPage, &StarterPage::playClicked, this, &MainWindow::startGame);
    connect(starterPage, &StarterPage::quitClicked, this, &MainWindow::quitGame);

    cardsPage = new CardsPage(this);

    stackedWidget->addWidget(starterPage);
    stackedWidget->addWidget(cardsPage);

    setCentralWidget(stackedWidget);

    setWindowTitle("Card Game");

    setStyleSheet(
        "QMainWindow {background-image : url(':/image/He.jpg'); background-size: cover;}"

        );


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startGame()
{
    // Create a difficulty selection dialog
    QDialog difficultyDialog(this);
    difficultyDialog.setWindowTitle("Select Difficulty");
    difficultyDialog.resize(400, 200);

    // Create layout for the dialog
    QVBoxLayout dialogLayout(&difficultyDialog);

    // Create radio buttons for difficulty options
    QRadioButton easyButton("Easy", &difficultyDialog);
    QRadioButton mediumButton("Medium", &difficultyDialog);
    QRadioButton hardButton("Hard", &difficultyDialog);

    // Add radio buttons to the layout
    dialogLayout.addWidget(&easyButton);
    dialogLayout.addWidget(&mediumButton);
    dialogLayout.addWidget(&hardButton);

    // Create a button to confirm the selection
    QPushButton confirmButton("Start Game", &difficultyDialog);
    dialogLayout.addWidget(&confirmButton);

    // Connect the button click to a lambda function
    connect(&confirmButton, &QPushButton::clicked, &difficultyDialog, [&]() {
        // Handle the difficulty selection here
        if (easyButton.isChecked()) {
            selectedDifficulty = 1;  // You can use an enum or other values based on your needs
        } else if (mediumButton.isChecked()) {
            selectedDifficulty = 2;
        } else if (hardButton.isChecked()) {
            selectedDifficulty = 3;
        }

        // Close the dialog
        difficultyDialog.accept();


        qDebug() << "Selected Difficulty: " << selectedDifficulty;

        // Set the selected difficulty for the CardsPage instance
        cardsPage->setSelectedDifficulty(selectedDifficulty);



        // Switch to the game page
        stackedWidget->setCurrentIndex(1);

    });

    // Show the difficulty selection dialog
    difficultyDialog.exec();
}


void MainWindow::quitGame()
{
    QApplication::quit();
}
