package lab.Intro;

public class DobryKierownik {
    private IWykonawca wykonawca;

    public DobryKierownik(IWykonawca wykonawca){
        this.wykonawca = wykonawca; //delegat
    }

    public  void wykonajZadanie(){
        wykonawca.wykonajZadanie();
    }
}
