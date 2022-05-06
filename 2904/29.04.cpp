#include <iostream>
#include <vector>

using namespace std;

 classbase {
public :
	virtual  voidshow() {};
};

template <typename T> class Point2D {
protected :
 T x, y;
public :
	Point2D(T x, T y) {
		this->x = x;
		this->y = y;
	}
};

template <typename T> class Z {
protected :
	T z;
public :
	Z (T z) {
		this->z = z;
	}
};

template <typename T> class H {
protected :
	T h;
public :
	H (T h) {
		this->h = h;
	}
};

template <typename T> class Point3Dh : public Point2D <T>, Z <T>, H <T>, base {
protected:
	bool flag;
public:
	Point3Dh(T x, T y, T z, T h) : Point2D <T> (x, y), Z <T> (z), H <T> (h) {
		flag = false;
		if (this->h == 0) {
			flag = true;
		}
	}
	void show () {
		if (flag == false) {
			cout << "Реальные координаты объекта : " << "(" << this->x / this->h << ", " << this->y / this->h << ", " << this->z / this->h << ")" << endl;
		}
		else {
			cout << "Ошибка, 4 координата объекта равна 0." << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	Point3Dh <int> point(3, 3, 3, 3);
	cout << "Однородные координаты точки : (3, 3, 3, 3), тип int." << endl;
	point.show();

	system("pause");
	system("cls");

	Point3Dh <double> point1(3.333, 3.333, 3.333, 3);
	cout << "Однородные координаты точки : (3.333, 3.333, 3.333, 3), тип double." << endl;
	point1.show();

	system("pause");
	system("cls");

	Point3Dh <short> point2(-5, 25, 5, 5);
	cout << "Однородные координаты точки : (-5, 25, 5, 5), тип short." << endl;
	point2.show();

	system("pause");
	system("cls");

	Point3Dh <long> point3(50, 60, 80, 10);
	cout << "Однородные координаты точки : (50, 60, 80, 10), тип long." << endl;
	point3.show();

	system("pause");
	system("cls");

	Point3Dh <float> point4(10.2, 20.2, 30.2, 10.2);
	cout << "Однородные координаты точки : (10.2, 20.2, 30.2, 10.2), тип float." << endl;
	point4.show();

	system("pause");
	system("cls");

	vector <base*> v;

	v.push_back ((base*)&point);
	v.push_back ((base*)&point1);
	v.push_back ((base*)&point2);
	v.push_back ((base*)&point3);
	v.push_back ((base*)&point4);

	cout << "Все объекты внесены в вектор." << endl;

	system("pause");
	system("cls");

	for (int i = 0; i < 4; i++) {
		cout << i+1 << "." << " ";
		v[i]->show();
	}

	system("pause");
}
