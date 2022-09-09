class SavingsAccount extends Account {

    public SavingsAccount(int id, String idClient){

        super(id, idClient);
        super.type = "CP";

    }

    //aumenta saldo em 1%
    public void monthlyUpdate(){

        super.balance += balance*0.01;

    }
}