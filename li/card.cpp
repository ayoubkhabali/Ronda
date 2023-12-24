// card.cpp
#include "card.h"

Card::Card(int id, const QString &imagePath, int value, const QString &type)
    :   id(id), value(value), type(type)
{
    image.load(imagePath);
}

int Card::getId() const
{
    return id;
}

const QPixmap& Card::getImage() const
{
    return image;
}

int Card::getValue() const
{
    return value;
}

const QString& Card::getType() const
{
    return type;
}
