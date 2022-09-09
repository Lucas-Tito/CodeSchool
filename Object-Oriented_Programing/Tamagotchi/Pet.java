/*
 * Tendo em vista que estes não eram necessários para o funcionamento do código, não desenvolvi os métodos get
 */


public class Pet{
    private int energyMax, hungryMax, cleanMax;
    private int energy, hungry, clean;      //Alterei shower para clean para deixar o código menos confuso
    private int diamonds;
    private int age;
    private boolean alive;


    Pet(int energyToInitialize, int hungryToInitialize, int cleanToInitialize){
        
        energyMax = energyToInitialize;
        hungryMax = hungryToInitialize;
        cleanMax = cleanToInitialize;

        energy = energyMax;
        hungry = hungryMax;
        clean = cleanMax;

        diamonds = 0;
        age = 0;

        alive = true;

    }

            /*ACÕES DO PET*/

    public void play(){
        
        if(testAlive()){

            setEnergy(-2);
            setHungry(-1);
            setClean(-3);

            diamonds++;
            age++;

        }
        
    }

    public void shower(){

        if(testAlive()){

            setEnergy(-3);
            setHungry(-1);
            setClean(cleanMax);
    
            age+=2;

        }
        
    }


    public void eat(){

        if(testAlive()){

            setEnergy(-1);
            setHungry(4);
            setClean(-2);
    
            age++;

        }   

    }


    public void sleep(){

        if(testAlive()){

            if((energyMax - energy) >= 5)
                setClean(cleanMax);
            else
                System.out.println("fail: nao esta com sono");

        }
        
    }



            /*MÉTODOS BOOLEANOS*/

    public boolean testAlive(){
        boolean isAlive = false;

        if(alive)
            isAlive = true;
        else 
            System.out.println("pet esta morto");

        return isAlive;
    }



                /* MÉTODOS SET */
//Tornei os métodos set privados para que o usuário não tivesse acesso a eles, pois caso contrário este acesso poderia ferir o modo de funcionamento pensado para o programa

    private void setEnergy(int energyToSet){     

            if(energy > energyToSet && (energy - Math.abs(energyToSet)) <= 0 || energy <= 0){
                energy = 0;
                System.out.println("fail: pet morreu de fraqueza");
                alive = false;
            }
            else if((energy + energyToSet) > energyMax)
                energy = energyMax;
            else
                energy += energyToSet; 

    }


    private void setHungry(int hungryToSet){

            if(hungry > hungryToSet && (hungry - Math.abs(hungryToSet)) <= 0 || hungry <= 0){   //No começo de cada set é verificado se o resultado da subtração das saciedades ou a saciedade sozinha é igual a zero 
                hungry = 0;
                System.out.println("fail: pet morreu de fome");
                alive = false;
            }
            else if((hungry + hungryToSet) > hungryMax)
                hungry = hungryMax;
            else
                hungry += hungryToSet;

    }


    private void setClean(int cleanToSet){

            if(clean > cleanToSet && (clean - Math.abs(cleanToSet)) <= 0 || clean <= 0){
                clean = 0;
                System.out.println("fail: pet morreu de sujeira");
                alive = false;
            }
            else if((clean + cleanToSet) > cleanMax)
                clean = cleanMax;
            else
                clean += cleanToSet;

    }

    public String toString(){
        String show = "E:" +energy+ "/" +energyMax+ 
        ", S:" +hungry+ "/" +hungryMax+ 
        ", L:" +clean+ "/" +cleanMax+ 
        ", D:" +diamonds+ ", I:" +age+ "\n";

        return show;
    }




   // int getClean();
   // int getHungry();
   // int getEnergy();
   // int getEnergyMax();
  //  int getCleanMax();
   // int getHungryMax();
  
      
    
   
  
  
  
}