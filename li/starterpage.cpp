#include "starterpage.h"
#include "ui_starterpage.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsPixmapItem>
StarterPage::StarterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StarterPage)
{
    ui->setupUi(this);

    playButton = new QPushButton("Play", this);
    quitButton = new QPushButton("Quit", this);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setStyleSheet("background: transparent;border:none");

    ui->graphicsView->setScene(scene);
    ui->title->setText("RONDA - Moroccan Playing Cards");
    ui->title->setStyleSheet("font-size: 50px; color : blue;font-weight:900");

    QGraphicsPixmapItem *imgItem = new QGraphicsPixmapItem(QPixmap(":/image/startPage.png"));
    scene->addItem(imgItem);

        setStyleSheet(
            "QPushButton {background-color : blue; border: none; font-weight : 600 ;border-radius : 10%;color:#fff;height:50px; font-size : 30px}"
            );

    playButton->setStyleSheet("min-width: 150px;");

    connect(playButton, &QPushButton::clicked, this, &StarterPage::playClicked);
    connect(quitButton, &QPushButton::clicked, this, &StarterPage::quitClicked);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(ui->title,0,Qt::AlignCenter);
    layout->addWidget(ui->graphicsView,1,Qt::AlignCenter);
    playButton->setFixedSize(150, 50);
    quitButton->setFixedSize(200, 50);
    layout->addWidget(playButton,0,Qt::AlignCenter);
    layout->addWidget(quitButton,0,Qt::AlignCenter);

}

StarterPage::~StarterPage()
{
    delete ui;
}
