public class Motorcycle {
    
    private Person person; //agregacao
    private int power;
    private int time;

    //Inicia o atributo power, time com zero e person com null
    Motorcycle(int powerToInit){

        power = powerToInit;
        time = 0;
        person = null;

    }


    //Comprar mais tempo
    public void buy(int timeBought){

        if(timeBought > 0)
            time += timeBought;
        else  
            System.out.println("Não vendemos fiado");

    }

    //Se estiver vazio, coloca a pessoa na moto e retorna true
    public boolean in(Person personToPlace){
        boolean Success = false;

        if(person == null){
            person = personToPlace;
            Success = true;
        }
            
        else
            System.out.println("Moto ocupada");
        
        return Success;
    }

    //Se houver uma person, retira e retorna
    //Se não, retorna null
    public Person out(){
        
        if(person != null)
            person = null;
        else
            System.out.println("Não há ninguém na moto");

        return person;

    }


    public void drive(int timeToSpend){

        if(person == null)
            System.out.println("Alguém deve subir na moto para dirigir");
        else{
            if(person.getIdade() < 10 && person.getIdade() >= 4){
                if(time > 0){
    
                    if(time > timeToSpend)
                        time -= timeToSpend;
                    else{
    
                        System.out.println("Andou " + time + " min e acabou o tempo");
                        time = 0;
    
                    }
                        
    
                }
                else 
                    System.out.println("Tempo zerado");
            }
            else    
                System.out.println("Devido a idade, esta pessoa não pode andar na moto");
        }            

    }


    //buzinar
    public void honk(){

        System.out.print("P");

        for(int i = 0; i<power ; i++)
            System.out.print("e");

        System.out.println("m");

    }

    public String toString(){
        String show = "potencia: " + power + ", minutos: " + time + ", pessoa: " +person;

        return show;
    }

}
