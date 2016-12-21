#ifndef ITEM
#define ITEM

enum ItemShape { NoShape, LineShape, SquareShape,SShape,ZShape, LShape,   
                   MirroredLShape, TShape};

class Item
{
public:
    Item() { setShape(NoShape); }
    ~Item(){}
    void setRandomShape();
    ItemShape shape() const { return pieceShape; }
    int x(int index) const { return coords[index][0]; }
    int y(int index) const { return coords[index][1]; }
    Item rotatedLeft() const;
    Item rotatedRight() const;
    int shapenum;
    

private:
    void setX(int index, int x) { coords[index][0] = x; }
    void setY(int index, int y) { coords[index][1] = y; }
    void setShape(ItemShape shape);
    ItemShape pieceShape;
    int coords[4][2];
};

#endif