using System;
namespace HelloApp{
	class program{
		static void Main(string[] args){
			mouth mouth_st_1 = new mouth("I got sick...", 3);
			// Конструктор со всеми параметрами
			// Отрицательный телефон - вызвали throw
			student tom = new student("Borisss", "Nattt",  -333333, mouth_st_1);
			tom.display();
			tom.talk();
			
			// Конструктор с одним параметром
			student kom = new student(222222);
			kom.RatingPrint();
			kom.display();
			
			// Конструктор без параметров
			student bob = new student();
			bob.display();
			
			student tom_2 = new student("Boris", "Nat", 222222, mouth_st_1);
			Console.WriteLine($"ID: {tom_2.ID}\n");
			
			// Массив объектов и работа с ним
			student [] mass = new student[3];
			for(int i = 0; i < 3; i++){
				mass[i] = new student("Boris", "Nat", 222222, mouth_st_1);
				Console.WriteLine($"Name: {mass[i].name}  Surname: {mass[i].surname} ID: { mass[i].ID}  Phone: {mass[i].number_of_phone}\n"); 
			}
			// Демонстрация работы с out и ref
			RefFunction(ref tom);
			Console.WriteLine($"ID: {tom.ID}\n");
			OutFunction(out tom);
			tom.display();
			// Перегрузка + и ++
			(tom + tom_2).display();
			tom.display();
			(++tom).display();
			
			// Работа со строками
			// Конкатенация строк
			string s1 = "hello";
			string s2 = "world";
			string s3 = s1 + " " + s2; // результат: строка "hello world"
			string s4 = String.Concat(s3, "!!!"); // результат: строка "hello world!!!"
			// Сравнение строк
			int result = String.Compare(s1, s2);
			if (result<0)
			{
				Console.WriteLine("s1 > s2\n");
			}
			else if (result > 0)
			{
				Console.WriteLine("s1 < s2\n");
			}
			else
			{
				Console.WriteLine("s1 = s2\n");
			}
			// Поиск в строке
			s1 = "hello world";
			char ch = 'o';
			int indexOfChar = s1.IndexOf(ch); // равно 4
			Console.WriteLine(indexOfChar);
			Console.WriteLine(s4);
			// Вставка
			string text = "Good day";
			string subString = "very good";
			text = text.Insert(8, subString);
			Console.WriteLine(text + "\n");
			
			// Статические методы и поля
			student.get_counter();
			Console.ReadKey();
		}
		
		// Работа с out и ref
		public static void RefFunction(ref student st){
				st.ID += 1;
		}
		public static void OutFunction(out student st){
			st = new student();
		}
	}
}