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

void save_results() {
    for (int i = 0; i < number_of_tasks; i++)
        out << todoitem[i].id << " " << todoitem[i].name << " " << todoitem[i].description << " " << todoitem[i].due_date << endl;
    cout << "\Tasks are recorded in the out.txt\n" << endl;
}