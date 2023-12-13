#include <iostream>
#include <vector>
using namespace std;

class Worker 
{
protected:
    string name;

public:
    Worker(string n) : name(n) {}

    string getName() const 
    {
        return name;
    }
};

class Department 
{
public:
    vector<Worker> Workers;

    void add(Worker&& worker) 
    {
        Workers.emplace_back(move(worker));
    }

    ~Department() 
    {
        cout << endl << endl << "Розформування відділу." << endl << endl << "Продовжують працювати поза відділом: ";

        for (const auto& worker : Workers)
        {
            cout << worker.getName() << " ";
        }
    }

    friend ostream& operator<<(ostream& display, const Department& department)
    {
        for (const auto& worker : department.Workers) 
        {
            display << worker.getName() << " ";
        }
        return display;
    }
};

int main() 
{
    system("chcp 1251>nul");

    Worker w1("Антін");
    Worker w2("Івасик");
    Worker w3("Євген");
    Worker w4("Їржик");
    Worker w5("Андрій");
    Worker w6("Катерина");
    Worker w7("Маргарита");

    Department* department = new Department;
    department->add(move(w1));
    department->add(move(w2));
    department->add(move(w3));
    department->add(move(w4));
    department->add(move(w5));
    department->add(move(w6));
    department->add(move(w7));

    cout << "Працівники відділу: " << *department;
    delete department;

    cout << w1.getName() << " ";
    cout << w2.getName() << " ";
    cout << w3.getName() << " ";
    cout << w4.getName() << " ";
    cout << w5.getName() << " ";
    cout << w6.getName() << " ";
    cout << w7.getName() << endl;

    return 0;
}
