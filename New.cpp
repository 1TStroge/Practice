#include <iostream>
#include <cmath>

const double PI = 3.14159265358979;

using namespace std;

void xz(int a);

int jc(int n); //阶乘

void hanoi(int n, char src, char medium, char dest);
void move(char src, char dest);

void swap(int& a, int& b);

void jd(double a);

void dx();

class Clock {
public:
	Clock(int newH, int newM, int newS); //构造函数，不写编译器自动构造
	Clock();
	void setTime(int newH = 0, int newM = 0, int newS = 0);
	void showTime();
private:
	int hour, minute, second;
};

Clock::Clock(int newH, int newM, int newS) :
	hour(newH), minute(newM),second(newS){
};
void Clock::setTime(int newH, int newM, int newS) {
	hour = newH;
	minute = newM;
	second = newS;
};

void Clock::showTime() {
	cout << hour << ":" << minute << ":" << second;
};

void gzhs();

int main()
{
	int n(0);
	cout << "输入1进入阶乘" << endl;
	cout << "输入2进入汉诺塔问题" << endl;
	cout << "输入3进入引用实例" << endl;
	cout << "输入4进入三角函数" << endl;
	cout << "输入5进入对象" << endl;
	cout << "输入6进入构造函数" << endl;
	
	int a;
	cin >> a;

	xz(a);

	return 0;
}

void xz(int a) {
	int i(0),n(0);
	int m(0),l(0);
	double angle;
	switch (a)
	{
	case 1:
		cout << endl << "这是阶乘功能"<<endl;
		cout << "请输入：";
		cin >> i;
		n = jc(i);
		cout <<i<< "的阶乘是："<<n;
		break;
	case 2:
		cout << "这是汉诺塔问题" << endl;
		cout << "输入个数：";
		cin >> i;
		hanoi(i,'A','B','C');
		break;
	case 3:
		cout << "这是引用" << endl;
		cout << "输入第一个数：";
		cin >> m;
		cout << "输入第二个数：";
		cin >> n;
		cout << "m:" << m << " n:" << n << endl;
		swap(m, n);
		cout << "m:" << m << " n:" << n;
		break;
	case 4:
		cin >> angle;
		jd(angle);
		break;
	case 5:
		cout << "这是对象" << endl;
		dx();
		break;
	case 6:
		cout << "这是构造函数" << endl;
		gzhs();
		break;
	default:cout << "又胡来？" << endl;
		cout <<"好好输入：" ;
		cin >> l;
		 xz(l);
		break;
	}
}

void gzhs() {
	Clock c(0, 0, 0);
	c.showTime();
}

void dx() {
	Clock myClock; //构造函数
	int a(0), b(0), c(0);
	cin >> a;
	cin >> b;
	cin >> c;
	myClock.setTime(a, b, c);
	myClock.showTime();
}

void jd(double a) {
	double radian = a * PI / 180;
	cout << "sin(" << a << ")=" << sin(radian) << endl;
}

void swap(int& a, int& b){
	int t = a;
	a = b;
	b = t;
}

void move(char src,char dest){
	cout << src << "-->" << dest << endl;
}

void hanoi(int n,char src,char medium,char dest){
	if (n ==1)
	{
		move(src, dest);

	}
	else
	{
		hanoi(n - 1, src,dest,medium);
		move(src, dest);
		hanoi(n - 1, medium,src, dest);
	}
}

int jc(int n) {
	unsigned result;
	if (n == 0)
	{
		result = 1;
	}
	else
	{
		result = jc(n - 1) * n;
	}
	return result;
}