package lab.Intro;

public class Segway extends Pojazd {
    private int generacja;

    public Segway(String model, TypSilnikaEnum typSilnika, int liczbaKol, boolean dwuslad, int generacja) {
        super(model, typSilnika, liczbaKol, dwuslad);
        this.generacja = generacja;
    }

    public int getGeneracja() {
        return generacja;
    }

    public void setGeneracja(int generacja) {
        this.generacja = generacja;
    }

    @Override
    public boolean isZgodnaKategoria(Pojazd innyPojazd) {
        if(!super.isZgodnaKategoria(innyPojazd)) return false;

        //TODO tutaj będą dwa sequey'ie i będziemy to robićna następnych zajęciach
        return false;
    }
}
