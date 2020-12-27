public class program{
    public static void main(String[] args) {
      mouth mouth_st_1 = new mouth("I got sick...", 3);
	  // Конструктор со всеми параметрами
      student tom = new student("Boris", "Nat", -333333, mouth_st_1);
      tom.display();
      tom.talk();
	  // Конструктор с одним параметром
      student kom = new student(222222);
	  kom.display();
	  kom.RatingPrint();
	  // Конструктор без параметров
      student bob = new student();
	  bob.display();
	  // Зад. 6 Возврат целочисленного значения из метода при помощи вспомог. класса
	  tom.give_number();
	  
	  // Массив объектов и работа с ним
	  student [] mass = new student[3];
	  for(int i = 0; i < 3; i++){
		  mass[i] = new student("Boris", "Nat", 222222, mouth_st_1);
		  System.out.printf("Name: %s \tSurname: %s\tID: %d\tPhone: %d\n", mass[i].name, mass[i].surname, mass[i].id, mass[i].number_of_phone);
	  }
	  // Обработка строк
		String str1 = "Java";
		String str2 = "Hello";
	    String str3 = str1 + " " + str2;
		str3 = "Year " + 2015;		 
		System.out.println(str3);
		str2 = str2.concat(str1);
		System.out.println(str2);
		str3 = String.join(" ", str2, str1);
		System.out.println(str3);
		
		// Cтатические методы и поля Лаб-8
		student.get_counter();
		
		// Одномерный массив из 15-ти студентов
		student [] students = new student[5];
		for(int i = 0; i < students.length; i++){
			students[i] = new student();
			System.out.printf("Student # %d: %s\n", students[i].IdPrint(), students[i].SurnamePrint());
			//Console.WriteLine($"Student № {students[i].IdPrint()}: {students[i].SurnamePrint()}\n"); 
		}
		// Двумерный массив студентов
		// Введем переменную кол-во аудиторий - classrooms и пусть оно принимает значение 3 и в каждой аудитории по 5 студентов
		int classrooms = 3;
		student[][] students_and_classrooms = new student[classrooms][5];
		for(int j = 0; j < classrooms; j++)
			for(int i = 0; i < 5; i++){
			students_and_classrooms[j][i] = new student();	
			System.out.printf("Classroom #%d: %d: %s\n", j+1, students_and_classrooms[j][i].IdPrint(), students_and_classrooms[j][i].SurnamePrint());
			//Console.WriteLine($"Classroom №{j+1}: {students_and_classrooms[j, i].IdPrint()}: {students_and_classrooms[j, i].SurnamePrint()}\n"); 
			}
	 }
}
