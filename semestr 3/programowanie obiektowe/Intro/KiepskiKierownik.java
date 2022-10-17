package lab.Intro;

public class KiepskiKierownik {
    private Wykonawca wykonawca;

    public KiepskiKierownik(Wykonawca wykonawca){
        this.wykonawca = wykonawca; //delegat
    }

    public  void wykonajZadanie(){
        wykonawca.wykonajZadanie();
    }
}
