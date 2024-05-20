#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Element
{
    string name;
    string id;
    int age;
    double score;
};

class Node
{
public:
    Element data;
    Node *next;

    Node()
    {
        next = nullptr;
    }
    Node(Element data)
    {
        this->data = data;
        next = nullptr;
    }
};

class MyLinkedStack
{
private:
    Node *stacktop;

public:
    MyLinkedStack()
    {
        stacktop = nullptr;
    }

    void initialize()
    {
        while (!isEmpty())
            pop();
    }
    bool isEmpty() const
    {
        return (stacktop == nullptr);
    }
    void push(const Element &e)
    {
        Node *temp = new Node(e);
        temp->next = stacktop;
        stacktop = temp;
    }
    void pop()
    {
        if (isEmpty())
            return;
        Node *temp = stacktop;
        stacktop = stacktop->next;
        temp = nullptr;
        delete temp;
    }
    Element peek(string id) const
    {
        Node *temp;
        Element e;
        for (temp = stacktop; temp != nullptr; temp = temp->next)
        {
            e = temp->data;
            if (e.id == id)
                return e;
        }
        e.id = "No";
        return e;
    }
    int getNodeCnt() const
    {
        int cnt;
        Node *temp = stacktop;
        for (cnt = 0; temp != nullptr; cnt++, temp = temp->next)
            ;
        return cnt;
    }
    void printNode() const
    {
        cout << endl;
        MyLinkedStack temp_stack;
        for (Node *temp = stacktop; temp != nullptr; temp = temp->next)
        {
            Element e = temp->data;
            temp_stack.push(e);
        }

        printf("id_number\tname\t\tage\t\tscore\n");
        for (Node *temp = temp_stack.stacktop; temp != nullptr; temp = temp->next)
        {
            Element e = temp->data;
            printf("%-5s\t\t%-15s\t%-3d\t\t%-5.1f\n", e.id.c_str(), e.name.c_str(), e.age, e.score);
        }
    }
    void deleteNode(string id)
    {
        Node *current;
        Node *temp;
        for (current = stacktop; current != nullptr; current = current->next)
        {

            Element e = current->data;
            if (e.id == id)
            {
                if (current == stacktop)
                    stacktop = stacktop->next;
                else
                    temp->next = current->next;
                current = nullptr;
                cout << e.name << "'s record is deleted." << endl;
                return;
            }
            temp = current;
        }
        cout << "No record Shown" << endl;
    }

    ~MyLinkedStack()
    {
        initialize();
    }
};

char getMenu();
void addData(MyLinkedStack *ls);
void deleteData(MyLinkedStack *ls);
void retrieveData(MyLinkedStack *ls);

int main()
{
    MyLinkedStack ls1; // linked stack

    // input file name from user
    char *file_name; // file name
    cout << "Enter input file name : ";
    cin >> file_name;

    // open the file to get some data
    ifstream ifs;
    ifs.open(file_name);
    if (ifs.fail()) // error check
    {
        printf("Failed to open the file %s on line %d of file %s\n", file_name, __LINE__, __FILE__);
        exit(-1);
    }

    // get data from the file
    string line;
    getline(ifs, line);
    while (getline(ifs, line))
    {
        istringstream iss(line);
        Element e;
        iss >> e.id >> e.name >> e.age >> e.score;
        ls1.push(e);
    }

    // program functions
    while (1)
    {
        // get menu chice from user
        char menu = getMenu();

        if (menu == 'A') // Add new data
            addData(&ls1);
        if (menu == 'D') // Delete data
            deleteData(&ls1);
        if (menu == 'R') // Retrieve data
            retrieveData(&ls1);
        if (menu == 'P') // Print data
            ls1.printNode();
        if (menu == 'Q') // Quit
            break;
    }

    // godd bye!
    cout << endl;
    cout << "Bye!" << endl;
}

char getMenu()
{
    char menu;
    cout << endl;
    cout << "*********** MENU ***********" << endl;
    cout << "A : Add new data" << endl;
    cout << "D : Delete Data" << endl;
    cout << "R : Retrieve data" << endl;
    cout << "P : Print list" << endl;
    cout << "Q : Quit" << endl;
    cout << "Chose menu : ";
    cin >> menu;

    return menu;
}

void addData(MyLinkedStack *ls)
{
    Element e;
    cout << "==> Type student name : ";
    cin >> e.name;
    cout << "==> Type student id : ";
    cin >> e.id;
    cout << "==> Type age of student : ";
    cin >> e.age;
    cout << "==> Type score : ";
    cin >> e.score;
    ls->push(e);
    cout << endl;

    cout << e.name << "'s record is added." << endl;
}

void deleteData(MyLinkedStack *ls)
{
    string id;
    cout << "==> Type student id : ";
    cin >> id;
    cout << endl;
    ls->deleteNode(id);
}

void retrieveData(MyLinkedStack *ls)
{
    string id;
    cout << "==> Type Student id : ";
    cin >> id;
    cout << endl;
    Element e = ls->peek(id);
    if (e.id == "No")
        cout << "No record shown" << endl;
    else
        cout << e.name << "'s age is " << e.age << " and score is " << e.score << endl;
}