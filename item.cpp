#include <QtCore>

#include <stdlib.h>

#include "item.h"

void Item::setRandomShape()
{    shapenum=qrand() % 7 + 1;
     setShape(ItemShape(shapenum));
}

void Item::setShape(ItemShape shape)
{
    static const int coordsTable[8][4][2] = {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },
        { { 0, 0 },  { 0, -2 },   { 0, -1 },  { 0, 1 } },
        { { 0, 0 },  { -1, 0 },   { -1, 1 },   { 0, 1 } },
        { { 0, 0 },  { 0, -1 },   { 1, 0 },   { 1, 1 } },
        { { 0, 0 },  { 1, 0 },   { 1, -1 },   { 0, 1 } },
        { { 0, 0 },   { 1, 1 },   { 0, -1 },   { 0, 1 } },
        { { 0,0 }, { 0, -1 },  { -1,1 },   { 0, 1 } },
        { { 0,0 },  { 0, -1 },  { -1, 0 },   { 1,0 } }
    };

    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
            coords[i][j] = coordsTable[shape][i][j];
    }
    pieceShape = shape;
}


Item Item::rotatedLeft() const
{
    if (pieceShape == SquareShape)
        return *this;

    Item result;
    result.pieceShape = pieceShape;
    for (int i = 0; i < 4; ++i) {
        result.setX(i, y(i));
        result.setY(i, -x(i));
    }
    result.shapenum=this->shapenum;
    return result;
}

Item Item::rotatedRight() const
{
    if (pieceShape == SquareShape)
        return *this;

    Item result;
    result.pieceShape = pieceShape;
    for (int i = 0; i < 4; ++i) {
        result.setX(i, -y(i));
        result.setY(i, x(i));
    }
    result.shapenum=this->shapenum;
    return result;
}