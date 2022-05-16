#include "Header.h"

int main() {
    cout << "Enter the number of tasks:" << endl;
    cin >> number_of_tasks;


    if (!in.is_open())
    {
        cout << "File cannot be opened" << endl;
    }
    else
    {
        for (int i = 0; i < number_of_tasks; i++)
        {
            in >> todoitem[i].id >> todoitem[i].name >> todoitem[i].description >> todoitem[i].due_date;
        }

    }
    menu();
    while (choice != 0)
    {
        cin >> choice;
        switch (choice)
        {
        case 0: {cout << "All the best" << endl; break; }
        case 1:
        {
            number_of_tasks++;
            if (number_of_tasks <= size_mass)
            {
                add_tasks();
            }

            else if (number_of_tasks > size_mass)
            {
                ToDoItem* temp = new ToDoItem[size_mass];
                for (int i = 0; i < number_of_tasks - 1; i++)
                {
                    temp[i].id = todoitem[i].id;
                    temp[i].name = todoitem[i].name;
                    temp[i].description = todoitem[i].description;
                    temp[i].due_date = todoitem[i].due_date;
                }
                delete[] todoitem;
                size_mass = size_mass * 2;
                ToDoItem* todoitem = new ToDoItem[size_mass];
                for (int i = 0; i < number_of_tasks - 1; i++)
                {
                    todoitem[i].id = temp[i].id;
                    todoitem[i].name = temp[i].name;
                    todoitem[i].description = temp[i].description;
                    todoitem[i].due_date = temp[i].due_date;
                }

                add_tasks();

                delete[] temp;
            }
            cout << "\nThe tasks is recorded, you can save the changes to a file (3)\n";
            menu();
            break;
        }

        case 2:
        {
            cout << endl;
            cout << "\nYour tasks:\n";
            for (int i = 0; i < number_of_tasks; i++)
            {
                cout << todoitem[i].id << " " << todoitem[i].name << " " << todoitem[i].description << " " << todoitem[i].due_date << endl;
            }
            cout << endl;
            menu();
            break;
        }

        case 3:
        {
            save_results();
            menu();
            break;
        }
        default: cout << "Wrong number" << endl;

            break;
        }
    }
    delete[] todoitem;
}