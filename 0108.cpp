#include <iostream>
#include <cmath>

using namespace std;

enum yue {Jan=1,Feb,Mar,Apr,May,Jun,Jul,Aug,Spe,Oct,Nov,Dec};

struct MyTime
{
	unsigned int year;
	unsigned int month;
	unsigned int day;

	unsigned int hour;
	unsigned int min;
	unsigned int sec;
};


class Point{ //点对象
public:
	Point(int newX,int newY);
	Point(const Point&p); //复制构造函数
	Point(); //默认构造函数
	void setPoint(int newX = 0, int newY = 0);
	void showPoint();
	int getX();
	int getY();
private:
	int x, y;
};

Point::Point(int newX, int newY) :
	x(newX), y(newY) {
};
void Point::setPoint(int newX, int newY) {
	x = newX;
	y = newY;
};
void Point::showPoint() {
	cout << "X:" << x << " " << "Y:" << y << endl;
};
int Point::getX() {
	int n(0);
	n = x;
	return n;
}
int Point::getY() {
	int n(0);
	n = y;
	return n;
}
Point::Point(const Point &p) { //复制构造函数 Point& p表示用p代理Point
	x = p.x;
	y = p.y;
	//cout << "恭喜发财！" << endl; // 是函数就符合函数规则，不能有返回
}



class Line //线段类定义
{
public:
	Line(Point xp1,Point xp2);
	Line();
	Line(const Line& l); //复制构造函数
	void showLength();

private:
	Point p1, p2;  //线段私有元素，2个点和一个长度
	double Len;
};

Line::Line(Point xp1,Point xp2):p1(xp1),p2(xp2){ //导入两点构造线段
	double x = static_cast<double>(p1.getX()-p2.getX());
	double y = static_cast<double>(p1.getY()-p2.getY());
	Len = sqrt(x * x + y * y);
}

Line::Line(const Line &l):p1(l.p1),p2(l.p2) { //用已有线段构造新的线段
	Len = l.Len;
};
void Line::showLength() {
	cout << "长度是：" << Len;
}

class ExamInfo {
private:
	string name;
	enum { GRADE, PASS, PERCENTAGE } mode;
	union {
		char grade;
		bool pass;
		int percent;
	};
public:
	ExamInfo(string name, char grade)
		: name(name), mode(GRADE), grade(grade) {}
	ExamInfo(string name, bool pass)
		: name(name), mode(PASS), pass(pass) {}
	ExamInfo(string name, int percent)
		: name(name), mode(PERCENTAGE), percent(percent) {}
	void show();
};
void ExamInfo::show() {
	cout << name << ":";
	switch (mode) {
	case GRADE:
		cout << grade;
		break;
	case PASS:
		cout << (pass ? "PASS" : "FALL");
		break;
	case PERCENTAGE:
		cout << percent;
		break;
	default:
		break;
	}
	cout << endl;
}

/*==================枚举类============================*/
enum class Side{
	Right,Left
};
enum class Thing {
	Wrong,Right
};

void mjl();
/*===================================================*/
/*====================CPU小程序======================*/
enum CPU_Rank{
	P1=1,P2,P3,P4,P5,P6,P7
};
class CPU
{
public:
	CPU(CPU_Rank r, int f, float v) {
		rank = r;
		frequency = f;
		voltage = v;
		cout << "构造了一个CPU！" << endl;
	};

	CPU_Rank GetRank()const { return rank; }
	int GetFrequency()const { return frequency; }
	float GetVoltage()const { return voltage; }

	void ShowCPU()const { cout <<"P"<<rank <<" "<< frequency<<" " << voltage<<endl; }

	void SetRank(CPU_Rank r) { rank = r; }
	void SetFrequency(int f) { frequency = f; }
	void SetVoltage(float v) { voltage = v; }

	void Run() { cout << "CPU运行" << endl; }

private:
	CPU_Rank rank;
	int frequency;
	float voltage;
};

void aCPU();
/*===================================================*/
/*========================RAM类练习==================*/
enum RAM_Type {
	DDR4 = 1,DDR3,DDR2,DDR1
};
class RAM
{
public:
	RAM(RAM_Type t, int c, float f) {
		type = t;
		capacity = c;
		frequency = f;
	};

	RAM_Type GetType()const { return type; }
	int GetCapacity()const { return capacity; }
	float GetFrequency()const { return frequency; }

	void ShowRAM()const { cout << "类型：" << type << " 容量：" << capacity<< " 频率：" << frequency << endl; }

	void SetType(RAM_Type r) { type = r; }

	void Run() { cout << "RAM运行" << endl; }

private:
	RAM_Type type;
	int capacity;
	float frequency;
};
/*===================================================*/
/*=====================CDROM类=======================*/
enum InstallType {
	external = 1,built_in
};
enum Port{
	SATA=1,USB
};
class CD_ROM
{
public:
	CD_ROM(InstallType i, Port p, int c) {
		type = i;
		port = p;
		capacity = c;
	};

	//调用接口写在这
	void ShowCD_ROM()const { cout << "安装类型：" << type << " 接口：" << port << " 容量：" << capacity << endl; }

	void Run() { cout << "CDROM运行" << endl; }

private:
	InstallType type;
	Port port;
	int capacity;

};
/*===================================================*/
/*=======================Computer类==================*/
class COMPUTER
{
public:
	COMPUTER(CPU c, RAM r, CD_ROM cd, int s, int b);//内部构造函数，所以要在类外部描述

	//接口
	void Run() { 
		my_cpu.Run();
		my_ram.Run();
		my_cdrom.Run();
		cout << "Computer运行" << endl;
	}
	void Detial() {
		cout << "Computer细节" << endl;
		my_cpu.ShowCPU();
		my_ram.ShowRAM();
		my_cdrom.ShowCD_ROM();
	}
private:
	CPU my_cpu;
	RAM my_ram;
	CD_ROM my_cdrom;
	int storage_size;
	int bandwidth;

};
//构造函数描述（内部定义外部描述）
COMPUTER::COMPUTER(CPU c, RAM r, CD_ROM cd, int s, int b) :my_cpu(c),my_ram(r),my_cdrom(cd){
	storage_size = s;
	bandwidth = b;
	cout << "Computer已建立！" << endl;
}
/*===================================================*/

int pdy(int a);

int jgt(int a);

int juedui(int a, int b);

int dw(int a);

int qh(int a);

int yz(int a);

void xz(int a);

double arctan(double n);

int hw(int a);
bool pdhw(int a, int b);
void dyhw();

void gzhs();

void jgtlht();

int main()
{
	const double PI (3.1415926);
	cout << "圆周率：" << PI << endl;

	cout << "输入1进入求绝对值："<<endl;
	cout << "输入2进入求和：" << endl;
	cout << "输入3求因子：" << endl;
	cout << "输入4进入结构体：" << endl ;
	cout << "输入5进入arctan：" << endl;
	cout << "输入6进入回文：" << endl;
	cout << "输入7进入构造函数：" << endl;
	cout << "输入8进入结构体和联合体：" << endl;
	cout << "输入9进入枚举类：" << endl;
	cout << "输入10进入CPU小程序：" << endl << endl;
	
	int a(0);
	cout << "输入：" ;
	cin >> a;
	xz(a); 

	return 0;
}




void xz(int a) {
	int n(0);
	int b = 0, c = 0;
	double result(0);
	switch (a)
	{
	case 1:
		cout << "a：";
		cin >> b;
		cout << "b：";
		cin >> c;
		n = juedui(b, c);
		break;
	case 2:
		cout << "这是求和" << endl;
		cout << "输入：";
		cin >> b;
		n = qh(b);
		cout << "0到" << a << "的和为" << n << endl;
		break;
	case 3:
		cout << "这是求因子" << endl;
		cout << "输入：";
		cin >> b;
		n = yz(b);
		break;
	case 4:
		cout << "这是结构体" << endl;
		n = jgt(a);
		break;
	case 5:
		cout << "这是arctan" << endl;
		result =arctan(1/5.0);
		cout << result;
		break;
	case 6:
		cout << "这是回文" << endl;
		dyhw();
		break;
	case 7:
		cout << "这是构造函数" << endl;
		gzhs();
		break;
	case 8:
		cout << "这是结构体和联合体" << endl;
		jgtlht();
		break;
	case 9:
		cout << "这是结构体和联合体" << endl;
		mjl();
		break;
	case 10:
		cout << "这是CPU小程序" << endl;
		aCPU();
		break;
	default:
		break;
	}
}

void aCPU() {
	CPU a(P6, 300, 2.8);
	a.Run();
	a.ShowCPU();
	cout << "*************************\n";

	RAM b(DDR4, 8, 1600);
	b.Run();
	b.ShowRAM();
	cout << "*************************\n";
	
	CD_ROM c(external, SATA, 512);
	c.Run();
	c.ShowCD_ROM();
	cout << "*************************\n";

	COMPUTER d(a, b, c, 128, 10);
	d.Run();
	d.Detial();
	cout << "*************************\n";
}

void mjl() {
	Side s = Side::Right;
	Thing w = Thing::Wrong;
}

void jgtlht(){
	ExamInfo course1("英语",'B');
	ExamInfo course2("算数", true);
	ExamInfo course3("计算机", 85);
	course1.show();
	course2.show();
	course3.show();
}

void gzhs() {
	Point myp1(1, 1), myp2(4, 5); //用类定义新的元素
	myp1.showPoint(); //调用类函数
	myp2.showPoint();
	Point b(myp1);
	b.showPoint();
	Line Line1(myp1,myp2); //找到两点之间的线段
	Line1.showLength();
	Line Line2(Line1); //构造新的线段
	Line2.showLength();
}

void dyhw(){
	int n = 0;
	for (int i = 11; i <= 9999; i++)
	{
		if (hw(i))
		{
			cout<<i<<" ";
			n++;
		}
	}
	cout << "总计" << n << "个";
}

int hw(int a) { //生成回文
	int i=a;
	bool b(0);
	// cin >> i;
	// unsigned c = i;
	int m(0);
	while (i>0)
	{
		m = m * 10 + i % 10;
		i = i / 10;
	}
	b = pdhw(m,a);
	// cout << b;
	return b;
};

bool pdhw(int b,int a){ //判回文是否相等
	int m = a;
	int n = b;
	return n == m;
}

double arctan(double n) {
	double sqr = n * n;
	double e = n;
	double result = 0;
	int i = 1;
	while (e / i > 1e-15)
	{
		double f = e / i;
		result = (1 % 4 == 1) ? result + f : result - f;
		e = e * sqr;
		i += 2;
	}
	return result;
}

int juedui(int a, int b) { //绝对值求法
	int c(0);
	c = c = (a - b) > 0 ? (a - b) : (b - a);
	cout << "绝对值：" << c << endl;
	return 0;
}

int yz(int a) { //这是求因子
	for (int i = 1; i <= a; i++)
	{
		if (a % i == 0)
			cout << i << " ";
	}
	return 0;
}

int qh(int a) {
	int i = 1, sum(0);
	while (i <= a) {
		sum = sum + i;
		i++;
	}
	return sum;
}

int dw(int a) { //do-while 循环
	int i = 1, sum(0);
	do
	{
		sum += i;
		i++;
	} while (i <= a);
	return sum;
}

int jgt(int a) { //结构体
	MyTime myTime = { 0 };

	int yue(0);

	cout << "年:";
	cin >> myTime.year;

	cout << "月";
	cin >> yue;
	myTime.month = pdy(yue);

	cout << "日";
	cin >> myTime.day;

	cout << "时";
	cin >> myTime.hour;

	cout << "分";
	cin >> myTime.min;

	cout << "秒";
	cin >> myTime.sec;

	cout << myTime.year << "/"
		<< myTime.month << "/"
		<< myTime.day << " "
		<< myTime.hour << ":"
		<< myTime.min << ":"
		<< myTime.sec << endl;
	return 0;

}

int pdy(int a) {
	int b, n(0);
	if (a > 12)
	{
		cout << "月份budui" << endl;
		do
		{
			cout << "输入正确的月份：";
			cin >> b;
		} while (b > 12);
		n = b;
	}
	else
	{
		n = a;
	}
	return n;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
