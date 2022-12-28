package com.project.dao;

import java.util.List;
import com.project.model.Projekt;


public interface ProjektDao {
	void setProjekt (Projekt projekt);
	
	List<Projekt> getProjekty(Integer offset, Integer limit);
	
	Projekt getProjekt (Integer projektId);
	
	void deleteProjekt (Integer projektId);
	
	Integer getRowsNumber();
}
