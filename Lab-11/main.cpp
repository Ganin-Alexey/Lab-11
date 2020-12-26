#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
 #include <sstream>  //include this to use string streams
 #include <string>
class student{
    public:
        // ������������� �������
        friend void reset(student &student);
        // ����������� ��� ����������
        student(){
            name = "None_" + std::to_string(num_of_stud);
            surname = "None_" + std::to_string(num_of_stud);
            id = num_of_stud++;
            number_of_phone = 000000;
        }
        // ����������� � ����� ����������
        student(int id_st){
            name = "None";
            surname = "None";
            id = id_st;
            number_of_phone = 000000;
            num_of_stud++;
            for (int i = 0; i < 10; i++){
                array_of_ratings[i] = 1 + rand() % 5;
            }
        }
        // ����������� �� ����� �����������
        student(std::string name_st, std::string surname_st, int id_st, int number_of_phone_st){
            try // ���� ���������� ������ ����� ����� � ���������� �� � ��������������� ���������� catch
            {
            name = name_st;
            surname = surname_st;
            // ���� ������������ ���� ������������� �����, �� ������������� ����������
            id = id_st;
            number_of_phone = number_of_phone_st;
            if (id_st < 0.0){
                throw "Can not take sqrt of negative number";// ������������� ���������� ���� const char*
            }
            if (number_of_phone_st < 0.0){
                throw -1;// ������������� ���������� ���� const char*
            }
            }
             catch (const char* exception) // ���������� ���������� ���� const char*
            {
                std::cerr << "Error: id < 0" << '\n';
                this->id = 0;
            }
            catch(int) // ���������� ���������� ���� const char*
            {
                std::cerr << "Error: number_of_phone < 0" << '\n';
                this->number_of_phone = 0;
            }
            num_of_stud++;
        }
        void read(){
            try // ���� ���������� ������ ����� ����� � ���������� �� � ��������������� ���������� catch
            {
            std::cout << "������� ���: ";
            std::cin >> name;
            std::cout << "������� �������: ";
            std::cin >> surname;
            std::cout << "������� ID: ";
            std::cin >> id;
            // ���� ������������ ���� ������������� �����, �� ������������� ����������
            if (id < 0.0){
                throw "Can not take sqrt of negative number";// ������������� ���������� ���� const char*
            }
            std::cout << "������� ����� ��������: ";
            std::cin >> number_of_phone;
            if (number_of_phone < 0.0){
                throw -1;// ������������� ���������� ���� const char*
            }
            }
             catch (const char* exception) // ���������� ���������� ���� const char*
            {
                std::cerr << "Error: id < 0" << '\n';
                this->id = 0;
            }
            catch(int) // ���������� ���������� ���� const char*
            {
                std::cerr << "Error: number_of_phone < 0" << '\n';
                this->number_of_phone = 0;
            }
        }
        void display_st(student st){
            std::cout << st.name << " " << st.surname << " " << st.id << " " << st.number_of_phone << std::endl;
        }
        // ���������� ������������� this
        void display() {
            display_st(*this);
        }
        void add(class student st2){
            std::cout << "(" << this->id << " + " << st2.id << ")" << std::endl;
        }
        void NameSurnamePrint(){
            std::cout << this->name << " " << this->surname << std::endl;
        }
        std::string NamePrint(){
            return this->name;
        }
        std::string SurnamePrint(){
            return this->surname;
        }
        void RatingPrint(){
            std::cout << "Rating " << this->NamePrint() << ": ";
            for (int i = 0; i < 10; i++){
                std::cout << array_of_ratings[i] << "; ";
            }
            std::cout << std::endl;
        }
        // ������� �������� �� ������ ����� ������ (&)
        int& IdPrint(){
            return this->id;
        }
        // ������� �������� �� ������ ����� ��������� (*)
        int* PhonePrint(){
            return &this->number_of_phone;
        }
        // ���������� ��������� +
        student operator + (student p1) {
            this->add(p1);
            return *this;
        }

        // ���������� ��������� ++ (����������)
        student operator++ (){
            this->id += 1;
            return *this;
        }
        // ���������� ��������� ++ (�����������)
        student operator++ (int){
            student prev = *this;
            this->id += 1;
            return prev;
        }
        // ����������� ���� � ������
        static int get_num_of_stud() {return num_of_stud;}
        //student() {num_of_stud++;}

        // ����������� �����������
        student(const student &copy) :
            name(copy.name), surname(copy.surname), id(copy.id), number_of_phone(copy.number_of_phone)
        {}
        // ���������� ��������� ������������
        student& operator= (const student &st)
        {
            // �������� �� ����������������
            if (this == &st)
                return *this;
             // ��������� ����������� ��������
             name = st.name;
             surname = st.surname;
             id = st.id;
             number_of_phone = st.number_of_phone;

             // ���������� ������� ������, ����� ����� ����������� ������� � ������� ���������� ���������� �������� ������������
             return *this;
        }
    private:
        std::string name;
        std::string surname;
        int id;
        static int num_of_stud; // ����������� ����
        int  number_of_phone;
        int array_of_ratings[10];
};
// ����������� ���� � ������
int student::num_of_stud = 0;   // ������������� �������� ������������ ����

void reset(student &student){
    // �� ����� ������ � �������� ������ �������� ������ student
    student.id = 0;
}

int main(){
    setlocale(LC_ALL, "RUS");
    // ����������� �� ����� �����������
    student stud_1("Aleks", "Ban", -2, 8913339);
    stud_1.display();

    // ����������� � ����� ����������
    student stud_4(5);
    stud_4.display();
    stud_4.RatingPrint();

    // ����������� ��� ����������
    student stud_5();

    // ������� �������� �� ������ ����� ������ (&) (�����)
    std::cout << stud_1.IdPrint() << std::endl;
    std::cout << *stud_1.PhonePrint() << std::endl;

    // ������������� �������
    reset(stud_1);
    stud_1.display();

    // ���������� ��������� +
    student stud_2;
    stud_1 + stud_2;

    // ���������� ��������� ++ (����������� � ����������)
    stud_1++;
    ++stud_1;
    stud_1.display();

    // ����������� ���� � ������
    std::cout << "���-�� ��������� - " << student::get_num_of_stud() << std::endl;

    student stud_3(99999);
    stud_3.display();

    // ���������� ��������� ������������ � �����������
    student stud_6("Par1", "-", 777777, 8141241);
    student stud_7("Par2", "-", 888888, 8351411);
    stud_7 = stud_6;
    stud_7.display();


    // ������ ��������� � �������������� �����������
    typedef struct {
    char *name;
    int value;
    } Node;

    Node n1, n2, n3;

    char name[] = "This is the name";

    n1 = (Node){ name, 1337 };
    n2 = n1; // ���������� �����, n2.name ��������� �� �� �� ������, ��� � n1.name

    n3.value = n1.value;
    n3.name = strdup(n1.name); // �������� ����� - n3.name ��������� n1.name � ���������
                               // ������ ��� �����������, �� ��� ��� �� ��� �� ���������

    // ���������� ������ �� 15-�� ���������
    student students[15];
    for(int i = 0; i < 15; i++){
       std::cout<< "Student �"  <<  students[i].IdPrint() << ": "<< students[i].SurnamePrint() << std::endl;
    }
    // ��������� ������ ���������
    // ������ ���������� ���-�� ��������� - classrooms � ����� ��� ��������� �������� �� 1 �� 3 � � ������ ��������� �� 5 ���������
    int classrooms = (2 + rand() % 5);
    student students_and_classrooms[classrooms][5];
    for(int j = 0; j < classrooms; j++)
        for(int i = 0; i < 5; i++){
           std::cout << "Classroom �" << j + 1 << ": " << students_and_classrooms[j][i].IdPrint() << ": "<< students_and_classrooms[j][i].SurnamePrint() << std::endl;
        }
    return 0;
}
