// never the same!!
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;

//abstract class;
class absClass {
	virtual void askForPromotion() = 0;
};

//class;
class Employee: absClass {
//private:
private://encapsulation;
	//attributes;
	string Company;
	int Age;

protected:
	string Name;

public:

	void setName(string _name) {
		Name = _name;
	}
	string getName() {
		return Name;
	}

	void setAge(int _age) {
		if (_age >= 18)
			Age = _age;
	}
	int getAge() {
		return Age;
	}

	//method;
	void introduce() {
		cout << "Name: " << Name << endl;
		cout << "Company: " << Company << endl;
		cout << "Age: " << Age << endl;
	}
	Employee() {}

	//constructor;
	Employee(string _name, string _company, int _age) {
		Name = _name;
		Company = _company;
		Age = _age;
	}
	//copy constructor;
	Employee(Employee a, string _name) {
		Name = _name;
	}
	//abstraction;
	void askForPromotion() {
		if (Age > 30)
			cout << Name << " got promoted!!" << endl;
		else
			cout << Name << ", no promotion for you :)" << endl;
	}

	//polymorphism;
	//Run Time PMM: over-riding virtual functions;
	virtual void Work() {
		cout << Name << " work on development, testing, ....." << endl;
	}

	//polymorphism;
	//Compile Time PMM: overloading functions;
	int CompileTimeFuncOveraloading(int fac) {
		return (Age * fac);
	}
	//compile time function overloading;
	int CompileTimeFuncOveraloading(int fac, int rem) {
		return (Age * fac) / rem;
	}

	//compile time operator overloading;
	//automatically called when '+' is used b/w two objects of "Employee";
	string operator + (Employee b) {
		return Name + " " + b.Name;
	}
};

//single inheritance;
class Developer: public Employee {
public:
	string ProgLanguage;
	Developer(string _name, string _company, int _age, string _language): Employee(_name, _company, _age) {
		ProgLanguage = _language;
	}

	void fixBugs() {
		//askForPromotion();
		cout << Name << " fixed bugs!" << endl;
	}

	//polymorphism; //runtime;
	void Work() {
		cout << Name << " work on development!" << endl;
	}
	//compile time function overloading;
	int CompileTimeFuncOveraloading(int fac, int rem) {
		return (getAge() * fac) / rem;
	}
};

//multilevel inheritance;
class CppDeveloper: virtual public Developer {
public:
	string Library;
	CppDeveloper(string _name, string _company, int _age, string _language, string _library):
		Developer(_name, _company, _age, _language) {
		Library = _library;
	}
	void knowsLibrary() {
		cout << getName() << " knows " << Library << endl;
	}

	string getLibrary() {
		return Library;
	}

	//polymorphism;
	void Work() {
		cout << Name << " work on C++ <3" << endl;
	}
};

class testing: virtual public Developer {};

class oops: public testing {
public:
	oops();
	~oops();

};

//multiple inheritance;
class MultipleInheritance: public CppDeveloper,  public testing {
};

#if 0
class Testing {
public:
	string Name;
	string Company;
	int Age;

	//it's possible ;)
	Employee emp = Employee("John", "Google", 24);
	Testing(string _name, int _age) {
		Name = _name;
		Age = emp.Age;
		emp.Name = _name;
	}
	string test() {
		return Name;
	}
	void print() {
		emp.introduce();
	}

	//~Testing();
};
#endif

void solve() {

	// Developer dev = Developer("Bob", "Google", 24, "C++");
	// dev.fixBugs();
	// dev.askForPromotion();
	// dev.Work();

	// CppDeveloper cpp = CppDeveloper("Alice", "Google", 24, "C++", "Boost");
	// cpp.knowsLibrary();
	// cout << cpp.getLibrary() << endl;
	// cpp.Work();

	// cpp.Work();
	// dev.Work();

	// Employee* e1 = &dev;
	// Employee* e2 = &cpp;

	// e1->Work();
	// e2->Work();

	// Testing t = Testing("Bob", 24);
	// t.print();

	Employee emp = Employee("Alice", "Google", 24);
	// cout << emp.CompileTimeFuncOveraloading(2) << endl;
	// cout << emp.CompileTimeFuncOveraloading(2, 2) << endl;


	Employee emp1 = Employee("Bob", "Google", 24);

	// Developer d1 = Developer("Bob", "Google", 24, "C++");
	// Developer d2 = Developer("Alice", "Google", 24, "SQL");

	// string x = d1 + d2;
	// cout << x << endl;


	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}