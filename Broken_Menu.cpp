    
    std::cout << "Wybierz tryb gry:" << std::endl;
    std::cout << "EASY - 1" << std::endl;
    std::cout << "NORMAL - 2" << std::endl;
    std::cout << "HARD - 3" << std::endl;
    std::cout << "WYJSCIE - 4" << std::endl;
    std::cout << "DEBUG - 0" << std::endl;
    std::cin >> gamemode;

    std::cout << "Wybierz wysokosc planszy" << std::endl;
    std::cin >> y;

    std::cout << "Wybierz szerokosc planszy" << std::endl;
    std::cin >> x;


    if (gamemode == 0) 
    {
        MinesweeperBoard board(x, y, DEBUG);
    }
    else if (gamemode == 1) 
    {
        MinesweeperBoard board(x, y, EASY);
    }
    else if (gamemode == 2) 
    {
        MinesweeperBoard board(x, y, NORMAL);
    }
    else if (gamemode == 3) 
    {
        MinesweeperBoard board(x, y, HARD);
    }
    else if (gamemode == 4) 
    {
        exit(0);
    }

    change_detection = true;

    if(change_detection == true)
    {
        view.text_display();
        change_detection = false;
    }
    


   