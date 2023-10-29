if (dataFile.is_open()) {
        std::string line;
        std::string remoteName;
        int delaiAction;

        std::getline(dataFile, remoteName);
        std::getline(dataFile, line);
        std::istringstream(line) >> delaiAction;

        std::vector<Button> buttons;
        std::vector<Shortcut> shortcuts;

        bool inApplicationsSection = false;
        bool inShortcutsSection = false;

        while (std::getline(dataFile, line) && !line.empty()) {
            if (isComment(line)) {
                continue;
            }

            if (line == "#Applications") {
                inApplicationsSection = true;
                inShortcutsSection = false;
                continue;
            } else if (line == "#Raccourcis") {
                inApplicationsSection = false;
                inShortcutsSection = true;
                continue;
            }

            if (inApplicationsSection) {
                std::istringstream iss(line);
                Button button;
                if (iss >> button.rgb >> button.name >> button.ir) {
                    buttons.push_back(button);
                }
            } else if (inShortcutsSection) {
                std::istringstream iss(line);
                Shortcut shortcut;
                if (iss >> shortcut.button >> shortcut.ir >> shortcut.key) {
                    std::string app;
                    while (iss >> app) {
                        shortcut.apps.push_back(app);
                    }
                    shortcuts.push_back(shortcut);
                }
            }
        }

        dataFile.close();

        // Maintenant vous pouvez utiliser les vecteurs "buttons" et "shortcuts"
        // pour accéder aux informations traitées à partir du fichier
    } else {
        std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
    }
