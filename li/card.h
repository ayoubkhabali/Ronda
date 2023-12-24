
#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QPixmap>


class Card
{
public:
    Card(int id, const QString &imagePath, int value, const QString &type);

    int getId() const;
    const QPixmap& getImage() const;
    int getValue() const;
    const QString& getType() const;
    bool operator==(const Card& other) const {
        return id == other.id && value == other.value && type == other.type;
    }


private:
    int id;
    QPixmap image;
    int value;
    QString type;
};

#endif // CARD_H
