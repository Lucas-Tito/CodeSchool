import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ContactStar extends Contact {
    private boolean star;
    //contrutor default
    public ContactStar(String nameToInitialize, List<Fone> fonesToInitialize, boolean starToInitialize){

        super(nameToInitialize, fonesToInitialize);
        star = starToInitialize;

    }

    //muda o prefixo e o valor de star
    public void setStar(boolean valueToSet){

        if(valueToSet == true){
            star = valueToSet;
            super.prefix = "@";
        } 
        else{
            star = valueToSet;
            super.prefix = "-";
        }

    }

    //boolean getStar();
    
}