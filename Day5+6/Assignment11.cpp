#include "Assignment11.h"

using namespace std;

CLine::CLine(int length, int color)
{
    this->length = length;
    this->color = color;
}

/******************************
* Function name: draw()
* Description:  draw line
* Parameter: 
        x: coordinates 
        y: coordinates
        device_context: Handle to Device Context - used to obtain graphical components
* Return value: void
*******************************/
void CLine::draw(int x, int y, HDC device_context)
{
    HPEN pen = CreatePen(PS_SOLID, 5, RGB(color, 0, 0));
    SelectObject(device_context, pen);

    LineTo(device_context, x + length, y);
}

CCircle::CCircle(int radium, int color)
{
    this->radium = radium;
    this->color = color;
}

/******************************
* Function name: draw()
* Description:  draw circle
* Parameter:
        x: coordinates
        y: coordinates
        device_context: Handle to Device Context - used to obtain graphical components
* Return value: void
*******************************/
void CCircle::draw(int x, int y, HDC device_context)
{
    HPEN pen = CreatePen(PS_SOLID, 5, RGB(color, 0, 0));
    SelectObject(device_context, pen);

    Ellipse(device_context, x, y, x + 2 * radium, y + 2 * radium);
}

CRectangle::CRectangle(int width, int height, int color)
{
    this->width = width;
    this->height = height;
    this->color = color;
}

/******************************
* Function name: draw()
* Description:  draw rectangle
* Parameter:
        x: coordinates 
        y: coordinates
        device_context: Handle to Device Context - used to obtain graphical components
* Return value: void
*******************************/
void CRectangle::draw(int x, int y, HDC device_context)
{
    HPEN pen = CreatePen(PS_SOLID, 5, RGB(color, 0, 0));
    SelectObject(device_context, pen);

    Rectangle(device_context, x, y, x + width, y + height);
}

CSquare::CSquare(int side, int color)
{
    this->width = side;
    this->height = side;
    this->color = color;
}

int main()
{
    CPicture Picture;
    Picture.Arr_ptr[0] = new CLine(50, 255);
    Picture.Arr_ptr[1] = new CCircle(50, 255);
    Picture.Arr_ptr[2] = new CRectangle(50, 30, 255);
    Picture.Arr_ptr[3] = new CSquare(50, 255);

    int Array_CoordinatesX[4];
    int Array_CoordinatesY[4];

    for (int i = 0; i < 4; i++)
    {
        cout << "Input coordinate of Shape " << i + 1 << endl;
        cout << "X: ";
        cin >> Array_CoordinatesX[i];
        cout << "Y: ";
        cin >> Array_CoordinatesY[i];
    }

    cout << "Enter your order of image: (1234, ...) " << endl;
    cout << "1. Line " << endl;
    cout << "2. Circle " << endl;
    cout << "3. Rectangle " << endl;
    cout << "4. Square " << endl;
    cout << "0. Exit" << endl;

    string order;
    while (1)
    {
        cout << " Enter your order: ";
        cin >> order;
        
        // Get window handle to console, and device context
        HWND console_handle = GetConsoleWindow();
        HDC device_context = GetDC(console_handle);
        int int_input;
        for (int i = 0; i < 4; i++)
        {
            int_input = order[i] - '0';
            if (int_input < 1 || int_input > 4)
                exit(0);
            //Draw a shape
            Picture.Arr_ptr[int_input - 1]->draw(Array_CoordinatesX[i], Array_CoordinatesY[i], device_context);
        }
        ReleaseDC(console_handle, device_context);
    }
}