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

        //tutaj będą dwa sequey'ie
        if(innyPojazd instanceof Segway){
            Segway innySegway = (Segway) innyPojazd;
            if(this.generacja == innySegway.getGeneracja()) return true;
        }else System.out.println("Błąd wewnętrzny porównania kategori!");

        return false;
    }
}
