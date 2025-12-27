// 🌐 ECHOPATH: Voice + Beep Assisted Traffic Signal System

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// ---------------- TEXT‑TO‑SPEECH FUNCTION ----------------
void speak(string text) {
    string command =
        "mshta vbscript:Execute(\"CreateObject(\"\"SAPI.SpVoice\"\").Speak(\"\"" +
        text + "\"\")(window.close)\")";
    system(command.c_str());
}

// ---------------- VIBRATION SIMULATION -------------------
void vibration() {
    cout << "[Vibration]" << endl;
}

// -------------- TRAFFIC SIGNAL CYCLE ---------------------
void runCycle(int redTime,
              int yellowTime,
              int greenTime,
              string lang,
              int beepDelay,
              bool isNight)
{
    // -------- RED signal ----------
    if (lang == "Hindi")
        speak("Signal laal hai, ab road cross karo");
    else
        speak("Signal red, vehicles stop pedestrians cross");

    for (int i = redTime; i > 0; i--) {
        speak(to_string(i));
        cout << " Red Signal: " << i << " seconds remaining" << endl;
        vibration();
        Beep(600, beepDelay); // Slow beep for Red
        Sleep(100);
    }
    cout << endl;

    // -------- YELLOW signal -------
    if (lang == "Hindi")
        speak("Signal peela hai, taiyaar ho jao");
    else
        speak("Signal yellow, get ready");

    for (int i = yellowTime; i > 0; i--) {
        speak(to_string(i));
        cout << " Yellow Signal: " << i << " seconds remaining" << endl;
        vibration();
        for (int j = 0; j < 3; j++)
            Beep(800 + 50 * j, beepDelay / 2); // Rising pitch
        Sleep(100);
    }
    cout << endl;

    // -------- GREEN signal --------
    if (lang == "Hindi")
        speak("Signal hara hai, ruk jaao");
    else
        speak("Signal green, vehicles go, pedestrians wait");

    for (int i = greenTime; i > 0; i--) {
        speak(to_string(i));
        cout << " Green Signal: " << i << " seconds remaining" << endl;
        vibration();
        Beep(700, beepDelay / 2);
        Beep(700, beepDelay / 2);          // Rapid double beep
        Sleep(100);
    }
    cout << endl;
}

// --------------------- MAIN FUNCTION ---------------------
int main() {
    cout << "=== Voice + Beep Assisted Traffic Signal ===" << endl;

    // Language selection
    cout << "Select language: 1. English  2. Hindi\nEnter choice: ";
    int langChoice;
    cin >> langChoice;
    string language = (langChoice == 2) ? "Hindi" : "English";

    // Traffic density
    cout << "Enter traffic density (low/medium/high): ";
    string density;
    cin >> density;

    int redTime = 3, yellowTime = 2, greenTime = 3;
    if (density == "low") {
        redTime = 3;  greenTime = 3;
    } else if (density == "medium") {
        redTime = 7;  greenTime = 5;
    } else if (density == "high") {
        redTime = 10; greenTime = 8;
    }

    // Emergency mode
    cout << "Emergency mode? (y/n): ";
    char emergency;
    cin >> emergency;
    if (emergency == 'y' || emergency == 'Y') {
        cout << "[Emergency mode ON] Giving priority to emergency vehicles.\n";
        speak("Emergency mode on, clearing path for emergency vehicles");
        redTime = 1;
        yellowTime = 1;
        greenTime = 6;
    }

    // Day/Night mode
    cout << "Time of use: 1. Day  2. Night\nEnter choice: ";
    int timeChoice;
    cin >> timeChoice;
    bool isNight = (timeChoice == 2);

    int beepDelay = isNight ? 150 : 300;  // Night: slower beeps, volume simulate
    if (isNight) {
        cout << "[Night mode, volume reduced]" << endl;
        speak("Night mode, volume reduced");
    }

    // Pedestrian button simulation
    cout << "Pedestrian button press kara? (y/n): ";
    char pedPress;
    cin >> pedPress;
    bool pedestrianPressed = (pedPress == 'y' || pedPress == 'Y');
    if (pedestrianPressed) {
        if (language == "Hindi")
            speak("Pedestrian button dabaya gaya, signaling advance hota hai");
        else
            speak("Pedestrian button pressed, signaling will advance");
    }

    // Mode selection
    cout << "1. Demo Mode (run fixed cycles)" << endl;
    cout << "2. Realistic Mode (run infinitely)" << endl;
    cout << "Enter your choice (1/2): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        if (pedestrianPressed) {
            cout << "Pedestrian button pressed before cycle, "
                    "signal will be shorter/advance.\n";
        }

        // run only once (or few times)
        runCycle(redTime, yellowTime, greenTime, language, beepDelay, isNight);

        speak("Simulation complete. Thank you!");
        cout << "\nSimulation complete. Thank you!" << endl;

    } else if (choice == 2) {
        cout << "\nRealistic mode running. Press Ctrl + C to stop.\n";
        while (true) {
            if (pedestrianPressed) {
                cout << "Pedestrian button pressed, signal will advance if needed.\n";
                // yahan extra logic add kar sakte ho
            }
            runCycle(redTime, yellowTime, greenTime, language, beepDelay, isNight);
        }
    } else {
        cout << "\nInvalid choice! Exiting.\n";
    }

    return 0;
}
