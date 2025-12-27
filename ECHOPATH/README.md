# Echopath – Voice + Beep Assisted Smart Traffic Signal System

## Project Description
Echopath is a C++ based mini project that simulates a smart traffic signal
system with **voice alerts, beep sounds, and vibration simulation**.  
It is designed to improve road safety by assisting vehicles and pedestrians
through sensory feedback.

## Key Features
- **Smart Traffic Signal Logic**: Red, Yellow, and Green cycles
- **Voice Alerts**: Supports English and Hindi
- **Beep Sounds**: Different tones for Red, Yellow, and Green signals
- **Vibration Simulation**: Console output simulates haptic feedback
- **Pedestrian Button Simulation**: Advance signaling for pedestrians
- **Emergency Mode**: Gives priority to emergency vehicles
- **Day/Night Mode**: Adjusts beep speed and volume

## Technologies Used
- **Programming Language**: C++
- **Platform**: Windows (uses `Beep()` and `Sleep()` functions)
- **Tools**: Visual Studio / CodeBlocks / any C++ compiler

## Project Structure
Echopath/ ├── docs/      : Project presentation, report, demo video ├── src/       : C++ source code files (main.cpp, etc.) ├── output/    : Screenshots or other output files (optional) ├── README.md  : This file ├── LICENSE    : MIT License
## How to Run
1. Open `main.cpp` in a C++ IDE (Visual Studio, CodeBlocks, or similar).
2. Compile and run the program.
3. Follow console instructions:
   - Select language (English/Hindi)
   - Set traffic density (low/medium/high)
   - Emergency mode? (y/n)
   - Time of use: Day/Night
   - Pedestrian button press simulation
   - Choose mode: Demo or Realistic
4. Observe voice, beep, and console outputs for traffic simulation.

## Author
Soumya Shukla  
M.Sc. Bioinformatics

## License
This project is licensed under the [MIT License](LICENSE).
