module com.example.kalkulator {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.kalkulator to javafx.fxml;
    exports com.kalkulator;
}