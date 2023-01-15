module lab.oxgame {
    requires javafx.controls;
    requires javafx.fxml;
    requires org.slf4j;
    requires java.sql;
    requires com.zaxxer.hikari;


    opens lab.oxgame to javafx.fxml;
    exports lab.oxgame;
}