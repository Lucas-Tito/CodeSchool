public class Grafite {

    float calibre;
    String dureza;
    int tamanho;


    Grafite(float calibreToInit, String durezaToInit, int tamanhoToInit){

        calibre = calibreToInit;
        dureza = durezaToInit;
        tamanho = tamanhoToInit;

    }

    public String toString(){
        String show = "[" +calibre+ ":" +dureza+ ":" +tamanho+ "]";

        return show;
    }

    public int desgastePorFolha(){
        int desgaste = 0;

        if(dureza.equals("HB"))
            desgaste = 1;

        else if(dureza.equals("2B"))
            desgaste = 2;

        else if(dureza.equals("4B"))
            desgaste = 4;

        else if(dureza.equals("6B"))
            desgaste = 6;
        

        return desgaste;

    }

}