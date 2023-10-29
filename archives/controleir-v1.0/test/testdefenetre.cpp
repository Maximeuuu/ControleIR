#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // TODO: Initialisation de l'application

    // Définition de la classe de fenêtre
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = L"MainWindowClass";
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    // Enregistrement de la classe de fenêtre
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, L"Échec de l'enregistrement de la classe de fenêtre.", L"Erreur", MB_ICONERROR);
        return 0;
    }

    // Création de la fenêtre principale
    HWND hWnd = CreateWindowEx(0, L"MainWindowClass", L"Page d'accueil", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

    if (!hWnd) {
        MessageBox(NULL, L"Échec de la création de la fenêtre.", L"Erreur", MB_ICONERROR);
        return 0;
    }

    // Affichage de la fenêtre
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Boucle de messages
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // TODO: Libération des ressources et nettoyage

    return static_cast<int>(msg.wParam);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CREATE:
            // TODO: Initialiser les éléments de l'IHM ici, par exemple, créer des boutons, des contrôles, etc.
            break;
        case WM_COMMAND:
            // TODO: Gérer les messages des boutons et des contrôles ici
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
