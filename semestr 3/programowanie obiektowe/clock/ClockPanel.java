package clock;

import java.awt.*;
import java.awt.geom.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.concurrent.TimeUnit;
import javax.swing.JPanel;

public class ClockPanel extends JPanel implements Runnable {
    private static final long serialVersionUID = 1L;
    private final DateTimeFormatter dtFormatter = DateTimeFormatter.ofPattern("HH:mm:ss");
    private volatile boolean start;
    private LocalDateTime dateTime;

    public ClockPanel(int width, int height){
        setPreferredSize(new Dimension(width, height));
        setOpaque(false);
        dateTime = LocalDateTime.now();
    }

    public void start(){
        this.start = true;
        new Thread(this).start();
    }

    @Override
    public void run() {
        int prevSecond = -1;
        while (start){
            dateTime = LocalDateTime.now();
            int second = dateTime.getSecond();
            if(second != prevSecond){
                prevSecond = second;
                repaint();
            }
            try{TimeUnit.MILLISECONDS.sleep(200);}
            catch (InterruptedException e){}
        }
    }

    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        paintClock(g2, dateTime);
    }

    private void paintClock(Graphics2D g2, LocalDateTime dateTime){
        float lineWidth = 3.0f;
        Stroke line = new BasicStroke(lineWidth, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND);
        Font font = new Font("Tahoma", Font.PLAIN, getHeight()/10);
        g2.setColor(new Color(200, 200, 255));
        g2.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC, 0.65f));
        g2.setStroke(line);
        g2.setFont(font);

        Point2D origin = new Point2D.Double(getWidth() / 2.0, getHeight() / 10);

        String time = dtFormatter.format(dateTime);
        Rectangle2D timeBounds = font.getStringBounds(time, g2.getFontRenderContext());
        g2.drawString(time, Math.round(origin.getX() - timeBounds.getWidth() / 2.0), Math.round(origin.getY() + getHeight() / 3.0));

        double radius = getWidth() / 2.0  - 2.0 * lineWidth;
        //TODO rysowanie wskazówek

        //rysowanie kółka
        double innerRadius = radius / 10;
        g2.fill(new Ellipse2D.Double(origin.getX() - innerRadius/2.0, origin.getY() + innerRadius/2.0, innerRadius, innerRadius));
    }
}
