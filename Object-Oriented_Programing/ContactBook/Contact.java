import java.util.List;
import java.util.ArrayList;

public class Contact {
    private String name;
    private List<Fone> fones;
    protected String prefix = "-"; //utilizado no toString
    //Crie um ArrayList para o ATRIBUTO fones
    //Se a variável fones não for null, adicione todos os fones usando o método addFone
    
    Contact(String nameToInitialize, List<Fone> fonesToInitialize){

        name = nameToInitialize;

        fones = new ArrayList<Fone>();
        if(fonesToInitialize != null)
            for(int i =0; i<fonesToInitialize.size(); i++)
                addFone(fonesToInitialize.get(i));

    }

    
    //Se fone for válido, insira no atributo fones
    //Se não, informe o erro
    public void addFone(Fone foneToAdd){

        if(foneToAdd.validate(foneToAdd.getNumber()))
        fones.add(new Fone(foneToAdd.getId(), foneToAdd.getNumber()));
    else
        System.out.println("fail: invalid number");

    }


    //Se o índice existir no ArrayList, remova o telefone com esse índice
    public void rmFone(int indexToRemoveFrom){
        if(!(fones.size() <= indexToRemoveFrom || indexToRemoveFrom < 0))
            fones.remove(indexToRemoveFrom);
        else
            System.out.println("fail: invalid index");
    }


    //Use um contador para mostrar o índice do telefone
    //Use o toString do fone para adicioná-lo à saída
    //O resultado dever ficar assim:
    //- david [0:oi:123] [1:tim:9081] [2:claro:5431]
    public String toString(){
        String show = prefix +" " +name+ " ";

        if(fones != null)
            for(int i=0; i<fones.size(); i++)
                show += "[" +i+ ":" +fones.get(i)+ "] ";

        return show;
    }


    //GETS e SETS
    public String getName(){
        return name;
    }
    //public void setName(String name);
    public List<Fone> getFones(){
        return fones;
    }
    //limpe a lista de fones
    //utilize o addFone para adicionar apenas os fones válidos
    public void setFones(List<Fone> fones){

        for(int i = 0; i < fones.size();i++)
            rmFone(i);
        
      }
}