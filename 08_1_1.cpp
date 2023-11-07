#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char name[100];

public:
    Employee(char* name) {
        strcpy(this->name, name);
    }
    void showyourname() const {
        cout << "name : " << name << endl;
    }
    virtual int GetPay() const = 0;
    virtual void showsalaryinfo() const = 0;
};

class PermanentWorker : public Employee {
private:
    int salary; // 월급

public:
    PermanentWorker(char* name, int money) : Employee(name), salary(money) {}
    int GetPay() const {
        return salary;
    }
    void showsalaryinfo() const {
        showyourname();
        cout << "salary : " << GetPay() << endl;
    }
};

class TemporaryWorker : public Employee {
private:
    int worktime;
    int payPerHour;

public:
    TemporaryWorker(char* name, int pay) : Employee(name), worktime(0), payPerHour(pay) {}
    void AddWorkTime(int time) {
        worktime += time;
    }
    int GetPay() const {
        return worktime * payPerHour;
    }
    void showsalaryinfo() const {
        showyourname();
        cout << "salary : " << GetPay() << endl;
    }
};

class SalesWorker : public PermanentWorker {
private:
    int salesResult;
    double bonus;

public:
    SalesWorker(char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonus(ratio) {}
    void AddSalesResult(int value) {
        salesResult += value;
    }
    int GetPay() const {
        return PermanentWorker::GetPay() + static_cast<int>(salesResult * bonus);
    }
    void showsalaryinfo() const {
        showyourname();
        cout << "salary : " << GetPay() << endl;
    }
};

namespace RISK {
enum { A = 30, B = 20, C = 10 };
}

class ForeignSalesWorker : public SalesWorker {
private:
    const int riskLevel;

public:
    ForeignSalesWorker(char* name, int money, double ratio, int risk)
        : SalesWorker(name, money, ratio), riskLevel(risk) {}

    int GetRiskPay() const {
        return static_cast<int>(SalesWorker::GetPay() * (riskLevel / 100.0));
    }

    int GetPay() const {
        return SalesWorker::GetPay() + GetRiskPay();
    }

    void showsalaryinfo() const {
        showyourname();
        cout << "salary : " << SalesWorker::GetPay() << endl;
        cout << "risk pay : " << GetRiskPay() << endl;
        cout << "sum: " << GetPay() << endl;
    }
};

class EmployeeHandler {
private:
    Employee* empList[50];
    int empNum;

public:
    EmployeeHandler() : empNum(0) {}

    void AddEmployee(Employee* emp) {
        empList[empNum++] = emp;
    }

    void ShowAllSalaryInfo() const {
        for (int i = 0; i < empNum; i++) {
            empList[i]->showsalaryinfo();
        }
    }

    void ShowAllSalaryInfo() {
        int sum = 0;
        for (int i = 0; i < empNum; i++) {
            sum += empList[i]->GetPay();
        }
        cout << "salary sum :" << sum << endl;
    }

    ~EmployeeHandler() {
        for (int i = 0; i < empNum; i++) {
            delete empList[i];
        }
    }
};

int main(void) {
    EmployeeHandler handler;

    ForeignSalesWorker* fseller1 = new ForeignSalesWorker("aaa", 1000, 0.1, RISK::A);
    fseller1->AddSalesResult(7000); // 영업실적
    handler.AddEmployee(fseller1);

    ForeignSalesWorker* fseller2 = new ForeignSalesWorker("bbb", 1000, 0.1, RISK::B);
    fseller2->AddSalesResult(7000); // 영업실적
    handler.AddEmployee(fseller2);

    handler.ShowAllSalaryInfo();
    return 0;
}
