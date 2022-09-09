public class Pass {
    private String name;
    private int age;

    Pass(String nameToInitialize, int ageToInitialize){

        name = nameToInitialize;
        age = ageToInitialize;

    }

    //return true if pass.age >= 65
    public boolean isPriority(){
        boolean IsPriority = false;

        if(age >= 65)
            IsPriority = true;

        return IsPriority;
    }

    //GETS e SETS
    public String getName(){
        return name;
    }
    //void setName(String name);
    //int getAge();
    //void setAge(int age);

    public String toString(){
        String show = name +":"+ age;

        return show;
    }
}