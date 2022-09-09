import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Agenda {
    private List<Contact> contacts;

    public Agenda(){

        contacts = new ArrayList<Contact>();

    }

    //retorna a posição do contato com esse nome no vetor ou -1 se não existir.
    private int findPosByName(String nameToFind){
        int indexToReturn = -1;

        for(int i=0; i<contacts.size(); i++)
            if(contacts.get(i).getName().equals(nameToFind))   //Se o nome do objeto no índice i for igual a nameToFind
                indexToReturn = i;


        return indexToReturn;
    }


    //retorna o objeto contato com esse nome ou null se não existir
    //utilize o método findPosByName
    public Contact findContact(String nameToFind){
        Contact contactToReturn = null;

        if(findPosByName(nameToFind)!=-1){
            int indexToUse = findPosByName(nameToFind);
            contactToReturn = contacts.get(indexToUse);
        }

        return contactToReturn;

    }


    //se nenhum contato existir com esse nome, adicione
    //se ja existir, faça o merge adicionando os telefones
    //por fim, ordene a lista para ficar em ordem alfabética
    
    public void addContact(Contact contactToAdd) {
        // O código para a ordenação da lista já está feito logo abaixo
        // esta é a última linha de código da função
        if(findContact(contactToAdd.getName())==null)
            contacts.add(contactToAdd);
        else{
            int indexToMergeFrom = findPosByName(contactToAdd.getName());   // acha o index do contato que sofrerá o merge
                
                for(int k=0; k<contactToAdd.getFones().size(); k++){
                    Fone foneToMerge = contactToAdd.getFones().get(k);
                    contacts.get(indexToMergeFrom).addFone(foneToMerge);
                }
                    
            
        
        
        
        this.contacts.sort((Contact c1, Contact c2) -> (c1.getName().compareTo(c2.getName())));
    }
}
    //Utilize o método findPosByName
    public void rmContact(String nameToFind){

        if(findPosByName(nameToFind) != -1){
            
            int indexToRemoveFrom = findPosByName(nameToFind);
            contacts.remove(indexToRemoveFrom);

        }
        else
            System.out.println("fail: contato nao encontrado");
    }

    //Monte uma lista auxiliar procurando no .toString() de cada contato
    //se ele possui a substring procurada.
    //dica: reveja os métodos da classe String e procure algum que ajude aqui
    public List<Contact> search(String pattern){

        List<Contact> SearchList = new ArrayList<Contact>();

        for(int i=0; i<contacts.size(); i++)
            if(contacts.get(i).toString().contains(pattern))
                SearchList.add(contacts.get(i));

            
        return SearchList;

    }


    public List<Contact> getContacts(){
        return contacts;
    }
    public String toString(){
        String show = "";

        for(int i=0; i<contacts.size(); i++){
            show += contacts.get(i).prefix + " " + contacts.get(i).getName()
            + " ";

            List<Fone> fones = contacts.get(i).getFones();
            for(int k=0; k<fones.size(); k++)
                show+="[" +k+ ":" +fones.get(k) + "] ";

            
            show+= "\n";
        }
        return show;
    }
}