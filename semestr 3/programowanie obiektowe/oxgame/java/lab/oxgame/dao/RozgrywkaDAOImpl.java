package lab.oxgame.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

import lab.oxgame.datasource.DataSource;
import lab.oxgame.model.Rozgrywka;

public class RozgrywkaDAOImpl implements RozgrywkaDAO {
    public void zapiszRozgrywke(Rozgrywka rozgrywka){
        boolean isInsert = rozgrywka.getRozgrywkaId() == null;
        String query = isInsert ?
                "INSERT INTO ROZGRYWKA (ZWYCIEZCA, GRACZ_O, GRACZ_X, DATACZAS_ROZGRYWKI) VALUES (?, ?, ?, ?)":
                "UPDATE ROZGRYWKA SET ZWYCIEZCA = ?, GRACZ_O = ?, GRACZ_X = ?, DATACZAS_ROZGRYWKI = ? WHERE ROZGRYWKA_ID = ?";
        try(Connection connect = DataSource.getConnection(); PreparedStatement prepStmt = connect.prepareStatement(query, Statement.RETURN_GENERATED_KEYS)) {
            prepStmt.setString(1, rozgrywka.getZwyciezca());
            prepStmt.setString(2, rozgrywka.getGraczO());
            prepStmt.setString(3, rozgrywka.getGraczX());
            if(rozgrywka.getDataczasRozgrywki() == null) rozgrywka.setDataczasRozgrywki(LocalDateTime.now());
            prepStmt.setObject(4, rozgrywka.getDataczasRozgrywki());
            if(!isInsert) prepStmt.setInt(4, rozgrywka.getRozgrywkaId());

            prepStmt.executeUpdate();
        }catch(SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public List<Rozgrywka> pobierzRozgrywki(Integer odWiersza, Integer liczbaWierszy) {
        List<Rozgrywka> rozgrywki = new ArrayList<>();
        String query = "SELECT * FROM ROZGRYWKA ORDER BY DATACZAS_ROZGRYWKI ASC OFFSET ? LIMIT ?";

        try (Connection connect = DataSource.getConnection(); PreparedStatement prepStmt = connect.prepareStatement(query, Statement.RETURN_GENERATED_KEYS)){
            prepStmt.setInt(1, odWiersza);
            prepStmt.setInt(2, liczbaWierszy);
            ResultSet rs = prepStmt.executeQuery();

            while(rs.next()){
                Rozgrywka rozgrywka = new Rozgrywka();
                rozgrywka.setRozgrywkaId(rs.getInt("ROZGRYWKA_ID"));
                rozgrywka.setZwyciezca(rs.getString("ZWYCIEZCA"));
                rozgrywka.setGraczO(rs.getString("GRACZ_O"));
                rozgrywka.setGraczX(rs.getString("GRACZ_X"));
                rozgrywka.setDataczasRozgrywki(rs.getObject("DATACZAS_ROZGRYWKI", LocalDateTime.class));
                rozgrywki.add(rozgrywka);
            }
        }catch(SQLException e) {
            throw new RuntimeException(e);
        }
        return rozgrywki;
    }

    @Override
    public void usunRozgrywki() {
        String query = "DELETE FROM ROZGRYWKA WHERE 1=1";
        try (Connection connect = DataSource.getConnection(); PreparedStatement prepStmt = connect.prepareStatement(query, Statement.RETURN_GENERATED_KEYS)) {
            ResultSet rs = prepStmt.executeQuery();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
