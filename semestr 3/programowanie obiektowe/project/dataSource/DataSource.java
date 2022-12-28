package com.project.dataSource;

import java.sql.Connection;
import java.sql.SQLException;
import com.zaxxer.hikari.HikariConfig;
import com.zaxxer.hikari.HikariDataSource;

public class DataSource {
	private static HikariConfig config;
	private static HikariDataSource ds;
	static {
		config = new HikariConfig();
		config.setJdbcUrl("jdbc:hsqldb:file:db/projekty");
		config.setUsername("Admin");
		config.setPassword("Admin");
		config.setMaximumPoolSize(1);
		ds = new HikariDataSource(config);
	}
	
	private DataSource() {}
	
	public static Connection getConnection() throws SQLException {
		return ds.getConnection();
	}
}