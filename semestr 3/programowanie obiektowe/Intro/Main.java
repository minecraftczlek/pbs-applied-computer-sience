package lab.Intro;

import java.util.concurrent.TimeUnit;

public class Main {
    public static void main(String[] args){
//        test();
//        testDziedziczenia();
//        testKiepskaDelegacja();
//        testDobraDelegacja();
        Runnable task = new Runnable() {
            @Override
            public void run() {
                String name = Thread.currentThread().getName();
                System.out.printf("[%s] Wątek uruchomiony%n", name);
                try {
                    TimeUnit.SECONDS.sleep(7); //Thread.sleep(7000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.printf("[%s] Wątek zakończony%n", name);
            }
        };
        Thread thread = new Thread(task);
        thread.start();
        System.out.println("Wątek wystartowany");
    }

    private static void testDobraDelegacja() {
        IWykonawca sekretarka = new Sekretarka();
        DobryKierownik kierownik = new DobryKierownik(sekretarka);
        kierownik.wykonajZadanie();

        Kurier kurier = new Kurier();
        kierownik = new DobryKierownik(kurier);
        kierownik.wykonajZadanie();

        IWykonawca informatyk = new IWykonawca() {
            @Override
            public void wykonajZadanie() {
                System.out.println(("INFORMATYK (anonimowy): wykonano zadanie\n"));
            }
        };
        kierownik = new DobryKierownik(informatyk);
        kierownik.wykonajZadanie();

        IWykonawca programista = () -> {
            System.out.println("PROGRAMISTA (lambda): wykonano zadanie\n");
        };
        kierownik = new DobryKierownik(programista);
        kierownik.wykonajZadanie();
    }

    private static void testKiepskaDelegacja() {
        Wykonawca sekretarka = new Wykonawca();
        KiepskiKierownik kierownik = new KiepskiKierownik(sekretarka);
        kierownik.wykonajZadanie();

    }


    private static void testDziedziczenia() {
        Pojazd samBMW = new Pojazd("BMW", TypSilnikaEnum.SPALINOWY, 4, true);
        Segway segwayI = new Segway("SegwayI", TypSilnikaEnum.ELEKTRYCZNY, 2, true, 1);

        boolean zgodna = samBMW.isZgodnaKategoria(segwayI);
        System.out.printf("BMW -> SegwayI: %b %n", zgodna);

        Segway segwayII = new Segway("segwayII", TypSilnikaEnum.ELEKTRYCZNY, 2, true, 2);
        zgodna = segwayI.isZgodnaKategoria(segwayII);
        System.out.printf("SegwayI -> SegwayII: %b %n", zgodna);

        Segway segwayIIDeluxe = new Segway("segwayIIDeluxe", TypSilnikaEnum.ELEKTRYCZNY, 2, true, 2);
        zgodna = segwayII.isZgodnaKategoria(segwayIIDeluxe);
        System.out.printf("SegwayII -> SegwayIIDeluxe: %b %n", zgodna);
    }

    private static void test() {
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

