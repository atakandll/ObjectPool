#include <iostream>
#include <vector>

class Object
{
   public:
	   void DoSomething() {
		   std::cout << "Object doing something." << std::endl;
	   }

};

class ObjectPool {

private:
	std::vector<std::shared_ptr<Object>>pool;
	int maxSize;

public: 
	ObjectPool(int size) : maxSize(size) {

		for (int i = 0;i < maxSize;++i) {
			pool.push_back(std::make_shared<Object>());
		}
	}

	std::shared_ptr<Object> acquiredObject() {

		if (pool.empty()) {
			std::cout << "Pool is empty.Creating a new object." << std::endl;
			return std::make_shared<Object>();
		}
		else {
			std::shared_ptr<Object> obj = pool.back();
			pool.pop_back();
			std::cout << "Send the object" << std::endl;
			return obj;
		}
	}
	void releaseObject(std::shared_ptr<Object> obj) {

		if (pool.size() < maxSize) {
			pool.push_back(obj);
		}
		else {
			std::cout << "Pool is full. Cannot add more objects." << std::endl;
		}
	}

};

int main() {

	ObjectPool pool(3);

	//Acquire objects from the pool
	auto obj1 = pool.acquiredObject();
	auto obj2 = pool.acquiredObject();
	auto obj3 = pool.acquiredObject();

	// Try to acquire more than the pool size
	auto obj4 = pool.acquiredObject(); // This should create a new object

	// Release objects back to the pool
	pool.releaseObject(obj1);
	pool.releaseObject(obj2);
	pool.releaseObject(obj3);
	// pool.relaseObject(obj4); // Won't push into pool as the pool is full

	return 0;

};

