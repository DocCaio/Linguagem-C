package jantarcanibais;
public class Cozinheiro implements Runnable{
    private Travessa travessa;
    
    Cozinheiro(Travessa t){
        travessa = t;
    }
    public void run() {
        while(true){
            /* Cozinheiro é acordado para encher a travessa*/
            travessa.enchetravessa();
        }
    }
    
}
