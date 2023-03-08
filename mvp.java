import java.util.ArrayList;

interface DataSubject {
    void register(DataObserver dataObserver);

    void notifyObservers();
}

interface DataObserver {
    void update(int nv);
}

class Data implements DataSubject {
    int data = 0;
    ArrayList<DataObserver> dol;

    void setData(int d) {
        data = d;
        notifyObservers();
    }

    @Override
    public void register(DataObserver dataObserver) {
        dol.add(dataObserver);
    }

    @Override
    public void notifyObservers() {
        for (DataObserver d : dol) {
            d.update(data);
        }
    }
}

class Display {
    void show(int v) {
        System.out.println("val" + v);
    }
}

class DataPresenter implements DataObserver {
    Display display;
    Data data;

    @Override
    public void update(int nv) {
        display.show(nv);
    }

    public DataPresenter(Data data, Display display) {
        this.data = data;
        this.display = display;
        data.register(this);
    }

}