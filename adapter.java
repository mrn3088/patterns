interface Duck {
	public void quack();
	public void fly();
}
interface Rail {
	void call();
	void flapping();
}
class Coot implements Rail {
	public void call() { System.out.println("krrp!"); }  // sound a Coot makes
	public void flapping() { System.out.println("flap, flap, flap"); }  // how a coot flies
  }
  
class CootAdapter implements Duck {
	Coot coot;
	public CootAdapter(Coot coot) {
		this.coot = coot;
	}

	@Override
	public void quack() {
		coot.call();
	}

	@Override
	public void fly() {
		coot.flapping();
	}

}