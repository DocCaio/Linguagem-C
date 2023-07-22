package exercicios;

public class Exercicios {

    public static void main(String[] args) {
        
        double termo1 = 1;
        double  termo2 = 2;

        int numeroTermos = 10;

        String retorno1 = "";
        String retorno2 = "";
        
        for(int i = 1; i <= numeroTermos; i++)
        {
            termo1 = Math.pow(i,2);
            termo2 = Math.pow((i*2), 2);
            
            retorno1 = retorno1 + " " + termo1;
            retorno2 = retorno2 + " " + termo2;
        }    
        System.out.println(retorno1);
        System.out.println(retorno2);
        
    }
    
}
