#include <bits/stdc++.h>
using namespace std;

namespace emp_management
{

    class Employee_management
    {
        int emp_id, salary, age;
        string name, address;

    public:
        void menu();
        void insert_employee();
        void show_all_employee();
        void search_employee();
        void update_employee();
        void delete_employee();
    };

    void Employee_management::menu()
    {
        int choice;

        while (true)
        {
            system("clear");

            cout << "--------------- Employee management system -------------------\n";
            cout << "--------------------------------------------------------------\n\n";
            cout << "Press  ①  for insert an employee......\n";
            cout << "--------------------------------------\n";
            cout << "Press  ②  for show all employees......\n";
            cout << "--------------------------------------\n";
            cout << "Press  ③  for search for an employee..\n";
            cout << "--------------------------------------\n";
            cout << "Press  ④  for update an employee......\n";
            cout << "--------------------------------------\n";
            cout << "Press  ⑤  for delete an employee......\n";
            cout << "--------------------------------------\n";
            cout << "Press  0  for exit....................\n";
            cout << "--------------------------------------";

            cout << "\n\n\nEnter your choice..............  ";

            if (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n\n";
                continue;
            }

            switch (choice)
            {
            case 1:

                insert_employee();
                break;
            case 2:

                show_all_employee();
                break;
            case 3:
                search_employee();

                break;
            case 4:
                update_employee();
                break;
            case 5:
                delete_employee();
                break;
            case 0:
                exit(0);
            default:
                cout << "\n\nInvalid choice number ❌❌❌. Try again....\n\n";
            }

            cout << "\n\nPress enter to continue.....";

            cin.ignore();
            cin.get();
        }
    }

    void Employee_management::insert_employee()
    {
        system("clear");
        fstream file;
        file.open("../output/employee_data.txt", ios::app);

        cout << "--------------- Insert  employees -------------------\n";
        cout << "-------------------------------------------------\n\n\n";

        cout << "Enter employee name...\n";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee age...\n";
        cin >> age;
        cout << "Enter employee salary...\n";
        cin >> salary;
        cout << "Enter employee address...\n";
        cin.ignore();
        getline(cin, address);

        int em_id = 1;

        ifstream Id;
        Id.open("../output/employeeId.txt");
        Id >> em_id;
        emp_id = em_id;

        ofstream fileId;
        fileId.open("../output/employeeId.txt");

        Employee_management em;

        if (file.is_open())
        {
            file << "\n"
                 << emp_id << "\n"
                 << name << "\n"
                 << age << "\n"
                 << salary << "\n"
                 << address;

            file.close();

            cout << "\n\n✅ ✅ ✅ Employee information successfully inserted ✅ ✅ ✅.\n";
            fileId << em_id + 1 << "\n";
        }
        else
        {
            cout << "\n\n❌❌❌ Something is wrong. Failed to insert employee ❌❌❌.\n";
        }
        fileId.close();
        Id.close();
    }

    void Employee_management::show_all_employee()
    {
        system("clear");
        ifstream file;
        cout << "--------------- All employees -------------------\n";
        cout << "-------------------------------------------------\n\n\n";

        cout << "Id\t"
             << "\tName\t"
             << "\t\tAge\t"
             << "\tSalary\t  "
             << "\tAddress\t\n";

        cout << "----------------------------------------------------------------------------------\n\n\n";

        file.open("../output/employee_data.txt");

        if (!file.is_open())
        {
            cout << "Error opening the file..... ❌❌❌\n";
            return;
        }

        // Check if the file is empty
        if (file.peek() == EOF)
        {
            cout << "The file is empty....😢😢\n";
            file.close();
            return;
        }

        Employee_management em;

        while (!file.eof())
        {
            file >> em.emp_id;
            file.ignore();
            getline(file, em.name);
            file >> em.age;
            file >> em.salary;
            file.ignore();
            getline(file, em.address);

            cout << em.emp_id << "\t\t" << em.name << "\t\t" << em.age << "\t\t" << em.salary << "\t\t" << em.address << endl;
        }
        file.close();
        cout << "\n----------------------------------------------------------------------------------\n\n\n";
    }

    void Employee_management ::search_employee()
    {

        system("clear");
        ifstream file;
        int search_Id, isFound = 0;

        cout << "--------------- Search employee-------------------\n";
        cout << "-------------------------------------------------\n\n\n";

        file.open("../output/employee_data.txt");

        if (!file.is_open())
        {
            cout << "Error opening the file..... ❌❌❌\n";
            return;
        }

        // Check if the file is empty
        if (file.peek() == EOF)
        {
            cout << "The file is empty....😢😢\n";
            file.close();
            return;
        }
        cout << "Enter employee ID....... :  ";
        cin >> search_Id;
        cout << "\n\n\n";

        Employee_management em;

        while (!file.eof())
        {

            file >> em.emp_id;
            file.ignore();
            getline(file, em.name);
            file >> em.age;
            file >> em.salary;
            file.ignore();
            getline(file, em.address);
            if (search_Id == em.emp_id)
            {
                cout << "Id\t"
                     << "\tName\t"
                     << "\t\tAge\t"
                     << "\tSalary\t  "
                     << "\tAddress\t\n";

                cout << "----------------------------------------------------------------------------------\n\n\n";

                cout << em.emp_id << "\t\t" << em.name << "\t\t" << em.age << "\t\t" << em.salary << "\t\t" << em.address << endl;
                isFound = 1;
            }
        }

        if (isFound)
        {
            cout << "\n----------------------------------------------------------------------------------\n\n\n";
        }
        if (!isFound)
        {
            cout << "This employee cannot exits 😢😢. Try again using different employee Id 🙂🙂.\n";
            return;
        }
        file.close();
    }

    void Employee_management ::update_employee()
    {

        system("clear");
        ifstream file;
        ofstream file1;
        file.open("../output/employee_data.txt");
        file1.open("../output/employee.txt");

        int update_Id, isFound = 0;

        cout << "---------------Update employee -------------------\n";
        cout << "-------------------------------------------------\n\n\n";

        if (!file.is_open() || !file1.is_open())
        {
            cout << "Error opening the file..... ❌❌❌\n";
            return;
        }

        // Check if the file is empty
        if (file.peek() == EOF)
        {
            cout << "The file is empty....😢😢\n";
            file.close();
            return;
        }
        cout << "Enter employee ID to update ....... :   ";
        cin >> update_Id;

        int up_salary, up_age;
        string up_name, up_address;

        Employee_management em;

        while (!file.eof())
        {

            file >> em.emp_id;
            file.ignore();
            getline(file, em.name);
            file >> em.age;
            file >> em.salary;
            file.ignore();
            getline(file, em.address);
            if (update_Id == em.emp_id)
            {
                cin.ignore();
                cout << "Enter employee name...\n";
                getline(cin, up_name);
                cout << "Enter employee age...\n";
                cin >> up_age;
                cout << "Enter employee salary...\n";
                cin >> up_salary;
                cout << "Enter employee address...\n";
                cin.ignore();
                getline(cin, up_address);

                file1 << "\n"
                      << em.emp_id << "\n"
                      << up_name << "\n"
                      << up_age << "\n"
                      << up_salary << "\n"
                      << up_address;

                cout << "\n\n✅ ✅ ✅ Employee update successfully..... ✅ ✅ ✅.\n";
                isFound = 1;
            }
            else
            {
                file1 << "\n"
                      << em.emp_id << "\n"
                      << em.name << "\n"
                      << em.age << "\n"
                      << em.salary << "\n"
                      << em.address;
            }
        }

        if (!isFound)
        {
            cout << "\n\nThis employee cannot exits 😢😢. Try again using different employee Id 🙂🙂.\n";
            return;
        }

        file.close();
        file1.close();
        remove("../output/employee_data.txt");
        rename("../output/employee.txt", "../output/employee_data.txt");
    }

    void Employee_management ::delete_employee()
    {

        system("clear");
        ifstream file;
        ofstream file1;
        file.open("../output/employee_data.txt");
        file1.open("../output/employee.txt");

        int delete_Id, isFound = 0;

        cout << "--------------- Delete employee -------------------\n";
        cout << "-------------------------------------------------\n\n\n";

        if (!file.is_open() || !file1.is_open())
        {
            cout << "Error opening the file..... ❌❌❌\n";
            return;
        }

        if (file.peek() == EOF)
        {
            cout << "The file is empty....😢😢\n";
            file.close();
            return;
        }
        cout << "Enter employee ID to delete ....... :   ";
        cin >> delete_Id;

        Employee_management em;

        while (!file.eof())
        {

            file >> em.emp_id;
            file.ignore();
            getline(file, em.name);
            file >> em.age;
            file >> em.salary;
            file.ignore();
            getline(file, em.address);
            if (delete_Id == em.emp_id)
            {
                cout << "\n\n✅ ✅ ✅ Employee delete successfully..... ✅ ✅ ✅.\n";
                isFound = 1;
            }
            else
            {
                file1 << "\n"
                      << em.emp_id << "\n"
                      << em.name << "\n"
                      << em.age << "\n"
                      << em.salary << "\n"
                      << em.address;
            }
        }

        if (!isFound)
        {
            cout << "\n\nThis employee cannot exits 😢😢. Try again using different employee Id 🙂🙂.\n";
            return;
        }
        file.close();
        file1.close();
        remove("../output/employee_data.txt");
        rename("../output/employee.txt", "../output/employee_data.txt");
    }
}