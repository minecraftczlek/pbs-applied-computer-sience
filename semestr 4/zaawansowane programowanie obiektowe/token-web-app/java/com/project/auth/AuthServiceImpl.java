package com.project.auth;

import java.util.Optional;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import com.project.model.Student;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;

@Service
@RequiredArgsConstructor
@Slf4j
public class AuthServiceImpl implements AuthService {
	private final RestTemplate restTemplate; 
	@Value("${rest.server.url}")
	private String serverUrl; 
	
	private String getUriStringComponent(String path) {
		return serverUrl + path;
	}
	
	@Override
	public Optional<String> login(Credentials credentials) {
		HttpEntity<Credentials> request = new HttpEntity<>(credentials);
		String url = getUriStringComponent("/api/login");
		log.info("REQUEST -> POST {}", url);
		AuthResponse authResponse = restTemplate
						.postForObject(url, request, AuthResponse.class);
		return Optional.ofNullable(authResponse.getToken());
	}

	@Override
	public void register(Student student) {
		HttpEntity<Student> request = new HttpEntity<>(student);
		String url = getUriStringComponent("/api/register");
		log.info("REQUEST -> POST {}", url);
		restTemplate.postForObject(url, request, Void.class);
	}
	
}
