#include <windows.h>
#include <iostream>
#include <cstdlib>

class CShape
{
public:
    int color;
    virtual void draw(int x, int y, HDC device_context) = 0;
};

class CLine : public CShape
{
private:
    int length;
public:
    void draw(int x, int y, HDC device_context);

    CLine(int length, int color);
};

class CCircle : public CShape
{
private:
    int radium;
public:
    void draw(int x, int y, HDC device_context);

    CCircle(int radium, int color);
};

class CRectangle : public CShape
{
protected:
    int width, height;
public:
    void draw(int x, int y, HDC device_context);

    CRectangle() {};
    CRectangle(int width, int height, int color);
};

class CSquare : public CRectangle
{
public:
    CSquare(int side, int color);
};

class CPicture
{
public:
    CShape* Arr_ptr[4]; 
};