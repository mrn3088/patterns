class Car {
    ITire t;
    IRim r;
    Car (ITire t, IRim r) {
        this.t = t;
        this.r = r;
    }
}
interface ITire {}
interface IRim {}

class Tire implements ITire {}
class Rim implements IRim {}

class CarBuilder {
    Car car;
    ITire t;
    IRim r;
    CarBuilder() {}
    CarBuilder useTire(ITire t) {
        this.t = t;
        return this;
    }
    CarBuilder useRim(IRim r) {
        this.r = r;
        return this;
    }

    Car build() {
        return new Car(t, r);
    }

}

class Main {
    public static void main(String[] args) {
        Car car = new CarBuilder()
                    .useTire(new Tire())
                    .useRim(new Rim())
                    .build();
    }
    
}