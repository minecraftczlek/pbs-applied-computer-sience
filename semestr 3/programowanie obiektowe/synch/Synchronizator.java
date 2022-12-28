package com.synch;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;

public class Synchronizator{
    private AtomicBoolean monitor;
    private ExecutorService executor;

    public Synchronizator(){
        monitor = new AtomicBoolean(false);
        executor = Executors.newSingleThreadExecutor();
    }
    public void start(){
        if(monitor.compareAndSet(false, true)){
            Runnable task = () -> {
                while(monitor.get()){
                    try{
                        synchronizuj();
                        TimeUnit.SECONDS.sleep(1);
                    }catch (InterruptedException e){
                        System.out.println("Wątek moniturorujący obudzony!");
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }
            };
            executor.execute(task);
        }
    }
    public void stop(){
        monitor.set(false);
    }
    public void dispose(){
        executor.shutdownNow();
    }
    public void synchronizuj()  throws IOException{
        //PRZYDATANE OPERACJE DO IMPLEMENTACJI MEDOTY SYNCHRONIZUJĄCEJ
        Path pathA = Paths.get("A");
        Path pathB = Paths.get("B");
        boolean isDirectoryA = Files.isDirectory(pathA);
        System.out.printf("Czy %s jest katalogiem %b%n", pathA, isDirectoryA);
        boolean existA = Files.exists(pathA);
        System.out.printf("Katalog %s istnieje: %b%n", pathA, existA);
        File dirA = pathA.toFile();
        String[] listA = dirA.list();
        File dirB = pathB.toFile();
        String[] listB = dirB.list();
        if(listB.length>0){
            for (int i = 0; i < listA.length; i++){
                boolean kopiuj=true;
				listB = dirB.list();
                for (int j = 0; j < listB.length; j++) {
                    if (listA[i].equals(listB[j])) {
                        kopiuj = false;
                        break;
                    }
                }
                if (kopiuj) {
                    String filetoCopy = listA[i];
                    Path src = Paths.get(pathA.toString(), filetoCopy);
                    Path dst = Paths.get(pathB.toString(), filetoCopy);
                    if (!Files.isDirectory(src)) {
                        System.out.printf("Kopiowanie pliku %s do %s%n", src, dst);
                        Files.copy(src, dst);
                    }
                    else {
                        System.out.printf("Tworzenie katalogu %s do %s%n", src, dst);
                        Files.createDirectories(dst);
                    }
                }
            }
            if (listB.length>listA.length) {
                for (int i = 0; i < listB.length; i++) {
                    boolean usun=false;
                    listB = dirB.list();
                    for (int j = 0; j < listA.length; j++) {
                        if (listB[i].equals(listA[j])==false) {
                            usun=true;
                        }
                    }
                    if (usun) {
                        String fileToDelete = listB[i];
                        Path file = Paths.get(pathB.toString(), fileToDelete);
                        System.out.printf("Usuwanie pliku %s%n%n", file);
                        Files.delete(file);
                        break;
                    }
                }
            }
        }
        else {
            for (int i = 0; i < listA.length; i++) {
                String filetoCopy = listA[i];
                Path src = Paths.get(pathA.toString(), filetoCopy);
                Path dst = Paths.get(pathB.toString(), filetoCopy);
                if (!Files.isDirectory(src)) {
                    System.out.printf("Kopiowanie pliku %s do %s%n", src, dst);
                    Files.copy(src, dst);
                    break;
                }
                else {
                    System.out.printf("Tworzenie katalogu %s do %s%n", src, dst);
                    Files.createDirectories(dst);
                }
            }
        }
        System.out.printf("Synchronizacja zakończona%n%n");
    }
    public static void main(String[] args){
        Synchronizator synch = new Synchronizator();
        synch.start();
        try{
            TimeUnit.MINUTES.sleep(1);
        }catch (InterruptedException e){
        }
        synch.stop();
        synch.dispose();
    }
}
