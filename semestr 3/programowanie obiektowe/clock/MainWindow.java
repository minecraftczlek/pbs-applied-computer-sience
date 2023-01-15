package clock;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class MainWindow {
    private JFrame frame;

    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                try{
                    GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
                    GraphicsDevice gd = ge.getDefaultScreenDevice();
                    boolean isPerPixelTranslucencySupported = gd.isWindowTranslucencySupported(GraphicsDevice.WindowTranslucency.PERPIXEL_TRANSLUCENT);
                    if(isPerPixelTranslucencySupported){
                        MainWindow window = new MainWindow();
                        window.frame.pack();
                        window.frame.setVisible(true);
                    }
                }catch (Exception e){
                    e.printStackTrace();
                }
            }
        });
    }

    public MainWindow(){
        initialize();
    }

    public void initialize(){
        frame = new JFrame();
        frame.setType(Window.Type.UTILITY);
        frame.setUndecorated(true);
        frame.setBackground(new Color(0, 0, 0, 0));
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocation(0, 600);
        frame.setAlwaysOnTop(true);
        ClockPanel clockPanel = new ClockPanel(250, 250);
        clockPanel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseReleased(MouseEvent me) {
                if(me.isPopupTrigger())System.exit(0);
            }
        });
        frame.setContentPane(clockPanel);
        clockPanel.start();
    }
}