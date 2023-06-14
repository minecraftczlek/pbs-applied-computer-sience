package com.project.auth;

import org.springframework.stereotype.Component;
import org.springframework.web.context.annotation.SessionScope;

import lombok.Data;

@Data
@Component
@SessionScope
public class TokenHolder {
	private String token;

	public void clear() {
		this.token = null;
	}
}