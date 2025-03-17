# Software Developer Test Solutions by Chirag Patel

Welcome to my GitHub repository containing solutions to two software development tests I completed as part of a job application process. These projects showcase my proficiency in Python, C++, real-time systems, and graphics programming using OpenGL, aligning with my expertise in automation, robotics, and software engineering.

## Projects Overview

### 1. Running Average Calculation (Test 1)
- **Description**: A console-based application that calculates a running average of continuously entered floating-point numbers without storing individual values. The program updates the average after each input and exits on the 'x' command.
- **Technologies**: Python
- **Key Features**:
  - Accepts floating-point inputs confirmed by Enter.
  - Computes the running average using the formula: `new_average = old_average + (new_value - old_average) / count`.
  - Terminates on input "x".
  - Memory-efficient with no storage of individual numbers.

### 2. Wind Turbine Simulation (Test 2)
- **Description**: A graphical application simulating a rotating wind turbine using OpenGL. The rotation speed (1–10) is adjustable via a `settings.txt` file, read every 5 seconds.
- **Technologies**: C++, OpenGL, FreeGLUT
- **Key Features**:
  - Renders a 2D wind turbine with a tower, hub, and rotating blades.
  - Dynamically updates speed from `settings.txt`.
  - Includes real-time animation and file-based configuration.

## Repository Structure
```
Wind Turbine Simulation and Running Average Calculation/
├── Test1_Running_Average/
│   ├── continuous_mean.py      # Source code
│   ├── continuous_mean.exe     # Runnable executable
├── Test2_Wind_Turbine/
│   ├── wind_turbine.cpp       # Source code
│   ├── wind_turbine.exe       # Runnable executable
│   ├── settings.txt           # Speed configuration file
│   ├── freeglut/              # FreeGLUT library folder (include and lib/x64)
├── README.md                  # This file
```


## Setup Instructions

### Test 1: Running Average Calculation
1. **Prerequisites**:
   - Python 3.x installed.
   - PyInstaller (optional, for `.exe` creation: `pip install pyinstaller`).
2. **Running the Code**:
   - Clone the repository: `git clone git@github.com:chiragpatel1229/Wind-Turbine-Simulation-and-Running-Average-Calculation.git`.
   - Navigate to `Test1_Running_Average/`.
   - Run the script: `python continuous_mean.py`.
   - Or use the pre-built executable: `continuous_mean.exe`.
3. **Building the `.exe`**:
   - Run: `pyinstaller --onefile continuous_mean.py` in the `Test1_Running_Average/` directory.
   - Find the executable in the `dist/` folder.

### Test 2: Wind Turbine Simulation
1. **Prerequisites**:
   - C++ compiler (e.g., MinGW or MSVC) with OpenGL and GLUT libraries.
   - GLUT development libraries (e.g., `freeglut` on Windows).
2. **Running the Code**:
   - Clone the repository: `git clone git@github.com:chiragpatel1229/Wind-Turbine-Simulation-and-Running-Average-Calculation.git`.
   - Navigate to `Test2_Wind_Turbine/`.
   - Ensure `settings.txt` contains a number between 1 and 10 (e.g., `5`).
   - Compile and run: `g++ wind_turbine.cpp -o wind_turbine.exe -lglut32 -lopengl32 -lglu32` (adjust for your system).
   - Or use the pre-built executable: `wind_turbine.exe`.
3. **Building the `.exe`**:
   - Use the compilation command above in a terminal with GLUT linked.

## Usage
- **Test 1**: Enter floating-point numbers one by one (press Enter after each). Type "x" to exit. The running average updates after each valid input.
- **Test 2**: Launch the executable to view the rotating wind turbine. Edit `settings.txt` with a value from 1 to 10 to adjust speed; changes apply every 5 seconds.

## Code Highlights
- **Test 1**: Features a memory-efficient running average algorithm, demonstrating problem-solving and Python proficiency.
- **Test 2**: Showcases graphics programming with OpenGL, dynamic file input, and real-time updates, highlighting C++ and automation skills.

## Contributing
This repository is for demonstration purposes. Feedback or suggestions are welcome via issues or pull requests.

## License
This project is licensed under the [MIT License](LICENSE) - see the `LICENSE` file for details.

## Contact
- **Name**: Chirag Patel
- **LinkedIn**: [[linkedin.com/in/chiragpatel](https://www.linkedin.com/in/chirag-patel-794084104/)]
- Feel free to connect for collaboration or further discussion!

## Acknowledgments
- Gratitude to the open-source communities for tools like OpenGL and PyInstaller.