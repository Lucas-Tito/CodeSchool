abstract class Account {
    protected int id;
    protected float balance;
    protected String clientId;
    protected String type; //CC or CP

    public Account(int idToInitialize, String clientIdToInitialize){
        
        id = idToInitialize;
        clientId = clientIdToInitialize;
        balance = (float)0;

    }
    
    //abstract method
    public abstract void monthlyUpdate();

    public void withdraw(float value){

        if(value <= balance)
            balance -= value;
        else
            System.out.println("fail: saldo insuficiente");

    }

    public void deposit(float value){

        balance += value;

    }


    //public void transfer(Account other, float value){}

    public String toString(){

        return id +":"+ clientId +":"+ balance +":"+ type;

    }

    //GETS and SETS
    int getId(){
        return id;
    }
    float getBalance(){
        return balance;
    }
    String getClientId(){
        return clientId;
    }
    //String getType();
}