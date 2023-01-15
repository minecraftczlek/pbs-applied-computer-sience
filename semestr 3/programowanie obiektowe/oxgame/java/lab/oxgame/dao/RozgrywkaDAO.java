package lab.oxgame.dao;

import java.util.List;
import lab.oxgame.model.Rozgrywka;

public interface RozgrywkaDAO {
    void zapiszRozgrywke(Rozgrywka rozgrywka);
    List<Rozgrywka> pobierzRozgrywki(Integer odWiersza, Integer liczbaWierszy);
    void usunRozgrywki();
}
