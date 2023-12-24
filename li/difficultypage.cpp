#include "difficultypage.h"
#include "ui_difficultypage.h"

DifficultyPage::DifficultyPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DifficultyPage)
{
    ui->setupUi(this);
}

DifficultyPage::~DifficultyPage()
{
    delete ui;
}
