// difficultydialog.h
#ifndef DIFFICULTYDIALOG_H
#define DIFFICULTYDIALOG_H

#include <QDialog>

namespace Ui {
class DifficultyDialog;
}

class DifficultyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DifficultyDialog(QWidget *parent = nullptr);
    ~DifficultyDialog();

    // Add a function to get the selected difficulty
    QString getSelectedDifficulty() const;

private:
    Ui::DifficultyDialog *ui;
};

#endif // DIFFICULTYDIALOG_H
