package com.project.config;

import org.springframework.boot.web.client.RestTemplateBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.client.RestTemplate;

@Configuration
public class SecurityConfig {
    // dzięki adnotacji @Bean Spring uruchomi metodę i zarejestruje w kontenerze obiekt przez nią
    @Bean
    // zwrócony, natomiast adnotacja @Autowired użyta w innej klasie spowoduje jego wstrzyknięcie
    RestTemplate customRestTemplate(RestTemplateBuilder restTemplateBuilder) {
        return restTemplateBuilder.basicAuthentication("admin", "admin").build();
    }
}