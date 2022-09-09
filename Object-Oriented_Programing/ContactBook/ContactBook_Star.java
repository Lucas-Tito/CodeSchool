import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class AgendaStar extends Agenda {

    //SE o contato existir e for do tipo ContatoStar altere o atributo star dele
    public void star(String nameToFind, boolean valueToSet){

        Contact contactToChange = findContact(nameToFind);
        if(contactToChange!=null){
            
            if(contactToChange instanceof ContactStar)
                ((ContactStar) contactToChange).setStar(valueToSet);
            
        }
        else
            System.out.println("fail: contato inexistente");
            
        
    }
    //filtre em uma nova lista apenas os contatos que forem do tipo ContatoStar e que estão favoritados
    public List<Contact> getStarred(){

        List<Contact> StarredList = new ArrayList<Contact>();

        for(int i=0; i<super.getContacts().size(); i++){

            if(super.getContacts().get(i) instanceof ContactStar)
                if(super.getContacts().get(i).prefix.equals("@"))
                    StarredList.add(super.getContacts().get(i));

        }
            

            
        return StarredList;

    }

}