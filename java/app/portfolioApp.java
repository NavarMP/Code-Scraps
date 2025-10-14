import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;

public class portfolioApp extends Application {
    
    private BorderPane mainLayout;
    private VBox contentArea;
    
    // Dark mode colors
    private final String BG_PRIMARY = "#0a0e27";
    private final String BG_SECONDARY = "#151b3d";
    private final String BG_CARD = "#1e2749";
    private final String ACCENT_COLOR = "#00d4ff";
    private final String TEXT_PRIMARY = "#ffffff";
    private final String TEXT_SECONDARY = "#a0aec0";
    
    @Override
    public void start(Stage primaryStage) {
        mainLayout = new BorderPane();
        mainLayout.setStyle("-fx-background-color: " + BG_PRIMARY + ";");
        
        // Create navigation sidebar
        VBox sidebar = createSidebar();
        mainLayout.setLeft(sidebar);
        
        // Create main content area
        ScrollPane scrollPane = new ScrollPane();
        scrollPane.setStyle("-fx-background: " + BG_PRIMARY + "; -fx-background-color: " + BG_PRIMARY + ";");
        scrollPane.setFitToWidth(true);
        
        contentArea = new VBox(30);
        contentArea.setPadding(new Insets(40));
        contentArea.setStyle("-fx-background-color: " + BG_PRIMARY + ";");
        
        scrollPane.setContent(contentArea);
        mainLayout.setCenter(scrollPane);
        
        // Show home page by default
        showHome();
        
        Scene scene = new Scene(mainLayout, 1200, 800);
        primaryStage.setTitle("Professional Portfolio");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    
    private VBox createSidebar() {
        VBox sidebar = new VBox(20);
        sidebar.setPrefWidth(280);
        sidebar.setPadding(new Insets(30, 20, 30, 20));
        sidebar.setStyle("-fx-background-color: " + BG_SECONDARY + ";");
        
        // Profile section
        VBox profile = new VBox(15);
        profile.setAlignment(Pos.CENTER);
        
        // Avatar
        Circle avatar = new Circle(50);
        avatar.setFill(Color.web(ACCENT_COLOR));
        avatar.setStroke(Color.web(BG_PRIMARY));
        avatar.setStrokeWidth(3);
        
        Label nameLabel = new Label("Your Name");
        nameLabel.setFont(Font.font("System", FontWeight.BOLD, 24));
        nameLabel.setTextFill(Color.web(TEXT_PRIMARY));
        
        Label titleLabel = new Label("Software Developer");
        titleLabel.setFont(Font.font("System", FontWeight.NORMAL, 14));
        titleLabel.setTextFill(Color.web(TEXT_SECONDARY));
        
        profile.getChildren().addAll(avatar, nameLabel, titleLabel);
        
        // Separator
        Separator sep1 = new Separator();
        sep1.setStyle("-fx-background-color: " + BG_CARD + ";");
        
        // Navigation menu
        VBox menu = new VBox(10);
        menu.getChildren().addAll(
            createNavButton("Home", "🏠"),
            createNavButton("About", "👤"),
            createNavButton("Projects", "💼"),
            createNavButton("Skills", "⚡"),
            createNavButton("Contact", "📧")
        );
        
        Region spacer = new Region();
        VBox.setVgrow(spacer, Priority.ALWAYS);
        
        // Footer
        Label footer = new Label("© 2024 Portfolio\nBuilt with JavaFX");
        footer.setFont(Font.font("System", 11));
        footer.setTextFill(Color.web(TEXT_SECONDARY));
        footer.setAlignment(Pos.CENTER);
        footer.setStyle("-fx-text-alignment: center;");
        
        sidebar.getChildren().addAll(profile, sep1, menu, spacer, footer);
        return sidebar;
    }
    
    private Button createNavButton(String text, String icon) {
        Button btn = new Button(icon + "  " + text);
        btn.setPrefWidth(240);
        btn.setPrefHeight(45);
        btn.setAlignment(Pos.CENTER_LEFT);
        btn.setPadding(new Insets(10, 20, 10, 20));
        btn.setFont(Font.font("System", FontWeight.NORMAL, 15));
        
        btn.setStyle(
            "-fx-background-color: transparent;" +
            "-fx-text-fill: " + TEXT_SECONDARY + ";" +
            "-fx-background-radius: 10;" +
            "-fx-cursor: hand;"
        );
        
        btn.setOnMouseEntered(e -> btn.setStyle(
            "-fx-background-color: " + BG_CARD + ";" +
            "-fx-text-fill: " + ACCENT_COLOR + ";" +
            "-fx-background-radius: 10;" +
            "-fx-cursor: hand;"
        ));
        
        btn.setOnMouseExited(e -> btn.setStyle(
            "-fx-background-color: transparent;" +
            "-fx-text-fill: " + TEXT_SECONDARY + ";" +
            "-fx-background-radius: 10;" +
            "-fx-cursor: hand;"
        ));
        
        btn.setOnAction(e -> {
            switch(text) {
                case "Home": showHome(); break;
                case "About": showAbout(); break;
                case "Projects": showProjects(); break;
                case "Skills": showSkills(); break;
                case "Contact": showContact(); break;
            }
        });
        
        return btn;
    }
    
    private void showHome() {
        contentArea.getChildren().clear();
        
        // Hero section
        VBox hero = new VBox(20);
        hero.setAlignment(Pos.CENTER);
        hero.setPadding(new Insets(60, 40, 60, 40));
        
        Label greeting = new Label("Hi, I'm");
        greeting.setFont(Font.font("System", FontWeight.NORMAL, 28));
        greeting.setTextFill(Color.web(TEXT_SECONDARY));
        
        Label name = new Label("Your Name");
        name.setFont(Font.font("System", FontWeight.BOLD, 56));
        name.setTextFill(Color.web(TEXT_PRIMARY));
        
        Label tagline = new Label("Building Digital Experiences");
        tagline.setFont(Font.font("System", FontWeight.NORMAL, 32));
        tagline.setTextFill(Color.web(ACCENT_COLOR));
        
        Label description = new Label(
            "A passionate software developer specializing in creating\n" +
            "elegant solutions to complex problems."
        );
        description.setFont(Font.font("System", 16));
        description.setTextFill(Color.web(TEXT_SECONDARY));
        description.setStyle("-fx-text-alignment: center;");
        description.setWrapText(true);
        
        HBox buttons = new HBox(20);
        buttons.setAlignment(Pos.CENTER);
        
        Button viewWork = createPrimaryButton("View My Work");
        Button getInTouch = createSecondaryButton("Get In Touch");
        
        buttons.getChildren().addAll(viewWork, getInTouch);
        
        hero.getChildren().addAll(greeting, name, tagline, description, buttons);
        
        // Stats section
        HBox stats = new HBox(40);
        stats.setAlignment(Pos.CENTER);
        stats.setPadding(new Insets(40));
        
        stats.getChildren().addAll(
            createStatCard("10+", "Projects Completed"),
            createStatCard("5+", "Years Experience"),
            createStatCard("15+", "Technologies Mastered")
        );
        
        contentArea.getChildren().addAll(hero, stats);
    }
    
    private void showAbout() {
        contentArea.getChildren().clear();
        
        Label title = createSectionTitle("About Me");
        
        VBox aboutCard = createCard();
        
        Label aboutText = new Label(
            "I'm a passionate software developer with expertise in building scalable, " +
            "user-friendly applications. My journey in technology began with a curiosity " +
            "about how things work, which evolved into a career focused on creating " +
            "meaningful digital experiences.\n\n" +
            "With a strong foundation in software engineering principles and a keen eye " +
            "for design, I strive to bridge the gap between functionality and aesthetics. " +
            "I believe that great software should not only work flawlessly but also " +
            "delight users at every interaction."
        );
        aboutText.setFont(Font.font("System", 16));
        aboutText.setTextFill(Color.web(TEXT_SECONDARY));
        aboutText.setWrapText(true);
        aboutText.setLineSpacing(5);
        
        Label educationTitle = createSubtitle("Education");
        Label education = new Label(
            "• Bachelor of Science in Computer Science\n" +
            "  University Name, 2020\n\n" +
            "• Certified Java Developer\n" +
            "  Oracle, 2021"
        );
        education.setFont(Font.font("System", 15));
        education.setTextFill(Color.web(TEXT_SECONDARY));
        
        aboutCard.getChildren().addAll(aboutText, educationTitle, education);
        
        contentArea.getChildren().addAll(title, aboutCard);
    }
    
    private void showProjects() {
        contentArea.getChildren().clear();
        
        Label title = createSectionTitle("Featured Projects");
        
        GridPane projectGrid = new GridPane();
        projectGrid.setHgap(30);
        projectGrid.setVgap(30);
        
        projectGrid.add(createProjectCard(
            "E-Commerce Platform",
            "Full-stack web application with payment integration",
            "Java • Spring Boot • React • PostgreSQL"
        ), 0, 0);
        
        projectGrid.add(createProjectCard(
            "Task Management App",
            "Collaborative project management tool with real-time updates",
            "JavaFX • MongoDB • WebSocket"
        ), 1, 0);
        
        projectGrid.add(createProjectCard(
            "Data Analytics Dashboard",
            "Interactive dashboard for visualizing business metrics",
            "Python • Flask • D3.js • MySQL"
        ), 0, 1);
        
        projectGrid.add(createProjectCard(
            "Mobile Fitness Tracker",
            "Cross-platform mobile app for tracking workouts",
            "React Native • Node.js • Firebase"
        ), 1, 1);
        
        contentArea.getChildren().addAll(title, projectGrid);
    }
    
    private void showSkills() {
        contentArea.getChildren().clear();
        
        Label title = createSectionTitle("Technical Skills");
        
        VBox skillsContainer = new VBox(30);
        
        skillsContainer.getChildren().addAll(
            createSkillCategory("Languages", new String[]{"Java", "Python", "JavaScript", "C++", "SQL"}),
            createSkillCategory("Frameworks", new String[]{"Spring Boot", "JavaFX", "React", "Node.js", "Django"}),
            createSkillCategory("Tools & Technologies", new String[]{"Git", "Docker", "AWS", "MongoDB", "PostgreSQL"}),
            createSkillCategory("Soft Skills", new String[]{"Problem Solving", "Team Collaboration", "Agile", "Communication"})
        );
        
        contentArea.getChildren().addAll(title, skillsContainer);
    }
    
    private void showContact() {
        contentArea.getChildren().clear();
        
        Label title = createSectionTitle("Get In Touch");
        
        VBox contactCard = createCard();
        contactCard.setMaxWidth(600);
        contactCard.setAlignment(Pos.CENTER);
        
        Label subtitle = new Label("Let's work together!");
        subtitle.setFont(Font.font("System", FontWeight.NORMAL, 20));
        subtitle.setTextFill(Color.web(TEXT_SECONDARY));
        
        VBox contactInfo = new VBox(20);
        contactInfo.setAlignment(Pos.CENTER_LEFT);
        contactInfo.setPadding(new Insets(20, 0, 20, 0));
        
        contactInfo.getChildren().addAll(
            createContactItem("📧", "Email", "your.email@example.com"),
            createContactItem("📱", "Phone", "+1 (123) 456-7890"),
            createContactItem("💼", "LinkedIn", "linkedin.com/in/yourprofile"),
            createContactItem("🐙", "GitHub", "github.com/yourusername")
        );
        
        Button sendMessage = createPrimaryButton("Send Message");
        sendMessage.setPrefWidth(300);
        
        contactCard.getChildren().addAll(subtitle, contactInfo, sendMessage);
        
        HBox centered = new HBox(contactCard);
        centered.setAlignment(Pos.CENTER);
        
        contentArea.getChildren().addAll(title, centered);
    }
    
    private Label createSectionTitle(String text) {
        Label title = new Label(text);
        title.setFont(Font.font("System", FontWeight.BOLD, 36));
        title.setTextFill(Color.web(TEXT_PRIMARY));
        return title;
    }
    
    private Label createSubtitle(String text) {
        Label subtitle = new Label(text);
        subtitle.setFont(Font.font("System", FontWeight.BOLD, 20));
        subtitle.setTextFill(Color.web(ACCENT_COLOR));
        subtitle.setPadding(new Insets(20, 0, 10, 0));
        return subtitle;
    }
    
    private VBox createCard() {
        VBox card = new VBox(20);
        card.setPadding(new Insets(30));
        card.setStyle(
            "-fx-background-color: " + BG_CARD + ";" +
            "-fx-background-radius: 15;" +
            "-fx-effect: dropshadow(gaussian, rgba(0, 212, 255, 0.2), 20, 0, 0, 0);"
        );
        return card;
    }
    
    private VBox createStatCard(String number, String label) {
        VBox card = new VBox(10);
        card.setAlignment(Pos.CENTER);
        card.setPadding(new Insets(30));
        card.setPrefWidth(200);
        card.setStyle(
            "-fx-background-color: " + BG_CARD + ";" +
            "-fx-background-radius: 15;"
        );
        
        Label numLabel = new Label(number);
        numLabel.setFont(Font.font("System", FontWeight.BOLD, 42));
        numLabel.setTextFill(Color.web(ACCENT_COLOR));
        
        Label textLabel = new Label(label);
        textLabel.setFont(Font.font("System", 14));
        textLabel.setTextFill(Color.web(TEXT_SECONDARY));
        
        card.getChildren().addAll(numLabel, textLabel);
        return card;
    }
    
    private VBox createProjectCard(String projectName, String description, String tech) {
        VBox card = new VBox(15);
        card.setPadding(new Insets(25));
        card.setPrefWidth(400);
        card.setPrefHeight(200);
        card.setStyle(
            "-fx-background-color: " + BG_CARD + ";" +
            "-fx-background-radius: 15;" +
            "-fx-cursor: hand;"
        );
        
        Label name = new Label(projectName);
        name.setFont(Font.font("System", FontWeight.BOLD, 20));
        name.setTextFill(Color.web(TEXT_PRIMARY));
        
        Label desc = new Label(description);
        desc.setFont(Font.font("System", 14));
        desc.setTextFill(Color.web(TEXT_SECONDARY));
        desc.setWrapText(true);
        
        Label techStack = new Label(tech);
        techStack.setFont(Font.font("System", FontWeight.NORMAL, 12));
        techStack.setTextFill(Color.web(ACCENT_COLOR));
        
        card.getChildren().addAll(name, desc, techStack);
        
        card.setOnMouseEntered(e -> card.setStyle(
            "-fx-background-color: " + BG_SECONDARY + ";" +
            "-fx-background-radius: 15;" +
            "-fx-cursor: hand;" +
            "-fx-effect: dropshadow(gaussian, rgba(0, 212, 255, 0.3), 25, 0, 0, 0);"
        ));
        
        card.setOnMouseExited(e -> card.setStyle(
            "-fx-background-color: " + BG_CARD + ";" +
            "-fx-background-radius: 15;" +
            "-fx-cursor: hand;"
        ));
        
        return card;
    }
    
    private VBox createSkillCategory(String category, String[] skills) {
        VBox container = new VBox(15);
        
        Label categoryLabel = new Label(category);
        categoryLabel.setFont(Font.font("System", FontWeight.BOLD, 20));
        categoryLabel.setTextFill(Color.web(ACCENT_COLOR));
        
        FlowPane skillTags = new FlowPane(15, 15);
        
        for (String skill : skills) {
            Label tag = new Label(skill);
            tag.setPadding(new Insets(10, 20, 10, 20));
            tag.setFont(Font.font("System", 14));
            tag.setTextFill(Color.web(TEXT_PRIMARY));
            tag.setStyle(
                "-fx-background-color: " + BG_CARD + ";" +
                "-fx-background-radius: 20;"
            );
            skillTags.getChildren().add(tag);
        }
        
        container.getChildren().addAll(categoryLabel, skillTags);
        return container;
    }
    
    private HBox createContactItem(String icon, String label, String value) {
        HBox item = new HBox(15);
        item.setAlignment(Pos.CENTER_LEFT);
        
        Label iconLabel = new Label(icon);
        iconLabel.setFont(Font.font("System", 24));
        
        VBox textBox = new VBox(5);
        
        Label labelText = new Label(label);
        labelText.setFont(Font.font("System", FontWeight.BOLD, 14));
        labelText.setTextFill(Color.web(TEXT_SECONDARY));
        
        Label valueText = new Label(value);
        valueText.setFont(Font.font("System", 16));
        valueText.setTextFill(Color.web(TEXT_PRIMARY));
        
        textBox.getChildren().addAll(labelText, valueText);
        item.getChildren().addAll(iconLabel, textBox);
        
        return item;
    }
    
    private Button createPrimaryButton(String text) {
        Button btn = new Button(text);
        btn.setPrefWidth(200);
        btn.setPrefHeight(50);
        btn.setFont(Font.font("System", FontWeight.BOLD, 15));
        btn.setStyle(
            "-fx-background-color: " + ACCENT_COLOR + ";" +
            "-fx-text-fill: " + BG_PRIMARY + ";" +
            "-fx-background-radius: 25;" +
            "-fx-cursor: hand;"
        );
        
        btn.setOnMouseEntered(e -> btn.setStyle(
            "-fx-background-color: #00b8e6;" +
            "-fx-text-fill: " + BG_PRIMARY + ";" +
            "-fx-background-radius: 25;" +
            "-fx-cursor: hand;" +
            "-fx-effect: dropshadow(gaussian, rgba(0, 212, 255, 0.5), 15, 0, 0, 0);"
        ));
        
        btn.setOnMouseExited(e -> btn.setStyle(
            "-fx-background-color: " + ACCENT_COLOR + ";" +
            "-fx-text-fill: " + BG_PRIMARY + ";" +
            "-fx-background-radius: 25;" +
            "-fx-cursor: hand;"
        ));
        
        return btn;
    }
    
    private Button createSecondaryButton(String text) {
        Button btn = new Button(text);
        btn.setPrefWidth(200);
        btn.setPrefHeight(50);
        btn.setFont(Font.font("System", FontWeight.BOLD, 15));
        btn.setStyle(
            "-fx-background-color: transparent;" +
            "-fx-text-fill: " + TEXT_PRIMARY + ";" +
            "-fx-border-color: " + ACCENT_COLOR + ";" +
            "-fx-border-width: 2;" +
            "-fx-background-radius: 25;" +
            "-fx-border-radius: 25;" +
            "-fx-cursor: hand;"
        );
        
        btn.setOnMouseEntered(e -> btn.setStyle(
            "-fx-background-color: " + BG_CARD + ";" +
            "-fx-text-fill: " + ACCENT_COLOR + ";" +
            "-fx-border-color: " + ACCENT_COLOR + ";" +
            "-fx-border-width: 2;" +
            "-fx-background-radius: 25;" +
            "-fx-border-radius: 25;" +
            "-fx-cursor: hand;"
        ));
        
        btn.setOnMouseExited(e -> btn.setStyle(
            "-fx-background-color: transparent;" +
            "-fx-text-fill: " + TEXT_PRIMARY + ";" +
            "-fx-border-color: " + ACCENT_COLOR + ";" +
            "-fx-border-width: 2;" +
            "-fx-background-radius: 25;" +
            "-fx-border-radius: 25;" +
            "-fx-cursor: hand;"
        ));
        
        return btn;
    }
    
    public static void main(String[] args) {
        launch(args);
    }
}