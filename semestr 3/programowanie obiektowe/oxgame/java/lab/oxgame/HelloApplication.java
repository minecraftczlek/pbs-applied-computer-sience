package lab.oxgame;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.io.IOException;

public class HelloApplication extends Application {
    private  static final Logger logger = LoggerFactory.getLogger(HelloApplication.class);

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 640, 560);
        stage.setTitle("kółko i krzyżyk");
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
    }

    public static void main(String[] args) {
        logger.info("Uruchamianie programu");
        try {
            launch();
        }catch (Exception e){
            logger.error("Błąd uruchaminaia {}", "inforamcje o błędzie: ", e);
        }
    }
}