class CheckingAccount extends Account {
    //initializes account.type with "CC"
    public CheckingAccount(int id, String idClient){

        super(id, idClient);
        super.type = "CC";

    }

    //removes 20 from balance
    public void monthlyUpdate(){

        super.balance -= 20;

    }
}