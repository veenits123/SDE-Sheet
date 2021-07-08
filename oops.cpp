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
};

//inheritance;
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
};

class CppDeveloper: public Developer {
public:
	string Library;
	CppDeveloper(string _name, string _company, int _age, string _language, string _library):
		Developer(_name, _company, _age, _language) {
		Library = _library;
	}
	void knowsLibrary() {
		cout << getName() << " knows " << Library << endl;
	}
};

void solve() {

	// Developer dev = Developer("Alice", "Google", 24, "C++");
	// dev.fixBugs();
	// dev.askForPromotion();

	CppDeveloper cpp = CppDeveloper("Alice", "Google", 24, "C++", "Boost");
	cpp.knowsLibrary();
	cout << cpp.getName();

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