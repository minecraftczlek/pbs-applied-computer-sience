package com.project.auth;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.project.model.Student;
import com.project.validation.ValidationService;

import lombok.RequiredArgsConstructor;

@RestController
@RequiredArgsConstructor
@RequestMapping("/api")
public class AuthController {
	private final AuthService authService;
    private final ValidationService<Student> validator;
	
	//Sprawdź zawartość zwracanego tokenu na https://jwt.io/
    @PostMapping("/register")
	public ResponseEntity<Void> register(@RequestBody Student student){
		validator.validate(student); 
		authService.register(student);
		return new ResponseEntity<Void>(HttpStatus.OK);
	}
    
	@PostMapping("/login")
	public ResponseEntity<AuthResponse> login(@RequestBody AuthRequest request){
		return ResponseEntity.ok(authService.authenticate(request));
	}
}
