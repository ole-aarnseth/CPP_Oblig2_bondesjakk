# **C++ Oblig 2 bondesjakk rapport**

**Til denne obligen valgte jeg å gjøre oppgave nr 1, "N-på-rad."**

## **Innledning**

Dette programmet består av to klasser, `class_board` og `class_ticTacToe`. Ideen bak klassene er at board representerer selve spillebrettet, mens
ticTacToe er selve gameplay-klassen som kjører spillet på et board-objekt. Disse klassene er deklarert i `class_board.h` og `class_ticTacToe.h`,
og implementert i `class_board.cpp` og `class_ticTacToe.cpp`, i tillegg benytter jeg en fil `main.cpp` som inneholder main-metoden, som starter selve
programmet ved å opprette et ticTacToe-objekt og kaller på objektets playRound()-funksjon. Minimal brettstørrelse er 8, mens maks er 66 (med
fontstørrelse 8.) Koden støtter opp mot 99, men da må fontstørrelsen på shell-vinduet reduseres til noe under 8. To spillere, kalt "Player X" og
"Player O" basert på deres brikker, spiller mot hverandre.

## **Klasseoversikt**

#### **Class board**

- Benytter namespace gameboard.
- Namespacet inneholder også definisjonene av datatypene `t_mark` og `t_gamestatus`. Førstnevnte representerer en brikke
på spillbrettet (X, O eller EMPTY), mens `t_gamestatus` er en statustype som returneres av boardStatus()-funksjonen.
- Klassen inneholder en to-dimensjonal t_mark-vector kalt myBoard, som utgjør selve spillbrettet.
- Inneholder følgende metoder:
  * **void makeBoard(int size):** Sørger for å bygge opp selve brettet med angitt størrelse.
  * **void flushBoard():** Nullstiller hele brettet ved å sette alle brikker til EMPTY.
  * **int getSize():** Returnerer størrelsen til brettet.
  * **void printBoard():** Skriver ut hele brettet på skjermen ved hjelp av std::cout.
  * **bool insertMark(unsigned int a, unsigned int b, tmark m):** Setter inn brikke på angitte koordinater.
  * **t_gamestatus boardStatus():** En algoritme som med noen for-løkker sjekker om noen har fått n-rad vertikalt, horisontalt og diagonalt, samt
sjekker den om det er uavgjort (alle rader blokkert.)

#### **Class ticTacToe**

- Benytter namespace tttGame.
- Klassen inneholder et board-objekt kalt theBoard.
- Inneholder følgende metoder:
  * **ticTacToe():** Konstruktør for klassen, den ber om input fra bruker, deretter bygges opp et board-objekt etter brukers angitte størrelse.
  * **void inputMark(int turn):** Ber om input fra bruker og setter inn en brikke i board-objektet, hvis verdien av turn er partall, spør den
"player X", hvis ikke spør den "player O." Ideen er at playRound() trekker et tilfeldig tall mellom 1-2 og kaller denne metoden med det tallet,
deretter inkrementeres turn for hvert kall. Da blir det tilfeldig hvem som begynner mellom "player X" og "player O".
  * **void playRound():** Starter selve spillet. Først plukkes det ut tilfeldig hvem som skal begynne, deretter kalles inputMark(). Etter at
brettet har fått antall inputs lik (brettstørrelse * 2) - 1, vil boardStatus()-algoritmen kjøres etter hver input (det er liten vits i å kjøre
den før noen kan vinne.) Til slutt vil den skrive ut resultatet av spillet på skjermen, basert på hva boardStatus returnerte. Deretter spør den
om bruker vil spille en runde til, og hvis ja vil den hoppe tilbake til starten av metoden.