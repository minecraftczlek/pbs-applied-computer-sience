package com.project.config;

import java.io.IOException;

import org.springframework.boot.web.client.RestTemplateBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpRequest;
import org.springframework.web.client.RestTemplate;
import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

import com.project.auth.TokenHolder;

import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;

@EnableWebMvc
@Configuration
@RequiredArgsConstructor
@Slf4j
public class WebConfig implements WebMvcConfigurer { 
	private final TokenHolder tokenHolder;

	@Override
    public void addInterceptors(InterceptorRegistry registry) {
		registry.addInterceptor(new HandlerInterceptor() {
			@Override
			public boolean preHandle(HttpServletRequest request, HttpServletResponse response, 
																Object handler) throws Exception {
				log.info("INTERCEPTOR'S REQUEST URL:" + request.getRequestURL());  // RequestMapping mapping = ((HandlerMethod)handler).getMethodAnnotation(RequestMapping.class);
				final String token = tokenHolder.getToken();
				log.info("INTERCEPTOR'S TOKEN ({})", token);
				if (token == null || token.isBlank()) {  // log.info("REDIRECT TO LOGIN ({})", mapping.toString());
					response.sendRedirect(request.getContextPath() + "/app/login");
					return false;
				}
				return true;
			}
		})
		.addPathPatterns("/app/**")
		.excludePathPatterns("/app/login", "/app/register", "/app/logout") ;
    }
	
    private void logRequest(HttpRequest request, byte[] body) throws IOException {
		log.info("REQUEST {");
		log.info(" URI: {}", request.getURI());
		log.info(" Method: {}", request.getMethod());
		log.info(" Headers: {}", request.getHeaders());
		log.info(" Request body: {}", new String(body, "UTF-8"));	
		log.info("}");
    }
    
	@Bean
	RestTemplate customRestTemplate(RestTemplateBuilder restTemplateBuilder) {
		return restTemplateBuilder.additionalInterceptors((request, body, execution) -> {
			final String token = tokenHolder.getToken();
			if (token != null && !token.isBlank()) {
				HttpHeaders headers = request.getHeaders();
				if (!headers.containsKey(HttpHeaders.AUTHORIZATION)) {
					final String prefix = "Bearer ";
					final String bearerToken = token.startsWith(prefix) ? token : prefix + token;
					request.getHeaders().add(HttpHeaders.AUTHORIZATION, bearerToken);
				}
			}
			logRequest(request, body);
			return execution.execute(request, body);
		}).build();
	}
    
  @Override
  public void addResourceHandlers(ResourceHandlerRegistry registry){
     registry
       .addResourceHandler("/**")
       .addResourceLocations("classpath:/META-INF/resources/", 
      		 			   "classpath:/resources/", 
      		 			   "classpath:/static/",
      		 			   "classpath:/public/");
  }
}

