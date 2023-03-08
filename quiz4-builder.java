interface ISensor {
}

interface ICPU {
}

interface ILens {
}

class DSensor implements ISensor {
}

class DCPU implements ICPU {
}

class PLens implements ILens {
    PLens(int size) {
    }
}

class ZLens implements ILens {
    ZLens(int a, int b) {
    }
}

class Camera {
    ISensor s;
    ICPU c;
    ILens l;

    // Camera(ISensor si, ICPU ci, ILens li) {
    // s = (si != null) ? si : new DSensor();
    // c = (ci != null) ? ci : new DCPU();
    // l = (li != null) ? li : new PLens(50);
    // }
    Camera(ISensor si, ICPU ci, ILens li) {
        this.s = si;
        this.c = ci;
        this.l = li;
    }

    // ... Camera methods ...
}

class CameraBuilder {
    Camera camera;
    ISensor s;
    ICPU c;
    ILens l;


    CameraBuilder useSensor(ISensor si) {
        s = si == null ? new DSensor() : si;
        return this;
    }

    CameraBuilder useCPU(ICPU ci) {
        c = ci == null ? new DCPU() : ci;
        return this;
    }

    CameraBuilder useLen(ILens li) {
        l = li == null ? new PLens(50) : li;
        return this;
    }

    Camera build() {
        return new Camera(s, c, l);
    }

    Camera buildDefault() {
        return this.useCPU(null).useLen(null).useLen(null).build();
    }
}

class CameraStore {
    Camera cam;

    CameraStore() {
        // cam = new Camera(null, null, new ZLens(24, 70)); // ß update this, too
        cam = new CameraBuilder().useCPU(null).useLen(null).useLen(new ZLens(24, 70)).build();
    }
    // ... CameraStore methods ...
}