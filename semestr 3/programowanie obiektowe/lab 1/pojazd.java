package lab.Intro;

public class Pojazd {
    private String model;
    private TypSilnikaEnum typSilnika;
    private int liczbaKol;
    private boolean dwuslad;

    public Pojazd(){
    }

    public Pojazd(String model, TypSilnikaEnum typSilnika, int liczbaKol, boolean dwuslad) {
        this.model = model;
        this.typSilnika = typSilnika;
        this.liczbaKol = liczbaKol;
        this.dwuslad = dwuslad;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public boolean isZgodnaKategoria(Pojazd innyPojazd){
        return innyPojazd != null
                && this.liczbaKol == innyPojazd.liczbaKol
                && this.dwuslad == innyPojazd.dwuslad
                && this.typSilnika.equals(innyPojazd.typSilnika);
    }
}
