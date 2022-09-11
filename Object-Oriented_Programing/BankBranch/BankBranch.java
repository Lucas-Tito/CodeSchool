import java.util.Map;
import java.util.HashMap;

class BankBranch {
    private Map<String, Client> clients;
    private Map<Integer, Account> accounts;
    private int nextAccountId = 0;


    //private Account getAccount(int id);

    public BankBranch(){

        clients = new HashMap<String, Client>();
        accounts = new HashMap<Integer, Account>();

    }

    //if client doesn't exists
    //client is created
    //creates checking and savings account too
    //add these accounts to accounts array and array on client
    //add client to clients map
    public void addClient(String clientIdToAdd){

        if(clients.containsKey(clientIdToAdd))
            System.out.println("fail: client already registered");
        else{
            clients.put(clientIdToAdd, new Client(clientIdToAdd));  //Adds client to clients map

            //Create client object and his respective accounts
            Client c = clients.get(clientIdToAdd);
            int CcId = nextAccountId++;
            Account CcAccount = new CheckingAccount(CcId, clientIdToAdd);
            int CpId = nextAccountId++;
            Account CpAccount = new SavingsAccount(CpId, clientIdToAdd);
           
            
            c.addAccount(CcAccount);
            c.addAccount(CpAccount);    //Add accounts to client object
            

            accounts.put(CcId, CcAccount);
            accounts.put(CpId, CpAccount);  //Add accounts to accounts map
            

        }

    }
    //gets tbe client and invoke actions
    public void withdraw(int idAccount, float valueToWithdraw){

        Account accountToWithdrawFrom = accounts.get(idAccount);
        accountToWithdrawFrom.withdraw(valueToWithdraw);

    }


    public void deposit(int idAccount, float valueToDeposit){

        Account accountToDepositIn = accounts.get(idAccount);
        accountToDepositIn.deposit(valueToDeposit);

    }

    public void transfer(int IdAccountTransferring, int IdAccountReceiving, float valueToTransfer){

        Account accountToGive = accounts.get(IdAccountTransferring);
        Account accountToReceive = accounts.get(IdAccountReceiving);

        if(accounts.containsKey(IdAccountTransferring) && accounts.containsKey(IdAccountReceiving)){
            accountToGive.withdraw(valueToTransfer);
            accountToReceive.deposit(valueToTransfer);
        }
        else
            System.out.println("fail: account not found");

    }
    
    public void monthlyUpdate(){

        for(Integer id: accounts.keySet())
            accounts.get(id).monthlyUpdate();

    }

    public String toString(){
        String show = "";

        show += "Clients:" + "\n";
        for(String id: clients.keySet()) // prints clients
            show += clients.get(id) + "\n";
        


        show += "Accounts:" + "\n";
        for(Integer id: accounts.keySet()) // prints accounts
                show += accounts.get(id) + "\n";
        

        return show;
    }
};