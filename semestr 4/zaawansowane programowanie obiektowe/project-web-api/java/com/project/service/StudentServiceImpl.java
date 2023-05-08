package com.project.service;

import com.project.model.Projekt;
import com.project.model.Student;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.ParameterizedTypeReference;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.http.HttpEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.net.URI;
import java.util.Optional;

@Service
public class StudentServiceImpl implements StudentService{
    private static final Logger logger = LoggerFactory.getLogger(ProjektServiceImpl.class);
    @Value("${rest.server.url}") // adres serwera jest wstrzykiwany przez Springa, a jego wartość
    private String serverUrl; // przechowywana w pliku src/main/resources/application.properties
    private final static String RESOURCE_PATH = "/api/studenci";
    private RestTemplate restTemplate;

    public StudentServiceImpl(RestTemplate restTemplate) {
        this.restTemplate = restTemplate;
    }

    @Override
    public Optional<Student> getStudent(Integer studentId) {
        URI url = ServiceUtil.getUriComponent(serverUrl, getResourcePath(studentId))
                .build()
                .toUri();
        logger.info("REQUEST -> GET {}", url);
        return Optional.ofNullable(restTemplate.getForObject(url, Student.class));
    }

    @Override
    public Student setStudent(Student student) {
        if (student.getStudentId() != null) { // modyfikacja istniejącego projektu
            String url = getUriStringComponent(student.getStudentId());
            logger.info("REQUEST -> PUT {}", url);
            restTemplate.put(url, student);
            return student;
        } else {//utworzenie nowego projektu
            // po dodaniu projektu zwracany jest w nagłówku Location - link do utworzonego zasobu
            HttpEntity<Student> request = new HttpEntity<>(student);
            String url = getUriStringComponent();
            logger.info("REQUEST -> POST {}", url);
            URI location = restTemplate.postForLocation(url, request);
            logger.info("REQUEST (location) -> GET {}", location);
            return restTemplate.getForObject(location, Student.class);
            // jeżeli usługa miałaby zwracać utworzony obiekt a nie link to trzeba by użyć
            // return restTemplate.postForObject(url, projekt, Projekt.class);
        }
    }

    @Override
    public void deleteStudent(Integer studentId) {
        URI url = ServiceUtil.getUriComponent(serverUrl, getResourcePath(studentId))
                .build()
                .toUri();
        logger.info("REQUEST -> DELETE {}", url);
        restTemplate.delete(url);
    }

    @Override
    public Page<Student> getStudenci(Pageable pageable) {
        URI url = ServiceUtil.getURI(serverUrl, getResourcePath(), pageable);
        logger.info("REQUEST -> GET {}", url);
        return getPage(url, restTemplate);
    }

    @Override
    public Page<Student> searchByNazwisko(String nazwisko, Pageable pageable) {
        URI url = ServiceUtil.getUriComponent(serverUrl, getResourcePath(), pageable)
                .queryParam("nazwisko", nazwisko)
                .build().toUri();
        logger.info("REQUEST -> GET {}", url);
        return getPage(url, restTemplate);
    }
    private Page<Student> getPage(URI uri, RestTemplate restTemplate) {
        return ServiceUtil.getPage(uri, restTemplate,
                new ParameterizedTypeReference<RestResponsePage<Student>>() {});
    }
    private String getResourcePath() {
        return RESOURCE_PATH;
    }

    private String getResourcePath(Integer id) {
        return RESOURCE_PATH + "/" + id;
    }

    private String getUriStringComponent() {
        return serverUrl + getResourcePath();
    }

    private String getUriStringComponent(Integer id) {
        return serverUrl + getResourcePath(id);
    }
}
