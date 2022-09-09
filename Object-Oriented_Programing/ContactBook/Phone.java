class Fone {
    private String id;
    private String number;

    Fone(String idToInitialize, String numberToInitialize){

        id = idToInitialize;
        number = numberToInitialize;

    }

    //verifica se o número é um número de telefone válido
    public boolean validate(String numberToValidate){
        boolean IsValid = false;
        String[] validCaracteres = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "(", ")", "."};
        int validCount = 0; //conta o número de o caracter foi considerado válido

        for(int k=0; k<numberToValidate.length(); k++)      //percorre os chars contidos na String numverToValidate
             for(int i=0; i<validCaracteres.length; i++){   //Verifica se todos os caracteres de numberToValidate são válidos
                String caractereToValidate = Character.toString(numberToValidate.charAt(k));    //Converte o char a ser validado em string 
                if(caractereToValidate.equals(validCaracteres[i]))
                    validCount ++;
            }
        if(validCount == numberToValidate.length())  //Se a variável validCount é igual ao numero de caracteres da string numberToValidate, todos os caracteres contidos nesta String são válidos
            IsValid = true;                

        return IsValid;
    }

    //O resultado deve ficar assim
    //oi:1234
    public String toString(){
        String show = id +":"+ number;

        return show;
    }

    //GETS e SETS
    public String getId(){
        return id;
    }
    //public void setId(String id);
    public String getNumber(){
        return number;
    }
    //public void setNumber(String number);
    //utiliza o static validate para retornar se essa instancia do fone é valida
    //public boolean isValid();
}