import java.util.LinkedList;

public class Trampoline{
    
    private LinkedList<Kid> waiting;
    private LinkedList<Kid> playing;
    
    Trampoline(){

        waiting = new LinkedList<Kid>();
        playing = new LinkedList<Kid>();

    }

    //remove and return the Kid with this name or null
    private Kid remove_kid(String nameToFind, LinkedList<Kid> list){
        Kid kidToRemove = null;

        if(!list.isEmpty()){
            for(int i=0; i<list.size(); i++){

                Kid kidToVerify = list.get(i); // Esta variável recebe o iésimo objeto da linkedlist para verificar se o mesmo contém o nomme alvo
    
                if(kidToVerify.getName().equals(nameToFind)){    //Atribui kidToRemove a criança a ser removida, remove a criaça da linkedlist e para o laço.
    
                    kidToRemove = list.get(i);
                    list.remove(i);
                    break;
                }     
            }
        }

        return kidToRemove;
    }

    //insere na lista de espera
    public void arrive(Kid kidToArrive){

        if(kidToArrive != null)
            waiting.addFirst(kidToArrive);
        else    
            System.out.println("fail: dado incompatível");

    }

    //remove da lista de espera e insere na lista playing
    public void in(){

        if(!waiting.isEmpty())
            playing.addFirst(waiting.removeLast());     //adiciona à lista dos que estão brincando e ao mesmo tempo remove da lista de espera (a função removeFirst além de remover, também retorna o objeto removido)
        else
            System.out.println("fail: nao ha ninguem na fila");

    }


    //remove de playing para wainting
    public void out(){

        if(!playing.isEmpty())
            waiting.addFirst(playing.removeLast());
        else
            System.out.println("fail: nao ha ninguem brincando");
        
    }

    //remove do parquinho
    public Kid remove(String nameToFind){
        Kid kidToRemove = null;

        if(waiting.isEmpty() && playing.isEmpty())    
            System.out.println("fail: a lista esta vazia");
        else{
                /* VERIFICAÇÃO DE WAITING */
            if(!waiting.isEmpty())
               kidToRemove = remove_kid(nameToFind, waiting);

            if(kidToRemove == null){  // se mesmo depois de verificar a lista waiting a criança para remover não for achada, inicia a verificação em playing.
                    /* VERIFICAÇÃO DE PLAYING */
                if(!playing.isEmpty())
                    kidToRemove = remove_kid(nameToFind, playing);
            } 
        }
        


        
        
                   

        return kidToRemove;
    }

    public String toString(){

        String show = "=> ";

        for(int i=0; i < waiting.size(); i++)
            show += waiting.get(i) + " ";
        
        show += "=> [ ";

        for(int i=0; i< playing.size(); i++)
            show += playing.get(i) + " ";

        show += "]";

        
        return show;
    }
    
}