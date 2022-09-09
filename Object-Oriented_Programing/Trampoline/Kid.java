/**
 * Desenvolvi apenas o método getName, pois foi o único que julguei necessário
 * Outrossim, getName está público, pois precisei do mesmo em algumas verificações na classe Trampoline
 */

public class Kid {

    private int age;
    private String name;

    Kid(String nameToInit, int ageToInit){

        name = nameToInit;
        age = ageToInit;

    }

    //int getAge();

    public String getName(){
        return name;
    }
    //void setAge(int age);
    //public void setName(String name); //gs

    public String toString(){

        String show = name+ ":" +age;

        return show;
    }
    
}