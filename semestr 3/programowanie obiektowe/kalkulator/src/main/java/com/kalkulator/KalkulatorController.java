package com.kalkulator;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;

import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Locale;

public class KalkulatorController {
    private Operation operation = Operation.BRAK;
    private double number = 0;
    DecimalFormat df = new DecimalFormat("0", DecimalFormatSymbols.getInstance(Locale.ENGLISH));

    @FXML
    private TextArea result;
    @FXML
    private Button button0, button1, button2, button3, button4, button5, button6, button7, button8, button9, buttonAdd, buttonRemove, buttonMultiplication, buttonDivision;

    @FXML
    private void result(){
        df.setMaximumFractionDigits(340);
        double n;
        try{
            n = Double.parseDouble(result.getText());
        }catch (Exception e){
            n = 0;
        }
        System.out.println(n);
        switch (operation){
            case BRAK -> number = n;
            case DODAWANIE -> number += n;
            case ODEJMOWANIE -> number -= n;
            case MNOZENIE -> number *= n;
            case DZIELENIE ->  number /= n;
        }
        result.setText(df.format(number));
        operation = Operation.BRAK;
    }
    @FXML
    protected void click(ActionEvent event){
        if(event.getSource() == button0)result.appendText("0");
        else if(event.getSource() == button1)result.appendText("1");
        else if(event.getSource() == button2)result.appendText("2");
        else if(event.getSource() == button3)result.appendText("3");
        else if(event.getSource() == button4)result.appendText("4");
        else if(event.getSource() == button5)result.appendText("5");
        else if(event.getSource() == button6)result.appendText("6");
        else if(event.getSource() == button7)result.appendText("7");
        else if(event.getSource() == button8)result.appendText("8");
        else if(event.getSource() == button9)result.appendText("9");
    }

    @FXML
    private void clickOperation(ActionEvent event){
        result();
        if(event.getSource() == buttonAdd)operation = Operation.DODAWANIE;
        else if(event.getSource() == buttonRemove)operation = Operation.ODEJMOWANIE;
        else if(event.getSource() == buttonMultiplication)operation = Operation.MNOZENIE;
        else if(event.getSource() == buttonDivision)operation = Operation.DZIELENIE;
        result.clear();
    }

    @FXML
    private void clear(){
        operation = Operation.BRAK;
        number = 0;
        result.clear();
    }

    @FXML
    private void dot(){
        if(!result.getText().contains("."))result.appendText(".");
    }

    @FXML
    private void sqrt(){
        df.setMaximumFractionDigits(340);
        result();
        double n = Double.parseDouble(result.getText());
        result.setText(df.format(Math.sqrt(n)));
    }

    @FXML
    private void percent(){
        df.setMaximumFractionDigits(340);
        result();
        double n = Double.parseDouble(result.getText());
        result.setText(df.format(n/100));
    }

    @FXML
    private void fraction(){
        df.setMaximumFractionDigits(340);
        result();
        double n = Double.parseDouble(result.getText());
        result.setText(df.format(1/n));
    }

    @FXML
    private void logarithm(){
        df.setMaximumFractionDigits(340);
        result();
        double n = Double.parseDouble(result.getText());
        result.setText(df.format(Math.log10(n)));
    }
}