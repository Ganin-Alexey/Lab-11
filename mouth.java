public class mouth{
    String words;
	int number;
    int number_of_offers;        
    /*начало блока инициализатора*/
    {
		number = 4;
        words = "Я забыл...";
        number_of_offers = 1;
    }
    /*конец блока инициализатора*/
    mouth(String words, int number_of_offers){
        this.words = words;
		this.number_of_offers = number_of_offers;
    }
    void talk(){ // объявляем метод рта "говорить"
            for(int i = 0; i < number_of_offers; i++){
                System.out.printf("%s", words);
            }
    }
	void give_number(){ 
		System.out.printf("\n%d\n", number);     
    }	
}