public interface Vehicle {
 public:
	virtual void start();
	virtual void stop();
}

public class CAR implements Vehicle{

public :
	void start()
	{
		lock();
		go();
	}
	void stop(){}
	void lock(){}
	void go(){}
	
}

public class SHIP implements Vehicle{

public :
	void start()
	{
		balance();
		swim();
	}
	void stop(){}
	void balance(){}
	void swim(){}
	
}

public class AIRPLANE implements Vehicle{

public :
	void start()
	{
		go();
		fly();
	}
	void stop(){}
	void fly(){}
	void go(){}
	
}

public class TANK implements Vehicle{

public :
	void start()
	{
		move();
		stop();
		fire();
	}
	void stop(){}
	void move(){}
	void fire(){}
	
}
