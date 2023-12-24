// difficultydialog.cpp
#include "difficultydialog.h"
#include "ui_difficultydialog.h"

DifficultyDialog::DifficultyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DifficultyDialog)
{
    ui->setupUi(this);
}

DifficultyDialog::~DifficultyDialog()
{
    delete ui;
}

QString DifficultyDialog::getSelectedDifficulty() const
{

    if (ui->easyRadioButton->isChecked()) {
        return "Easy";
    } else if (ui->middleRadioButton->isChecked()) {
        return "Middle";
    } else if (ui->difficultRadioButton->isChecked()) {
        return "Difficult";
    } else {
        // Default to Easy if none is selected
        return "Easy";
    }
}
