using System;
namespace HelloApp{
public class mouth{
    public string words;
    public int number_of_offers;        
    
    public mouth(string words, int number_of_offers){
        this.words = words;
		this.number_of_offers = number_of_offers;
    }
    public void talk(){ // объявляем метод рта "говорить"
            for(int i = 0; i < number_of_offers; i++){
                Console.WriteLine($"{words}");
            }
    }	
}
}