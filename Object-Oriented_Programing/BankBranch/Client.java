import java.util.ArrayList;

import java.util.ArrayList;
import java.util.List;

class Client {

    private String clientId;
    private List<Account> accounts;

    public Client(String clientIdToInitialize){

        clientId = clientIdToInitialize;
        accounts = new ArrayList<Account>();

    }

    public void addAccount(Account account){

        accounts.add(account);

    }

    public java.lang.String toString(){

        String show = "- " +clientId+ " [";

        for(int i=0; i<accounts.size(); i++){

            if(i == accounts.size()-1)
                show += accounts.get(i).id;
            else
                show += accounts.get(i).id + ", ";
        }

        show += "]";
        
        return show;
             
    }


    //GETS and SETS
    //String getClientId();
    //void setClientId(String clientId);
    List<Account> getAccounts(){
        return accounts;
    }
    //void setAccounts(List<Account> accounts);

};