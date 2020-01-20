#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
#include <vector>

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
	Point() :x(0), y(0) { cout << "默认点构造函数" << endl; }; //默认点构造函数
	void setPoint(int newX = 0, int newY = 0); //初始化
	void showPoint();
	int getX();
	int getY();
	void move(int newX,int newY);
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
void Point::move(int newX,int newY) {
	x = newX;
	y = newY;
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
	CPU () { //构造函数可不带任何参数，调用是不带（）
		SetRank();
		SetFrequency();
		SetVoltage();
		cout << "构造了一个CPU！" << endl;
	};

	CPU_Rank GetRank()const { return rank; }
	int GetFrequency()const { return frequency; }
	float GetVoltage()const { return voltage; }

	void ShowCPU()const { 
		cout << "Rank：";
		switch (rank)
		{
		case 1:
			cout << "P1";
			break;
		case 2:
			cout << "P2";
			break;
		case 3:
			cout << "P3";
			break;
		case 4:
			cout << "P4";
			break;
		case 5:
			cout << "P5";
			break;
		case 6:
			cout << "P6";
			break;
		case 7:
			cout << "P7";
			break;
		default:
			break;
		}
		cout << " 频率：" << frequency << " 电压：" << voltage << endl;
	}

	void SetRank() {
		int n(0);
		string s1;
		cout << "P1=1,P2,P3,P4,P5,P6,P7" << endl;
		cin >> n;
		getline(cin, s1);
		switch (n)
		{
		case 1:
			rank = P1;
			break;
		case 2:
			rank = P2;
			break;
		case 3:
			rank = P3;
			break;
		case 4:
			rank = P4;
			break;
		case 5:
			rank = P5;
			break;
		case 6:
			rank = P6;
			break;
		case 7:
			rank = P7;
			break;
		default:
			break;
		}
	}
	void SetFrequency() { 
		int f(0);
		cout << "输入频率：";
		cin >> f;
		frequency = f; 
	
	}
	void SetVoltage( ) {
		float v;
		cout << "输入浮点电压：";
		cin >> v;
		voltage = v; 
	}

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

	void ShowRAM()const { 
		cout << "类型：";
		switch (type)
		{
		case DDR4:
			cout << "DDR4";
			break;
		case DDR3:
			cout << "DDR3";
			break;
		case DDR2:
			cout << "DDR2";
			break;
		case DDR1:
			cout << "DDR1";
			break;
		default:
			break;
		}
		cout<< " 容量：" << capacity << " 频率：" << frequency << endl;
	}

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
	void ShowCD_ROM()const { 
		cout << "安装类型：";
		switch (type)
		{
		case external:
			cout << "External";
			break;
		case built_in:
			cout << "Built-In";
			break;
		default:
			break;
		}
		cout << " 接口：";
		cout << (port==SATA?"SATA":"USB") << " 容量：" << capacity << "GB"<<endl;
	}

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
		cout << "Computer运行" << endl<<endl;
	}
	void Detial() {
		cout << "Computer细节" << endl<<endl;
		my_cpu.ShowCPU();
		my_ram.ShowRAM();
		my_cdrom.ShowCD_ROM();
	}
	void setComputer();

	void setComputerCpu();

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

void COMPUTER::setComputer(){
	// my_cpu.SetRank(CPU_Rank r);
	//my_cpu.SetFrequency();
}

void COMPUTER::setComputerCpu() {
	my_cpu.SetFrequency(); //修改频率
}

/*===================================================*/
/*==================银行账户=========================*/
class SavingsAccount
{
public:

	SavingsAccount(int NewID,double NewRate,int date); //内部构造函数 参数 date; ID; rate

	/*================接口============================*/
	int getID()const {return ID;}
	double getBalance()const { return balance; }
	double getRate()const { return rate; }
	
	//展示 int ID, double Balance, double Rate, int Date
	void show()const { cout <<"ID:"<< ID<<" Balance:"<<balance<<" Rate"<<rate<<" Date"<<date<<endl; } 

	void deposit(int Newdate, double amount);
	void withdraw(int Newdate, double amount);
	//利息结算
	void settle(int Newdate);
	
	//

	~SavingsAccount();

private:
	int ID; //
	double balance; // 余额
	double rate; //利率
	int date;
	int lastDate; //上次余额变更日期
	double accumulation; //余额日期累加和
	void record(int date,double amount);
	double accumulate(int date)const {
		return accumulation + balance * (date - lastDate);
	}
};

SavingsAccount::SavingsAccount(int NewID, double NewRate, int date) //
	:ID(NewID),rate(NewRate),lastDate(date),accumulation(0),date(0),balance(0){
	cout << date << ID << " is created" << endl;
}

void SavingsAccount::record(int date,double amount){
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100; //保留小数点后两位
	balance += amount;
	//cout << date << " #" << ID << " " << amount << " " << balance << endl;
	show();
}

void SavingsAccount::deposit(int Newdate,double amount) {
	record(Newdate, amount);
}
void SavingsAccount::withdraw(int Newdate,double amount){
	if (amount>getBalance())
	{
		cout << "穷逼，钱不够了！" << endl;
	}
	else
	{
		record(Newdate, -amount);
	}
}
void SavingsAccount::settle(int Newdate){
	double interest = accumulate(date) * rate / 365; //计算年息
	if (interest!=0)
	{
		record(date, interest);
	}
	else
	{
		accumulation = 0;
	}
}

SavingsAccount::~SavingsAccount()
{
}
/*===================================================*/
/*======================Date类=======================*/
class Date
{
public:
	Date(int year, int month, int day);
	~Date();
	//接口
	int getYear();

private:
	int year;
	int month;
	int day;
	int tolalDay;
};

Date::Date(int year,int month,int day):year(year),month(month),day(day){

}

Date::~Date()
{
}
int Date::getYear() {
	return 0;
}
/*===================================================*/
/*======================动态数组类===================*/
class ArrayOfPoints
{
public:
	ArrayOfPoints(int size) :size(size) {
		points = new Point[size]; //没有向Point传递参数调用默认构造函数！！！！！！！！
	};
	ArrayOfPoints(const ArrayOfPoints& pointsArry);
	~ArrayOfPoints() {		//析构函数
		cout << "删除空间" << endl;
		delete[] points;
	};
	
	Point& element(int index){ //引用
		assert(index >= 0 && index < size);
		return points[index];
	}
	

private:
	Point* points; //指向动态数组首地址
	int size;	   //数组大小
};
ArrayOfPoints::ArrayOfPoints(const ArrayOfPoints& v) {
	size = v.size;
	points = new Point[size];
	for (int i = 0; i < size; i++)
	{
		points[i] = v.points[i];
	}
}
/*===================================================*/

int pdy(int a);

int jgt(int a);

void juedui(int a, int b);

int dw(int a);

void qh(int a);

int yz(int a);

void xz(int a);

double arctan(double n);

int hw(int a);
bool pdhw(int a, int b);
void dyhw();

void gzhs();

void jgtlht();

void BankAccount();

void shuzu();

void zhizhen();
void splitFloat(float x, int* intPart, float* fracPart);
void print(const int* p, int n);
int* search(int* a, int num);
int coumputer(int a, int b, int(*func)(int, int));
int max(int a, int b);
int min(int a, int b);
void dtdwsz();

void dtnc();
void vc();
double average(const vector<double>& arr);

void scfz();

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
	cout << "输入10进入CPU小程序：" << endl;
	cout << "输入11进入银行账户程序：" << endl;
	cout << "输入12进入数组示例：" << endl;
	cout << "输入13进入指针示例：" << endl;
	cout << "输入14进入动态内存示例：" << endl;
	cout << "输入15进入Vector示例：" << endl;
	cout << "输入16进入深层复制演示：" << endl << endl;
	
	
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
	cout << "*************************************" << endl;
	switch (a)
	{
	case 1:
		cout << "a：";
		cin >> b;
		cout << "b：";
		cin >> c;
		juedui(b, c);
		break;
	case 2:
		cout << "这是求和" << endl;
		cout << "输入：";
		cin >> b;
		qh(b);
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
	case 11:
		cout << "这是银行账户程序" << endl;
		BankAccount();
		break;
	case 12:
		cout << "这是数组演示" << endl;
		shuzu();
		break;
	case 13:
		cout << "这是指针演示" << endl;
		zhizhen();
		break;
	case 14:
		cout << "这是动态内存演示" << endl;
		dtnc();
		break;
	case 15:
		cout << "这是动态内存演示" << endl;
		vc();
		break;
	case 16:
		cout << "这是深层复制演示" << endl;
		scfz();
		break;
	default:
		break;
	}
}

void BankAccount() {
	SavingsAccount account1(123456, 0.015,1); //int NewID, double NewRate(利率), int date
	SavingsAccount account2(654321, 0.015, 1);
	//account1.show();
	account1.deposit(5, 5000.00); //int Newdate,double amount
	account2.deposit(25, 10000);

	account1.deposit(45, 5500.00);
	account2.withdraw(60, 4000);
	account1.settle(90);
	account2.settle(90);

}

void scfz() {
	int count;
	cout << "输入点的个数";
	cin >> count;
	ArrayOfPoints pArr1(count);
	pArr1.element(0).setPoint(5, 15);
	pArr1.element(1).setPoint(15, 20);

	pArr1.element(0).showPoint();
	pArr1.element(1).showPoint();

	ArrayOfPoints pArr2(pArr1);

	cout << "复制数组pArr1" << endl;
	cout << "Point 0 of pArr2: X:" << pArr2.element(0).getX() << " Y:" << pArr2.element(0).getY() << endl;
	cout << "Point 1 of pArr2: X:" << pArr2.element(1).getX() << " Y:" << pArr2.element(1).getY() << endl;

	pArr1.element(0).move(25, 30);
	pArr1.element(1).move(35, 40);

	cout << "移动后的pArr1:" << endl;
	pArr1.element(0).showPoint();
	pArr1.element(1).showPoint();

	cout << "移动点pArr1后的pArr2"<<endl;

	pArr2.element(0).showPoint();
	pArr2.element(1).showPoint();
}

void vc() {
	unsigned n;
	cout << "n:";
	cin >> n;
	vector<double>arr(n);
	cout << "输入" << n << "个实数：" << endl;
	for (unsigned i = 0; i < n; i++)
	{
		cin >> arr[i];
		cout << "平均数" << average(arr) << endl;
	}
	std::vector<int>v = { 1,2,3 };
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	for (auto e:v)
	{
		std::cout << e << std::endl;
	}
}
double average(const vector<double>& arr) {
	double sum = 0;
	for (unsigned i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
	}
	return sum / arr.size();
}
void dtnc() {
	int count;
	cin >> count;
	ArrayOfPoints points1(count);

	points1.element(1).showPoint();
	points1.element(1).move(4, 6);
	points1.element(1).showPoint();
	
}

void zhizhen() {
	int a = 5;
	void* vp;
	vp = &a;
	int* pint = static_cast<int*>(vp);
	int* p = nullptr;//空指针
	int* ptr = &a;
	cout << "a=" << a << endl;
	//cout << "*p=" << *p << endl; //错误表达
	cout << "*ptr=" << *ptr << endl;
	int line1[3]{ 1 };
	int line2[3]{ 0,1 };
	int line3[]{ 0,0,1 };

	int* pLine[3] = { line1,line2,line3 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << pLine[i][j] << " ";
		}
		cout << endl;
	}

	float x, f;
	int n;
	cout << "输入浮点数：";
	cin >> x;
	splitFloat(x, &n, &f); //指针参数

	const int N = 6;
	int array[N];
	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
	}
	print(array, N);

	//指针函数
	int* zeroptr = search(array, N);
	cout << *zeroptr;
	cout << endl;
	//函数指针
	int C = coumputer(9, 10, &max);
	cout << C << endl;
	 C = coumputer(9, 10, min); //第二种写法
	cout << C << endl;

	//类成员指针
	Point point1(4, 5);
	Point* p1 = &point1;
	cout << p1->getX()<<endl;

	//动态创建多维数组
	dtdwsz();
}
void dtdwsz(){
	int(*cp)[9][8] = new int[7][9][8];
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				*(*(*(cp + i) + j) + k) = (i * 100 + j * 10 + k);
			}
		}
	}
	
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				cout << cp[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	//cout << cp[0][0][0];
	delete[]cp;
}

int coumputer(int a, int b, int(*func)(int,int)) {
	return func(a, b);
}
int max(int a, int b) {
	return((a > b) ? a : b);
}
int min(int a, int b) {
	return((a < b) ? a : b);
}

void print(const int* p, int n){ //常数指针
	cout << "{" << *p;
	for (int i = 1; i < n; i++)
	{
		cout << "," << *(p + i);
	}
	cout << "}" << endl;
}

int* search(int* a,int num) {
	for (int i = 0; i < num; i++)
	{
		if (a[i]==4)
		{
			return &a[i];
		}
	}
	return 0;
}

void splitFloat(float x, int* intPart, float* fracPart) {
	*intPart = static_cast<int>(x);
	*fracPart = x - *intPart;
	cout << "整数部分" << *intPart << " 小数部分" << *fracPart << endl;
}

void shuzu() {
	int a[9], b[9];
	for (int i = 0; i < 9; i++)
	{
		a[i] = i+1;
		int k = i+1;
		for (int n = 0; n < k; n++)
		{
			b[n] = n+1;
			cout << a[i] << "*" << b[n] << "=" << a[i] * b[n]<<" ";
		}
		cout << endl;
	}
}

void aCPU() {
	CPU a;
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
	d.setComputer();
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

void juedui(int a, int b) { //绝对值求法
	int c(0);
	c = c = (a - b) > 0 ? (a - b) : (b - a);
	cout << "绝对值：" << c << endl;
}

int yz(int a) { //这是求因子
	for (int i = 1; i <= a; i++)
	{
		if (a % i == 0)
			cout << i << " ";
	}
	return 0;
}

void qh(int a) {
	int i = 1, sum(0);
	while (i <= a) {
		sum = sum + i;
		i++;
	}
	cout << "0到" << a << "的和为" << sum << endl;
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
