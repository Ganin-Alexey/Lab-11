public class student{
    String name;
    String surname;
    int id;
    int number_of_phone;
    mouth mouth_of_student;
	int [] array_of_ratings = new int[10];
	private static int counter=1; /* Статическое поле */
    /*начало блока инициализатора*/
	// Конструктор без параметров
    student(){
        name = "None";
        surname = "None";
        id=counter;
        number_of_phone = 000000;
    }
    /*конец блока инициализатора*/
	// Конструктор со всеми параметрами
    student(String name, String surname, int number_of_phone, mouth mouth_of_student){
        try // ищем исключения внутри этого блока и отправляем их в соответствующий обработчик catch
            {
            this.name = name;
			this.surname = surname;
			this.id = counter++;
			this.number_of_phone = number_of_phone;
			this.mouth_of_student = mouth_of_student;
            if (number_of_phone < 0){
                throw new Exception("The Number_of_phone is less than 0");// выбрасывается исключение типа const char*
            }
            }
             catch (Exception ex) // обработчик исключений типа const char*
            {
                System.out.println(ex.getMessage());
                this.number_of_phone = 0;
            }
    }
	// Конструктор с одним параметром
    student(int number_of_phone){
        name = "None";
        surname = "None";
        this.id = counter++;
        this.number_of_phone = number_of_phone;
		for (int i = 0; i < 10; i++){
                array_of_ratings[i] = 0;
        }
    }
    void display_st(student st){
        System.out.printf("Name: %s \tSurname: %s\tID: %d\tPhone: %d\n", st.name, st.surname, st.id, st.number_of_phone);
    }
    // Правильное использование this
    void display() {
        display_st(this);
    }
	// Возрат значения из метода через вспомогательный класс
    void talk(){
        mouth_of_student.talk();
    }
	void give_number(){
        mouth_of_student.give_number();
    }
	static void get_counter(){
		System.out.printf("Num of student: %d \n", counter);
	}
	void RatingPrint(){
		System.out.printf("Rating %s: ", name);
           for (int i = 0; i < 10; i++){
               array_of_ratings[i] = 0;
			   System.out.printf("%d; ", array_of_ratings[1]);
           }
           System.out.printf("\n");
    }
}
