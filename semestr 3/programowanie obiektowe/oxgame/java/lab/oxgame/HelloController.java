package lab.oxgame;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import lab.oxgame.dao.RozgrywkaDAO;
import lab.oxgame.dao.RozgrywkaDAOImpl;
import lab.oxgame.model.Rozgrywka;

import java.util.List;

public class HelloController {
    RozgrywkaDAO rozgrywkaDAO = new RozgrywkaDAOImpl();
    private String playerO, playerX;
    private int actions;
    @FXML
    private TextField textFieldPlayerO, textFieldPlayerX;
    @FXML
    private Button button00, button01, button02, button10, button11, button12, button20, button21, button22;
    @FXML
    private TextArea history;
    @FXML
    private Label labelTour;

    @FXML
    protected void game(){
        playerO = textFieldPlayerO.getText();
        playerX = textFieldPlayerX.getText();//pobieranie graczy
        if(playerO.length()>0 && playerX.length()>0){
            button00.setDisable(false);
            button01.setDisable(false);
            button02.setDisable(false);
            button10.setDisable(false);
            button11.setDisable(false);
            button12.setDisable(false);
            button20.setDisable(false);
            button21.setDisable(false);
            button22.setDisable(false);//włączanie przycisków
            button00.setText("");
            button01.setText("");
            button02.setText("");
            button10.setText("");
            button11.setText("");
            button12.setText("");
            button20.setText("");
            button21.setText("");
            button22.setText("");//czyszczenie przycisków
            labelTour.setText("X");
            actions = 0;
        }

        history.clear();
        List<Rozgrywka> rozgrywki = rozgrywkaDAO.pobierzRozgrywki(0, 100);
        for(int i=0; i<=rozgrywki.size(); i++){
            Rozgrywka rozgrywka = rozgrywki.get(i);
            history.appendText(rozgrywka.getRozgrywkaId().toString() + "\t");
            history.appendText(rozgrywka.getZwyciezca()+ "\t");
            history.appendText(rozgrywka.getGraczO() + "\t");
            history.appendText(rozgrywka.getGraczX() + "\t");
            history.appendText(rozgrywka.getDataczasRozgrywki().toString() + "\n");
        }
    }

    @FXML
    private void click(ActionEvent event){
        if(event.getSource() == button00){
            button00.setText(labelTour.getText());
            button00.setDisable(true);
        }else if(event.getSource() == button01){
            button01.setText(labelTour.getText());
            button01.setDisable(true);
        }else if(event.getSource() == button02){
            button02.setText(labelTour.getText());
            button02.setDisable(true);
        }else if(event.getSource() == button10){
            button10.setText(labelTour.getText());
            button10.setDisable(true);
        }else if(event.getSource() == button11){
            button11.setText(labelTour.getText());
            button11.setDisable(true);
        }else if(event.getSource() == button12){
            button12.setText(labelTour.getText());
            button12.setDisable(true);
        }else if(event.getSource() == button20){
            button20.setText(labelTour.getText());
            button20.setDisable(true);
        }else if(event.getSource() == button21){
            button21.setText(labelTour.getText());
            button21.setDisable(true);
        }else if(event.getSource() == button22){
            button22.setText(labelTour.getText());
            button22.setDisable(true);
        }

        if(check(labelTour.getText())) {
            System.out.printf("wygrał: %s%n", labelTour.getText());
//            if(labelTour.getText()=="X")history.appendText("WYGRAŁ: "+playerX+"\n");
//            else history.appendText("WYGRAŁ: "+playerO+"\n");

            Rozgrywka rozgrywka = new Rozgrywka(labelTour.getText(), playerO, playerX);
            rozgrywkaDAO.zapiszRozgrywke(rozgrywka);

            textFieldPlayerO.setText(playerX);
            textFieldPlayerX.setText(playerO);
            game();
            return;
        }
        if(++actions == 9){
//            System.out.printf("REMiS%n");
//            history.appendText("REMIS\n");

            Rozgrywka rozgrywka = new Rozgrywka(null, playerO, playerX);
            rozgrywkaDAO.zapiszRozgrywke(rozgrywka);

            textFieldPlayerO.setText(playerX);
            textFieldPlayerX.setText(playerO);
            game();
            return;
        }

        if(labelTour.getText()=="O")labelTour.setText("X");
        else labelTour.setText("O");
    }

    @FXML
    private boolean check(String s){
        if(button00.getText()==s && button01.getText()==s && button02.getText()==s);
        else if(button10.getText()==s && button11.getText()==s && button12.getText()==s);
        else if(button20.getText()==s && button21.getText()==s && button22.getText()==s);
        else if(button00.getText()==s && button10.getText()==s && button20.getText()==s);
        else if(button01.getText()==s && button11.getText()==s && button21.getText()==s);
        else if(button02.getText()==s && button12.getText()==s && button22.getText()==s);
        else if(button00.getText()==s && button11.getText()==s && button22.getText()==s);
        else if(button20.getText()==s && button11.getText()==s && button02.getText()==s);
        else return false;
        return true;
    }

    @FXML
    private void clear(){
        rozgrywkaDAO.usunRozgrywki();
        game();
    }

    @FXML
    public void initialize(){
        history.setText("adwwd");
//        game();
    }
}