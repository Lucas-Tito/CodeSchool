import java.util.Map;
import java.util.HashMap;

class BankBranch {
    private Map<String, Client> clients;
    private Map<Integer, Account> accounts;
    private int nextAccountId = 0;

    //obtém conta ou lança exceção
    //private Account getAccount(int id);

    public BankBranch(){

        clients = new HashMap<String, Client>();
        accounts = new HashMap<Integer, Account>();

    }

    //se o cliente não existir
    //cria o cliente
    //cria uma conta poupança e uma conta corrent para o cliente
    //adiciona essas contas no vetor de contas e no vetor do cliente
    //adiciona o cliente no mapa de clientes
    public void addClient(String clientIdToAdd){

        if(clients.containsKey(clientIdToAdd))
            System.out.println("fail: cliente ja cadastrado");
        else{
            clients.put(clientIdToAdd, new Client(clientIdToAdd));  //Adiciona o client no Map clients

            //Cria o objeto cliente e as respectivas contas a serem adicionadas
            Client c = clients.get(clientIdToAdd);
            int CcId = nextAccountId++;
            Account CcAccount = new CheckingAccount(CcId, clientIdToAdd);
            int CpId = nextAccountId++;
            Account CpAccount = new SavingsAccount(CpId, clientIdToAdd);
           
            
            c.addAccount(CcAccount);
            c.addAccount(CpAccount);    // Adiciona as contas ao objeto cliente
            

            accounts.put(CcId, CcAccount);
            accounts.put(CpId, CpAccount);  //Adicionas as contas ao Map accounts
            

        }

    }
    //obtem o cliente e invoca as ações
    public void withdraw(int idConta, float valueToWithdraw){

        Account accountToWithdrawFrom = accounts.get(idConta);
        accountToWithdrawFrom.withdraw(valueToWithdraw);

    }


    public void deposit(int idConta, float valueToDeposit){

        Account accountToDeposiIn = accounts.get(idConta);
        accountToDeposiIn.deposit(valueToDeposit);

    }

    public void transfer(int IdcontaDe, int IdcontaPara, float valueToTransfer){

        Account accountToGive = accounts.get(IdcontaDe);
        Account accountToRecieve = accounts.get(IdcontaPara);

        if(accounts.containsKey(IdcontaDe) && accounts.containsKey(IdcontaPara)){
            accountToGive.withdraw(valueToTransfer);
            accountToRecieve.deposit(valueToTransfer);
        }
        else
            System.out.println("fail: conta nao encontrada");

    }
    
    public void monthlyUpdate(){

        for(Integer id: accounts.keySet())
            accounts.get(id).monthlyUpdate();

    }

    public String toString(){
        String show = "";

        show += "Clients:" + "\n";
        for(String id: clients.keySet()) // printa os clientes
            show += clients.get(id) + "\n";
        


        show += "Accounts:" + "\n";
        for(Integer id: accounts.keySet()) // printa as contas 
                show += accounts.get(id) + "\n";
        

        return show;
    }
};