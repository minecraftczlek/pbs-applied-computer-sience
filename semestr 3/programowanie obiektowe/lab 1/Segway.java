package lab;

public class Segway extends Pojazd {
    private int generacja;

    public Segway(String model, TypSilnikaEnum typSilnika, int liczbaKol, boolean dwuslad, int generacja) {
        super(model, typSilnika, liczbaKol, dwuslad);
        this.generacja = generacja;
    }
}
