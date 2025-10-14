import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class p19JavaFX extends Application {
    
    // Parameters (from your original HTML)
    int x = 10;
    int y = 20;
    int width = 500;
    int height = 300;
    String colorHex = "FF0000";
    
    @Override
    public void start(Stage primaryStage) {
        // Create canvas for drawing
        Canvas canvas = new Canvas(600, 400);
        GraphicsContext gc = canvas.getGraphicsContext2D();
        
        // Convert hex color to JavaFX Color
        Color col = Color.web("#" + colorHex);
        
        // Draw rectangle
        gc.setStroke(col);
        gc.setLineWidth(1);
        gc.strokeRect(x, y, width, height);
        
        // Setup scene and stage
        StackPane root = new StackPane();
        root.getChildren().add(canvas);
        
        Scene scene = new Scene(root, 600, 400);
        primaryStage.setTitle("Rectangle with Specified Coordinates");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    
    public static void main(String[] args) {
        launch(args);
    }
}