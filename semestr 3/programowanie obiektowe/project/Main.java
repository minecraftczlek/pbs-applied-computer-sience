package com.project;

import java.time.LocalDate;

import java.time.LocalDateTime;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.project.dao.ProjektDao;
import com.project.dao.ProjektDaoImpl;
import com.project.model.Projekt;

public class Main {
    private static final Logger logger = LoggerFactory.getLogger(Main.class);

    public static void main(String[] args) {
        ProjektDao projektDAO = new ProjektDaoImpl();

        Projekt projekt = new Projekt("testowy", "testowy", LocalDateTime.now(), LocalDate.of(2023, 1, 22));
        try {
            projektDAO.setProjekt(projekt);
            logger.info("Id projektu: {}", projekt.getProjektId());

            List<Projekt> projekty = projektDAO.getProjekty(0, 100);
            for (Projekt prj : projekty) {
                logger.info("Id projektu: {}, nazwa {}", projekt.getProjektId(), projekt.getNazwa());
            }
        } catch (Exception e) {
            logger.error("Błąd podczas operacji bazodanowych", e);
        }
    }
}
