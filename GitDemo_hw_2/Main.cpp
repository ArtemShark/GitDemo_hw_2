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