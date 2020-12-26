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
        // Дружественная функция
        friend void reset(student &student);
        // Конструктор без параметров
        student(){
            name = "None_" + std::to_string(num_of_stud);
            surname = "None_" + std::to_string(num_of_stud);
            id = num_of_stud++;
            number_of_phone = 000000;
        }
        // Конструктор с одним параметром
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
        // Конструктор со всеми параметрами
        student(std::string name_st, std::string surname_st, int id_st, int number_of_phone_st){
            try // ищем исключения внутри этого блока и отправляем их в соответствующий обработчик catch
            {
            name = name_st;
            surname = surname_st;
            // Если пользователь ввел отрицательное число, то выбрасывается исключение
            id = id_st;
            number_of_phone = number_of_phone_st;
            if (id_st < 0.0){
                throw "Can not take sqrt of negative number";// выбрасывается исключение типа const char*
            }
            if (number_of_phone_st < 0.0){
                throw -1;// выбрасывается исключение типа const char*
            }
            }
             catch (const char* exception) // обработчик исключений типа const char*
            {
                std::cerr << "Error: id < 0" << '\n';
                this->id = 0;
            }
            catch(int) // обработчик исключений типа const char*
            {
                std::cerr << "Error: number_of_phone < 0" << '\n';
                this->number_of_phone = 0;
            }
            num_of_stud++;
        }
        void read(){
            try // ищем исключения внутри этого блока и отправляем их в соответствующий обработчик catch
            {
            std::cout << "Введите Имя: ";
            std::cin >> name;
            std::cout << "Введите Фамилию: ";
            std::cin >> surname;
            std::cout << "Введите ID: ";
            std::cin >> id;
            // Если пользователь ввел отрицательное число, то выбрасывается исключение
            if (id < 0.0){
                throw "Can not take sqrt of negative number";// выбрасывается исключение типа const char*
            }
            std::cout << "Введите Номер телефона: ";
            std::cin >> number_of_phone;
            if (number_of_phone < 0.0){
                throw -1;// выбрасывается исключение типа const char*
            }
            }
             catch (const char* exception) // обработчик исключений типа const char*
            {
                std::cerr << "Error: id < 0" << '\n';
                this->id = 0;
            }
            catch(int) // обработчик исключений типа const char*
            {
                std::cerr << "Error: number_of_phone < 0" << '\n';
                this->number_of_phone = 0;
            }
        }
        void display_st(student st){
            std::cout << st.name << " " << st.surname << " " << st.id << " " << st.number_of_phone << std::endl;
        }
        // Правильное использование this
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
        // Возврат значения из метода через ссылку (&)
        int& IdPrint(){
            return this->id;
        }
        // Возврат значения из метода через указатель (*)
        int* PhonePrint(){
            return &this->number_of_phone;
        }
        // Перегрузка оператора +
        student operator + (student p1) {
            this->add(p1);
            return *this;
        }

        // Перегрузка оператора ++ (префиксная)
        student operator++ (){
            this->id += 1;
            return *this;
        }
        // Перегрузка оператора ++ (постфиксная)
        student operator++ (int){
            student prev = *this;
            this->id += 1;
            return prev;
        }
        // Статические поля и методы
        static int get_num_of_stud() {return num_of_stud;}
        //student() {num_of_stud++;}

        // Конструктор копирования
        student(const student &copy) :
            name(copy.name), surname(copy.surname), id(copy.id), number_of_phone(copy.number_of_phone)
        {}
        // Перегрузка оператора присваивания
        student& operator= (const student &st)
        {
            // Проверка на самоприсваивание
            if (this == &st)
                return *this;
             // Выполняем копирование значений
             name = st.name;
             surname = st.surname;
             id = st.id;
             number_of_phone = st.number_of_phone;

             // Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
             return *this;
        }
    private:
        std::string name;
        std::string surname;
        int id;
        static int num_of_stud; // Статическое поле
        int  number_of_phone;
        int array_of_ratings[10];
};
// Статические поля и методы
int student::num_of_stud = 0;   // инициализация скрытого статического поля

void reset(student &student){
    // Мы имеем доступ к закрытым членам объектов класса student
    student.id = 0;
}

int main(){
    setlocale(LC_ALL, "RUS");
    // Конструктор со всеми параметрами
    student stud_1("Aleks", "Ban", -2, 8913339);
    stud_1.display();

    // Конструктор с одним параметром
    student stud_4(5);
    stud_4.display();
    stud_4.RatingPrint();

    // Конструктор без параметров
    student stud_5();

    // Возврат значения из метода через ссылку (&) (Вывод)
    std::cout << stud_1.IdPrint() << std::endl;
    std::cout << *stud_1.PhonePrint() << std::endl;

    // Дружественная функция
    reset(stud_1);
    stud_1.display();

    // Перегрузка оператора +
    student stud_2;
    stud_1 + stud_2;

    // Перегрузка оператора ++ (постфиксная и префиксная)
    stud_1++;
    ++stud_1;
    stud_1.display();

    // Статические поля и методы
    std::cout << "Кол-во студентов - " << student::get_num_of_stud() << std::endl;

    student stud_3(99999);
    stud_3.display();

    // Перегрузка оператора присваивания и копирования
    student stud_6("Par1", "-", 777777, 8141241);
    student stud_7("Par2", "-", 888888, 8351411);
    stud_7 = stud_6;
    stud_7.display();


    // ПРИМЕР ГЛУБОКОГО И ПОВЕРХНОСТНОГО КОПИРОВАНИЯ
    typedef struct {
    char *name;
    int value;
    } Node;

    Node n1, n2, n3;

    char name[] = "This is the name";

    n1 = (Node){ name, 1337 };
    n2 = n1; // Неглубокая копия, n2.name указывает на ту же строку, что и n1.name

    n3.value = n1.value;
    n3.name = strdup(n1.name); // Глубокая копия - n3.name идентично n1.name в отношении
                               // только его содержимого, но это уже не тот же указатель

    // Одномерный массив из 15-ти студентов
    student students[15];
    for(int i = 0; i < 15; i++){
       std::cout<< "Student №"  <<  students[i].IdPrint() << ": "<< students[i].SurnamePrint() << std::endl;
    }
    // Двумерный массив студентов
    // Введем переменную кол-во аудиторий - classrooms и пусть оно принимает значение от 1 до 3 и в каждой аудитории по 5 студентов
    int classrooms = (2 + rand() % 5);
    student students_and_classrooms[classrooms][5];
    for(int j = 0; j < classrooms; j++)
        for(int i = 0; i < 5; i++){
           std::cout << "Classroom №" << j + 1 << ": " << students_and_classrooms[j][i].IdPrint() << ": "<< students_and_classrooms[j][i].SurnamePrint() << std::endl;
        }
    return 0;
}
