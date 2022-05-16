#include "Header.h"

struct ToDoItem {
    int id;
    string name;
    string description;
    double due_date;
};


int number_of_tasks;
int choice = 666;
int size_mass = 5;
ToDoItem* todoitem = new ToDoItem[size_mass];

ifstream in("C:\\Users\\Admin\\Desktop\\Академия Шаг\\Homework\\Програмирование\\Lesson 28\\GitDemo_hw_2\\GitDemo_hw_2\\in.txt");
ofstream out("C:\\Users\\Admin\\Desktop\\Академия Шаг\\Homework\\Програмирование\\Lesson 28\\GitDemo_hw_2\\GitDemo_hw_2\\out.txt");

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
 
 
void add_tasks() {
    cout << "\nEnter the id of the new tasks\n";
    cin >> todoitem[number_of_tasks - 1].id;
    cout << "\nEnter the name of the new tasks\n";
    cin >> todoitem[number_of_tasks - 1].name;
    cout << "\nEnter the description of the new tasks\n";
    cin >> todoitem[number_of_tasks - 1].description;
    cout << "\nEnter the date of the new tasks\n";
    cin >> todoitem[number_of_tasks - 1].due_date;

}

void menu() {
    cout << "To enter a new tasks, press 1" << endl;
    cout << "To display all tasks, press 2" << endl;
    cout << "Press 3 to save changes to the file" << endl;
    cout << "Press 0 to exit" << endl;

}

void save_results() {
    for (int i = 0; i < number_of_tasks; i++)
        out << todoitem[i].id << " " << todoitem[i].name << " " << todoitem[i].description << " " << todoitem[i].due_date << endl;
    cout << "\Tasks are recorded in the out.txt\n" << endl;

}

      