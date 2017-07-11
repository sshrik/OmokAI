#include"omok.cpp"
#include<iostream>

using namespace std;

typedef struct{
    int x, y;
}Point;

void printLocation(Location l)    {
    cout << "Class`s value : " << l.GetX() << " " << l.GetY() << endl;
}
void printPoint(Point p)    {
    cout << "Struct`s value : " << p.x << " " << p.y << endl;
}
Location addLocation(Location l)    {
    l.SetX(l.GetX() + 2);
    l.SetY(l.GetY() + 2);
    return l;
}
Point addPoint(Point p)  {
    p.x = p.x + 2;
    p.y = p.y + 2;

    return p;
}

int main()  {
    cout << "======================== Print Test ========================================" << endl;
    /* ======================== Print Test ======================================== */
    Location class_x(2,3);
    Location class_y;

    cout << "Class x`s Address : " << &class_x << endl;
    cout << "Class y`s Address : " << &class_y << endl;

    printLocation(class_x);
    printLocation(class_y);
    
    class_y = class_x;
    // Default Copy Constructor is made and inserted.
    
    cout << "Class x`s Address : " << &class_x << endl;
    cout << "Class y`s Address : " << &class_y << endl;
    
    printLocation(class_x);
    printLocation(class_y);

    Point struct_x, struct_y;
    struct_x.x = 3;
    struct_x.y = 5;
    struct_y.x = 7;
    struct_y.y = 2;
    
    cout << "Struct x`s Address : " << &struct_x << endl;
    cout << "Struct y`s Address : " << &struct_y << endl;

    printPoint(struct_x);
    printPoint(struct_y);

    struct_y = struct_x;
    // struct copy is value copy.

    cout << "Struct x`s Address : " << &struct_x << endl;
    cout << "Struct y`s Address : " << &struct_y << endl;

    printPoint(struct_x);
    printPoint(struct_y);

    /* ======================== Print Test ======================================== */
    cout << "===================== Return Value Test ====================================" << endl;
    /* ===================== Return Value Test ==================================== */
    Location class_z;
    cout << "Class z`s Address : " << &class_z << endl;
    cout << "Class x`s Address : " << &class_x << endl;

    printLocation(class_z);
    printLocation(class_x);
    
    class_z = addLocation(class_x);

    cout << "Class z`s Address : " << &class_z << endl;
    cout << "Class x`s Address : " << &class_x << endl;

    printLocation(class_z);
    printLocation(class_x);

    Point struct_z;
    struct_z.x = 7;
    struct_z.y = 5;
    
    cout << "Struct z`s Address : " << &struct_z << endl;
    cout << "Struct x`s Address : " << &struct_x << endl;

    printPoint(struct_z);
    printPoint(struct_x);

    struct_z = addPoint(struct_x);
    // struct copy is value copy.

    cout << "Struct z`s Address : " << &struct_z << endl;
    cout << "Struct x`s Address : " << &struct_x << endl;

    printPoint(struct_z);
    printPoint(struct_x);
    /* ===================== Return Value Test ==================================== */
    cout << "======================= Raw Print Test =====================================" << endl;
    /* ======================= Raw Print Test ===================================== */
    //cout << class_x << endl; -> Error Occured!
    //cout << struct_x << endl; -> Error Occured!
    /* ======================= Raw Print Test ===================================== */

    return 0;
}