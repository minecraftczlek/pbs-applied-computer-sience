package com.project.auth;

import java.util.Optional;

import com.project.model.Student;

public interface AuthService {
	Optional<String> login(Credentials credentials);

	void register(Student student);
}
