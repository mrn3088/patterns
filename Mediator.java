import java.util.Collections;
import java.util.List;

class Naive {
    private class Board {
        UI ui;

        String getState(String str) {
            // do some thing...
            String theState = str;
            return theState; // should be replaced
        }

        void update(String str) {
            // updating the internal board state
            ui.update(str);
        }
    }

    private class UI {
        Board board;

        void onClick() {
            board.update("Clicked");
        }

        void update(String str) {
            System.out.println("UI updated with state: " + str);
        }
    }
}
