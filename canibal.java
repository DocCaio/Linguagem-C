package jantarcanibais;
import java.util.logging.Level;
import java.util.logging.Logger;
public class Canibal implements Runnable{
    private Travessa travessa;
    
    Canibal(Travessa t){
        travessa = t;
    }  
    public void run() {
        while(true){
            try {
                if(travessa.seserve() == true){
                    /* canibal servido */
                }else{
                    /* travessa vazia, alguem tem que acordar o cozinheiro. */
                }
            } catch (InterruptedException ex) {
                Logger.getLogger(Canibal.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
    }
    
}