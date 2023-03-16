package com.lab.statistics;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.Map;

public class Statistics {
    public static Map<String, Long> countWords(Path path, int wordsLimit) throws IOException {
        Map<String, Long> map = new LinkedHashMap<>();
        Long words = 0L;
        try (BufferedReader reader = Files.newBufferedReader(path)){
            String line =  reader.readLine();
            while(line != null) {
                String[] wordsTab = line.split(" ");
                for (int i = 0; i < wordsTab.length; i++) {
                    String word = wordsTab[i];
                    word = word.replaceAll("[^\\węóąłżźćń]",""); //usuwanie znakó specjalnych
                    if (word.length() > 2) {//tylko słowa dłuższe niż dwa znaki
                        word = word.toUpperCase(); //bez uwzględniania wielkości
                        map.put(word, map.getOrDefault(word, 0L) + 1);
                    }
                }
                line =  reader.readLine();
            }
        }
        Map<String, Long> result = new LinkedHashMap<>();
        map.entrySet().stream().sorted(Map.Entry.comparingByValue(Comparator.reverseOrder())).
                limit(wordsLimit).forEach(entry->result.put(entry.getKey(), entry.getValue()));
//        System.out.println(result.toString());
        return result;
    }
}
