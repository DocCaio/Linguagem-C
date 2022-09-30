package jantarcanibais;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;
public class Travessa {
    int porcoes, porcao_inicial;
    Semaphore numero_porcoes, cozinheiro, canibal;
    
    Travessa(int M /* numero de porções */){
        //porcoes = M;
        porcao_inicial = M;
        numero_porcoes = new Semaphore(0);
        cozinheiro = new Semaphore(1);
        canibal = new Semaphore(0);
    }
    
    /*Retorna true se conseguiu se servir, senão retorna falso. */
    public boolean seserve() throws InterruptedException{
        numero_porcoes.acquire();
        System.out.println("Canibal");
        if(porcoes == 1){
            //Último canibal se servindo
            System.out.println("Acordar Cozinheiro");
            porcoes --;
            canibal.acquire();
            cozinheiro.release();
            //Thread.sleep(1000);
            return false;
        }
        porcoes--;
        return true;
    }
    
    public void enchetravessa(){
        try {
            
            cozinheiro.acquire();
            System.out.println("Porcao antes: "+porcoes);
            System.out.println("Cozinheiro Acordado");
            porcoes = porcao_inicial;
            System.out.println("Porcao Depois: "+porcoes);
            numero_porcoes.release(10);
            canibal.release();
            
            
            Thread.sleep(1000);
            
            
        } catch (InterruptedException ex) {
            Logger.getLogger(Travessa.class.getName()).log(Level.SEVERE, null, ex);
        }
        //System.out.println("Cozinheiro");
    }
}
    
    

