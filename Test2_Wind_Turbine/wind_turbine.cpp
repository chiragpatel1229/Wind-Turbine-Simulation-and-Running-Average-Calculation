#include <GL/glut.h>  // Implimented the OpenGL functionality
#include <iostream>
#include <fstream>
#include <cmath>

// Global variables
float turbineRotationAngle = 0.0f;         // Tracks the rotation angle of the blades (degrees)
int turbineSpeedLevel = 1;                 // Starting speed level of rotation (1 = slowest and with 10 = fastest)
const char* speedConfigFile = "settings.txt";  // File name and to adjust the speed

// Functions
void renderScene();                        // Renders the wind turbine scene
void updateRotation(int value);            // Updates the turbine rotation angle periodically
void updateSpeedConfig(int value);         // Reads speed settings from file every 5 seconds
void loadSpeedFromFile();                  // Loads the speed value from the configuration file
void drawWindTurbine();                    // Draws the wind turbine silhouette

/*
 -- Renders the wind turbine scene.
 -- Clears the buffer, sets the view, and create a shape of the turbine.
 */
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear color and depth buffers
    glLoadIdentity();                                    // Reset the modelview matrix
    
    // Position the camera to view the 2D turbine properly
    glTranslatef(0.0f, 0.0f, -5.0f);
    
    drawWindTurbine();  // Draw the wind turbine silhouette
    
    glutSwapBuffers();  // Swap buffers for smooth animation
}

/**
 -- Draws the wind turbine outline, the tower, and blades.
 -- Used OpenGL to create a simplified 2D representation.
 */
void drawWindTurbine() {
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to black for turbine

    // Draw the tower
    glBegin(GL_POLYGON);
        glVertex2f(-0.1f, -2.0f);  // Bottom-left corner
        glVertex2f( 0.1f, -2.0f);  // Bottom-right corner
        glVertex2f( 0.15f,  0.5f);  // Top-right corner
        glVertex2f(-0.15f,  0.5f);  // Top-left corner
    glEnd();

    glPushMatrix();  // Set current transformation matrix
        glTranslatef(0.0f, 0.5f, 0.0f);  // Move to the hub position (top of tower)

        // Draw the circular hub 
        float hubRadius = 0.12f;
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float rad = i * 3.14159f / 180.0f;  // Convert degrees to radians
            glVertex2f(std::cos(rad) * hubRadius, std::sin(rad) * hubRadius);
        }
        glEnd();

        glPushMatrix();  // Set hub transformation
            glRotatef(turbineRotationAngle, 0.0f, 0.0f, 1.0f);  // Rotate blades at the Z-axis

            // Draw three blades, each located 120 degrees apart
            for (int i = 0; i < 3; i++) {
                glPushMatrix();
                    glRotatef(i * 120.0f, 0.0f, 0.0f, 1.0f);  // Position each blade
                    glBegin(GL_POLYGON);
                        glVertex2f(0.0f, -0.05f);  // Blade base
                        glVertex2f(1.3f, -0.08f);  // Blade tip
                        glVertex2f(1.3f,  0.08f);  // Blade tip
                        glVertex2f(0.0f,  0.05f);  // Blade base
                    glEnd();
                glPopMatrix();
            }
        glPopMatrix();
    glPopMatrix();
}

/*
-- Updates the turbine rotation angle based on the speed level.
-- Called every 15ms for smooth animation.
 */
void updateRotation(int value) {
    turbineRotationAngle += turbineSpeedLevel;  // Increment angle based on speed
    if (turbineRotationAngle > 360.0f) {
        turbineRotationAngle -= 360.0f;         // Keep angle within 0-360 degrees
    }
    
    glutPostRedisplay();                    // Request a redraw of the scene
    glutTimerFunc(15, updateRotation, 0);   // prepare for the next update
}

/**
-- Adjust the speed level from the settings.txt file.
-- verifies the speed value (must be between 1 and 10).
 */
void loadSpeedFromFile() {
    std::ifstream file(speedConfigFile);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open settings file: " << speedConfigFile << std::endl;
        return;
    }

    int speed;
    file >> speed;
    if (speed >= 1 && speed <= 10) {
        turbineSpeedLevel = speed;  // Update speed if valid
        std::cout << "Turbine speed updated to: " << turbineSpeedLevel << std::endl;
    } else {
        std::cerr << "Error: Invalid speed value! (" << speed << "). IT must be between 1 and 10." << std::endl;
    }
    file.close();
}

/*
-- Timely (Regularly) reads the speed setting from the file every 5 seconds.
 */
void updateSpeedConfig(int value) {
    loadSpeedFromFile();                        // Read and update the speed
    glutTimerFunc(5000, updateSpeedConfig, 0);  // Set to check again in 5 seconds
}

/*
-- Initializes OpenGL settings to create the view.
-- Sets up the projection matrix and background color.
 */
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background to white
    
    glMatrixMode(GL_PROJECTION);       // Switch to projection matrix
    glLoadIdentity();                  // Reset projection matrix
    glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);  // Set orthographic projection for 2D view
    glMatrixMode(GL_MODELVIEW);        // Switch back to modelview matrix
}

/*
-- Main function to initialize GLUT, set up the window, and start the animation loop.
-- @param argc: Number of command-line arguments.
-- @param argv: Array of command-line arguments.
-- @return: Exit status (0 for success).
 */
int main(int argc, char** argv) {
    loadSpeedFromFile();                // Load initial speed setting
    
    // Initialize GLUT and create the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // Enable double buffering, RGB color, and depth
    glutInitWindowSize(500, 500);       // Set window size pixels
    glutCreateWindow("Wind Turbine Simulation");  // Create window with title
    
    // Set up OpenGL and callbacks
    init();                             // Initialize OpenGL settings
    glutDisplayFunc(renderScene);       // Set display callback
    glutTimerFunc(0, updateRotation, 0);        // Start rotation updates
    glutTimerFunc(5000, updateSpeedConfig, 0);  // Start speed updates
    
    glutMainLoop();                     // Enter the GLUT event loop
    return 0;
}