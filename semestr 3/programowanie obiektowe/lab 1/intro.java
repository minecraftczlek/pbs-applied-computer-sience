package lab;

public class intro {
    public static void main(String[] args){
        System.out.println("żegnaj świecie!");

        double[] tab = new double[] {3.5, 5.5, 13, 3, 6.6};
        System.out.println("Wynik: " + srednia(tab));
    }

    public static double srednia(double[] tab){
        double wynik = 0 ;

        for(int i=0; i < tab.length; i++)wynik += tab[i];

        return wynik / tab.length;
    }
}
