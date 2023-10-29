#include <iostream>
#include <Windows.h>

int main() {
    // Simuler la touche 'A'
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = 0xB3;  // Code de la touche virtuelle
    input.ki.dwFlags = 0;  // Touche enfoncée
    SendInput(1, &input, sizeof(INPUT));

    input.ki.dwFlags = KEYEVENTF_KEYUP;  // Touche relâchée
    SendInput(1, &input, sizeof(INPUT));

    std::cout << "Touche 'A' simulée." << std::endl;

	// Envoyer
    keybd_event(0xB3, 0, 0, 0);
    keybd_event(0xB3, 0, KEYEVENTF_KEYUP, 0); // Relâchement de la touche Ctrl

    return 0;
}
