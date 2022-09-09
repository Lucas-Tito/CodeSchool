public class Person {
    
    private String name;
    private int age;       

    Person(String nameToInit, int ageToInit){

        name = nameToInit;
        age = ageToInit;

    }

    public int getIdade(){           //Criei o método get para usar este atributo na verificação de idade no método drive() da classe Motorcycle
        return age;
    }

    public String toString(){
        String show = "[" + name + ":" + age + "]";

        return show;
    }

}
