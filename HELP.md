# Simple Line Editor - Help Guide

Welcome to the Simple Line Editor! This editor operates entirely from the command line using single-letter commands. 

## Supported Commands

*   **`i <line_number>` : Insert a Line**
    *   **Description:** Prompts you to insert a new line of text at the specified line number. Any existing lines at or below this number will be shifted down.
    *   **Usage Example:** Type `i 1` and press Enter. The editor will prompt you for text. Type `Hello World` and press Enter. "Hello World" is now line 1.

*   **`d <line_number>` : Delete a Line**
    *   **Description:** Deletes the text at the specified line number. Any lines below it will be shifted up to fill the gap.
    *   **Usage Example:** Type `d 2` and press Enter. The second line of your document is removed.

*   **`p` : Display the Document**
    *   **Description:** Prints the entire current state of the document to the terminal, complete with line numbers.
    *   **Usage Example:** Type `p` and press Enter to view your text.

*   **`q` : Quit**
    *   **Description:** Exits the editor. 
    *   **Usage Example:** Type `q` and press Enter.