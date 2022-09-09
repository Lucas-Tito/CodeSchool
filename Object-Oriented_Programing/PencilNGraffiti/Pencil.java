import java.util.ArrayList;

public class Lapiseira {
    float calibre;
    Grafite bico;
    ArrayList<Grafite> tambor;

    Lapiseira(float calibreToInit){
        calibre = calibreToInit;
        bico = null;
        tambor = new ArrayList<Grafite>();
    }

    public String toString(){
        String show = "calibre: " +calibre+ ", bico: " + bico+ ", tambor: {";

        for(int i = 0; i < tambor.size(); i++)
            show+= tambor.get(i);
        
        show+="}";

        return show;
    }

     public boolean inserir(Grafite grafiteToInsert){
        boolean success = false;   

            if(calibre == grafiteToInsert.calibre){
                tambor.add(grafiteToInsert);
                success = true;
            }
            else
                System.out.println("fail: calibre incompatível");  


        return success;
    }

    public Grafite remover(){

        if(bico != null){
            bico = null;
        }
        else
            System.out.println("fail: nao existe grafite no bico");

        return bico;

    }

    public boolean puxar(){

            boolean success = false;
            
            if(!tambor.isEmpty()){

                if(bico == null){
                    bico = tambor.get(0);
                    tambor.remove(0);
                    success = true;
                }
                else
                    System.out.println("fail: ja existe grafite no bico");

            }
            else
                System.out.println("fail: nao existe grafite no tambor");
            


            return success;

    }

    public void escrever(){
        if(bico != null && bico.tamanho > 10){

            if(bico.tamanho - bico.desgastePorFolha() >= 10){
                
                if(bico.tamanho - bico.desgastePorFolha() == 10)
                    System.out.println("warning: grafite acabou");

                bico.tamanho -= bico.desgastePorFolha();
                
            }         
            else{
                bico.tamanho = 10;
                System.out.println("fail: folha incompleta");
                System.out.println("warning: grafite acabou");  
            } 
                
        }
        else{
            if(bico == null)
                System.out.println("fail: nao existe grafite no bico");

            else if(bico.tamanho <= 10)
                System.out.println("fail: grafite acabou");
        }
}
}