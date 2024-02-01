#include<iostream>
using namespace std;

struct Point3D {
	float x, y, z;
};

class PointList {
	Point3D* arr;
	int maxSize;
	int curSize;
	int cursor;
public:
    PointList(int maxSize) {
        this->maxSize = maxSize;
        arr = new Point3D[maxSize];
        curSize = 0;
        cursor = -1;
    }

   
    ~PointList() {
        delete[] arr;
    }
    bool isEmpty() {
        if (curSize == 0)
        {
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull() {
        if (curSize == maxSize) {
            return true;
        }
        else {
            return false;
        }
    }

    void insert(Point3D newPoint) {
        if (!isFull()) {
            if (isEmpty()) {
                cursor = 0;
            }
            arr[curSize] = newPoint;
            curSize++;
            cursor++;
        }
    }
    void showStructure() {
        if (curSize == 0)
        {
            cout << "List is empty" << endl;
            
        }
        else {
            for (int i = 0; i < curSize; i++)
            {
                cout <<"(" << arr[i].x << arr[i].y << arr[i].z<<")";

            }
        }
    }

    Point3D getCurser() {
        if (!isEmpty()) {
            Point3D* temp;
            temp = new Point3D[curSize];
            for (int i = 0; i < curSize; i++)
            {
                temp[i].x = arr[i].x;
                temp[i].y = arr[i].y;
                temp[i].z = arr[i].z;

            }
            return *temp;

        }
        else {
            for (int i = 0; i < curSize; i++)
            {
                arr[i].x = -1.0f;
                arr[i].y = -1.0f;
                arr[i].z = -1.0f;

            }
        }
    }
    void gotoBeginning() {
        if (!isEmpty())
        {
            cursor = 0;

        }

    }
    void gotoEnd() {
        cursor = curSize;
    }
    bool gotoNext() {
    }
    bool goPerior() {

        if (cursor != 0 ) {
            cursor--;
            return true;
        }
        else {
            return false;
        }
    }
    void clear() {
        for (int i = 0; i < curSize; i++)
        {
            arr[i].x = 0;
            arr[i].y = 0;
            arr[i].z = 0;

        }

    }
    bool replace(Point3D newPoint) {

        if ((cursor > -1) && cursor < curSize)
        {
        for (int i = 0; i < curSize; i++)
        {
            arr[i].x = newPoint.x;
            arr[i].y = newPoint.y;
            arr[i].z = newPoint.z;

        }
        return true;
        }
    }
    void remove() {
        arr[cursor].x = arr[curSize].x;
        arr[cursor].x = arr[curSize].x;
        arr[cursor].x = arr[curSize].x;

        arr[cursor].x = 0;
        arr[cursor].y = 0;
        arr[cursor].z = 0;
        curSize--;
        if (!isEmpty() && cursor !=0 )
        {
            cursor = curSize;
        }
        else {
            cursor = 0;
        }
     
   
    }


};
int main() {
    Point3D s1 = { 1, 2, 3 };
    Point3D s2 = { 4, 5, 6 };
    PointList a1(5);
    a1.insert(s1);
    a1.insert(s2);
    //a1.remove();
    
    a1.showStructure();

}




