import java.util.ArrayList;
import java.util.List;

// class Board { // model
//     UI ui;
//     void mupdate() {
//         System.out.println("Board updated");
//     }
// }

// class UI { // view
//     Board board;
//     void vupdate() {
//         System.out.println("Ui updated");
//     }
//     void onClick() {
//         // do something
//         board.mupdate();
//     }
// }

interface UISubject {
    void registerObserver(UIObserver o);

    void notifyObservers();

}

interface BoardSubject {
    void registerObserver(BoardObserver o);

    void notifyObservers();

}

interface UIObserver {
    void onUIChanged(); // update
}

interface BoardObserver {
    void onBoardChanged(); // update
}

class Board implements BoardSubject {
    List<BoardObserver> os = new ArrayList<>();

    @Override
    public void registerObserver(BoardObserver o) {
        os.add(o);
    }

    @Override
    public void notifyObservers() {
        for (var ob : os) {
            ob.onBoardChanged();
        }
    }

    public void update() {
        System.out.println("board updated");
    }
}

class UI implements UISubject {
    List<UIObserver> os = new ArrayList<>();

    @Override
    public void registerObserver(UIObserver o) {
        os.add(o);
    }

    @Override
    public void notifyObservers() {
        for (var ob : os) {
            ob.onUIChanged();
        }
    }

    public void onClick() {
        notifyObservers();
    }

    public void update() {
        System.out.println("ui updated");
    }
}

class Presenter implements BoardObserver, UIObserver {
    Board board;
    UI ui;

    Presenter(Board board, UI ui) {
        this.board = board;
        this.ui = ui;
        board.registerObserver(this); 
        ui.registerObserver(this); 
    }

    @Override
    public void onUIChanged() {
        board.update();
    }

    @Override
    public void onBoardChanged() {
        ui.update();
    }

}