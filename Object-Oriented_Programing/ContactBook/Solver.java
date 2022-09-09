import java.util.Scanner;
import java.util.stream.Collectors; 
import java.util.Arrays;
import java.util.List;

class Solver {
    //cria um ContactStar a partir do vetor de entrada tal como
    //add joao oi:123 tim:432 claro:09123
    static ContactStar parseContact(String[] ui) {
        return new ContactStar(ui[1], Arrays.asList(ui).stream()
            .skip(2).map(token -> new Fone(token.split(":")[0], token.split(":")[1]))
            .collect(Collectors.toList()), false);
    }
}