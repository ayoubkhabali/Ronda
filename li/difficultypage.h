#ifndef DIFFICULTYPAGE_H
#define DIFFICULTYPAGE_H

#include <QDialog>

namespace Ui {
class DifficultyPage;
}

class DifficultyPage : public QDialog
{
    Q_OBJECT

signals:
    void difficultySelected(QString difficulty);


public:
    explicit DifficultyPage(QWidget *parent = nullptr);
    ~DifficultyPage();

private:
    Ui::DifficultyPage *ui;
};

#endif // DIFFICULTYPAGE_H
