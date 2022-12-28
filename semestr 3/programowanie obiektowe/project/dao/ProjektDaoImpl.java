package com.project.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.LocalDateTime;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import com.project.dataSource.DataSource;
import com.project.model.Projekt;

public class ProjektDaoImpl implements ProjektDao {

	@Override
	public void setProjekt(Projekt projekt) {
		boolean isInsert = projekt.getProjektId() == null;
		String query = isInsert ?
				"INSERT INTO projekt (nazwa, opis, dataczas_utworzenia, "
				+ "data_oddania) VALUES (?, ?, ?, ?)"
			: "UPDATE projeky SET nazwa = ?, opis = ?, dataczas_utworzenia = ?, "
			+ "data_oddania = ? WHERE projekt_id = ?";
		try (Connection connect = DataSource.getConnection();
				PreparedStatement prepStmt = connect
						.prepareStatement(query, Statement.RETURN_GENERATED_KEYS)){
			prepStmt.setString(1, projekt.getNazwa());
			if(projekt.getDataczasUtworzenia() == null)
				projekt.setDataczasUtworzenia(LocalDateTime.now());
			prepStmt.setString(2, projekt.getOpis());
			prepStmt.setObject(3, projekt.getDataczasUtworzenia());
			prepStmt.setObject(4, projekt.getDataOddania());
			if(!isInsert) prepStmt.setInt(5, projekt.getProjektId());
			
			prepStmt.executeUpdate();
			
			if (isInsert) {
				ResultSet keys = prepStmt.getGeneratedKeys();
				if (keys.next()) {
					projekt.setProjektId(keys.getInt(1));
				}
				keys.close();
			}
		}catch(SQLException e) {
			throw new RuntimeException(e);
		}
		
	}

	@Override
	public List<Projekt> getProjekty(Integer offset, Integer limit) {
		List<Projekt> projekty = new ArrayList<>();
		String query = "SELECT * FROM projekt"
				+ " ORDER BY dataczas_utworzenia DESC OFFSET ? LIMIT ?";
		
		try (Connection connect = DataSource.getConnection();
				PreparedStatement prepStmt = connect
						.prepareStatement(query)){
			prepStmt.setInt(1, offset);
			prepStmt.setInt(2, limit);
			ResultSet rs = prepStmt.executeQuery();
			while(rs.next()) {
				Projekt projekt = new Projekt();
				projekt.setProjektId(rs.getInt("projekt_id"));
				projekt.setNazwa(rs.getString("nazwa"));
				projekt.setOpis(rs.getString("Opis"));
				projekt.setDataczasUtworzenia(rs.getObject("dataczas_utworzenia", LocalDateTime.class));
				projekt.setDataOddania(rs.getObject("data_oddania", LocalDate.class));
				projekty.add(projekt);
			}
		}catch(SQLException e) {
			throw new RuntimeException(e);
		}
		
		return projekty;
	}

	@Override
	public Projekt getProjekt(Integer projektId) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void deleteProjekt(Integer projektId) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public Integer getRowsNumber() {
		// TODO Auto-generated method stub
		return null;
	}

}
